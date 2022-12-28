/**
 * @file main.c
 * @brief HelloClient example.
 *
 * HelloServer is a simple example of fennet's usage, it
 * connects to an HTTP server and prints it's response.
 */

#include <fennet/lib.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define SA struct sockaddr

/**
 * @brief Entry point of the HelloClient Example.
 */
int
main(int argc, char** argv)
{
  // Socket interface initialisation
  int main_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (main_socket == -1) {
    printf("Couldn't initialise the main socket.\n");
    return 1;
  }
  printf("Initialised the main socket!\n");

  struct sockaddr_in address = {
    AF_INET, htons(PORT), { inet_addr("127.0.0.1") }, {}
  };

  if (connect(main_socket, (const struct sockaddr*)&address, sizeof(address))) {
    printf("Connection failed.\n");
    return 1;
  }
  printf("Connected to the server successfully!\n");

  const char* msg =
    "GET / HTTP/1.1\nHost: localhost:8080\n"
    "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:108.0) Gecko/20100101\n"
    "Firefox/108.0\n"
    "Accept:\n"
    "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/\n"
    "webp,*/*;q=0.8\n"
    "Accept-Language: pl,en-US;q=0.7,en;q=0.3\n"
    "Accept-Encoding: gzip, deflate, br\n"
    "DNT: 1\n"
    "Connection: keep-alive\n"
    "Cookie: sverdle=2291-paint%20newer%20%20%20%20-_____%20__c__\n"
    "Upgrade-Insecure-Requests: 1\n"
    "Sec-Fetch-Dest: document\n"
    "Sec-Fetch-Mode: navigate\n"
    "Sec-Fetch-Site: none\n"
    "Sec-Fetch-User: ?1\n\n";

  write(main_socket, msg, sizeof(msg));

  char ret[1024 * 30] = {};
  read(main_socket, ret, sizeof(ret));
  read(main_socket, ret, sizeof(ret));
  read(main_socket, ret, sizeof(ret));

  printf("\nServer's reply:\n%s\n", ret);
}