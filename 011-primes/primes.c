
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(unsigned int);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {

  putchar('\n');
  size_t col = 0;
  for (unsigned int i_ = 0; i_ <= 104730; ++i_) {
    unsigned int tv =i_;
    bool prime;
    prime = is_prime(tv);
    if (prime) {
      printf(" %6u", tv);
      col++;
      if (col > 9) {
        putchar('\n');
        col = 0;
      }
    }
    else {
      //printf("%6u is not prime\n", tv);
    }
  }
  putchar('\n');

  return 0;
}

/*
 *  MARK: is_prime()
 *  @see: https://primes.utm.edu/lists/small/10000.txt
 */
bool is_prime(unsigned int pv) {

  bool prime;

  switch (pv) {
    case 0:
    case 1:
      // zero & one are not prime
      prime = false;
      break;

    case 2:
    case 3:
    case 5:
    case 7:
    case 11:
    case 13:
    case 17:
    case 19:
      //  2, 3, 5, 7, 11, 13, 17, 19 are prime
      prime = true;
      break;

    default:
      if ((pv %  2) == 0 || (pv %  3) == 0 || (pv %  5) == 0 || (pv %  7) == 0 ||
          (pv % 11) == 0 || (pv % 13) == 0 || (pv % 17) == 0 || (pv % 19) == 0) {
        // even numbers other than two are not prime (plus some other optimizations)
        prime = false;
      }
      else {
        prime = true;
        for (unsigned int t_ = 3; t_ <= sqrt(pv); t_ += 2) {
          // test all numbers between 3 & sqrt(the number) skipping all even numbers
          if ((pv % t_) == 0) {
            prime = false;
            break;
          }
        }
      }
  }

  return prime;
}
