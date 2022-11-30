#define STATICS_
#include "s_impl.h"

static int s0 = 0;
static int s1 = 0;
static int s2 = 0;

static
void statics(void);

int main() {
  externs();
  statics();

  s0 = 10;
  fns0();

  externs();
  statics();

  s1 = 11;
  fns1();

  externs();
  statics();

  s2 = 12;
  fns2();

  externs();
  statics();

  return 0;
}

static
void statics(void) {
  printf("In function %s()\n", __func__);
  printf("Statics: s0 = %2d, s1 = %2d, s2 = %2d\n", s0, s1, s2);
}
