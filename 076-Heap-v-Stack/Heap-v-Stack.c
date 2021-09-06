
#include <stdio.h>
#include <stdlib.h>

#ifndef ELEMENTS
#   define ELEMENTS 100
#endif

int main(int argc, char const * argv[]) {
  int on_the_stack[ELEMENTS];
  size_t const on_the_stack_sz = sizeof on_the_stack;

  int * on_the_heap = malloc(ELEMENTS * sizeof(int));
  size_t on_the_heap_sz = ELEMENTS * sizeof(int);

  printf("Stack address: %14p, size in bytes: %5zu\n", (void *) on_the_stack, on_the_stack_sz);
  printf(" Heap address: %14p, size in bytes: %5zu\n", (void *) on_the_heap, on_the_heap_sz);

  for (size_t ix = 0; ix < ELEMENTS; ++ix) {
    on_the_stack[ix] = 1 * ix;
    on_the_heap[ix]  = 1 * ix;
  }

  size_t const cc_max = 10;
  printf("\non_the_stack\n");
  //  display last 100 elements
  for (size_t ix = ELEMENTS - 100, cc = 0; ix < ELEMENTS; ++ix) {
    printf("%9d%s", on_the_stack[ix], (++cc % cc_max == 0 ? "\n" : " "));
  }
  putchar('\n');

  printf("\non_the_heap\n");
  //  display last 100 elements
  for (size_t ix = ELEMENTS - 100, cc = 0; ix < ELEMENTS; ++ix) {
    printf("%9d%s", on_the_heap[ix], (++cc % cc_max == 0 ? "\n" : " "));
  }
  putchar('\n');

  free(on_the_heap);

  return 0;
}
