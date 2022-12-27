/**
 * @file main.c
 * @brief HelloServer example.
 *
 * HelloServer is a simple example of fennet's usage, it
 * serves an HTTP server that always responds with the text "Hello!".
 */

#include <fennet/lib.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

/**
 * @brief Entry point of the HelloServer Example.
 */
int
main(int argc, char** argv)
{
  int sockfd, connfd, len;
  struct sockaddr_in servaddr = {}, cli;

  // socket create and verification
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  } else
    printf("Socket successfully created..\n");

  // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  // Binding newly created socket to given IP and verification
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
    printf("socket bind failed...\n");
    exit(0);
  } else
    printf("Socket successfully binded..\n");

  // Now server is ready to listen and verification
  if ((listen(sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  } else
    printf("Server listening..\n");
  len = sizeof(cli);

  // Accept the data packet from client and verification
  connfd = accept(sockfd, (SA*)&cli, &len);
  if (connfd < 0) {
    printf("server accept failed...\n");
    exit(0);
  } else
    printf("server accept the client...\n");

  char buffer[1024] = {};

  read(connfd, buffer, 1024);
  printf("From client: %s\n", buffer);

  // intentionally leak memory (do a little trolling)
  write(connfd, "HTTP/1.1 200 OK\r\n\r\nAAAAAAAAHELPME", 1024);

  close(sockfd);
}

/** Wiem że między nami już jakiś czas nie jest najlepiej, i, jak już ci pisałem
dawno temu chciałem te nieznaski porzucić mówiąc ci po prostu o wszystkim co
mnie martwi na głos, z nadzieją że te zmartwienia, gdy ci je już wyjawię, po
prostu znikną, bo po części dręczą mnie przez to że chowam je w sobie. Nie
wiedziałem tylko, chociaż i tego się bałem, że mogłem nieumyślnie doprowadzić
do punktu w którym nie chcesz się ze mną przez to wszystko zadawać... */

/* I martwi mnie właśnie to, czy przypadkiem to co tu napisałeś to nie
 * najzwyczajniej w świecie próba przygotowania mnie na to. */