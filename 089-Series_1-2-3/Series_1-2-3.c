
#include <stdio.h>
#include <stdlib.h>

#define MAX (19)
// #define INTERACTIVE_
// #define DEBUG_PRINT_

void seriesR(size_t const nr, int array[nr], size_t el);
void seriesI(size_t const nr, int array[nr]);

int main() {
  int array[MAX] = { 1, 2, 3, };
  size_t const array_e = sizeof(array) / sizeof(*array);
  size_t term = 4ull;

#ifdef INTERACTIVE_
  printf("Provide initial 3 values: ");
  fflush(stdout);
  scanf("%d %d %d", &array[0], &array[1], &array[2]);
  printf("Which term [GE 4, LE %zu]?: ", array_e);
  fflush(stdout);
  scanf("%lu", &term);
  if (term < 4 || term > array_e) {
    printf("term %zu is out of range", term);
    exit(EXIT_FAILURE);
  }
  term--;
#endif

  seriesR(array_e, array, 4ul);

  printf("%3zu: %6d\n", term + 1, array[term]);
  printf("%3zu: %6d\n", array_e, array[array_e - 1]);

  printf("%3zu: ", array_e);
  for (size_t x_ = 0; x_ < array_e; ++x_) {
    printf("%7d", array[x_]);
  }
  putchar('\n');
  putchar('\n');

  seriesI(array_e, array);

  printf("%3zu: %6d\n", term + 1, array[term]);
  printf("%3zu: %6d\n", array_e, array[array_e - 1]);

  printf("%3zu: ", array_e);
  for (size_t x_ = 0; x_ < array_e; ++x_) {
    printf("%7d", array[x_]);
  }
  putchar('\n');
  putchar('\n');
  
  return EXIT_SUCCESS;
}

void seriesR(size_t const nr, int array[nr], size_t el) {
  if (el < nr + 1) {
    array[el - 1] = array[el - 2] + array[el - 3] + array[el - 4];
#ifdef DEBUG_PRINT_
    printf("%3zu: ", el + 1);
    for (size_t x_ = 0; x_ < el; ++x_) {
      printf("%7d", array[x_]);
    }
    putchar('\n');
#endif

    seriesR(nr, array, el + 1);
  }
}

void seriesI(size_t const nr, int array[nr]) {
  for (size_t e_ = 3; e_ < nr; ++e_) {
    array[e_] = array[e_ - 1] + array[e_ - 2] + array[e_ - 3];

#ifdef DEBUG_PRINT_
    printf("%3zu: ", e_ + 1);
    for (size_t x_ = 0; x_ < e_ + 1; ++x_) {
      printf("%7d", array[x_]);
    }
    putchar('\n');
#endif
  }
}

