//  @see: https://riptutorial.com/c/example/2784/generic-selection-based-on-multiple-arguments

#include <stdio.h>

#include "minmax_generic.h"

static
char const * const dlm = "....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|";

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  puts(dlm);
  test_list();
  putchar('\n');

  puts(dlm);
  test_scalar();
  putchar('\n');

  return 0;
}

/*
 *  MARK: test_list()
 */
void test_list(void) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  int32_t nrs[] = { 1, 3, 5, 0, -1, -3, -5, 2, 4, 6, -2, -4, -6, };
  size_t const nrs_sz = sizeof nrs / sizeof *nrs;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < nrs_sz; ++n_) {
    printf("%5d", nrs[n_]);
  }
  putchar('\n');
  // int32_t max = max32(nrs_sz, nrs);
  int32_t max_32 = max(nrs_sz, nrs);
  int32_t min_32 = min(nrs_sz, nrs);
  printf("min: %5d\n", min_32);
  printf("max: %5d\n", max_32);
  printf("???: %5d %5d\n", min(3ul, &nrs[5]), max(3ul, &nrs[5]));
  putchar('\n');

  int64_t nrs64[] = { 11l, 13l, 15l, 0l, -11l, -13l, -15l, 12l, 14l, 16l, -12l, -14l, -16l, };
  size_t const nrs64_sz = sizeof nrs64 / sizeof *nrs64;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < nrs64_sz; ++n_) {
    printf("%5ld", nrs64[n_]);
  }
  putchar('\n');
  int64_t max_64 = max(nrs64_sz, nrs64);
  int64_t min_64 = min(nrs64_sz, nrs64);
  printf("min: %5ld\n", min_64);
  printf("max: %5ld\n", max_64);
  putchar('\n');

  uint32_t unrs32[] = { 21l, 23l, 25l, 20l, 22l, 24l, 26l, };
  size_t const unrs32_sz = sizeof unrs32 / sizeof *unrs32;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < unrs32_sz; ++n_) {
    printf("%5u", unrs32[n_]);
  }
  putchar('\n');
  uint32_t umax_32 = max(unrs32_sz, unrs32);
  uint32_t umin_32 = min(unrs32_sz, unrs32);
  printf("min: %5u\n", umin_32);
  printf("max: %5u\n", umax_32);
  putchar('\n');

  uint64_t unrs64[] = { 221l, 223l, 225l, 220l, 222l, 224l, 226l, };
  size_t const unrs64_sz = sizeof unrs64 / sizeof *unrs64;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < unrs64_sz; ++n_) {
    printf("%5lu", unrs64[n_]);
  }
  putchar('\n');
  uint64_t umax_64 = max(unrs64_sz, unrs64);
  uint64_t umin_64 = min(unrs64_sz, unrs64);
  printf("min: %5lu\n", umin_64);
  printf("max: %5lu\n", umax_64);
  putchar('\n');

  float nrsf[] = { 409.6f, 327.67f, -327.68f, 6553.5f, };
  size_t const nrsf_sz = sizeof nrsf / sizeof *nrsf;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < nrsf_sz; ++n_) {
    printf("%9.3f", nrsf[n_]);
  }
  putchar('\n');
  float max_f = max(nrsf_sz, nrsf);
  float min_f = min(nrsf_sz, nrsf);
  printf("min: %9.3f\n", min_f);
  printf("max: %9.3f\n", max_f);
  putchar('\n');

  double nrsd[] = { 409.6, 327.67, -327.68, 6553.5, };
  size_t const nrsd_sz = sizeof nrsd / sizeof *nrsd;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < nrsd_sz; ++n_) {
    printf("%9.3lf", nrsd[n_]);
  }
  putchar('\n');
  double max_d = max(nrsd_sz, nrsd);
  double min_d = min(nrsd_sz, nrsd);
  printf("min: %9.3lf\n", min_d);
  printf("max: %9.3lf\n", max_d);
  putchar('\n');

  long double nrsld[] = { 409.6L, 327.67L, -327.68L, 6553.5L, };
  size_t const nrsld_sz = sizeof nrsld / sizeof *nrsld;
  printf("nrs: ");
  for (size_t n_ = 0ul; n_ < nrsld_sz; ++n_) {
    printf("%9.3Lf", nrsld[n_]);
  }
  putchar('\n');
  long double max_ld = max(nrsld_sz, nrsld);
  long double min_ld = min(nrsld_sz, nrsld);
  printf("min: %9.3Lf\n", min_ld);
  printf("max: %9.3Lf\n", max_ld);
  putchar('\n');

  return;
}

/*
 *  MARK: test_scalar()
 */
