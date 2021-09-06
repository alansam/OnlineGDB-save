
#include <stdio.h>

#define N 5

void InputArray(size_t n, int a[n]);
void OutputArray(size_t n, int pa[n]);
void selection_sort(size_t n, int[n]);
int sort(size_t n, int a[n]);

int main() {
  int a[N];

  printf("Input %d numbers\n", N);
  InputArray(N, a);
  selection_sort(N, a);
  OutputArray(N, a);

  return 0;
}

void InputArray(size_t n, int pa[n]) {
  int * end = pa + n;
  for (; pa < end; ++pa) {
    scanf("%d", pa);
  }
}

void OutputArray(size_t n, int pa[n]) {
  int * end = pa + n;
  for (; pa < end; ++pa) {
    printf("%5d", *pa);
  }
  putchar('\n');
}

void selection_sort(size_t n, int a[n]) {
  if (n < 0) {
    return;
  }
  sort(n, a); //  get a[n]
  printf("sort %zu: ", n);
  OutputArray(N, a);
  selection_sort(n - 1, a);
}

int sort(size_t n, int a[n]) {
  for (size_t i = 0; i < n; ++i) {
    if (a[n - 1] < a[i]) {
      int m;
      m = a[i];
      a[i] = a[i - 1];
      a[i - 1] = m;
    }
  }
  return a[n];
}
