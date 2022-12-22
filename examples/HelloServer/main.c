/**
 * @file main.c
 * @brief HelloServer example.
 *
 * HelloServer is a simple example of fennet's usage, it
 * serves an HTTP server that always responds with the text "Hello!".
 */

#include <fennet/lib.h>
#include <stdio.h>

/**
 * @brief Entry point of the HelloServer Example.
 */
int
main(int argc, char** argv)
{
  if (doesItLookLikeImBoring() == YUP) {
    printf("Yeah, you're boring...\n");
  } else {
    printf("No, you're not boring!\n");
  }
}