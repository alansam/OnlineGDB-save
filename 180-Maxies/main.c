//
//  main.c
//  CF.Maxies
//
//  Created by Alan Sampson on 5/5/22.
//

#include <stdio.h>

//  MARK: - Definitions
//  MARK: MAX() macro
#define MAX(lh, rh) (lh) > (rh) ? (lh) : (rh)

//  MARK: - Implementation
/*
 *  MARK: max() [inline]
 */
static
inline
__attribute__((always_inline))
int max(int lh, int rh) {
  return lh > rh ? lh : rh;
}

/*
 *  MARK: maxary() [inline]
 */
static
inline
__attribute__((always_inline))
int maxary(size_t const sz, int vals[sz]) {
  int mx = vals[0];
  for (size_t i_ = 1; i_ < sz; ++i_) {
    mx = max(mx, vals[i_]);
  }
  return mx;
}

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  printf("CF.Maxies\n");

  char const * dlm1 = "----------------------------------------";
  char const * dlm2 = "--------------------";

  int mx = 0;
  int i10 = 10;
  int i09 =  9;
  int i11 = 11;
  int vals[10] = { 0, };
  vals[0] = i09;
  vals[1] = i10;
  vals[2] = i11;

  puts(dlm1);
  mx = max(i10, i09);
  printf("max: %2d, %2d = %2d\n", i10, i09, mx);
  puts(dlm2);
  mx = MAX(i10, i09);
  printf("MAX: %2d, %2d = %2d\n", i10, i09, mx);
  putchar('\n');

  puts(dlm1);
  mx = max(i09, i10);
  printf("max: %2d, %2d = %2d\n", i09, i10, mx);
  puts(dlm2);
  mx = MAX(i09, i10);
  printf("MAX: %2d, %2d = %2d\n", i09, i10, mx);
  putchar('\n');

  puts(dlm1);
  mx = max(max(i11, i10), i09);
  printf("max: %2d, %2d, %2d = %2d\n", i11, i10, i09, mx);
  puts(dlm2);
  mx = MAX(MAX(i11, i10), i09);
  printf("MAX: %2d, %2d, %2d = %2d\n", i11, i10, i09, mx);
  putchar('\n');

  puts(dlm1);
  mx = maxary(2, vals);
  printf("maxary: %2d, %2d = %2d\n", vals[0], vals[1], mx);
  putchar('\n');

  puts(dlm1);
  mx = maxary(3, vals);
  printf("maxary: %2d, %2d, %2d = %2d\n", vals[0], vals[1], vals[2], mx);
  putchar('\n');

  return 0;
}
