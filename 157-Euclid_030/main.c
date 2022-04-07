/*
 *  Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 *  1634 = 1^4 + 6^4 + 3^4 + 4^4
 *  8208 = 8^4 + 2^4 + 0^4 + 8^4
 *  9474 = 9^4 + 4^4 + 7^4 + 4^4
 *  As 1 = 1^4 is not a sum it is not included.
 *
 *  The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 *  Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */
 
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

uint32_t numPlaces(uint64_t nr) {
  int pl = 1u;
  while (nr > 9u) {
    nr /= 10u;
    pl++;
  }
  return pl;
}

bool is_nth_pow(uint64_t const number, uint32_t const pw) {
  bool isp = false;
  uint64_t num = number;
  uint8_t digits[32] = { 0, };
  size_t const digits_sz = sizeof(digits) / sizeof(*digits);
  uint32_t const num_pl = numPlaces(num);

  for (size_t d_ = 0ul; d_ < num_pl; ++d_) {
    digits[d_] = num % 10u;
    num /= 10;
  }

  // printf("%8lu: ", number);
  // for (size_t d_ = 0; d_ < num_pl; ++d_) {
  //   printf("%2hhu", digits[d_]);
  // }
  // putchar('\n');

  uint64_t powsum = 0ul;
  for (size_t d_ = 0; d_ < num_pl; ++d_) {
    uint32_t dig = digits[d_];
    uint64_t powr = dig;
    for (size_t p_ = 0; p_ < pw - 1; ++p_) {
      powr *= dig;
    }
    powsum += powr;
  }

  if (powsum == number) {
    isp = true;
  }

  return isp;
}

int main() {
  printf("157-Euclid_30\n");

  // 4th powers: 1634 8208 9474
  // uint64_t p4[] = { 1634ul, 8208ul, 9474ul, };
  // size_t const p4_sz = sizeof(p4) / sizeof(*p4);

  // uint64_t sum4 = 0ul;
  // for (size_t t_ = 0; t_ < p4_sz; ++t_) {
  //   printf("%8lu, %u\n", p4[t_], numPlaces(p4[t_]));
  //   bool isp = is_nth_pow(p4[t_], 4u);
  //   if (isp) {
  //     sum4 += p4[t_];
  //     printf("%6lu is a power of %u\n", p4[t_], 4u);
  //   }
  //   else {
  //     printf("%6lu is not a power of %u\n", p4[t_], 4u);
  //   }
  // }
  // printf("sum of %uth powers: %8lu\n", 4u, sum4);
  // putchar('\n');

  uint64_t sum4 = 0ul;
  for (size_t i_ = 2ul; i_ < 10000000ul; ++i_) {
    bool isp = is_nth_pow(i_, 4u);
    if (isp) {
      sum4 += i_;
      printf("%6lu is a power of %u\n", i_, 4u);
    }
    else {
      // printf("%6lu is not a power of %u\n", i_, 4u);
    }
  }
  printf("sum of %uth powers: %8lu\n", 4u, sum4);
  putchar('\n');

  uint64_t sum5 = 0ul;
  for (size_t i_ = 2ul; i_ < 10000000ul; ++i_) {
    bool isp = is_nth_pow(i_, 5u);
    if (isp) {
      sum5 += i_;
      printf("%6lu is a power of %u\n", i_, 5u);
    }
    else {
      // printf("%6lu is not a power of %u\n", i_, 5u);
    }
  }
  printf("sum of %uth powers: %8lu\n", 5u, sum5);
  putchar('\n');

  return 0;
}


