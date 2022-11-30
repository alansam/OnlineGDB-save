//  @see: https://www.geeksforgeeks.org/program-to-find-remainder-without-using-modulo-or-operator/

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

typedef struct idiv_t idiv_t;
struct idiv_t {
  int quot;
  int rem;
};

inline
static
idiv_t idiv(int numerator, int denominator) {
  if (denominator == 0) {
    printf("GRONK! divide by zero check!");
    fprintf(stderr, "divide by zero check!");
    exit(EXIT_FAILURE);
  }
  idiv_t rs = { .quot = 0, .rem = -1, };
  rs.quot = numerator / denominator;
  rs.rem = (numerator - denominator * (numerator / denominator));
  return rs;
}

int main() {
  int const divisors[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    0x7fff, (short) 0x8000, 0xffff,
    0x7fff / 2, ((short) 0x8000 / 2), 0xffff / 2,
    0,
  };
  size_t const divisors_l = sizeof divisors / sizeof *divisors;

  int const dividends[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 21, 33, 99, 100, 101,
    1066, 1666, 1966, 1024, 4096,
    0x7fff, (short) 0x8000, 0xffff,
    0,
  };
  size_t const dividends_l = sizeof dividends / sizeof *dividends;

  for (size_t i_ = 0; i_ < divisors_l; ++i_) {
    int divisor = divisors[i_];
    printf("Remainders of %6d:\n", divisor);
    for (size_t d_ = 0; d_ < dividends_l; ++d_) {
      int dividend = dividends[d_];
      idiv_t dr = idiv(dividend, divisor);
      char flag = dr.rem == 0 ? '*' : ' ';
      printf("%6d \u00f7 %6d = %6d rem %6d %c\n", dividend, divisor, dr.quot, dr.rem, flag);
    }
    putchar('\n');
  }

  return EXIT_SUCCESS;
}
