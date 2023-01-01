/**
 * @file main.c
 * @brief HelloServer example.
 *
 * HelloServer is a simple example of fennet's usage, it
 * serves an HTTP server that always responds with the text "Hello!".
 */

#include <fennet/lib.h>

#ifndef _WIN32
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#define PORT 8080

/**
 * @brief Entry point of the HelloServer Example.
 */
int
main(int argc, char** argv)
{
#ifndef _WIN32
  // Socket interface initialisation
  int main_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (main_socket == -1) {
    printf("Couldn't initialise the main socket.\n");
  }
  printf("Initialised the main socket!\n");

  // The address we want to be bound as
  struct sockaddr_in address = {
    AF_INET, htons(PORT), { htonl(INADDR_ANY) }, {}
  };

  // Bind to the address
  if (bind(main_socket, (const struct sockaddr*)&address, sizeof(address))) {
    printf("Socket couldn't be bound.\n");
    return 1;
  }
  printf("Socket bound!\n");

  // Listen for new connections on socket
  if (listen(main_socket, 15)) {
    printf("Socket couldn't be listened on.\n");
    return 1;
  }
  printf("Listening on socket!\n");

  // Determine whether
  struct sockaddr_in client_address = {};
  unsigned int client_address_size = sizeof(client_address);
  int connection = accept(
    main_socket, (struct sockaddr*)&client_address, &client_address_size);
  if (connection < 0) {
    printf("Accept failed.\n");
  }
  printf("Client accepted!\n");

  // Receive HTTP Request
  char buf[1024 * 30] = {};
  read(connection, buf, sizeof(buf));

  // Send HTTP Response
  const char* response = "HTTP/1.1 200 OK\n\n<h1>AAAAAAAAHELPME</h1>d";
  write(connection, response, strlen(response));

  shutdown(main_socket, SHUT_RDWR);
  close(main_socket);
#endif

  return 0;
}
