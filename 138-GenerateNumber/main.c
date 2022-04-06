
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <iso646.h>

#define DEBUG_

enum tens {
  T00 =           1, T01 =           10, T02 =           100, T03 =      1000, T04 =      10000,
  T05 =      100000, T06 =      1000000, T07 =      10000000, T08 = 100000000, T09 = 1000000000,
};

static
inline
int32_t get_rn(int32_t min, int32_t max) {
  return (random() % (max + 1- min) + min);
}

int32_t integer_wise(int32_t min, int32_t max, size_t len) {
  if (len > 9) {
    fprintf(stderr, "%zu is too large\n", len);
    exit(EXIT_FAILURE);
  }

  size_t const rn_l = len;
  int32_t * rn = malloc(rn_l * sizeof(int32_t));

  int32_t acc = 0;
  for (size_t i_ = 0; i_ < rn_l; ++i_) {
    int32_t factor;
    switch (i_) {
      case  0: factor = T00; break;
      case  1: factor = T01; break;
      case  2: factor = T02; break;
      case  3: factor = T03; break;
      case  4: factor = T04; break;
      case  5: factor = T05; break;
      case  6: factor = T06; break;
      case  7: factor = T07; break;
      case  8: factor = T08; break;
      case  9: factor = T09; break;
    }
    rn[i_] = get_rn(min, max) * factor;
    acc += rn[i_];
  }

#ifdef DEBUG_
  for (size_t i_ = 0; i_ < rn_l; ++i_) {
    printf("%14d\n", rn[i_]);
  }
#endif

  free(rn);

  return acc;
}

int32_t character_wise(int32_t min, int32_t max, size_t len) {
  if (len > 9) {
    fprintf(stderr, "%zu is too large\n", len);
    exit(EXIT_FAILURE);
  }

  size_t const nr_str_l = len + 1;
  char * nr_str = calloc(nr_str_l, sizeof(char));

#ifdef DEBUG_
  printf("%3zu%3zu\n", strlen(nr_str), nr_str_l);
#endif

  for (size_t n_ = 0; n_ < nr_str_l - 1; ++n_) {
    nr_str[n_] = get_rn(min, max) | '0';
  }

#ifdef DEBUG_
  for (size_t n_ = 0; n_ < nr_str_l - 1; ++n_) {
    printf("%#04x\n", nr_str[n_]);
  }
#endif

#ifdef DEBUG_
  printf("%3zu\n", strlen(nr_str));
  printf("%14s\n", nr_str);
#endif

  int32_t acc;
  sscanf(nr_str, "%d", &acc);

  free(nr_str);

  return acc;
}

int main() {
  srandom(time(0));

  int32_t min = 1;
  int32_t max = 9;

#ifdef DEBUG_
  int cc = 1;
  int const cc_max = 40;
  for (size_t r_ = 0; r_ < 100; ++r_) {
    printf("%3d%s", get_rn(min, max), (cc++ % cc_max == 0) ? "\n" : "");
  }
  putchar('\n');
#endif

  printf("%14d\n", integer_wise(min, max, 9));
  putchar('\n');

  printf("%14d\n", character_wise(min, max, 9));
  putchar('\n');

  return 0;
}

