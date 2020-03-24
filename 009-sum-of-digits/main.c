
#include <stdio.h>
#include <limits.h>

unsigned long sum_of_digits(unsigned long initial);

int main(int argc, char const * argv[]) {
  
    unsigned long sampl[] = {
      111ULL, 123ULL,
      9876543210ULL, 123456789ULL, 99999999ULL,
       9999999999999999999ULL,
       ULONG_MAX, 0ULL,
    };
    size_t sampl_c = sizeof(sampl) / sizeof(*sampl);

    for (size_t s_ = 0; s_ < sampl_c; ++s_) {
      unsigned long total = sum_of_digits(sampl[s_]);

      printf("%21lu, sum of digits: %5lu\n", sampl[s_], total);
    }

    return 0;
}

unsigned long sum_of_digits(unsigned long initial) {

  unsigned long sum = 0;
  
  if (initial != 0) {
    unsigned long next = initial / 10;
    sum = initial % 10;
    //printf("%lu\n", sum);
    sum += sum_of_digits(next);
  }

  return sum;
}

