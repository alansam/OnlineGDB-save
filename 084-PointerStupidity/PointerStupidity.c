
#include <stdio.h>

int main() {
  char c[] = "GATE2011";
  char *p = c;
  printf("%s\n", p + p[3] - p[1]);

  printf("%#04x, %2d\n", p[3], p[3]);
  printf("%#04x, %2d\n", p[1], p[1]);
  printf("%#04x, %2d\n", p[3] - p[1], p[3] - p[1]);
  printf("%s\n", p + 4);

  return 0;
}
