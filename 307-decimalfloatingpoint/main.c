//  @see: https://stackoverflow.com/questions/38509009/what-uncommon-floating-point-sizes-exist-in-c-compilers/60785089#60785089
//  @see: https://www.ibm.com/docs/en/zos/2.3.0?topic=point-floating-numbers
//  @see: https://stackoverflow.com/questions/57017033/why-doesnt-this-decimal32-value-have-the-expected-bit-pattern/57017430#57017430

//  opts: -Wall -Wpedantic -lgmp -std=gnu2x -fsanitize=address

#include <stdio.h>
#include <stdint.h>

typedef union d32 d32;
union d32 {
  _Decimal32    da;
  float         ff;
  uint32_t      dx;
  unsigned char xa[sizeof(_Decimal32)];
};

void show(d32 du) {
  uint16_t ct = 0;
  printf("%d: %zu %08x\n", ++ct, sizeof(_Decimal32), (uint32_t) du.da);
  printf("%d: %02x [{%x == '%c'} %02x %u] %u %08x\n",
         ++ct,
         (du.dx >> 24),
         (du.dx >> 31),
         ((du.dx >> 31) == 1 ? '-' : '+'),
        //  (((du.dx >> 24) & 0x8f) >> 7),
        //  ((((du.dx >> 24) & 0x8f) >> 7) == 1 ? '-' : '+'),
         ((du.dx >> 24) & 0x7f),
         ((du.dx >> 24) & 0x7f),
         (du.dx & 0x00ffffff),
         du.dx);
  printf("%d: ", ++ct);
  for (size_t u_ = 0ul; u_ < sizeof du.xa; ++u_) {
    printf("%02x ", du.xa[u_]);
  }
  putchar('\n');
  printf("%d: %08x\n", ++ct, 123456);
  putchar('\n');

  return;
}

int main() {
  d32 du1 = { .da =  123.456df, };
  d32 du2 = { .da = -123.456df, };

  show(du1);
  show(du2);

  return 0;
}

