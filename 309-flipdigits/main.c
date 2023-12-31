
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

/*
 *  MARK: flip_char()
 */
uint32_t flip_char(uint32_t val) {
  char valstr[sizeof(int) * 8ul] = { '\0', };
  uint32_t rslt;

  sprintf(valstr, "%" PRIu32, val);
  size_t const valstr_sz = strlen(valstr);

  for (size_t c_ = 0ul, e_ = valstr_sz - 1ul; c_ < valstr_sz / 2ul; ++c_, --e_) {
    char tmp   = valstr[c_];
    valstr[c_] = valstr[e_];
    valstr[e_] = tmp;
  }

  sscanf(valstr, "%" SCNu32, &rslt);
  return rslt;
}

/*
 *  MARK: flip_nr()
 */
uint32_t flip_nr(uint32_t val) {
  uint32_t rslt = 0u;

  if (val >= 10u) {
    uint32_t vval = val;
    do {
      rslt = rslt * 10u + (vval % 10u);
      vval /= 10u;
    } while (vval != 0u);
  }
  else {
    rslt = val;
  }

  return rslt;
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  uint32_t test[] = {
    4294914924u, 4294967293u, 429496729u, 42949672u, 4294967u,
         12345u,       1122u,       999u,       11u,      10u,
             6u,          0u,
  };
  size_t const test_sz = sizeof test / sizeof *test;

  printf("In: %12" PRIu32 " UINT_MAX\n", UINT_MAX);

  for (size_t t_ = 0ul; t_ < test_sz; ++t_) {
    uint32_t vi = test[t_];
    uint32_t vo = flip_char(vi);
    printf("In: %12" PRIu32 ", Out: %12" PRIu32 ".\n", vi, vo);
    vo = flip_nr(vi);
    printf("In: %12" PRIu32 ", Out: %12" PRIu32 ".\n", vi, vo);
    putchar('\n');
  }

  return 0;
}
