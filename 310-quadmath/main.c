//  opts: -Wall -Wpedantic -lgmp -std=gnu2x -fsanitize=address -lquadmath

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <quadmath.h>

typedef union overlay overlay;
union overlay {
  float       of;
  double      od;
  long double ol;
  _Float128   oQ;
  __float128  oq;
  uint8_t     odata[sizeof(__float128)];
};

inline
static
char * sd(char * out, overlay look) {
  for (ssize_t d_ = sizeof(__float128) - 1ul, o_ = 0ul; d_ >= 0; --d_, o_ += 2ul) {
    sprintf(out + o_, "%02x", look.odata[d_]);
  }
  return out;
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  char sfa128[sizeof(__float128) * 8ul] = { '\0', };
  char sff128[sizeof(__float128) * 8ul] = { '\0', };
  char pr_out[sizeof(__float128) * 2ul + 1] = { '\0', };
  overlay look = { 0, };

  float fa = 1.0f;
  float fb = 3.0f;
  float fc = fa / fb;
  memset(look.odata, '\0', sizeof(__float128));
  look.of = fc;
  printf("%11s [%3zu]: %*s, %35a, %35.7f\n",
         "float", (sizeof(float) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         fc, fc);

  _Float32 ga = 1.0f;
  _Float32 gb = 3.0f;
  float gc = ga / gb;
  memset(look.odata, '\0', sizeof(__float128));
  look.of = gc;
  printf("%11s [%3zu]: %*s, %35a, %35.7f\n",
         "_Float32", (sizeof(_Float32) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         gc, gc);

  _Float32x ha = 1.0f;
  _Float32x hb = 3.0f;
  float hc = ha / hb;
  memset(look.odata, '\0', sizeof(__float128));
  look.of = hc;
  printf("%11s [%3zu]: %*s, %35la, %35.7lf\n",
         "_Float32x", (sizeof(_Float32x) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         hc, hc);

  double da = 1.0l;
  double db = 3.0l;
  double dc = da / db;
  memset(look.odata, '\0', sizeof(__float128));
  look.od = dc;
  printf("%11s [%3zu]: %*s, %35la, %35.16lf\n",
         "double", (sizeof(double) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         dc, dc);

  long double la = 1.0L;
  long double lb = 3.0L;
  long double lc = la / lb;
  memset(look.odata, '\0', sizeof(__float128));
  look.ol = lc;
  printf("%11s [%3zu]: %*s, %35La, %35.19Lf\n",
         "long double", (sizeof(long double) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         lc, lc);

  __float80 La = 1.0L;
  __float80 Lb = 3.0L;
  __float80 Lc = La / Lb;
  memset(look.odata, '\0', sizeof(__float128));
  look.ol = Lc;
  printf("%11s [%3zu]: %*s, %35La, %35.19Lf\n",
         "__float80", (sizeof(__float80) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         Lc, Lc);

  _Float64x xa = 1.0L;
  _Float64x xb = 3.0L;
  _Float64x xc = xa / xb;
  memset(look.odata, '\0', sizeof(__float128));
  look.ol = xc;
  printf("%11s [%3zu]: %*s, %35La, %35.19Lf\n",
         "_Float64x", (sizeof(_Float64x) * 8ul),
         (int) (sizeof(__float128) * 2ul), sd(pr_out, look),
         xc, xc);

  _Float128 Qa = 1.0Q;
  _Float128 Qb = 3.0Q;
  _Float128 Qc = Qa / Qb;
  memset(sfa128, '\0', sizeof(__float128) * 8ul);
  memset(sff128, '\0', sizeof(__float128) * 8ul);
  quadmath_snprintf(sfa128, sizeof(__float128) * 8ul, "%Qa", Qc);
  quadmath_snprintf(sff128, sizeof(__float128) * 8ul, "%.33Qf", Qc);
  memset(look.odata, '\0', sizeof(__float128));
  look.oq = Qc;
  printf("%11s [%3zu]: %32s, %35s, %35s\n",
         "_Float128", (sizeof(_Float128) * 8ul),
         sd(pr_out, look),
         sfa128, sff128);

  __float128 qa = 1.0q;
  __float128 qb = 3.0q;
  __float128 qc = qa / qb;
  memset(sfa128, '\0', sizeof(__float128) * 8ul);
  memset(sff128, '\0', sizeof(__float128) * 8ul);
  quadmath_snprintf(sfa128, sizeof(__float128) * 8ul, "%Qa", qc);
  quadmath_snprintf(sff128, sizeof(__float128) * 8ul, "%.33Qf", qc);
  memset(look.odata, '\0', sizeof(__float128));
  look.oQ = qc;
  printf("%11s [%3zu]: %32s, %35s, %35s\n",
         "__float128", (sizeof(__float128) * 8ul),
         sd(pr_out, look),
         sfa128, sff128);

  return 0;
}

