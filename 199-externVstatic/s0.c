
#include "s_impl.h"

int s0 = 0;

void fns0(void) {
  printf("In function %s()\n", __func__);
  s0 = 20;
  printf("s0 = %2d\n", s0);
  printf("s1 = %2d\n", ++s1);
  printf("s2 = %2d\n", s2 += 2);
}
