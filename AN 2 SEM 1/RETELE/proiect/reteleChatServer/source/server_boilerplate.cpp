//
// Created by Teodor Ciripescu on 09/12/2019.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include<string>

#include "../headers/server_boilerplate.h"
#include "../headers/command_handler.h"

#define THREAD_COUNT 100

extern int errno;

thData threadData[THREAD_COUNT];
int threadData_len = 0;

database d;

command_handler ch;

int server_boilerplate::createServer(int PORT) {
    struct sockaddr_in server;	// structura folosita de server - socket address internet style
    struct sockaddr_in from; // structura folosita de clienti
    int sd;		//socket descriptor
    pthread_t th_read[100];    //Identificatorii thread-urilor care se vor crea
    int i=0;

    /* crearea socketului
     * socket (int domain, int type, int protocol)
     *  domain = AF_INET (Familie: TCP, UDP,...)
     *  type  = SOCK_STREAM (TCP socket)
     *  protocol = 0 (nivelul transport)
     * */
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror ("[server]Error at socket().\n");
        return errno;
    }
    /* utilizarea optiunii SO_REUSEADDR
     *int setsockopt (int sockfd, int level, int optname, void *optval, socklen_t *optlen);
     * sockfd = sd descriptorul socketului
     * level = SOL_SOCKET se refera la nivelul socketului
     * optname = SO_REUSEADDR dam voie sa fie refolosita adresa locala
     * optval = on pointer catre valoarea optiunii (should be nonzero to enable a boolean option, or zero if the option is to be disabled)
     * */
    int on=1;
    setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

    /* pregatirea structurilor de date
     * bzero - initializeaza memoria alocata structurilor cu 0
     * */
    bzero (&server, sizeof (server));
    bzero (&from, sizeof (from));

    /* umplem structura folosita de server */
    /* stabilirea familiei de socket-uri
     * AF_INET - familia TCP, UDP
     * */
    server.sin_family = AF_INET;
    /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    /* stabilim portul
     * htons - host-to-network short functioneaza pe integeri de 16 biti
     * face conversie la ordinea octetilor specifica retelei (big endian -> little endian)
     * */
    server.sin_port = htons (PORT);

    /* atasam socketul
     * ataseaza o adresa locala la un socket
     * int bind ( int sockfd, const struct sockaddr *addr, int addrlen);
     * asigneaza o adresa  socket-ului
     * sd - descriptorul socketului
     * */
    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
        perror ("[server]Error at bind().\n");
        return errno;
    }

    /* punem serverul sa asculte daca vin clienti sa se conecteze
     * int listen(int sockfd, int backlog);
     * sockfd - descriptorul socketului ce are atasat o adresa
     * backlog - numarul de conexiuni din coada de asteptare
     * */
    if (listen (sd, 2) == -1)
    {
        perror ("[server]Error at listen().\n");
        return errno;
    }

    /* servim in mod concurent clientii...folosind thread-uri */
    printf ("[server]Waiting at port %d...\n",PORT);
    /* golim bufferul lui stdout */
    fflush (stdout);

    /* ne conectam la baza de date */
    d.createConnection();

    while (1)
    {
        int client_descriptor;
        thData * thread_data; //parametru functia executata de thread
        int length = sizeof (from);

        /* acceptam clientul (stare blocanta pana cand se conecteaza clientul)
         * int accept (int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
         * returneaza descriptorul clientului
         * populeaza structura from de tip sockaddr cu datele clientului
         * */
        if ((client_descriptor = accept (sd, (struct sockaddr *) &from, reinterpret_cast<socklen_t *>(&length))) < 0)
        {
            perror ("[server]Eroare la accept().\n");
            continue;
        }

        /* s-a realizat conexiunea, se astepta mesajul */
        thread_data=(struct thData*)malloc(sizeof(struct thData));
        thread_data->idUser=-1;
        thread_data->descriptor=client_descriptor;
        /* se creaza un thread nou ce se va ocupa de client
         * int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
         *
         * */
        pthread_create(&th_read[i], NULL, &treatClient, thread_data);
    }
}

