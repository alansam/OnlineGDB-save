
#include  <stdio.h>

#define DEBUG_

void sorta(int * arr, size_t size);
void sortb(int arr[], size_t size);
void show(int * arr, size_t size);

int main(void) {
  int harry[] = { 9, 6, 5, 8, 7, 1, 0, 4, 3, 2, };
  size_t harry_l = sizeof(harry) / sizeof(*harry);
  int barry[] = { 9, 6, 5, 8, 7, 1, 0, 4, 3, 2, };
  size_t barry_l = sizeof(barry) / sizeof(*barry);

  show(harry, harry_l);
  sorta(harry, harry_l);
  show(harry, harry_l);
  putchar('\n');

  show(barry, barry_l);
  sortb(barry, barry_l);
  show(barry, barry_l);
  putchar('\n');

  return 0;
}

void sorta(int * arr, size_t size) {
  printf("f(): %s\n", __func__);
  printf("%p %zu\n", arr, sizeof(arr));
  int tmp;
#ifdef DEBUG_
  int step = 0;
#endif
  for (size_t x = 0; x < size; ++x) {
    for (size_t y = 1; y < size - x; ++y) {
#ifdef DEBUG_
      printf("%03d --: %3zu, %3zu, ", step++, x, y);
#endif
      if (*(arr + y) < *(arr + y - 1)) {
#ifdef DEBUG_
        printf("swapping %3d and %3d: ", *(arr + y), *(arr + y - 1));
#endif
        tmp = *(arr + y - 1);
        *(arr + y - 1) = *(arr + y);
        *(arr + y) = tmp;
#ifdef DEBUG_
        show(arr, size);
#endif
      }
#ifdef DEBUG_
      else { printf("no swaps\n"); }
#endif
    }
  }

  return;
}

void sortb(int arr[], size_t size) {
  printf("f(): %s\n", __func__);
  printf("%p %zu\n", arr, sizeof(arr));
#ifdef DEBUG_
  int step = 0;
#endif
  for (size_t a_ = 0; a_ < size - 1; ++a_) {
    for (size_t b_ = a_ + 1; b_ < size; ++b_) {
#ifdef DEBUG_
      printf("%03d --: %3zu, %3zu, ", step++, a_, b_);
#endif
      if (arr[b_] < arr[a_]) {
#ifdef DEBUG_
        printf("swapping %3d and %3d: ", arr[a_], arr[b_]);
#endif
        arr[a_] ^= arr[b_];
        arr[b_] ^= arr[a_];
        arr[a_] ^= arr[b_];
#ifdef DEBUG_
        show(arr, size);
#endif
      }
#ifdef DEBUG_
      else { printf("no swaps\n"); }
#endif
    }
  }

  return;
}

void show(int * arr, size_t size) {

  for (size_t h_ = 0; h_ < size; ++h_) {
    printf("%2d ", arr[h_]);
  }
  putchar('\n');

  return;
}

