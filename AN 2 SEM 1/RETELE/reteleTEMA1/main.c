//CIRIPESCU TEODOR A7
//project written on MacOS
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_COMMAND_SIZE 256
#define LOGIN_CONFIG_PATH "../users.txt"
#define FIFO_PATH "../loginfifo"
#define MYFIND_ROOT_PATH ".."

int LOGGED_IN;
char myFindData[2048];
void findFiles(char* path, char* file);
int getFileStats(const char* path, char* output_data);

void login(const char* username){ // FIFO
    pid_t pid;
    int fd;
    char response[2];
    switch( pid = fork() ) {
        case -1:
            perror("fork");
            exit(2);

        case 0: //child process
            fd = open(FIFO_PATH, O_WRONLY); //opening the fifo
            if(fd == -1){
                perror("Error opening fifo.");
            }

            FILE *fp = fopen(LOGIN_CONFIG_PATH, "r");
            if (fp == NULL){
                perror ("Error opening login config file.");
            }

            char buffer[256];
            while( fscanf(fp, "%s", buffer) == 1 ){
                if( strcmp(username, buffer) == 0 ){
                    fclose(fp);
                    if( -1 == write(fd, "1", 2)){ // user found
                        perror("Error writing in fifo.");
                    }
                    close(fd);
                    exit(1);
                }
            }
            fclose(fp);
            if( -1 == write(fd, "0", 2)){ // user not found
                perror("Error writing in fifo.");
            }
            close(fd);
            exit(0);

        default: //parent process
            mkfifo(FIFO_PATH, 0666); //creating fifo
            fd = open(FIFO_PATH, O_RDONLY);
            if(fd == -1){
                perror("Error opening fifo");
            }
            if(-1 == read(fd, response, sizeof(response))){
                perror("Error reading from fifo.");
            }
            if( strcmp(response,"1") == 0 )
                LOGGED_IN = 1;
            else
                LOGGED_IN = 0;
            close(fd);
            printf("login result: %d\n\n", LOGGED_IN);
            wait(NULL);
    }
}
int myFind(char* path, char *file){ // PIPE
    pid_t pid;
    int fd[2];
    unsigned long respLen;
    if (pipe (fd) == -1){
        perror ("pipe");
        exit (2);
    }

    switch(pid=fork()) {
        case -1:
            perror("fork");
            exit(2);

        case 0: //child process
            close(fd[0]); //closing input part of pipe
            strcpy(myFindData, "");
            findFiles(path, file);
            respLen = strlen(myFindData) + 1;
            if( -1 == write( fd[1], &respLen, sizeof(unsigned long))){
                perror("Error writing response length to pipe.");
            }
            if(-1 == write( fd[1], myFindData, respLen )){
                perror("Error writing response to pipe.");
            }
            close(fd[1]);
            exit(1);

        default: //parent process
            close(fd[1]); //closing output part of pipe
            if(-1 == read(fd[0], &respLen, sizeof(unsigned long))){
                perror("Error reading response length from pipe.");
            }
            if(-1 == read(fd[0], myFindData, respLen)){
                perror("Error reading response from pipe.");
            }
            if(respLen > 1) {
                printf("myFind result:\n%s\n\n", myFindData);
            }
            else {
                printf("No files were found with the name of %s.\n", file);
            }
            close(fd[0]);
            wait(NULL);
    }


}
void myStat(const char* path){ //SOCKETS
    int sockp[2];
    char myStatData[1024];
    pid_t pid;
    unsigned long respLen;
    //int socketpair(int domain, int type, int protocol, int sv[2]);
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0)
    {
        perror("socketpair");
        exit(2);
    }
    switch(pid=fork()) {
        case -1:
            perror("fork");
            exit(2);

        case 0: //child process
            close(sockp[0]); // closing input
            getFileStats(path, myStatData);
            respLen = strlen(myStatData) + 1;
            if( -1 == write( sockp[1], &respLen, sizeof(unsigned long))){
                perror("Error writing response length to socket.");
            }
            if (write(sockp[1], myStatData, respLen) < 0)
                perror("Error writing response to socket.");
            close(sockp[1]);
            exit(1);

        default: //parent process
            close(sockp[1]); // closing output
            if(-1 == read(sockp[0], &respLen, sizeof(unsigned long))){
                perror("Error reading response length from socket.");
            }
            if (read(sockp[0], myStatData, respLen) < 0)
                perror("Error reading response to socket.");
            close(sockp[0]);
            if(respLen > 1) {
                printf("myStat result:\n%s\n\n", myStatData);
            }
            else {
                printf("No file was found at %s.\n", path);
            }

            wait(NULL);
    }



}
void findFiles(char* path, char* file){
    DIR* dir;
    struct dirent *ent;
    char npath[256];
    if((dir=opendir(path)) != NULL){
        while (( ent = readdir(dir)) != NULL){
            strcpy(npath, path);
            if(strcmp(ent->d_name, file)==0){
                char output_data[1024];
                char file_path[256];
                snprintf(file_path, sizeof(file_path), "%s/%s", npath, ent->d_name);
                getFileStats(file_path, output_data);
                snprintf(myFindData, sizeof(myFindData), "%s%s\nPath :%s\n%s",
                        myFindData,
                        ent->d_name,
                        npath,
                        output_data);
            }
            if(ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0  && strcmp(ent->d_name, "..") != 0){
                strcat(npath, "/");
                strcat(npath, ent->d_name);
                findFiles(npath, file);

            }
        }
        closedir(dir);
    }
}
int getFileStats(const char* path, char* output_data){
    struct stat file_stats;
    char perm[10]="---------";
    char file_type[32];
    int err = 0;
    if(stat(path, &file_stats)!=0){
        err = 1;
        perror("Error getting file stats.\n");
        return 0;
    }
    //http://man7.org/linux/man-pages/man7/inode.7.html
    //Getting the type of file
    switch(file_stats.st_mode & S_IFMT){
        case S_IFDIR : strcpy(file_type,"Directory\n"); break;
        case S_IFREG : strcpy(file_type,"Normal file\n"); break;
        case S_IFLNK : strcpy(file_type,"Link\n"); break;
        case S_IFIFO : strcpy(file_type,"FIFO\n"); break;
        case S_IFSOCK: strcpy(file_type,"Socket\n"); break;
        case S_IFBLK : strcpy(file_type,"Block device\n"); break;
        case S_IFCHR : strcpy(file_type,"Character device\n"); break;
        default: strcpy(file_type,"Unknown file type");
    }
    //Getting the permission string
    if(S_IRUSR & file_stats.st_mode) perm[0]='r';
    if(S_IWUSR & file_stats.st_mode) perm[1]='w';
    if(S_IXUSR & file_stats.st_mode) perm[2]='x';
    if(S_IRGRP & file_stats.st_mode) perm[3]='r';
    if(S_IWGRP & file_stats.st_mode) perm[4]='w';
    if(S_IXGRP & file_stats.st_mode) perm[5]='x';
    if(S_IROTH & file_stats.st_mode) perm[6]='r';
    if(S_IWOTH & file_stats.st_mode) perm[7]='w';
    if(S_IXOTH & file_stats.st_mode) perm[8]='x';

    char buff[1024];
    snprintf(buff, sizeof(buff), "File size: %lld bytes\nFile creation date: %sFile time of last data access: %sFile time of last data modification: %sFile type: %sFile permissions: %s\nFile UID: %d\nNumber of hard links: %d\n",
             file_stats.st_size,
             ctime((const time_t *) &file_stats.st_birthtimespec.tv_sec),
             ctime((const time_t *) &file_stats.st_atimespec.tv_sec),
             ctime((const time_t *) &file_stats.st_mtimespec.tv_sec),
             file_type,
             perm,
             file_stats.st_uid, // unsigned int
             file_stats.st_nlink
             );
    if(err==0)
        strcpy(output_data, buff);
    else
        strcpy(output_data,"");
    return 1;
}

