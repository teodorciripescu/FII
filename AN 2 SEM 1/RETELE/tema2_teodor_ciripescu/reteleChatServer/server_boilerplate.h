//
// Created by Teodor Ciripescu on 09/12/2019.
//

#ifndef RETELECHATSERVER_SERVER_BOILERPLATE_H
#define RETELECHATSERVER_SERVER_BOILERPLATE_H

#include "database_commands.h"

//server_boilerplate.h
struct thData{
    int idUser; //user's id extracted from the DB at authentication
    int descriptor; //descriptor returned by accept
};

class server_boilerplate {
     static void *treatClient(void *arg);
     static void addThreadData(void *arg);
     static void talkToClient(void *arg);
public:
    int createServer(int PORT);

    static char *handleCommand(short len, char *command, thData *thread_data);

};


#endif //RETELECHATSERVER_SERVER_BOILERPLATE_H
