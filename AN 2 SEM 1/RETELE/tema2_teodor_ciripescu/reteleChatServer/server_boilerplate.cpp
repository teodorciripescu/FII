//
// Created by Teodor Ciripescu on 09/12/2019.
//
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <iostream>

#include "server_boilerplate.h"
#include "database_commands.h"

extern int errno;

thData threadData[100];
int threadData_len = 0;
database_commands dc;

int server_boilerplate::createServer(int PORT) {
    struct sockaddr_in server;	// structura folosita de server
    struct sockaddr_in from;
    int sd;		//socket descriptor
    pthread_t th[100];    //Identificatorii thread-urilor care se vor crea
    int i=0;

    /* creating the socket */
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror ("[server]Error at socket().\n");
        return errno;
    }
    /* utilizarea optiunii SO_REUSEADDR */
    int on=1;
    setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

    /* pregatirea structurilor de date */
    bzero (&server, sizeof (server));
    bzero (&from, sizeof (from));

    /* umplem structura folosita de server */
    /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;
    /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    /* utilizam un port utilizator */
    server.sin_port = htons (PORT);

    /* atasam socketul */
    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
        perror ("[server]Error at bind().\n");
        return errno;
    }

    /* punem serverul sa asculte daca vin clienti sa se conecteze */
    if (listen (sd, 2) == -1)
    {
        perror ("[server]Error at listen().\n");
        return errno;
    }
    /* servim in mod concurent clientii...folosind thread-uri */
    printf ("[server]Waiting at port %d...\n",PORT);
    fflush (stdout);
    while (1)
    {
        int client;
        thData * thread_data; //parametru functia executata de thread
        int length = sizeof (from);



        // client= malloc(sizeof(int));
        /* accepting the client (blocking state until connection is made) */
        if ((client = accept (sd, (struct sockaddr *) &from, reinterpret_cast<socklen_t *>(&length))) < 0)
        {
            perror ("[server]Eroare la accept().\n");
            continue;
        }

        /* s-a realizat conexiunea, se astepta mesajul */

        thread_data=(struct thData*)malloc(sizeof(struct thData));
        thread_data->idUser=-1;
        thread_data->descriptor=client;

        pthread_create(&th[i], NULL, &treatClient, thread_data);

    }//while
}

void *server_boilerplate::treatClient(void *arg) {
    struct thData thread_data;
    thread_data= *((struct thData*)arg);
    printf ("[thread]- %d - New thread, waiting for client...\n", thread_data.idUser);
    fflush (stdout);
    pthread_detach(pthread_self());
    talkToClient((struct thData *) arg);
    /* am terminat cu acest client, inchidem conexiunea */
    close ((intptr_t)arg);
    return(NULL);
}



void server_boilerplate::talkToClient(void *arg) {
    int nr=10, i=0;
    short int command_len = 0;
    char command[256];
    thData thread_data;
    thread_data= *((struct thData*)arg);
    addThreadData(arg);
    while(1){
        if (read (thread_data.descriptor, &command_len, sizeof(short int)) <= 0)
        {
            printf("[User %d]\n", thread_data.idUser);
            perror ("Error at reading command length from client.\n");

        }
        printf ("[User %d]Command length = %d.\n", thread_data.idUser, command_len);


        if (read (thread_data.descriptor, &command, command_len + 1) <= 0)
        {
            printf("[User %d]\n", thread_data.idUser);perror ("Error at reading command from client.\n");

        }
        handleCommand(command_len, command, &thread_data);

        //Writing back to the client will be done in another thread to avoid blocking states

        /* sending response to client */
//        if (write (thread_data.descriptor, &nr, sizeof(int)) <= 0)
//        {
//            printf("[User %d] ", thread_data.idUser);
//            perror ("[User]Eroare la write() catre client.\n");
//        }
//        else
//            printf ("[User %d]Mesajul a fost trasmis cu succes.\n", thread_data.idUser);

        fflush (stdout);
        //delete command;
        if(nr==1) break;
        break;
    }
}

void server_boilerplate::addThreadData(void *arg) {
    struct thData thread_data;
    thread_data= *((struct thData*)arg);
    for(int i=0; i<100; i++){
        if(threadData[i].descriptor == 0 && threadData[i].idUser == 0){
            threadData[i] = thread_data;
            threadData_len++;
            return;
        }
    }
}

char *server_boilerplate::handleCommand(short len, char *command, thData *thread_data) {
    int command_id = (int)command[0];
    if(command_id==1){ //AUTH
        int username_len = (int)command[1];
        int password_len = (int)command[2];
        char *username = new char[username_len+2];
        char *password = new char[password_len+2];
        memcpy(username, &command[3], username_len);
        username[username_len] = '\0';
        memcpy(password, &command[3+username_len], password_len);
        password[password_len] = '\0';
        std::cout<<"COMMAND: AUTH("<<"username: "<<username<< ", password: "<<
                        password<<") descript: "<<thread_data->descriptor<<"\n";

        bool authenticated = dc.auth(username, password, &thread_data->idUser, &thread_data->descriptor);
        if(authenticated){
            addThreadData(thread_data);
            std::cout<<"Authenticated! userId = "<<thread_data->idUser<<std::endl;
        }
        delete[] username;
        delete[] password;
    }

    return nullptr;
}
