/*
 *  GNU MP Sample.
 *  @see: https://gmplib.org
 *
 *  Compiled with: -Wall -Wpedantic -Werror=vla -std=gnu2x -lgmp -lm -fsanitize=address -pthread
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <gmp.h>
#include <string.h>

#define LEN_I 100
#define LEN_O (LEN_I + LEN_I)

typedef struct aupair aupair;
struct aupair {
  char first[LEN_I + 1];
  char second[LEN_I + 1];
};

char * multiply_gmp(size_t product_sz, char * product, char const * multiplicand, char const * multiplier);

/*
 *  MARK:  show_n_tell()
 */
static
inline
__attribute__((always_inline))
void show_n_tell(char const product[], char const multiplicand[], char const multiplier[]) {
  printf("Product      : %3zu : %s\n", strlen(product), product);
  printf("multiplicand : %3zu : %s\n", strlen(multiplicand), multiplicand);
  printf("multiplier   : %3zu : %s\n", strlen(multiplier), multiplier);
  return;
}

int main(int argc, char const * argv[]) {
  printf("GMP Version: %s\n", gmp_version);

  //  sample data
  aupair samples[] = {
    { "", "" },  //  space for ULLONG_MAX
    { "", "" },  //  space for LLONG_MIN, LLONG_MAX
    { "150353265326", "22055653351" },
    {   "100",   "100" },
    {   "100",  "-100" },
    {  "-100",   "100" },
    {  "-100",  "-100" },
    {  "0100",  "0100" },
    { "-0100",  "0100" },
    {  "0100", "-0100" },
    { "-0100", "-0100" },
    {     "0",     "0" },
    {     "1",     "1" },
    {    "-1",    "-1" },
    {   "00",     "00" },
    {  "-00",    "-00" },
    {   "01",     "00" },
    {  "-01",    "-01" },
    {  "-00",    "-01" },
    {  "-01",    "-00" },
  };
  size_t samples_sz = sizeof samples / sizeof *samples;

  //  add some big numbers
  sprintf(samples[0].first, "%llu", ULLONG_MAX);
  sprintf(samples[0].second, "%llu", ULLONG_MAX);
  sprintf(samples[1].first, "%lld", LLONG_MIN);
  sprintf(samples[1].second, "%lld", LLONG_MAX);

  for (size_t s_ = 0ul; s_ < samples_sz; ++s_) {
    putchar('\n');
    char product[LEN_O + 1] = { '\0', };
    char * product_p = product;
    product_p = multiply_gmp(LEN_O + 1, product, samples[s_].first, samples[s_].second);
    show_n_tell(product_p, samples[s_].first, samples[s_].second);
  }
  putchar('\n');

  return EXIT_SUCCESS;
}

/*
 *  MARK: multiply_gmp()
 */
char * multiply_gmp(size_t product_sz, char * product, char const * multiplicand, char const * multiplier) {
  mpz_t product_bd;
  mpz_t multiplicand_bd;
  mpz_t multiplier_bd;
  mpz_inits(product_bd, multiplicand_bd, multiplier_bd, NULL);

  mpz_set_str(multiplicand_bd, multiplicand, 10);
  mpz_set_str(multiplier_bd,multiplier, 10);

  mpz_mul(product_bd, multiplicand_bd, multiplier_bd);

  mpz_get_str(product, 10, product_bd);

  mpz_clears(product_bd, multiplicand_bd, multiplier_bd, NULL);

  return product;
}
