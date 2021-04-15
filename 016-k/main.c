#include <stdio.h>
#include <limits.h>

/* printd: print n in decimal */
void printd(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}

//  TODO: rewritten to handle INT_MIN (-2147483648)
/* printd: print n in decimal */
void printd_fixed(int n)
{
  unsigned w;
  if (n < 0) {
    putchar('-');
    w = ~n;
    w++;
  }
  else
    w = n;
  if (w / 10)
    printd_fixed((int) (w / 10));
  putchar(w % 10 + '0');
}


int main(int argc, const char * argv[]) {

  int dd[] = {
    0, -0,
    INT_MAX, INT_MIN,
    INT_MAX - 1, INT_MIN + 1,
    SHRT_MAX, SHRT_MIN,
  };
  size_t dd_l = sizeof(dd) / sizeof(dd[0]);
  
  size_t d_;
  for (d_ = 0; d_ < dd_l; ++d_) {
    printd(dd[d_]);
    putchar('\n');
  }
  putchar('\n');

  for (d_ = 0; d_ < dd_l; ++d_) {
    printd_fixed(dd[d_]);
    putchar('\n');
  }
  putchar('\n');

  return 0;
}

