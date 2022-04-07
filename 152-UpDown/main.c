
#include <stdio.h>

int main() {
  int what = ' ';
  int what_now = ' ';

  while (what != '.') {
    printf("enter a character [a '.' ends it]: ");
    fflush(stdout);
    what = getchar();
    printf("echo %c\n", what);
    int c_;
    // while ((c_ = getchar()) != EOF);
    if (what >= 'A' && what <= 'Z') {
      what_now = what + 'a' - 'A';
    }
    else if (what >= 'a' && what <= 'z') {
      what_now = what - 'a' + 'A';
    }
    printf("\n -- %c -> %c\n\n", what, what_now);
  }

  return 0;
}

