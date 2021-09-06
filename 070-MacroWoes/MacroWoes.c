
#include <stdio.h>

//  Why it's a horrible idea to use macros instead of (inline) functions
#define MPRODUCT0(x) (x * x)
#define MPRODUCT1(x) ((x) * (x))
inline
static
long PRODUCT(int x) {
  long r = x * x;
  // printf("%d %ld\n", x, r);
  return r;
}

int main() {
  putchar('\n');

  int i = 3, j, k, l;
  j = PRODUCT(i + 1); //  PRODUCT(4) 4 * 4 == 16
  k = PRODUCT(i++);   //  PRODUCT(3) 3 * 3 ==  9  -- i now = 4
  l = PRODUCT(++i);   //  PRODUCT(5) 5 * 5 == 25

  printf("inline function long PRODUCT(int x) { long r = x * x; return r; }: %3d %3d %3d %3d\n", i, j, k, l);

  i = 3;
  j = MPRODUCT0(i + 1); //  (i + 1 * i + 1) == (3 + 1 * 3 + 1) == 7
  k = MPRODUCT0(i++);   //  (i++ * i++) !! Undefined behaviour
  l = MPRODUCT0(++i);   //  (++i * ++i) !! Undefined behaviour

  printf("#define MPRODUCT0(x) (x * x)                                     : %3d %3d %3d %3d\n", i, j, k, l);

  i = 3;
  j = MPRODUCT1(i + 1); //  ((i + 1) * (i + 1)) == ((3 + 1) * (3 + 1)) == (4 * 4) == 16
  k = MPRODUCT1(i++);   //  ((i++) * (i++)) !! Undefined behaviour
  l = MPRODUCT1(++i);   //  ((++i) * (++i)) !! Undefined behaviour

  printf("#define MPRODUCT1(x) ((x) * (x))                                 : %3d %3d %3d %3d\n", i, j, k, l);
}

