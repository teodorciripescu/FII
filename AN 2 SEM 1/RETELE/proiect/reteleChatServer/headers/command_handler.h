//
// Created by Teodor Ciripescu on 05/01/2020.
//

#ifndef RETELECHATSERVER_COMMAND_HANDLER_H
#define RETELECHATSERVER_COMMAND_HANDLER_H

#include "../headers/server_boilerplate.h"

class command_handler {
    void login(thData *thread_data, char *command);//1
    void Register(int sd, char *command);//2
    void getFriendList(thData *thread_data);//3
    void sendFriendRequest(thData *thread_data, char *command);//4
    void getFriendRequestList(thData *thread_data);//5
    void acceptFriendRequest(thData *thread_data, char *command);//6
    void rejectFriendRequest(thData *thread_data, char *command);//7
    void getConversations();//8
    void getMessages(thData *thread_data, char *command);//9
    void getUnseenMessages(thData *thread_data, char *command);//10
    void sendMessage(thData *thread_data, char *command);//11
    void replyMessage(thData *thread_data, char *command);//12
    void deleteMessage(thData *thread_data, char *command);//13
    void logout(thData *thread_data);//14
    void seen(thData *thread_data, char *command);//15
    void getFriendListPendingMessages(thData *thread_data);//18
    void error(thData *thread_data, const char *error_message); //19
public:
    char *handleCommand(int command_id, char *command, thData *thread_data);
};


#endif //RETELECHATSERVER_COMMAND_HANDLER_H
