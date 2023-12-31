
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <inttypes.h>

bool is_palindromic(long nr);

static
char * swivel(char * flp, char const * str);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  int64_t nr;

  if (argc > 1) {
    nr = strtol(argv[1], NULL, 10);
  }
  else {
    nr = -1234321l;
  }

  printf("%21" PRId64 " %s a palindrome\n",
         nr,
         (is_palindromic(abs(nr)) ? "is" : "is not"));
  putchar('\n');

  int64_t const tests[] = {
                     1l,                  -1l,
                    22l,                 -22l,
                    23l,                 -23l,
               1234321l,            -1234321l,
             123454321l,          -123454321l,
               1234567l,            -1234567l,
    9123372036302733219, -9123372036302733219,
               LONG_MAX,      (LONG_MIN + 1l),  // NOTE: labs(LONG_MIN) is not valid
  };
  size_t const tests_sz = sizeof tests / sizeof *tests;

  for (size_t t_ = 0ul; t_ < tests_sz; ++t_) {
    uint64_t nr = tests[t_];
    printf("%21" PRId64 " %s a palindrome\n",
           nr,
           (is_palindromic(labs(nr)) ? "is" : "is not"));
  }
  putchar('\n');

  return 0;
}

/*
 *  MARK: swivel()
 */
static
char * swivel(char * flp, char const * str) {
  size_t str_l = strlen(str) + 1ul;

  for (size_t c_ = 0ul, x_ = str_l - 2ul; c_ < str_l - 1ul; ++c_, --x_) {
    flp[x_] = str[c_];
  }

  return flp;
}

/*
 *  MARK: is_palindromic()
 */
bool is_palindromic(int64_t nr) {
  bool ispal = false;
  char numb[sizeof(int64_t) * 4] = { '\0', };
  char flip[sizeof(int64_t) * 4] = { '\0', };

  if (nr > 9) {
    int64_t rn;
    sprintf(numb, "%" PRId64, nr);
    swivel(flip, numb);
    sscanf(flip, "%" SCNd64, &rn);
    ispal = (rn == nr);
    // ispal = strcmp(numb, flip) == 0 ? true : false;
  }
  else {
    ispal = true;
  }

  return ispal;
}

