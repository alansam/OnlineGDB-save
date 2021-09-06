#include <stdio.h>

int main(int argc, char const * argv[]) {
  printf("before jump\n");

  int aa = 0;
  int ab = 1;
  int ac = 2;
  printf("%d, %d, %d\n", aa, ab, ac);

  goto jumper;

  {
    int aa = 10;
    int ab = 11;
    int ac = 12;

jumper:
    printf("%d, %d, %d\n", aa, ab, ac);
  }

  return 0;
}
