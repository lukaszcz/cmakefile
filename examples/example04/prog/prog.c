#include <stdio.h>

int main()
{
#ifdef GENERAL
  printf("GENERAL\n");
#endif
#ifdef NDEBUG
  printf("NDEBUG\n");
#endif
#ifdef PROG1
  printf("PROG1\n");
#endif
#ifdef PROG2
  printf("PROG2\n");
#endif
#ifdef PROG_RELEASE
  printf("PROG_RELEASE\n");
#endif
  return 0;
}
