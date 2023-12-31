/*
 *  I just came across the “%n” format specifier of printf():
 *  %n - returns the number of characters written so far by
 *  this call to the function. The result is written to the
 *  value pointed to by the argument. The specification may
 *  not contain any flag, field width, or precision. 
 *
 *
 *  Has anyone ever used this for fun or profit?
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const * argv[]) {
  double π   = M_PI;
  double π_2 = M_PI_2;
  int psize[10] = { 0, };
  size_t psize_sz = sizeof psize / sizeof *psize;
  char ptxt[256] = { '\0', };
  psize[0] = sprintf(ptxt,
                     "π = %n%.15f%n, π/2 = %n%.19f%n and some %n more.",
                     &psize[1], π,   &psize[2],
                     &psize[3], π_2, &psize[4],
                     &psize[5]);
  size_t x_ = 6ul;
  psize[x_++] = strlen(ptxt);
  printf("\"%s\" : %zu\n", ptxt, strlen(ptxt));
  for (size_t p_ = 0ul; p_ < (x_ <= psize_sz ? x_ : psize_sz); ++p_) {
    printf("%3d", psize[p_]);
  }
  putchar('\n');

  printf("π   [floating point digits |%2d - %2d|]: %2d\n",
         psize[2], psize[1], psize[2] - psize[1]);
  printf("π/2 [floating point digits |%2d - %2d|]: %2d\n",
         psize[4], psize[3], psize[4] - psize[3]);

  return 0;
}
