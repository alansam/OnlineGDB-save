//  Create a Pascal's Triangle

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 *  MARK: factorial()
 */
uint64_t factorial(uint64_t nr) {
  if (nr > 20ul) {
    fprintf(stderr, "The maximum possible factorial that can be calculated with"
                    " 64-bit integers is 20!, %" PRIu64 "! is out of range.",
                    nr);
    exit(1);
  }
  
  uint64_t fact = 1ul;
	for (; nr > 1ul; --nr) {
  	fact *= nr;
  }

	return fact;
}

/*
 *  MARK: combination()
 *  n choose k
 *. C(n,k) = n!/(k!.(n-k)!)
 */
uint64_t combination(int n_, int k_) {
	return factorial(n_) / (factorial(k_) * factorial(n_ - k_));
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
	uint32_t rows = 6ul;
  if (argc > 1) {
    rows = atoi(argv[1]);
  }

	putchar('\n');

	for (uint64_t n_ = 0ul; n_ <= rows; n_++) {
		for (uint64_t k_ = 0ul; k_ <= rows - n_; k_++) {
			printf("  ");
		}

		for (uint64_t k_ = 0ul; k_ <= n_; k_++) {
			printf(" %3" PRIu64, combination(n_, k_));
		}
  	putchar('\n');
	}

	return 0;
}
