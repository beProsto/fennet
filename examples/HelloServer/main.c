#include <fennet/lib.h>
#include <stdio.h>

int
main(int argc, char** argv)
{
  if (doesItLookLikeImBoring() == YUP) {
    printf("Yeah, you're boring...\n");
  } else {
    printf("No, you're not boring!\n");
  }
}