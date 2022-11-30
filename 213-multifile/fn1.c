
#include "fn1.h"

int fun1(int argc, char const * argv[]) {
  printf("In function %s()\n", __func__);

  int divie = 100;
  int divis = 7;
  div_t qr = div(divie, divis);
  printf("%5d / %3d = %3d, remainder %3d\n", divie, divis, qr.quot, qr.rem);
  return 0;
}
