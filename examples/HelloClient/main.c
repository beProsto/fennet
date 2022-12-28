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
#include <string.h>
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

  // The address we want to connect to
  struct sockaddr_in address = {
    AF_INET, htons(PORT), { inet_addr("127.0.0.1") }, {}
  };

  // Connect to the address (will return other than 0 if it failed)
  if (connect(main_socket, (const struct sockaddr*)&address, sizeof(address))) {
    printf("Connection failed.\n");
    return 1;
  }
  printf("Connected to the server successfully!\n");

  // Send HTTP request message to the sever
  const char* msg = "GET / HTTP/1.1\n\n";
  write(main_socket, msg, strlen(msg));

  // Receive HTTP response
  char ret[1024 * 30] = {};
  read(main_socket, ret, sizeof(ret));
  printf("\nServer's reply:\n%s\n", ret);

  return 0;
}