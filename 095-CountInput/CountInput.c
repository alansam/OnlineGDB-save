
#include <stdio.h>

int main() {
  long nc = 0;
  int gc;
  while ((gc = getchar()) != EOF) {
    ++nc;
    printf("%#04X %ld\n", gc, nc);
    if (gc == '\n') {
      putchar('\n');
    }
  }
  return 0;
}
