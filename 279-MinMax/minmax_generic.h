
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <float.h>

void test_list(void);
void test_scalar(void);

//  MARK: max_s_s32()
inline
static
int32_t max_s_s32(int32_t const lhs, int32_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

//  MARK: max_s_u32()
inline
static
uint32_t max_s_u32(uint32_t const lhs, uint32_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

//  MARK: max_s_s64()
inline
static
int64_t max_s_s64(int64_t const lhs, int64_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

//  MARK: max_s_u64()
inline
static
uint64_t max_s_u64(uint64_t const lhs, uint64_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

//  MARK: max_s_ffp()
inline
static
float max_s_ffp(float const lhs, float const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

//  MARK: max_s_dfp()
inline
static
double max_s_dfp(double const lhs, double const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

//  MARK: max_s_lfp()
inline
static
long double max_s_lfp(long double const lhs, long double const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs >= rhs ? lhs : rhs;
}

#define max_scalar(X, Y) _Generic((X)+(Y), \
                                  int32_t:            max_s_s32, \
                                  int32_t const:      max_s_s32, \
                                  uint32_t:           max_s_u32, \
                                  uint32_t const:     max_s_u32, \
                                  uint64_t:           max_s_u64, \
                                  uint64_t const:     max_s_u64, \
                                  int64_t:            max_s_s64, \
                                  int64_t const:      max_s_s64, \
                                  float:              max_s_ffp, \
                                  float const:        max_s_ffp, \
                                  double:             max_s_dfp, \
                                  double const:       max_s_dfp, \
                                  long double:        max_s_lfp, \
                                  long double const:  max_s_lfp, \
                                  default:            max_s_s32) \
                            ((X), (Y))


//  MARK: min_s_s32()
inline
static
int32_t min_s_s32(int32_t const lhs, int32_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

//  MARK: min_s_u32()
inline
static
uint32_t min_s_u32(uint32_t const lhs, uint32_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

//  MARK: min_s_s64()
inline
static
int64_t min_s_s64(int64_t const lhs, int64_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

//  MARK: min_s_u64()
inline
static
uint64_t min_s_u64(uint64_t const lhs, uint64_t const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

//  MARK: min_s_ffp()
inline
static
float min_s_ffp(float const lhs, float const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

//  MARK: min_s_dfp()
inline
static
double min_s_dfp(double const lhs, double const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

//  MARK: min_s_lfp()
inline
static
long double min_s_lfp(long double const lhs, long double const rhs) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  return lhs <= rhs ? lhs : rhs;
}

#define min_scalar(X, Y) _Generic((X)+(Y), \
                                  int32_t:            min_s_s32, \
                                  int32_t const:      min_s_s32, \
                                  uint32_t:           min_s_u32, \
                                  uint32_t const:     min_s_u32, \
                                  uint64_t:           min_s_u64, \
                                  uint64_t const:     min_s_u64, \
                                  int64_t:            min_s_s64, \
                                  int64_t const:      min_s_s64, \
                                  float:              min_s_ffp, \
                                  float const:        min_s_ffp, \
                                  double:             min_s_dfp, \
                                  double const:       min_s_dfp, \
                                  long double:        min_s_lfp, \
                                  long double const:  min_s_lfp, \
                                  default:            min_s_s32) \
                            ((X), (Y))

//  MARK: max32()
inline
static
int32_t max32(size_t const sz, int32_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  int32_t max = INT_MIN;
  if (sz > 0ul) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

//  MARK: max32u()
inline
static
uint32_t max32u(size_t const sz, uint32_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  uint32_t max = 0u;
  if (sz > 0) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

//  MARK: max64()
inline
static
int64_t max64(size_t const sz, int64_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  int64_t max = LONG_MIN;
  if (sz > 0ul) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

//  MARK: max64u()
inline
static
uint64_t max64u(size_t const sz, uint64_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  uint64_t max = 0ul;
  if (sz > 0ul) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

//  MARK: maxf()
inline
static
float maxf(size_t const sz, float const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  float max = FLT_MIN;
  if (sz > 0ul) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

//  MARK: maxd()
inline
static
double maxd(size_t const sz, double const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  double max = DBL_MIN;
  if (sz > 0ul) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

//  MARK: maxld()
inline
static
long double maxld(size_t const sz, long double const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  long double max = LDBL_MIN;
  if (sz > 0ul) {
    max = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      max = max > nrs[m_] ? max : nrs[m_];
    }
  }

  return max;
}

#define maxptr(Y) _Generic((Y),                 \
                  int32_t *:            max32,  \
                  int32_t const *:      max32,  \
                  uint32_t *:           max32u, \
                  uint32_t const *:     max32u, \
                  int64_t *:            max64,  \
                  int64_t const *:      max64,  \
                  uint64_t *:           max64u, \
                  uint64_t const *:     max64u, \
                  float *:              maxf,   \
                  float const *:        maxf,   \
                  double *:             maxd,   \
                  double const *:       maxd,   \
                  long double *:        maxld,  \
                  long double const *:  maxld)
#define max(X, Y) _Generic((X),             \
                  size_t:       maxptr(Y),  \
                  size_t const: maxptr(Y))  \
                  ((X), (Y))

//  MARK: min32()
inline
static
int32_t min32(size_t const sz, int32_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  int32_t min = INT_MAX;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

//  MARK: min32u()
inline
static
uint32_t min32u(size_t const sz, uint32_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  int32_t min = 0u;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

//  MARK: min64()
inline
static
int64_t min64(size_t const sz, int64_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  int64_t min = LONG_MAX;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

//  MARK: min64u()
inline
static
uint64_t min64u(size_t const sz, uint64_t const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  uint64_t min = 0ul;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

//  MARK: minf()
inline
static
float minf(size_t const sz, float const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  float min = FLT_MAX;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

//  MARK: mind()
inline
static
double mind(size_t const sz, double const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  double min = DBL_MAX;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

//  MARK: minld()
inline
static
long double minld(size_t const sz, long double const nrs[sz]) {
  fprintf(stderr, "LOG: In function %s()\n", __func__);
  long double min = LDBL_MAX;
  if (sz > 0ul) {
    min = nrs[0ul];
    for (size_t m_ = 1ul; m_ < sz; ++m_) {
      min = min < nrs[m_] ? min : nrs[m_];
    }
  }

  return min;
}

#define minptr(Y) _Generic((Y),                 \
                  int32_t *:            min32,  \
                  int32_t const *:      min32,  \
                  uint32_t *:           min32u, \
                  uint32_t const *:     min32u, \
                  int64_t *:            min64,  \
                  int64_t const *:      min64,  \
                  uint64_t *:           min64u, \
                  uint64_t const *:     min64u, \
                  float *:              minf,   \
                  float const *:        minf,   \
                  double *:             mind,   \
                  double const *:       mind,   \
                  long double *:        minld,  \
                  long double const *:  minld,  \
                  int32_t:              min_s_s32,  \
                  int32_t const:        min_s_s32,  \
                  uint32_t:             min_s_u32,  \
                  uint32_t const:       min_s_u32,  \
                  int64_t:              min_s_s64,  \
                  int64_t const:        min_s_s64,  \
                  uint64_t:             min_s_u64,  \
                  uint64_t const:       min_s_u64,  \
                  float:                min_s_ffp,  \
                  float const:          min_s_ffp,  \
                  double:               min_s_dfp,  \
                  double const:         min_s_dfp,  \
                  long double:          min_s_lfp,  \
                  long double const:    min_s_lfp)
#define min(X, Y) _Generic((X),             \
                  size_t:             minptr(Y),  \
                  size_t const:       minptr(Y),  \
                  int32_t:            minptr(Y),  \
                  int32_t const:      minptr(Y),  \
                  uint32_t:           minptr(Y),  \
                  uint32_t const:     minptr(Y),  \
                  int64_t:            minptr(Y),  \
                  int64_t const:      minptr(Y),  \
                  float:              minptr(Y),  \
                  float const:        minptr(Y),  \
                  double:             minptr(Y),  \
                  double const:       minptr(Y),  \
                  long double:        minptr(Y),  \
                  long double const:  minptr(Y))  \
                  ((X), (Y))
