
#include <stdio.h>
#include <limits.h>

unsigned long sum_of_digits_recursive(unsigned long initial);
unsigned long sum_of_digits_iterative(unsigned long initial);

typedef unsigned long(*fsum_of_digits)(unsigned long initial);

struct digits_funcs {
  fsum_of_digits fptr;
  char const *   fname;
};
typedef struct digits_funcs digits_funcs;

digits_funcs funcs[] = {
  { .fptr = sum_of_digits_recursive, .fname = "sum_of_digits_recursive", },
  { .fptr = sum_of_digits_iterative, .fname = "sum_of_digits_iterative", },
};
size_t funcs_c = sizeof(funcs) / sizeof(*funcs);

int main(int argc, char const * argv[]) {
  
    unsigned long sampl[] = {
      111ULL, 123ULL,
      9876543210ULL, 123456789ULL, 99999999ULL,
       9999999999999999999ULL,
       ULONG_MAX, 0ULL,
    };
    size_t sampl_c = sizeof(sampl) / sizeof(*sampl);

    for (size_t fn = 0; fn < funcs_c; ++fn) {
      fsum_of_digits sum_of_digits = funcs[fn].fptr;
      char const * func_name = funcs[fn].fname;
      printf("\nUsing function: %s()\n\n", func_name);
      
      for (size_t s_ = 0; s_ < sampl_c; ++s_) {
        unsigned long total = sum_of_digits(sampl[s_]);

        printf("%21lu, sum of digits: %5lu\n", sampl[s_], total);
      }
    }

    return 0;
}

unsigned long sum_of_digits_iterative(unsigned long initial) {

  unsigned long sum = 0;

  while (initial != 0) {
    sum += initial % 10;
    initial /= 10;
  }

  return sum;
}

unsigned long sum_of_digits_recursive(unsigned long initial) {

  unsigned long sum = 0;
  
  if (initial != 0) {
    unsigned long next = initial / 10;
    sum = initial % 10;
    //printf("%lu\n", sum);
    sum += sum_of_digits_recursive(next);
  }

  return sum;
}


