
#include "fn2.h"
#include "fn1.h"

int fun2(int argc, char const * argv[]) {
  printf("In function %s()\n", __func__);

  fun1(argc, argv);

  double pi = acos(-1);
  printf("\u03c0 = %.10f", pi);

  return 0;
}
