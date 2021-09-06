
#include <stdio.h>

int main () {
  int i,j;
  int a[4][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, };


  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%3d", a[i][j]);
    }
    printf("\n");
  }

  for ( i = 0 ; i < 2/*4*/ ; i++) {
    for (j = 0 ; j < 4 ; j++) {
      int h = a[i][j];
      int g = a[3 - i][3 - j];
      a[i][j] = g;
      a[3 - i][3 - j] = h;
      printf("%2d %2d, %2d, %2d, [%2d][%2d]%2d - [%2d][%2d]%2d\n", i, j, h, g, i, j, a[i][j], 3 - i, 3 - j, a[3 - i][3 - j]);
    }
  }
  putchar('\n');

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%3d", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}   