cmake_minimum_required(VERSION 3.15)
project(reteleChatServer)

set(CMAKE_CXX_STANDARD 14)


add_executable(reteleChatServer main.cpp database.cpp database.h server_boilerplate.cpp server_boilerplate.h database_commands.cpp database_commands.h)
target_link_libraries(reteleChatServer LINK_PUBLIC sqlite3)