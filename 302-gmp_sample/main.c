/*
 *  GNU MP Sample.
 *  @see: https://gmplib.org
 *
 *  Compiled with: -Wall -Wpedantic -std=gnu2x -lgmp
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <gmp.h>
#include <obstack.h>

//  MARK: - Definitions.
/*
 *  MARK: Structure sample.
 */
typedef struct sample sample;
struct sample {
  char const addend1[256];
  char const addend2[256];
};

//  MARK: - Implementation.
/*
 *  MARK: bigsum()
 */
char * bigsum(char * str_sum, char const * str_addend1, char const * str_addend2) {
  mpz_t addend1;
  mpz_t addend2;
  mpz_t sum;
  mpz_init(addend1);
  mpz_init(addend2);
  mpz_init(sum);

  mpz_set_str(addend1, str_addend1, 0);
  mpz_set_str(addend2, str_addend2, 0);

  mpz_add(sum, addend1, addend2);
  str_sum = mpz_get_str(str_sum, 10, sum);

  mpz_clear(addend1);
  mpz_clear(addend2);
  mpz_clear(sum);
  
  return str_sum;
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  printf("GNU MP Sample.\n");
  printf("GNU MP V.M.P: %d.%d.%d\n", __GNU_MP_VERSION,
                                     __GNU_MP_VERSION_MINOR,
                                     __GNU_MP_VERSION_PATCHLEVEL);
  putchar('\n');
  printf("GMP Version:  %s\n", gmp_version);
  putchar('\n');
  printf("GNU MP compiler:       %s\n", __GMP_CC);
  printf("GNU MP compiler flags: %s\n", __GMP_CFLAGS);
  putchar('\n');

  sample samples[] = {
    { "2", "1", },
    { "1230382819298383892929938373", "190382829938388229929292", },
  };
  size_t const samples_sz = sizeof samples / sizeof *samples;

  for (size_t s_ = 0ul; s_ < samples_sz; ++s_) {
    char result[1024] = { '\0', };
    bigsum(result, samples[s_].addend1, samples[s_].addend2);
    printf("%s + %s = %s\n", samples[s_].addend1, samples[s_].addend2, result);
    putchar('\n');
  }

  return 0;
}

