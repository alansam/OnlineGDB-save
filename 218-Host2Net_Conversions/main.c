/*
 *  @see: https://linux.die.net/man/3/htonl
 *  @see: https://linux.die.net/man/3/endian
 *  @see: https://www.gta.ufrj.br/ensino/eel878/sockets/htonsman.html
 *  @see: https://stackoverflow.com/questions/20813028/endian-h-not-found-on-mac-osx
 */

// #define _BSD_SOURCE    /* See feature_test_macros(7) */ /* In glibc up to and including 2.19 */
#define _DEFAULT_SOURCE   /* Since glibc 2.19 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <arpa/inet.h>
// #include <netinet/in/h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <sys/types.h>  /* NOTE: includes endian.h */
// #include <endian.h>
#include <features.h>

//  mess with type generics (wow is this ugly!)
//  @see: https://en.cppreference.com/w/c/language/generic
//  @see: https://stackoverflow.com/questions/17302913/generics-for-multiparameter-c-functions-in-c11
#define show(S, X) _Generic((S), \
  default: _Generic((X), \
    int32_t:  show32, \
    uint32_t: show32, \
    int16_t:  show16, \
    uint16_t: show16, \
    int64_t:  show64, \
    uint64_t: show64, \
    default:  show32  \
    ) )(S, X)

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  format an int as hex characters
static
inline
uint8_t const * show32(uint8_t * target, int32_t val) {
  typedef union i2x i2x;
  union i2x {
    int32_t ival;
    uint8_t xval[sizeof val];
  };

  uint8_t const * fnort = target;
  i2x vv;
  vv.ival = val;
  //  format each byte as printable hex
  for (size_t c_ = 0; c_ < sizeof val; ++c_) {
    sprintf((char *) target, "%02x ", vv.xval[c_]);
    target += 3;  //  advance to next print position
  }
  *(--target) = '\0'; //  remove trailing space

  return fnort;
}

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  format an int as hex characters
static
inline
uint8_t const * show16(uint8_t * target, int16_t val) {
  typedef union i2x i2x;
  union i2x {
    int16_t ival;
    uint8_t xval[sizeof val];
  };

  uint8_t const * fnort = target;
  i2x vv;
  vv.ival = val;
  //  format each byte as printable hex
  for (size_t c_ = 0; c_ < sizeof val; ++c_) {
    sprintf((char *) target, "%02x ", vv.xval[c_]);
    target += 3;  //  advance to next print position
  }
  *(--target) = '\0'; //  remove trailing space

  return fnort;
}

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  format an int as hex characters
static
inline
uint8_t const * show64(uint8_t * target, int64_t val) {
  typedef union i2x i2x;
  union i2x {
    int64_t ival;
    uint8_t xval[sizeof val];
  };

  uint8_t const * fnort = target;
  i2x vv;
  vv.ival = val;
  //  format each byte as printable hex
  for (size_t c_ = 0; c_ < sizeof val; ++c_) {
    sprintf((char *) target, "%02x ", vv.xval[c_]);
    target += 3;  //  advance to next print position
  }
  *(--target) = '\0'; //  remove trailing space

  return fnort;
}

void hton_sample0(void);
void endian_sample0(void);
void endian_sample1(void);

static
char const * const dlm0 = "....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|";

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  driver entry point
 */
int main(int argc, char const * argv[]) {

  hton_sample0();
  endian_sample0();
  endian_sample1();

  return 0;
}

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
void hton_sample0(void) {
  printf("In function %s()\n", __func__);

  int32_t const iv[] = { 299, -299, };
  int16_t const hv[] = { 299, -299, };

  puts(dlm0);
  for (size_t n_ = 0; n_ < (sizeof iv / sizeof *iv); ++n_) {
    uint8_t tgt[sizeof *iv * 3 + 1];
    printf("H: %12" PRId32 " == %#010" PRIx32 " == %s\n", iv[n_], iv[n_], show(tgt, iv[n_]));
    uint32_t nbe = htonl(iv[n_]);
    printf("N: %12" PRId32 " == %#010" PRIx32 " == %s\n", nbe, nbe, show(tgt, nbe));
    int32_t hbe = ntohl(nbe);
    printf("H: %12" PRId32 " == %#010" PRIx32 " == %s\n", hbe, hbe, show(tgt, hbe));
    putchar('\n');
  }

  puts(dlm0);
  for (size_t n_ = 0; n_ < (sizeof hv / sizeof *hv); ++n_) {
    uint8_t tgt[sizeof *hv * 3 + 1];
    printf("H: %12" PRId16 " == %#06" PRIx16 " == %s\n", hv[n_], (uint16_t) hv[n_], show16(tgt, hv[n_]));
    uint32_t nbe = htons(hv[n_]);
    printf("N: %12" PRId16 " == %#06" PRIx16 " == %s\n", nbe, nbe, show(tgt, nbe));
    int32_t hbe = ntohs(nbe);
    printf("H: %12" PRId16 " == %#06" PRIx16 " == %s\n", hbe, hbe, show(tgt, hbe));
    putchar('\n');
  }
}

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  The program below display the results of converting an integer from host
 *  byte order to both little-endian and big-endian byte order. Since host
 *  byte order is either little-endian or big-endian, only one of these
 *  conversions will have an effect. When we run this program on a little-endian
 *  system such as x86-32, we see the following:
 *
 *    x.u32 = 0x44332211
 *    htole32(x.u32) = 0x44332211
 *    htobe32(x.u32) = 0x11223344
 */
