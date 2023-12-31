
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

inline
static
void sa(size_t sz, uint16_t num[]) {
  for (size_t r_ = 0ul; r_ < sz; ++r_) {
    printf("%d ", num[r_]);
  }
  putchar('\n');
}

int main(int argc, char const * argv[]) {

  uint16_t addendl[] = { 9u, 0u, 2u, 9u, 3u, 3u, 7u, };
  uint16_t addendr[] = { 9u, 0u, 0u, 4u, 9u, 2u, 2u, };
  size_t const addend_sz = sizeof addendl / sizeof *addendl;

  size_t const sum_sz = addend_sz + 1ul;
  uint16_t * sum = calloc(sum_sz, sizeof(uint16_t));

  uint16_t carry = 0u;
  size_t rx = sum_sz - 1ul;

  for (size_t d_ = 0ul; d_ < addend_sz; ++d_) {
    uint16_t al = addendl[addend_sz - d_ - 1ul];
    uint16_t ar = addendr[addend_sz - d_ - 1ul];
    uint16_t as = al + ar;
    uint16_t ps = (as % 10ul) + carry;
    carry = as / 10u;
    sum[rx--] = ps;
  }
  if (carry != 0u) {
    sum[rx] = carry;
  }

  putchar(' ');
  putchar(' ');
  sa(addend_sz, addendl);
  putchar(' ');
  putchar(' ');
  sa(addend_sz, addendr);
  sa(sum_sz, sum);

  free(sum);
  sum = NULL;

  return 0;
}

