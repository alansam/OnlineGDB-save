
#include "s_impl.h"

int s2 = 0;

void fns2(void) {
  printf("In function %s()\n", __func__);
  s2 = 22;
  printf("s2 = %2d\n", s2);
}
