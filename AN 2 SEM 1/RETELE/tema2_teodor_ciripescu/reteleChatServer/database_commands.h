//
// Created by Teodor Ciripescu on 10/12/2019.
//

#ifndef RETELECHATSERVER_DATABASE_COMMANDS_H
#define RETELECHATSERVER_DATABASE_COMMANDS_H


#include "database.h"
#include "server_boilerplate.h"


class database_commands {
    database d;

public:
    database_commands(){
        d.createConnection();
    }

    bool auth(const char *username, const char *password, int* idUser, int* descriptor);
    static int auth_callback(void* data, int argc, char** argv, char** azColName);
};


#endif //RETELECHATSERVER_DATABASE_COMMANDS_H
