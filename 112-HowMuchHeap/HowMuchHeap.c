
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

int main() {

  char * biggie = NULL;
  for (size_t sv = 0; sv < 64 && biggie == NULL; ++sv) {
    size_t sz = SIZE_MAX >> sv;
    printf("%22zu\n%22zu\n%22zu\n", sv, SIZE_MAX, sz);
    biggie = malloc(sz);
    printf("%p\n", biggie);
    free(biggie);
  }

  return 0;
}