void endian_sample0(void) {
  printf("In function %s()\n", __func__);
  puts(dlm0);

  union {
    uint32_t u32;
    uint8_t arr[4];
  } x;
  x.arr[0] = 0x11;

  /* Lowest-address byte */
  x.arr[1] = 0x22;
  x.arr[2] = 0x33;
  x.arr[3] = 0x44;

  /* Highest-address byte */
  printf("x.u32 = 0x%x\n", x.u32);
  printf("htole32(x.u32) = 0x%x\n", htole32(x.u32));
  printf("htobe32(x.u32) = 0x%x\n", htobe32(x.u32));
  putchar('\n');
}

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
void endian_sample1(void) {
  printf("In function %s()\n", __func__);

  int16_t i16[] = { SHRT_MIN, SHRT_MAX, };
  int32_t i32[] = { INT_MIN, INT_MAX, };
  int64_t i64[] = { LLONG_MIN, LLONG_MAX, };

  puts(dlm0);
  for (size_t o_ = 0; o_ < (sizeof i16 / sizeof *i16); ++o_) {
    bool host_is_le = false;
    bool host_is_be = false;
    uint16_t hv = i16[o_];
    uint16_t le = htole16(hv);
    uint16_t be = htobe16(hv);
    uint16_t lh = le16toh(le);
    uint16_t bh = be16toh(be);
    host_is_le = (hv == le) ? true : false;
    host_is_be = !host_is_le;
    uint8_t tgt[sizeof hv * 3 + 1] = { '\0', };
    printf("h: %20" PRId16 " == %#06" PRIx16 " == %s\n", hv, hv, show(tgt, hv));
    printf("l: %20" PRId16 " == %#06" PRIx16 " == %s %c\n", le, le, show(tgt, le), (!host_is_le ? '*' : ' '));
    printf("b: %20" PRId16 " == %#06" PRIx16 " == %s %c\n", be, be, show(tgt, be), (!host_is_be ? '*' : ' '));
    printf("l: %20" PRId16 " == %#06" PRIx16 " == %s\n", lh, lh, show(tgt, lh));
    printf("b: %20" PRId16 " == %#06" PRIx16 " == %s\n", bh, bh, show(tgt, bh));
    putchar('\n');
  }

  puts(dlm0);
  for (size_t o_ = 0; o_ < (sizeof i32 / sizeof *i32); ++o_) {
    bool host_is_le = false;
    bool host_is_be = false;
    uint32_t iv = i32[o_];
    uint32_t le = htole32(iv);
    uint32_t be = htobe32(iv);
    uint32_t lh = le32toh(le);
    uint32_t bh = be32toh(be);
    host_is_le = (iv == le) ? true : false;
    host_is_be = !host_is_le;
    uint8_t tgt[sizeof iv * 3 + 1] = { '\0', };
    printf("h: %20" PRId32 " == %#010" PRIx32 " == %s\n", iv, iv, show(tgt, iv));
    printf("l: %20" PRId32 " == %#010" PRIx32 " == %s %c\n", le, le, show(tgt, le), (!host_is_le ? '*' : ' '));
    printf("b: %20" PRId32 " == %#010" PRIx32 " == %s %c\n", be, be, show(tgt, be), (!host_is_be ? '*' : ' '));
    printf("l: %20" PRId32 " == %#010" PRIx32 " == %s\n", lh, lh, show(tgt, lh));
    printf("b: %20" PRId32 " == %#010" PRIx32 " == %s\n", bh, bh, show(tgt, bh));
    putchar('\n');
  }

  puts(dlm0);
  for (size_t o_ = 0; o_ < (sizeof i64 / sizeof *i64); ++o_) {
    uint64_t lv = i64[o_];
    bool host_is_le = false;
    bool host_is_be = false;
    uint64_t le = htole64(lv);
    uint64_t be = htobe64(lv);
    uint64_t lh = le64toh(le);
    uint64_t bh = be64toh(be);
    host_is_le = (lv == le) ? true : false;
    host_is_be = !host_is_le;
    uint8_t tgt[sizeof lv * 3 + 1] = { '\0', };
    printf("h: %20" PRId64 " == %#018" PRIx64 " == %s\n", lv, lv, show(tgt, lv));
    printf("l: %20" PRId64 " == %#018" PRIx64 " == %s %c\n", le, le, show(tgt, le), (!host_is_le ? '*' : ' '));
    printf("b: %20" PRId64 " == %#018" PRIx64 " == %s %c\n", be, be, show(tgt, be), (!host_is_be ? '*' : ' '));
    printf("l: %20" PRId64 " == %#018" PRIx64 " == %s\n", lh, lh, show(tgt, lh));
    printf("b: %20" PRId64 " == %#018" PRIx64 " == %s\n", bh, bh, show(tgt, bh));
    putchar('\n');
  }
}
