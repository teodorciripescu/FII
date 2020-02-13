//transmitem din parinte 2 nr un nr catre un copil, un alt nr la alt copil
//si folosim un sg canal, cei 2 copii citesc la acelasi socket
//"sunt primul copil si am citi numarul"
/* socketpair.c   
   Programul ilustreaza utilizarea primitivei socketpair(); se permite 
   trimiterea de mesaje in ambele directii.
            
   Autor: Lenuta Alboaie <adria@infoiasi.ro> (c)2009  
  */
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

int main() 
  { 
    int sockp[2], child1, child2; 
    char msg[1024];
    int r;

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0) 
      { 
        perror("Err... socketpair"); 
        exit(1); 
      }

    if (((child1 = fork()) == -1) || ((child2 = fork()) == -1)) perror("Err...fork"); 
    else 
      if (child1 && child2)   //parinte 
        {  
            printf("parinte: %d este primul copil\n", child1);
            printf("parinte: %d este al doilea copil\n", child2);
            close(sockp[0]); 
            char msg1[1024]="primul mesaj\n";
            char msg2[1024]="al doilea mesaj\n";
            if (write(sockp[1], msg1, sizeof(msg1)) < 0) perror("[parinte]Err...write"); 
            wait();
            if (write(sockp[1], msg2, sizeof(msg2)) < 0) perror("[parinte]Err...write"); 
            wait();
            //sleep(5);
            close(sockp[1]); 
          } 
        else if(!child1)   //copil1
          { 
            close(sockp[1]); 
            if (read(sockp[0], msg, 1024) < 0) perror("[copil1]Err..read"); 
            printf("[copil1]  %s\n", msg); 
            close(sockp[0]);
            exit(1);
           }
        else if(!child2) //copil2
            {
            close(sockp[1]); 
            if (read(sockp[0], msg, 1024) < 0) perror("[copil2]Err..read"); 
            printf("[copil2]  %s\n", msg); 
            close(sockp[0]);
            exit(2);
            } 
    }             