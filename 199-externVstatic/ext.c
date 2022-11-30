
#include "s_impl.h"

void externs(void) {
  printf("In function %s()\n", __func__);
  printf("Externs: s0 = %2d, s1 = %2d, s2 = %2d\n", s0, s1, s2);
}
