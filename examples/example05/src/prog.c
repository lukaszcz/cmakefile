
#include <stdio.h>

int main() {
#ifdef NONE
  printf("none\n");
#endif
#ifdef A
  printf("A\n");
#endif
#ifdef B
  printf("B\n");
#endif
  return 0;
}
