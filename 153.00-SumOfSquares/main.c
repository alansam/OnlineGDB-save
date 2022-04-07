
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

#define MAX_LIMIT_
#ifdef MAX_LIMIT_
static
size_t const maximum_limit = 1000000000;
#else   /* MAX_LIMIT_ */
static
size_t const maximum_limit = 20;
#endif  /* MAX_LIMIT_ */

int main(int argc, char const * argv[]) {
  size_t count = 0ul;

  do {
    printf("Number [0 to stop]: ");
    fflush(stdout);
    scanf("%" SCNu64, &count);
    printf("[echo] %10" PRIu64 "\n", count);
    if (count == 0) {
      printf( "Terminating ...\n");
      break;
    }
    else if (count > maximum_limit) {
      fprintf(stderr, "%" PRIu64 " exceeds maximum\n", count);
      exit(EXIT_FAILURE);
    }

    uint64_t result = 0ul;
    uint64_t nr = 0ul;
    for (size_t n_ = 1ul; n_ <= count; ++n_) {
      nr = n_ * 2ul;
      result += nr * nr;
    }

    printf("count : %20" PRIu64 "\n", count);
    printf("nr    : %20" PRIu64 "\n", nr);
    printf("result: %20" PRIu64 "\n", result);
  } while (count != 0ul);
  printf("maxval: %20" PRIu64 "\n", ULONG_MAX);

  return EXIT_SUCCESS;
}

