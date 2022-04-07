
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  printf("4 digits?: ");
  char in[4];
  for (size_t d_ = 0; d_ < sizeof in; ++d_) {
    in[d_] = getchar();
    putchar(in[d_]);
    // if (!isdigit(in[d_])) {
    if (in[d_] < '0' || in[d_] > '9') {
      fprintf(stderr, "'%c' is not a digit!\n", in[d_]);
      exit(EXIT_FAILURE);
    }
  }
  putchar('\n');

  unsigned result = (in[0] - '0') * 1000
                  + (in[1] - '0') *  100
                  + (in[2] - '0') *   10
                  + (in[3] - '0');

  printf("ans: %06o %5d %#010x\n", result, result, result);

  return EXIT_SUCCESS;
}

