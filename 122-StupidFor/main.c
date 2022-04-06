
#ifdef __cplusplus
#include <iostream>
#include <cstdio>
#else
#include <stdio.h>
#endif

int main() {
  for (int i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1) {
     printf("i =%4d, j =%4d\n", i, j);
  }

  size_t const col = 2;
  size_t const row = 2;

  int mtrx[row][col] = {
    { 1, 2, },
    { 3, 4, },
  };

  for (size_t r = 0; r < row; ++r) {
    for (size_t c = 0; c < col; ++c) {
      printf("%d ", mtrx[r][c]);
    }
    putchar('\n');
  }
  putchar('\n');

  return 0;
}