void *server_boilerplate::treatClient(void *arg) {
    struct thData thread_data;
    thread_data= *((struct thData*)arg);
    printf ("[thread]- %d - New thread, waiting for client...\n", thread_data.idUser);
    fflush (stdout);
    /* pthread_detach marcheaza threadul ca detached
     * adica atunci cand acesta este terminat, toata memoria va fi eliberata automat
     * */
    pthread_detach(pthread_self());

    receiveFromClient((struct thData *) arg);
    /* am terminat cu acest client, inchidem conexiunea */
    close ((intptr_t)arg);
    return(NULL);
}

void server_boilerplate::receiveFromClient(void *arg) {
    thData thread_data;
    thread_data= *((struct thData*)arg);
    addThreadData(arg);
    bool alive = true;
    while(alive){
        short int command_len = 0;
        int command_id = -1;

        if (read (thread_data.descriptor, &command_id, sizeof(int)) <= 0){
            printf("[User %d]\n", thread_data.idUser);
            perror ("Error at reading command_id from client.\n");
        }

        if (read (thread_data.descriptor, &command_len, sizeof(short int)) <= 0){
            printf("[User %d]\n", thread_data.idUser);
            perror ("Error at reading command length from client.\n");
        }
        printf ("[User %d]Command length = %d.\n", thread_data.idUser, command_len);
        char command[256*4];
        if (read (thread_data.descriptor, &command, command_len) <= 0){
            printf("[User %d]\n", thread_data.idUser);perror ("Error at reading command from client. User disconnected.\n");
            alive = false;
            printThreadData();
            deleteThreadData(&thread_data);
            printThreadData();
            return;
        }
        command[command_len]='\0';

        if(command_id == 14){
            printf("[User %d] %s logged out.\n", thread_data.idUser, thread_data.username);
            deleteThreadData(&thread_data);
            return;
        }

        ch.handleCommand(command_id, command, &thread_data);

        fflush (stdout);
    }
}

void server_boilerplate::sendMsgToClient(int command_id, int sd, const char *msg) {
    int len = strlen(msg);
    if (write (sd, &command_id, sizeof(int)) <= 0)
    {
        perror ("Error at writing command_id length to client.\n");
    }
    if (write (sd, &len, sizeof(short int)) <= 0)
    {
        perror ("Error at writing msg length to client.\n");
    }
    if (write (sd, msg, len) <= 0)
    {
        perror ("Error at writing msg to client.\n");
    }
}

void server_boilerplate::addThreadData(void *arg) {
    struct thData thread_data;
    thread_data = *((struct thData*)arg);
    for(int i = 0; i < THREAD_COUNT; i++){
        if(threadData[i].descriptor == thread_data.descriptor && threadData[i].idUser == -1){
            threadData[i] = thread_data;
            return;
        }
    }
    for(int i = 0; i < THREAD_COUNT; i++){
        if((threadData[i].descriptor == 0 && threadData[i].idUser == 0)){
            threadData[i] = thread_data;
            threadData_len++;
            return;
        }
    }
}
void server_boilerplate::deleteThreadData(thData *thread_data) {
    for(int i = 0; i < THREAD_COUNT; i++){
        if(threadData[i].descriptor == thread_data->descriptor && threadData[i].idUser == thread_data->idUser){
            threadData[i].descriptor = 0;
            threadData[i].idUser = 0;
            strcpy(threadData[i].username,"");
            return;
        }
    }
}
void server_boilerplate::printThreadData() {
    for(int i = 0; i < threadData_len; i++){
        printf("| %d %d %s|, ", threadData[i].descriptor, threadData[i].idUser, threadData[i].username);
    }
    printf("\n");
}



int server_boilerplate::getDescriptorFromOnlineUser(const char *username){
    for(int i = 0; i < THREAD_COUNT; i++){
        if(strcmp(threadData[i].username, username) == 0){
            //printf("found him!\n");
            return threadData[i].descriptor;
        }
    }
    return 0;
}
int server_boilerplate::getDescriptorFromOnlineUser(int id){
    for(int i = 0; i < THREAD_COUNT; i++){
        if(threadData[i].idUser == id){
            //printf("found him!\n");
            return threadData[i].descriptor;
        }
    }
    return 0;
}