
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// #define DEBUG_

enum { EVEN, ODD, };
static
char const * const evn_odd[] = { "even", "odd", };
static
size_t const evn_odd_sz = sizeof evn_odd / sizeof *evn_odd;

//  remainder
static
inline
bool rem_show(int32_t val) {
#ifdef DEBUG_
  printf("%08x %08x %08x %d: ", val, (val / 2), (val % 2), (val % 2 == 0));
#endif
  bool chk = (val % 2 == 0);  //  remainder of val / 2 == 0 means even
  printf("%% %4d is %s\n", val, (chk ? evn_odd[EVEN] : evn_odd[ODD]));
  return true;
}

//  bitwize AND
static
inline
bool bitand_show(int32_t val) {
#ifdef DEBUG_
  printf("%08x %08x %08x %d: ", val, 0x01, (val & 0x01), !(val & 0x01));
#endif
  bool chk = !(val & 0x01); //  low bit on means val is odd
  printf("& %4d is %s\n", val, (chk ? evn_odd[EVEN] : evn_odd[ODD]));
  return true;
}

//  bitwize XOR
static
inline
bool bitxor_show(int32_t val) {
#ifdef DEBUG_
  printf("%08x %08x %08x %d: ", val, (val ^ 0x01), (val + 1), ((val ^ 0x01) == (val + 1)));
#endif
  bool chk = (val ^ 0x01) == (val + 1); //  val XOR 1 == val + 1 means even
  printf("^ %4d is %s\n", val, (chk ? evn_odd[EVEN] : evn_odd[ODD]));
  return true;
}

//  bitwize OR
static
inline
bool bitor_show(int32_t val) {
#ifdef DEBUG_
  printf("%08x %08x %08x %d: ", val, (val | 0x01), (val + 1), ((val | 0x01) > (val)));
#endif
  bool chk = (val | 0x01) > (val);  //  val OR 1 .GT. val means even
  printf("| %4d is %s\n", val, (chk ? evn_odd[EVEN] : evn_odd[ODD]));
  return true;
}

//  divide
static
inline
bool div_show(int32_t val) {
#ifdef DEBUG_
  printf("%08x %08x %08x %d: ", val, ((val / 2) * 2), (val), (((val / 2) * 2) == val));
#endif
  bool chk = (((val / 2) * 2) == val);  //  val div by 2 then mult by 2 == val means even
  printf("/ %4d is %s\n", val, (chk ? evn_odd[EVEN] : evn_odd[ODD]));
  return true;
}

typedef bool (*showfn)(int32_t);

static
char const * testdata[] = { "5", "8", "55", "88", "-5", "-8", /*"-0",*/ "22", };
static
size_t const testdata_sz = sizeof testdata / sizeof *testdata;

static
showfn const sfns[] = { rem_show, bitand_show, bitxor_show, bitor_show, div_show, };
static
size_t const sfns_sz = sizeof sfns / sizeof *sfns;

//  Program EPA
int main(int argc, char const * argv[]) {
  bool reading = true;
  int32_t val = 0;

  for (size_t f_ = 0; f_ < sfns_sz; ++f_) {
    size_t i_ = 0;
    do {
      sscanf(testdata[i_++], "%d", &val);
      reading = (val == 0 || i_ >= testdata_sz) ? false : sfns[f_](val);
    } while (reading);
    putchar('\n');
  }

  return 0;
}
