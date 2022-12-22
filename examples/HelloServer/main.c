/**
 * @file main.c
 * @brief HelloServer example source code.
 *
 * HelloServer is a simple example of fennet.
 * It serves an HTTP server that always responds with the text "Hello!".
 */

#include <fennet/lib.h>
#include <stdio.h>

/**
 * @brief Main entry point of the program.
 *
 * A longer description.
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