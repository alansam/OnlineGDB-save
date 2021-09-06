
#include <stdio.h>

#define AS_TRACE_

int product(size_t size, int array[*]);
int sum(size_t size, int array[*]);
void arrayElement(size_t size, int array[*]);
void arrayShow(size_t size, int array[*]);

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *  MARK: main()
 */
int main() {
  size_t size;
  printf("Enter array size: ");
  fflush(stdout);
  scanf("%lu", &size);

  int array[size];
#ifdef AS_TRACE_
  printf("array[%zu], size in bytes: %zu\n", size, sizeof array);
  printf("array address: %p\n", (void *) array);
  printf("Enter array elements: \n");
#endif /* AS_TRACE_ */
  arrayElement(size, array);
  arrayShow(size, array);
  printf("Product is %d\n", product(size, array));
  printf("    Sum is %d\n", sum(size, array));

  return 0;
}

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *  MARK: product()
 */
int product(size_t size, int array[size]) {
#ifdef AS_TRACE_
  printf("In: %s()\n", __func__);
  printf("array[%zu], size in bytes: %zu\n", size, size * sizeof array[0]);
  printf("array address: %p\n", (void *) array);
#endif /* AS_TRACE_ */
  int product = 1;
  for (size_t i_ = 0; i_ < size; ++i_) {
    product *= array[i_]; //  use array index
  }
  putchar('\n');

  return product;
}

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *  MARK: sum()
 */
int sum(size_t size, int array[size]) {
#ifdef AS_TRACE_
  printf("In: %s()\n", __func__);
  printf("array[%zu], size in bytes: %zu\n", size, size * sizeof array[0]);
  printf("array address: %p\n", (void *) array);
#endif /* AS_TRACE_ */
  int total = 0;
  for (size_t i_ = 0; i_ < size; ++i_) {
    total += *array++;  //  use pointer arith.
  }
  putchar('\n');

  return total;
}

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *  MARK: arrayElement()
 */
void arrayElement(size_t size, int array[size]) {
#ifdef AS_TRACE_
  printf("In: %s()\n", __func__);
  printf("array[%zu], size in bytes: %zu\n", size, size * sizeof array[0]);
  printf("array address: %p\n", (void *) array);
#endif /* AS_TRACE_ */
  for (size_t i_ = 0; i_ < size; ++i_) {
    printf("array[%3zu]: ", i_);
    fflush(stdout);
    scanf("%d", &array[i_]);
  }
  putchar('\n');
}

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *  MARK: arrayShow()
 */
void arrayShow(size_t size, int array[size]) {
#ifdef AS_TRACE_
  printf("In: %s()\n", __func__);
  printf("array[%zu], size in bytes: %zu\n", size, size * sizeof array[0]);
  printf("array address: %p\n", (void *) array);
#endif /* AS_TRACE_ */
  
  for (size_t i_ = 0; i_ < size; ++i_) {
    printf("array[%3zu]: %5d\n", i_, *array++);
  }
  putchar('\n');
}
