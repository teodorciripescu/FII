#include <iostream>
#include "server_boilerplate.h"
#include "database.h"
int main() {
    server_boilerplate server;
    server.createServer(2908);
    return 0;
}