
#include <stdio.h>
#include "fn1.h"
#include "fn2.h"

int main(int argc, char const * argv[]) {
  printf("In function %s()\n", __func__);

  fun1(argc, argv);
  fun2(argc, argv);

  return 0;
}
