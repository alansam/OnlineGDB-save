/*
 * Hint, use joti or seq to generate input:
 * E.G:
 * MacOS:
 * ( jot -r 1000 ; jot 1 -1 ) | ../bin/Odds_n_Evens_too 2>/dev/null
 * Linux:
 * seq 1009  -1 | ../bin/Odds_n_Evens_too 2>/dev/null
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARY_MAX 10

static
inline
void show_array(size_t const mx, int const even_odd[ARY_MAX]) {
  size_t const cc_max = 10;
  for (size_t eo = 0, cc = 0; eo < mx; ++eo) {
    printf(" %6d%s", even_odd[eo], (++cc % cc_max == 0 ? "\n" : ""));
  }
  putchar('\n');
}

int main() {
  int * evens = malloc(ARY_MAX * sizeof(int));
  size_t evens_el = ARY_MAX;
  size_t evens_mx = 0;
  int * odds = malloc(ARY_MAX * sizeof(int));
  size_t odds_el = ARY_MAX;
  size_t odds_mx = 0;

  printf("enter list of integers: ");
  fflush(stdout);
  int nr;
  do {
    scanf("%i", &nr);
    if (nr != -1) { //  depends if -1 should be included in list or not
      if (nr % 2 == 0) {
        evens[evens_mx++] = nr;
      }
      else {
        odds[odds_mx++] = nr;
      }
    }
    // catch condition where max odd or max even nrs is exceeded
    if (evens_mx >= evens_el) {
      evens_el += ARY_MAX;
      fprintf(stderr, "\ntoo many even numbers, extending \"evens\" to %zu elements\n", evens_el);
      evens = realloc(evens, evens_el * sizeof(int));
    }
    if (odds_mx >= odds_el) {
      odds_el += ARY_MAX;
      fprintf(stderr, "\ntoo many odd numbers, extending \"odds\" to %zu elements\n", odds_el);
      odds = realloc(odds, odds_el * sizeof(int));
    }
  } while (nr != -1);

  printf("\nthere are %zu even and %zu odd numbers\n", evens_mx, odds_mx);
  if (evens_mx > 0) {
    printf("Even numbers:\n");
    show_array(evens_mx, evens);
    putchar('\n');
  }
  if (odds_mx > 0) {
    printf("Odd numbers:\n");
    show_array(odds_mx, odds);
    putchar('\n');
  }

  free(evens);
  free(odds);

  return EXIT_SUCCESS;
}
