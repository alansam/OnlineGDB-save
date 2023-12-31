#include <stdio.h>

#include "cs50.h"

int main() {
  int ch = 0;
  string name = get_string("what is your name %s?\n", "Bobby");
  printf("Hello, name, %s\n\n", name);
  while ((ch = getchar()) != '\n' && ch != EOF);

  char c1 = get_char("what is your name %s?\n", "Bobby");
  printf("1st char %c\n\n", c1);
  while ((ch = getchar()) != '\n' && ch != EOF);

  double d1 = get_double("what is your pie %s\nπ          : %s?\n", "Bobby",
                         "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
  printf("Big number : %.50lf\n\n", d1);
  while ((ch = getchar()) != '\n' && ch != EOF);
  c1 = get_char(".\n");
  while ((ch = getchar()) != '\n' && ch != EOF);

  float f1 = get_float("what is your pie %s\nπ          : %s?\n", "Bobby",
                         "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
  printf("Less number: %.25f\n\n", f1);
  while ((ch = getchar()) != '\n' && ch != EOF);
  c1 = get_char(".\n");
  while ((ch = getchar()) != '\n' && ch != EOF);

  int i1 = get_int("what is your number %s?\nINT_MAX      : %d\n", "Bobby", 0x7fffffff);
  printf("Less integer : %d\n\n", i1);
  while ((ch = getchar()) != '\n' && ch != EOF);

  long l1 = get_long("what is your number %s?\nLONG_MAX     : %ld\n", "Bobby", 0x7fffffffffffffff);
  printf("More integer : %ld\n\n", l1);
  while ((ch = getchar()) != '\n' && ch != EOF);

  long long m1 = get_long_long("what is your number %s?\nLLONG_MAX    : %Ld\n", "Bobby", 0x7fffffffffffffff);
  printf("Extra integer: %Ld\n\n", m1);
  while ((ch = getchar()) != '\n' && ch != EOF);

  return 0;
}
