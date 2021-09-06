
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

inline
static
int rand_in_range(int const upper, int const lower) {
  int num = upper + random() / (RAND_MAX / (lower - upper + 1) + 1);
  return num;
}

typedef struct pair_int pair_int;
struct pair_int {
  int first;
  int second;
};

inline
static
pair_int min_max_element_int(size_t const sz, int const ary[sz]) {
  pair_int min_max = { .first = INT_MAX, .second = INT_MIN, };

  for (size_t e_ = 0; e_ < sz; ++e_) {
    if (ary[e_] < min_max.first) {
      min_max.first = ary[e_];
    }
    if (ary[e_] > min_max.second) {
      min_max.second = ary[e_];
    }
  }

  return min_max;
}

static
size_t const lineBreak = 20;

inline
static
void show_me(size_t const sz, int const ary[sz]) {
  for (size_t e_ = 0, cc = 0; e_ < sz; ++e_) {
    printf("%6d%s", ary[e_], (++cc % lineBreak == 0 ? "\n" : ""));
  }
  putchar('\n');
}

extern
int cmpfunc(void const * lhs, void const * rhs) {
   return ( *(int *) lhs - *(int *) rhs );
}

int main() {
  srandom(time(NULL));

  int ary[250];
  size_t const ary_el = sizeof(ary) / sizeof(*ary);

  for (size_t x_ = 0; x_ < ary_el; ++x_) {
    ary[x_] = rand_in_range(-5000, 50000);
  }

  show_me(ary_el, ary);

  putchar('\n');

  pair_int min_max = min_max_element_int(ary_el, ary);
  printf("min = %d, max = %d\n", min_max.first, min_max.second);

  putchar('\n');

  qsort(ary, ary_el, sizeof(*ary), cmpfunc);
  show_me(ary_el, ary);

  return 0;
}
