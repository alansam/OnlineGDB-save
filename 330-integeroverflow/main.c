// Today I wanted to see if having a varible declared as an unsigned int,
// would throw an error if it were negative. It did not, which I guess
// I'm finding confusing. why doesn't this produce and error?

//  @see: https://www.scaler.com/topics/c/overflow-and-underflow-in-c/
//  @see: https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

typedef union consider consider;
union consider {
  uint32_t urange;
  int32_t  srange;
};

int main() {
  int minD = 10;
  int maxD = 100;
  int range = maxD - minD;
  unsigned int Drange = minD - maxD;
  printf("Drange: %d Range: %d\n", Drange, range);
  printf("Drange: %u Range: %u\n", Drange, range);
  //unsigned int Drange is negative: how?
  putchar('\n');

  consider csd = { .srange = minD - maxD, };
  printf("consider { .urange = %11u, %#010x };\n", csd.urange, csd.urange);
  printf("consider { .srange = %11d, %#010x };\n", csd.srange, csd.srange);
  printf("Drange: %d Srange: %d\n", csd.urange, csd.srange);
  printf("Drange: %u Srange: %u\n", csd.urange, csd.srange);
  
  putchar('\n');

  uint32_t ofs[] = { 0x0, 0x7fffffff, 0xffffffff, };
  size_t ofs_sz = sizeof ofs / sizeof *ofs;
  for (size_t o_ = 0ul; o_ < ofs_sz; ++o_) {
    int32_t of1 = (int32_t) ofs[o_];
    int32_t of2 = of1 + 1;
    int32_t of3 = of1 - 1;
    printf(" int: %11d [%08x], +1: %11d [%08x], -1: %11d [%08x]\n",
           of1, of1, of2, of2, of3, of3);
  }
  putchar('\n');

  for (size_t o_ = 0ul; o_ < ofs_sz; ++o_) {
    uint32_t of1 = ofs[o_];
    uint32_t of2 = of1 + 1;
    uint32_t of3 = of1 - 1;
    printf("uint: %11u [%08x], +1: %11u [%08x], -1: %11u [%08x]\n",
           of1, of1, of2, of2, of3, of3);
  }
  putchar('\n');

  bool chk = false;
  for (size_t o_ = 0ul; o_ < ofs_sz; ++o_) {
    int32_t of1 = (int32_t) ofs[o_];
    int32_t of2 = 0;
    chk = __builtin_add_overflow(of1, 1, &of2);
    printf(" int: %11d [%08x], +1: %11d [%08x] Oflow?: %s\n",
           of1, of1, of2, of2, (chk ? "true" : "false"));
    chk = __builtin_sub_overflow(of1, 1, &of2);
    printf(" int: %11d [%08x], -1: %11d [%08x] Oflow?: %s\n",
           of1, of1, of2, of2, (chk ? "true" : "false"));
  }
  putchar('\n');

  for (size_t o_ = 0ul; o_ < ofs_sz; ++o_) {
    uint32_t of1 = ofs[o_];
    uint32_t of2 = 0u;
    chk = __builtin_add_overflow(of1, 1u, &of2);
    printf("uint: %11u [%08x], +1: %11u [%08x] Oflow?: %s\n",
           of1, of1, of2, of2, (chk ? "true" : "false"));
    chk = __builtin_sub_overflow(of1, 1u, &of2);
    printf("uint: %11u [%08x], -1: %11u [%08x] Oflow?: %s\n",
           of1, of1, of2, of2, (chk ? "true" : "false"));
  }
  putchar('\n');

  return 0;
}
