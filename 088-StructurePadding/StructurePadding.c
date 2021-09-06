
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main() {
#ifdef BUFF
  printf("Hi ");
  fflush(stdout);
  printf("Do you see me?");
  *((int *) 0) = 1;
#else
  typedef struct gas gas;
  struct gas {
    gas *   gp;
    int8_t  cc;
    int32_t ii;
    int16_t ss;
  };
  size_t const gas_sz = sizeof(gas);

  gas gaz = { .gp = &gaz, .cc = 'A', .ii = INT_MAX, .ss = SHRT_MAX, };
  printf("%p\n", &gaz);
  printf("%p\n", &gaz.gp);
  printf("%p\n", &gaz.cc);
  printf("%p\n", &gaz.ii);
  putchar('\n');
  printf("%zu %p %c %hd %ld\n", gas_sz, gaz.gp, gaz.cc, gaz.ss, gaz.ii);

  uint8_t * gaz_p = (uint8_t *) gaz.gp;
  for (size_t x_ = 0ul, cc = 0ul; x_ < gas_sz; ++x_) {
    printf("%02x%s", *gaz_p++, (++cc % 16 == 0 ? "\n" : (cc % 8 == 0 ? "   " : " ")));
  }
#endif

  return 0;
}
