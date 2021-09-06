
# include <stdio.h>
# include <stdint.h>

#define I_TYP int64_t

size_t snoop(size_t const arrayc, I_TYP const arrayv[arrayc]);

int main() {
  I_TYP array[] = { 10, 20, 30, 40, 50, };
  size_t array_sz = sizeof(array) / sizeof(*array);
  size_t arr_size = *(&array + 1) - *(&array);

  printf("%zu\n", arr_size);
  arr_size = snoop(array_sz, array);
  printf("%zu\n", arr_size);
  putchar('\n');

  printf("sizeof(array)        : %zu\n", sizeof(array));
  printf("sizeof(&array)       : %zu\n", sizeof(&array));
  printf("sizeof(*(&array))    : %zu\n", sizeof(*(&array)));
  printf("sizeof(*(&array + 0)): %zu\n", sizeof(*(&array + 0)));
  printf("sizeof(*(&array + 1)): %zu\n", sizeof(*(&array + 1)));
  putchar('\n');

  I_TYP * array_end = *(&array + 1);
  printf("%p\n", array_end);
  printf("%p\n", array);
  printf("%zu\n", array_end - array);
  putchar('\n');

  for (size_t e_ = 0; e_ < array_sz; ++e_) {
    printf("%zu: %p\n", e_, &array[e_]);
  }
  putchar('\n');
  printf("%zu: %p\n", array_sz, &array[array_sz]);
  putchar('\n');

  size_t a0 = 0x0000000000000fff & (size_t) &array[0];
  size_t a5 = 0x0000000000000fff & (size_t) &array[5];
  printf("%4zu - %4zu = %4zu\n", a5, a0, a5 - a0);
  printf("%4zx - %4zx = %4zx\n", a5, a0, a5 - a0);
  printf("%p - %p = %zu\n", &array[5], &array[0], &array[5] - &array[0]);
  putchar('\n');

  printf("array        : %p\n", array);
  printf("&array       : %p\n", &array);
  printf("(&array + 0) : %p\n", (&array + 0));
  printf("(&array + 1) : %p\n", (&array + 1));
  putchar('\n');
  printf("*(&array + 1): %p\n", *(&array + 1));
  printf("*(&array + 0): %p\n", *(&array + 0));
  putchar('\n');
  printf("%zu\n", (&array + 1) - (&array + 0));
  printf("%zu\n", *(&array + 1) - *(&array + 0));
  putchar('\n');

  return 0;
}

size_t snoop(size_t const arrayc, I_TYP const arrayv[arrayc]) {
  size_t arr_size = *(&arrayv + 1) - arrayv;

  return arr_size;
}