int main() {
    /*
    login("ionel");
    myFind("..", "file4.txt");
    myStat("../mockdirectory/file4.txt");
    */
    int running = 1;
    char command[MAX_COMMAND_SIZE],command_param[MAX_COMMAND_SIZE];
    ///*
    while(running){
        //getting the command
        fgets(command, MAX_COMMAND_SIZE, stdin);
        if( strncmp(command, "login : ", 8) == 0 ){ //login command
            printf("login command received.\n");
            memcpy( command_param, &command[8], strlen(command) - 8 );
            command_param[strlen(command) - 9] = '\0'; // -9 because it also registers \n
            printf("login param: %s\n", command_param);
            login(command_param);
        }
        else if(!LOGGED_IN){
            printf("Please login in order to run any commands.\n");
        }
        else if( strncmp(command, "myfind ", 7) == 0 ){ //myfind command
            printf("myfind command received.\n");
            memcpy( command_param, &command[7], strlen(command) - 7 );
            command_param[strlen(command) - 8] = '\0';
            printf("myfind param: %s\n", command_param);
            myFind(MYFIND_ROOT_PATH, command_param);
        }
        else if( strncmp(command, "mystat ", 7) == 0 ){ //mystat command
            printf("mystat command received.\n");
            memcpy( command_param, &command[7], strlen(command) - 7 );
            command_param[strlen(command) - 8] = '\0';
            printf("mystat param: %s\n", command_param);
            myStat(command_param);
        }
        else if( strncmp(command, "exit", 4) == 0 ){ //exit command
            printf("exit command received.\nBye Bye!\n");
            running = 0;
        }
        else{ //unknown command
            printf("unknown command received. Could not run it.\n");
        }
    }
    return 0;
}