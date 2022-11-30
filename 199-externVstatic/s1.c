
#include "s_impl.h"

int s1 = 0;

void fns1(void) {
  printf("In function %s()\n", __func__);
  s1 = 21;
  printf("s1 = %2d\n", s1);
}
