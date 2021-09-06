
#include <stdio.h>

double avg(size_t sz, int array[sz]);

int main() {
  {
    int array[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, };
    size_t array_el = sizeof(array) / sizeof(*array);
    printf("size %zu\n", array_el);

    double average = avg(array_el, array);
    printf("Avg %.3f\n", average);
  }
  /// this doesn't work, comment it out for a successful compile
  // size_t array_el = sizeof(array) / sizeof(*array);
  // printf("size %zu\n", array_el);

  return 0;
}

double avg(size_t sz, int ary[sz]) {
  // size_t elmts = sizeof(ary) / sizeof(*ary);
  // printf("size %zu\n", elmts);

  double average = 0.0;
  if (sz > 0) {
    int sum = 0;
    for (size_t x_ = 0; x_ < sz; ++x_) {
      sum += ary[x_];
    }
    average = (double) sum / sz;
  }

  /// this doesn't work, comment it out for a successful compile
  // size_t array_el = sizeof(array) / sizeof(*array);
  // printf("size %zu\n", array_el);

  return average;
}
