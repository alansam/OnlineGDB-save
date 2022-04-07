
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

static
inline
void show_n_tell(size_t const nr, uint64_t const coll[nr], size_t const ccmax) {
  for (size_t c_ = 0ul, cc = 1ul; c_ < nr; ++c_, cc++) {
    printf("%15" PRIu64 "%s", coll[c_], (cc % ccmax == 0 ? "\n" : ""));
  }
  putchar('\n');
}

/*
 *  MARK: fibonacci_iter()
 */
uint64_t * fibonacci_iter(uint64_t const number, uint64_t * fibs) {
  fibs[0] = 0u;
  fibs[1] = 1u;
  for (size_t f_ = 2ul; f_ < number; ++f_) {
    fibs[f_] = fibs[f_ - 2] + fibs[f_ - 1];
  }

  return fibs;
}

/*
 *  MARK: fibonacci_recu()
 */
uint64_t * fibonacci_recu(size_t idx, size_t const number, uint64_t * fibs) {
  if (idx < number) {
    switch (idx) {
      case 0u:
        fibs[0] = 0u;
        break;
      case 1u:
        fibs[1] = 1u;
        break;
      default:
        fibs[idx] = fibs[idx - 2] + fibs[idx - 1];
    }
    fibonacci_recu(idx + 1, number, fibs);
  }

  return fibs;
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  if (argc > 0) {
    printf("Running: %s\n\n", argv[0]);
  }

  size_t const number = 60ul;
  uint64_t * fibs = malloc(number * sizeof(uint64_t));
  if (fibs == NULL) {
    exit(EXIT_FAILURE);
  }

  printf("Iterative Fibonacci function\n");
  fibonacci_iter(number, fibs);
  show_n_tell(number, fibs, 10ul);
  putchar('\n');

  memset(fibs, 0, number * sizeof(uint64_t));
  show_n_tell(number, fibs, 10ul);
  putchar('\n');

  printf("Recursive Fibonacci function\n");
  fibonacci_recu(0ul, number, fibs);
  show_n_tell(number, fibs, 10ul);
  putchar('\n');

  free(fibs);

  return EXIT_SUCCESS;
}

