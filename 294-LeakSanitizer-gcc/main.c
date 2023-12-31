/*
 * @see: https://www.osc.edu/resources/getting_started/howto/howto_use_address_sanitizer
 * GNU gcc compiler options: -Wall -Wpedantic -Werror=vla -fsanitize=address -std=gnu2x -static-libasan
 * LLVM clang compiler options: -Wall -Wpedantic -Werror=vla -fsanitize=address -std=gnu2x -static-libsan
 */
#include <stdio.h>
#include <stdlib.h>

int * gm(size_t sz) {
  int * lots = malloc(sz);
  return lots;
}

int main(int argc, char const * argv[]) {
  printf("294-LeakSanitizer\n");
  int * gotalot = NULL;
  size_t get = 0ul;

  printf("EPA main():      %18p\n", (void *) main);
  printf("EPA gm():        %18p\n", (void *) gm);

  get = 1024ul * sizeof(int);
  gotalot = gm(get);
  printf("%7zu bytes at %18p\n",
         get, (void *) gotalot);

  get *= 4;
  gotalot = gm(get);
  printf("%7zu bytes at %18p\n",
         get, (void *) gotalot);

  free(gotalot);

  return 0;
}
