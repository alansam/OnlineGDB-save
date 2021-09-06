
#include <stdio.h>

#define ELMTS 2

int main() {
  int sa[][ELMTS] = {
    { 1234, 56, },
    { 1212, 33, },
    { 1434, 80, },
    { 1313, 78, },
  };
  size_t sa_r = sizeof(sa) / sizeof(sa[1]);
  int (*psa_r)[ELMTS];
  int *psa_e;

  for (size_t i_ = 0; i_ < sa_r; i_++) {
    psa_r = &sa[i_];
    psa_e = (int *) psa_r;
    printf("%4zu: ", i_ + 1);

    for (size_t j_ = 0; j_ < ELMTS; j_++) {
      printf("%6d%c", *(psa_e + j_), ((j_ + 1) % ELMTS == 0 ? ' ' : ','));
    }
    putchar('\n');
  }

  return 0;
}
