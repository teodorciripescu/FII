#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include <pthread.h>

#include "./headers/write_handler.h"
#include "./headers/read_handler.h"

#define MAX_COMMAND_SIZE 256

using namespace std;
/* codul de eroare returnat de anumite apeluri */
extern int errno;

/* portul de conectare la server*/
int port;

/* socket descriptor */
int sd;

bool alive = true;

bool authenticated = false;

char myUsername[256];


int main (int argc, char *argv[])
{
  struct sockaddr_in server;	// structura folosita pentru conectare
  pthread_t th_read;
  pthread_t th_write;

  /* stabilim portul */
  port = atoi ("2908");

  /* cream socketul */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }

  /* umplem structura folosita pentru realizarea conexiunii cu serverul */
  /* familia socket-ului */
  server.sin_family = AF_INET; /* internetwork: UDP, TCP, etc. */
  /* adresa IP a serverului */
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
    /* stabilim portul
       * htons - host-to-network short functioneaza pe integeri de 16 biti
       * face conversie la ordinea octetilor specifica retelei (big endian -> little endian)
       * */
  server.sin_port = htons (port);

  /* ne conectam la server
   * int connect (int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen);
   *  sd - descriptorul socketului
   *  populeaza structura server de tip sockaddr cu datele serverului cu care vrem sa comunicam
   * */
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }
  /* se vor crea 2 threaduri separate pt fiecare client in parte
   * un thread pentru read unde clientul va citi mesjele primite de la server
   * un tread pentru write unde clientul va scrie comenzi serverului
   * */
  pthread_create(&th_read, NULL, &read_handler::readFromServer, NULL);
  pthread_create(&th_write, NULL, &write_handler::writeToServer, NULL);
  while(alive){}
}