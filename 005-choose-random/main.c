#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
# include <unistd.h>
#endif

#ifdef _POSIX_VERSION
typedef long rnr_t;
#else
typedef int rnr_t;
#endif

typedef rnr_t (*frand_t)(void);
typedef void (*fsrand_t)(unsigned int);

#ifdef _POSIX_VERSION
frand_t frand = random;
fsrand_t fsrand = srandom;
static
bool const posix = true;
# define PRTdRN "ld"
#else
frand_t frand = rand;
fsrand_t fsrand = srand;
static
bool const posix = false;
# define PRTdRN "d"
#endif

int main(int argc, char const * argv[]) {

  printf("Using %s\n\n", posix ? "random()" : "rand()");

  fsrand(time(NULL));
  rnr_t rnr = frand();
  printf("A random number: %12" PRTdRN "\n", rnr);
  for (size_t i_ = 0; i_ < 1000000; ++i_);

  long lnr = frand();
  printf("A random number: %12ld\n", lnr);
  
  return EXIT_SUCCESS;
}
