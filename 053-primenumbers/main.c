
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define max 5000UL

void primo(uint64_t end, bool sieve[end]) {
  end = end == 0 ? 100 : end;
  uint64_t i_, j_;
  for (i_ = 2; i_ < end; i_++) {
    for (j_ = 2; j_ <= (i_ / j_); j_++) {
      if (!(i_ % j_)) {
        break; // if factor found, not prime
      }
    }
    if (j_ > (i_ / j_)) {
      sieve[i_] = true;
    }
  }

  return;
}

int main() {
  bool sieve[max] = { false, };
  primo(max, sieve);

  size_t cc = 0;
  size_t const cc_max = 20;
  printf("primes from 2 to %lu:\n", max);
  for (uint64_t b_ = 2; b_ < max; ++b_) {
    if (sieve[b_]) {
      printf("%6lu%s", b_, (++cc % cc_max == 0 ? "\n" : ""));
    }
  }
  putchar('\n');

  return 0;
}

