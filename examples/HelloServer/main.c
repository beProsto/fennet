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
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define SA struct sockaddr

/**
 * @brief Entry point of the HelloServer Example.
 */
int
main(int argc, char** argv)
{

  return 0;
}

// const char* response = "HTTP/1.1 200 OK\nContent-type: "
//                        "text/html\n\n<h1>AAAAAAAAHELPME</h1>d";

/** Wiem że między nami już jakiś czas nie jest najlepiej, i, jak już ci pisałem
dawno temu chciałem te nieznaski porzucić mówiąc ci po prostu o wszystkim co
mnie martwi na głos, z nadzieją że te zmartwienia, gdy ci je już wyjawię, po
prostu znikną, bo po części dręczą mnie przez to że chowam je w sobie. Nie
wiedziałem tylko, chociaż i tego się bałem, że mogłem nieumyślnie doprowadzić
do punktu w którym nie chcesz się ze mną przez to wszystko zadawać... */
