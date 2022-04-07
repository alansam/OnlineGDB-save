
#include <stdio.h>
#include <tgmath.h>

#define PHI ((1 + sqrt(5)) / 2)
 
long long unsigned fib(unsigned nr) {
  return floor( (pow(PHI, nr) - pow(1 - PHI, nr)) / sqrt(5) );
}

long long unsigned fibb_r(long long unsigned an, long long unsigned bn, unsigned nr) {
  return (--nr > 0) ? (fibb_r(bn, an + bn, nr)) : (an);
}

long long int unsigned fibb_i(unsigned nr) {
	long long unsigned fnow = 0LL, fnext = 1LL, tempf;
	while (--nr > 0) {
		tempf = fnow + fnext;
		fnow  = fnext;
		fnext = tempf;
	}

	return fnext;	
}

int main() {
  printf("Hello World\n");

  long long unsigned fn = 0ull;
  for (unsigned n_ = 1u; n_ < 20; ++n_) {
    fn = fib(n_);
    printf("%5llu", fn);
  }
  putchar('\n');

  for (unsigned n_ = 1u; n_ < 20; ++n_) {
    fn = fibb_i(n_);
    printf("%5llu", fn);
  }
  putchar('\n');

  for (unsigned n_ = 1u; n_ < 20; ++n_) {
    fn = fibb_r(1, 1, n_);
    printf("%5llu", fn);
  }
  putchar('\n');

  return 0;
}