void test_scalar(void) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  size_t ct = 0;
  int32_t s32l = 12;
  int32_t s32r = -4;
  int32_t rs32 = max_scalar(s32l, s32r);
  printf("%2zu: %20d > %20d ? %20d\n", ++ct, s32l, s32r, rs32);
  rs32 = min_scalar(s32l, s32r);
  printf("%2zu: %20d < %20d ? %20d\n", ++ct, s32l, s32r, rs32);
  rs32 = min(s32l, s32r);
  printf("%2zu: %20d < %20d ? %20d\n", ++ct, s32l, s32r, rs32);

  uint32_t u32l = 12u;
  uint32_t u32r = UINT_MAX / 10u;
  uint32_t ru32 = max_scalar(u32l, u32r);
  printf("%2zu: %20u > %20u ? %20u\n", ++ct, u32l, u32r, ru32);
  ru32 = min_scalar(u32l,u32r);
  printf("%2zu: %20u < %20u ? %20u\n", ++ct, u32l, u32r, ru32);
  ru32 = min(u32l,u32r);
  printf("%2zu: %20u < %20u ? %20u\n", ++ct, u32l, u32r, ru32);
  putchar('\n');

  int64_t s64l = -4472;
  int64_t s64r = 4096;
  int64_t rs64 = max_scalar(s64l, s64r);
  printf("%2zu: %20ld > %20ld ? %20ld\n", ++ct, s64l, s64r, rs64);
  rs64 = min_scalar(s64l, s64r);
  printf("%2zu: %20ld < %20ld ? %20ld\n", ++ct, s64l, s64r, rs64);
  rs64 = min(s64l, s64r);
  printf("%2zu: %20ld < %20ld ? %20ld\n", ++ct, s64l, s64r, rs64);

  uint64_t u64l = USHRT_MAX;
  uint64_t u64r = 4096u;
  uint64_t ru64 = max_scalar(u64l, u64r);
  printf("%2zu: %20lu > %20lu ? %20lu\n", ++ct, u64l, u64r, ru64);
  ru64 = min_scalar(u64r, u64r);
  printf("%2zu: %20lu < %20lu ? %20lu\n", ++ct, u64l, u64r, ru64);
  ru64 = min(u64r, u64r);
  printf("%2zu: %20lu < %20lu ? %20lu\n", ++ct, u64l, u64r, ru64);
  putchar('\n');

  rs64 = max_scalar(s32l, s64r);
  printf("%2zu: %20d > %20ld ? %20ld\n", ++ct, s32l, s64r, rs64);
  rs64 = min_scalar(s32l, s64l);
  printf("%2zu: %20d < %20ld ? %20ld\n", ++ct, s32l, s64r, rs64);

  rs64 = max_scalar(s64l, s32r);
  printf("%2zu: %20ld > %20d ? %20ld\n", ++ct, s64l, s32r, rs64);
  rs64 = min_scalar(s64l, s32r);
  printf("%2zu: %20ld < %20d ? %20ld\n", ++ct, s64l, s32r, rs64);
  putchar('\n');

  int16_t s16l = SHRT_MAX;
  int16_t s16r = SHRT_MIN;
  int16_t rs16 = max_scalar(s16l, s16r);
  printf("%2zu: %20hd > %20hd ? %20hd\n", ++ct, s16l, s16r, rs16);
  rs16 = min_scalar(s16l, s16r);
  printf("%2zu: %20hd < %20hd ? %20hd\n", ++ct, s16l, s16r, rs16);
  rs16 = min(s16l, s16r);
  printf("%2zu: %20hd < %20hd ? %20hd\n", ++ct, s16l, s16r, rs16);
  putchar('\n');

  float ffl = 1.3333333333333333333e10;
  float ffr = -4096.7;
  float rff = max_scalar(ffl, ffr);
  printf("%2zu: %20.6f > %20.6f ? %20.6f\n", ++ct, ffl, ffr, rff);
  rff = min_scalar(ffl, ffr);
  printf("%2zu: %20.6f < %20.6f ? %20.6f\n", ++ct, ffl, ffr, rff);
  rff = min(ffl, ffr);
  printf("%2zu: %20.6f < %20.6f ? %20.6f\n", ++ct, ffl, ffr, rff);

  double fdl = 1.3333333333333333333e10;
  double fdr = -4096.7;
  double rdf = max_scalar(fdl, fdr);
  printf("%2zu: %20.6lf > %20.6lf ? %20.6lf\n", ++ct, fdl, fdr, rdf);
  rdf = min_scalar(fdl, fdr);
  printf("%2zu: %20.6lf < %20.6lf ? %20.6lf\n", ++ct, fdl, fdr, rdf);
  rdf = min(fdl, fdr);
  printf("%2zu: %20.6lf < %20.6lf ? %20.6lf\n", ++ct, fdl, fdr, rdf);

  long double fll = 1.3333333333333333333e10;
  long double flr = -4096.7;
  long double rlf = max_scalar(fll, flr);
  printf("%2zu: %20.6Lf > %20.6Lf ? %20.6Lf\n", ++ct, fll, flr, rlf);
  rlf = min_scalar(fll, flr);
  printf("%2zu: %20.6Lf < %20.6Lf ? %20.6Lf\n", ++ct, fll, flr, rlf);
  rlf = min(fll, flr);
  printf("%2zu: %20.6Lf < %20.6Lf ? %20.6Lf\n", ++ct, fll, flr, rlf);
  putchar('\n');

  rdf = max_scalar(ffl, fdr);
  printf("%2zu: %20.6f > %20.6lf ? %20.6lf\n", ++ct, ffl, fdr, rdf);
  rdf = min_scalar(ffl, fdr);
  printf("%2zu: %20.6f < %20.6lf ? %20.6lf\n", ++ct, ffl, fdr, rdf);

  rlf = max_scalar(fll, ffr);
  printf("%2zu: %20.6Lf > %20.6f ? %20.6Lf\n", ++ct, fll, ffr, rlf);
  rlf = min_scalar(fll, ffr);
  printf("%2zu: %20.6Lf < %20.6f ? %20.6Lf\n", ++ct, fll, ffr, rlf);

  return;
}
