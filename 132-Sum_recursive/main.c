
#include <stdio.h>

int fun(int s, int n) {
  // static int s = 0;
  int d;
  if (n != 0) {
    d = n % 10;
    n = n / 10;
    s += d;
    fun(s, n);
  }
  else {
    return s;
  }
}

int main() {
  int tests[] = { 123, 1234, 12345, 123456, };
  size_t const tests_l = sizeof(tests) / sizeof(*tests);
  for (size_t t_ = 0; t_ < tests_l; ++t_) {
    int a = fun(0, tests[t_]);
    printf("%7d%7d\n", tests[t_], a);
  }
}

