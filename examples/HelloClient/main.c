/**
 * @file main.c
 * @brief HelloClient example.
 *
 * HelloServer is a simple example of fennet's usage, it
 * connects to an HTTP server and prints it's response.
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
  doesItLookLikeImBoring();
}

/** Wiem że między nami już jakiś czas nie jest najlepiej, i, jak już ci pisałem
dawno temu chciałem te nieznaski porzucić mówiąc ci po prostu o wszystkim co
mnie martwi na głos, z nadzieją że te zmartwienia, gdy ci je już wyjawię, po
prostu znikną, bo po części dręczą mnie przez to że chowam je w sobie. Nie
wiedziałem tylko, chociaż i tego się bałem, że mogłem nieumyślnie doprowadzić
do punktu w którym nie chcesz się ze mną przez to wszystko zadawać... */

/* I martwi mnie właśnie to, czy przypadkiem to co tu napisałeś to nie
 * najzwyczajniej w świecie próba przygotowania mnie na to. */