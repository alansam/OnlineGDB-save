
#include <stdio.h>

int f(int fv) {
  return fv > 3 ? 10 : 0;
}

void test1(int x1, int y1) {
  if (y1 = f(x1), y1 > x1)       { printf("OK: %3d %3d\n", x1, y1); }
  else                           { printf("No: %3d %3d\n", x1, y1); }
}

void test2(int x1, int y1) {
  if ((y1 = f(x1)), (y1 > x1))   { printf("OK: %3d %3d\n", x1, y1); }
  else                           { printf("No: %3d %3d\n", x1, y1); }
}

void test3(int x1, int y1) {
  if (((y1 = f(x1)), (y1 > x1))) { printf("OK: %3d %3d\n", x1, y1); }
  else                           { printf("No: %3d %3d\n", x1, y1); }
}

int main() {
  int x1 = 6;
  int x2 = 2;
  int y1 = 7;
  test1(x1, y1);
  test1(x2, y1);
  test2(x1, y1);
  test2(x2, y1);
  test3(x1, y1);
  test3(x2, y1);

  int cc = '\0';
  int ii = 0;
  scanf("%d", &ii);
  printf("%d\n", ii);
  while ((cc = getchar()), cc != '\n') { putchar(cc); }
  putchar('\n');
  for (size_t nn = 0ul; nn < 20; ++nn) {
    putchar('=');
  }
  putchar('\n');
  scanf("%d", &ii);
  printf("%d\n", ii);
  while ((cc = getchar()), cc != '\n') { putchar(cc); }
  putchar('\n');

  // printf("%d, %d, %d\n", ii++, ++ii, ++ii);

  ii++, ++ii, ++ii;
  printf("%d %d\n", ii, ii);

  return 0;
}
