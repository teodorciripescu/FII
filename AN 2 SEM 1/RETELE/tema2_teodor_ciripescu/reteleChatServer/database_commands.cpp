//
// Created by Teodor Ciripescu on 10/12/2019.
//

#include "database_commands.h"
#include "database.h"
#include "sqlite3.h"
#include<string>
#include<iostream>
using namespace std;
int *p;
bool database_commands::auth(const char *username, const char *password, int* idUser, int* descriptor) {
     std::string sqlstatement = "SELECT id FROM users WHERE username='"+(string)username+"' AND password='"+(string)password+"'";
     p=idUser;
     d.executeSQLstatement(sqlstatement.c_str(), &auth_callback);
    return *idUser > 0;
}

int database_commands::auth_callback(void *data, int argc, char **argv, char **azColName) {
    if(argv[0])
        *p=atoi(argv[0]);
    return 0;
}
