#include <stdio.h>
// #include <conio.h>

int main() {
  int a[50][50];
  // int i, j, k;
  int arows, acolumns;
  printf("Enter the no. of rows and no. of columns of A matrix \n");
  scanf("%d %d", &arows, &acolumns);

  int b[50][50];
  int brows, bcolumns;

  printf("Enter the no. of rows and no. of columns of B matrix\n");
  scanf("%d %d", &brows, &bcolumns);
  printf("Enter elements of matrix A: \n");
  for (size_t i = 0; i < arows; i++) {
    for (size_t j = 0; j < acolumns; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter elements of matrix B: \n");
  for (size_t i = 0; i < brows; i++) {
    for (size_t j = 0; j < bcolumns; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  int product[50][50];
  int sum = 0;
  for (size_t i = 0; i < arows; i++) {
    for (size_t j = 0; j < bcolumns; j++) {
      for (size_t k = 0; k < arows; k++) {
        sum += a[i][k] * b[k][i];
        product[i][k] = sum;
      }
    }
  }
  
  {
    printf("Resultant Matrix \n");
    for (size_t i = 0; i < arows; i++) {
      for (size_t j = 0; j < acolumns; j++) {
        printf("%5d", product[i][j]);
      }
      printf("\n");
    }
  }
};

