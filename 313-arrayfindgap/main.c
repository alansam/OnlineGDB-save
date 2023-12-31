
#include <stdio.h>
#include <stdlib.h>

static
int intcmp(void const * plft, void const * prgt) {
  int const lft = *((int *) plft);
  int const rgt = *((int *) prgt);

  int rc = 0;
  rc = lft > rgt ? 1 : (lft < rgt ? -1 : 0);

  return rc;
}

inline
static
void show(size_t sz, int aa[]) {
  for (size_t a_ = 0ul, cc = 1ul, mx = 20ul; a_ < sz; ++a_) {
    printf("%4d%s", aa[a_], (cc++ % mx == 0ul ? "\n" : ""));
  }
  putchar('\n');
}

static
int via_sort(size_t ary_sz, int ary[]) {
  show(ary_sz, ary);
  printf("\n%zu%4d%4d\n", ary_sz, ary[0], ary[ary_sz - 1]);

  qsort(ary, ary_sz, sizeof(*ary), intcmp);

  printf("\n%zu%4d%4d\n", ary_sz, ary[0], ary[ary_sz - 1]);
  show(ary_sz, ary);

  int missing = 1;
  if (ary[0ul] != 1) {
    missing = 1;
  }
  else if (ary[ary_sz - 1] != 100) {
    missing = 100;
  }
  else {
    missing = 1;
    for (size_t f_ = 1ul; f_ < ary_sz; ++f_) {
      printf(".. %4d%4d\n", missing, ary[f_]);
      if (ary[f_] != ++missing) {
        break;
      }
    }
  }

  return missing;
}

static
int via_math(size_t ary_sz, int ary[]) {
  int max = 0;
  int total = 0;

  for (int m_ = 1; m_ <= 100; ++m_) {
    max += m_;
  }

  for (size_t v_ = 0ul; v_ < ary_sz; ++v_) {
    total += ary[v_];
  }
  printf("%5d%5d\n", max, total);

  return max - total;
}

int main() {
  int ary[] = {
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
         1,
             2,  3,  4,  5,  6,  7,  8,  9,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    10, 11, 12,
                // 13,
                    14, 15, 16, 17, 18, 19,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
   100,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
  };
  size_t const ary_sz = sizeof ary / sizeof *ary;
  int missing;

  missing = via_math(ary_sz, ary);
  printf("missing element: %3d\n\n", missing);

  missing = via_sort(ary_sz, ary);
  printf("missing element: %3d\n\n", missing);

  return 0;
}

