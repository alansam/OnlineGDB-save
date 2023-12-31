//  Floating point precision.
//	- Updated to add GNU MP BigNum floating point example

//  opts: -Wall -Wpedantic -lgmp -std=gnu2x -fsanitize=address

#include <stdio.h>
#include <math.h>
#include <quadmath.h>
#include <gmp.h>

int main(int argc, char const * argv[]) {
  float  fa = 1.0f;
  float  fb = 3.0f;
  float  fc = fa / fb;
  puts("float:");
  printf("    %%.7f: %.7f\n", fc);
  printf("   %%.16f: %.16f\n", fc);
  putchar('\n');

  double da = 1.0;
  double db = 3.0;
  double dc = da / db;
  puts("double:");
  printf("  %%.16lf: %.16lf\n", dc);
  printf("  %%.19lf: %.19lf\n", dc);
  putchar('\n');

  puts("long double:");
  long double la = 1.0l;
  long double lb = 3.0l;
  long double lc = la / lb;
  printf("  %%.19Lf: %.19Lf\n", lc);
  printf("  %%.24Lf: %.24Lf\n", lc);
  putchar('\n');

  _Float128 Qa = 1.0Q;
  _Float128 Qb = 3.0Q;
  _Float128 Qc = Qa / Qb;
  puts("_Float128:");
  printf("  %%.34Qf: %.34Qf\n", Qc);
  printf("  %%.44Qf: %.44Qf\n", Qc);
  putchar('\n');

  __float128 qa = 1.0q;
  __float128 qb = 3.0q;
  __float128 qc = qa / qb;
  puts("__float128:");
  printf("  %%.34Qf: %.34Qf\n", qc);
  printf("  %%.44Qf: %.44Qf\n", qc);
  putchar('\n');

  mpf_t ma;
  mpf_t mb;
  mpf_t mc;

  mpf_init2(ma, 256);
  mpf_init2(mb, 256);
  mpf_init2(mc, 256);

  mpf_set_d(ma, 1.0);
  mpf_set_d(mb, 3.0);

  mpf_div(mc, ma, mb);

  puts("mpf_t:");
  gmp_printf("  %%.79Ff: %.79Ff\n", mc);
  gmp_printf("  %%.99Ff: %.99Ff\n", mc);
  putchar('\n');

  mpf_clear(ma);
  mpf_clear(mb);
  mpf_clear(mc);

  return 0;
}

/*
Results -
float:
    %.7f: 0.3333333
   %.16f: 0.3333333432674408

double:
  %.16lf: 0.3333333333333333
  %.19lf: 0.3333333333333333148

long double:
  %.19Lf: 0.3333333333333333333
  %.24Lf: 0.333333333333333333342368

_Float128:
  %.34Qf: 0.3333333333333333333333333333333333
  %.44Qf: 0.33333333333333333333333333333333331728391713

__float128:
  %.34Qf: 0.3333333333333333333333333333333333
  %.44Qf: 0.33333333333333333333333333333333331728391713

mpf_t:
  %.79Ff: 0.3333333333333333333333333333333333333333333333333333333333333333333333333333333
  %.99Ff: 0.333333333333333333333333333333333333333333333333333333333333333333333333333333300000000000000000000
 */

