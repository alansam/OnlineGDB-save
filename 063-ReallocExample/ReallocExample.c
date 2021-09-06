#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const * argv[]) {

  char const * const strings[] = {
    "teste", "testee", "teste", "teste", "teste", "teste", "testee", "teste", "teste", "tester",
    "taste", "tastee", "taste", "taste", "taste", "taste", "tastee", "taste", "taste", "taster",
  };
  size_t const strings_e = sizeof(strings) / sizeof(*strings);

  putchar('\n');

  size_t sz = 1 * sizeof(char *);
  printf("|< allocate %5zu bytes", sz);
  char const ** array = malloc(1 * sizeof(char *));
  printf(" at %p >| ", array);

  for (size_t i = 0u; i < strings_e; ++i) {
// #define POINTER_STYLE
#ifdef POINTER_STYLE
    *(array + i) = *(strings + i);
    printf("%5zu [%p]: %p - %s\n", i, array + i, *(array + i), *(array + i));
#else
    array[i] = strings[i];
    printf("%5zu [%p]: %p - %s\n", i, array + i, array[i], array[i]);
#endif

    sz = (i + 2) * sizeof(char *);
    printf("|< allocate %5zu bytes", sz);
    array = realloc(array, sz);
    printf(" at %p >| ", array);
  }

  free(array);
  array = NULL;

  return 0;
}
