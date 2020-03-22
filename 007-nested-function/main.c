#include <stdio.h>

int main(int argc, char const * argv[]) {

  printf("nesties\n");

#if defined(__GNUC__) || defined(__clang__)
  int __attribute__((unused)) xx = 0;
#endif
  int x_ = 3;

#if defined(__GNUC__)
  int nested(int x_val) {
    printf("%s [inline]\n", __func__);
    return x_val * x_val;
  }
#else
  int nested(int x_val);
#endif

  printf("%1$d x %1$d = %2$d\n", x_, nested(x_));

  return 0;
}

#if !defined(__GNUC__)
int nested(int x_val) {
  printf("%s [out of line]\n", __func__);
  return x_val * x_val;
}
#endif
