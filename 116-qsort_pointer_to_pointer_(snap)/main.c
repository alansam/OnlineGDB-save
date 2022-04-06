
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "snap.h"

#define COLS 10
// #define COMP_DEBUG_

static
bool ascending = true;

typedef struct collected collected;
struct collected {
  size_t rows;
  char ** aryary;
};

static
collected collect(void);
static
void aryary_prt(size_t const row, size_t const col, char ** pparray);
int comp_ch(void const * vp_lhs, void const * vp_rhs);
int comp_str(void const * vp_lhs, void const * vp_rhs);

/*
 *  MARK: main()
 */
int main() {
  collected cr = collect(); //  don't forget to free this resource
  size_t rows = cr.rows;
  char ** aryary = cr.aryary;

  printf("contents of char ** aryary\n%18p:\n", (void *) aryary);
  for (size_t c_ = 0; c_ < rows; ++c_) {
    printf("  %18p\n", (void *) aryary[c_]);
  }
  putchar('\n');

  printf("contents of char ** aryary before sort:\n");
  aryary_prt(rows, COLS, aryary);
  putchar('\n');

  ascending = false;
  qsort(aryary, rows, sizeof(char *), comp_ch);

  printf("contents of char ** aryary after sort [descending]:\n");
  aryary_prt(rows, COLS, aryary);
  putchar('\n');

  ascending = true;
  qsort(aryary, rows, sizeof(char *), comp_str);

  printf("contents of char ** aryary after sort [ascending]:\n");
  aryary_prt(rows, COLS, aryary);
  putchar('\n');

  free(aryary);

  return 0;
}

/*
 *  MARK: comp_ch()
 */
int comp_ch(void const * vp_lhs, void const * vp_rhs) {
  //  type conversions
  char const ** lhs = (char const **) vp_lhs;
  char const ** rhs = (char const **) vp_rhs;

  //  only examine 1st char in array
  //  results: -1 == LT, 0 == GT, 1 == GT
  int rslt = 0; //  zero is default
  if (**lhs < **rhs) { rslt = -1; }
  else if (**lhs > **rhs) { rslt = 1; }
  // else if (**lhs == **rhs) { rslt = 0; }  //  zero is default, no need for the actual test
  rslt = ascending ? rslt : -rslt;        //  if descending order required, take -ve of result

#ifdef COMP_DEBUG_
  printf("%18p [%c] ? %18p [%c] == %d\n", (void *) *lhs, **lhs, (void *) *rhs, **rhs, rslt);
  snap(stdout, *lhs, COLS);
  snap(stdout, *rhs, COLS);
#endif /* COMP_DEBUG_ */

  return rslt;
}

/*
 *  MARK: comp_str()
 */
int comp_str(void const * vp_lhs, void const * vp_rhs) {
  //  type conversions
  char const ** lhs = (char const **) vp_lhs;
  char const ** rhs = (char const **) vp_rhs;

  //  work striings
  char lstr[COLS + 1] = { '\0', };
  char rstr[COLS + 1] = { '\0', };
  strncpy(lstr, *lhs, COLS);
  strncpy(rstr, *rhs, COLS);

  int rslt;
  rslt = strncmp(lstr, rstr, COLS);           //  compare work strings
  rslt = ascending ? rslt : -rslt;            //  if descending order required, take -ve of result
  rslt = rslt == 0 ? 0 : (rslt > 0 ? 1 : -1); //  normalize result to -1, 0, 1

#ifdef COMP_DEBUG_
  printf("%18p [%s] ? %18p [%s] == %d\n", (void *) *lhs, lstr, (void *) *rhs, rstr, rslt);
  snap(stdout, *lhs, COLS);
  snap(stdout, *rhs, COLS);
#endif /* COMP_DEBUG_ */

  return rslt;
}

/*
 *  MARK: collect()
 */
static
collected collect(void) {
  //  sample data
  static
  char dim2[][COLS] = {
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', },
    { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', },
    { '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', },
    { '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', },
    { '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', },
    { '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', },
    { '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', },
    { '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', },
    { '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', },
    { '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', },
    { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', },
  };
  size_t const rows = sizeof(dim2) / sizeof(*dim2);

  printf("rows: %zu\n", rows);
  char ** aryary = malloc(sizeof(char *) * rows); //  acquire storage for array of pointers
  for (size_t c_ = 0; c_ < rows; ++c_) {
    //  fill array with pointers to sample data arrays
    aryary[c_] = dim2[c_];
  }

  printf("samples: %18p\n", (void *) dim2);
  snap(stdout, dim2, sizeof dim2);

  printf("char **: %18p\n", (void *) aryary);
  snap(stdout, aryary, sizeof sizeof(char *) * rows);

  collected cr = { .rows = rows, .aryary = aryary, };
  return cr;
}

/*
 *  MARK: aryary_prt()
 */
inline
void aryary_prt(size_t const row, size_t const col, char ** pparray) {
  printf("%18p:\n", (void *) pparray);
  for (size_t c_ = 0; c_ < row; ++c_) {
    char * dim = *pparray++;
    printf("  %18p -> ", (void *) dim);
    for (size_t r_ = 0; r_ < col; ++r_) {
      printf("%c", *dim++);
    }
    putchar('\n');
  }
  putchar('\n');
}
