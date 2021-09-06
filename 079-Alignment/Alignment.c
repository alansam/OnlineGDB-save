
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

typedef struct gas gas;
struct gas {
  gas *     gp;
  int8_t    cc;
  int32_t   ii;
  int16_t   ss;
  uint64_t  ul;
  char      st[12];
};

static
inline
void snap(size_t sz, void * gaz) {
  uint8_t * gaz_p = (uint8_t *) gaz;
  printf("base address: %p, size: %zu\n", gaz, sz);
  for (size_t x_ = 0ul, cc = 0ul; x_ < sz; ++x_) {
    printf("%02x%s", *gaz_p++,
           (++cc % 16 == 0 ? "\n" : (cc % 8 == 0 ? "   " : " ")));
  }
}

int main(int argc, char const * argv[]) {

  gas gaz = {
    .gp = &gaz,
    .cc = 'A',
    .ii = INT_MAX,
    .ss = SHRT_MAX,
    .ul = ULONG_MAX,
  };
  strcpy(gaz.st, "\u00a3align gas");  //  £align gas

  printf("++: %p\n", &gaz);
  printf("gp: %p\n", &gaz.gp);
  printf("cc: %p\n", &gaz.cc);
  printf("ii: %p\n", &gaz.ii);
  printf("ss: %p\n", &gaz.ss);
  printf("ul: %p\n", &gaz.ul);
  printf("st: %p\n", &gaz.st);
  putchar('\n');

  printf("size: %zu,\ngp: %p,\ncc: '%c',"
         "\nii: %d,\nss: %hd,\nul: %lu,\nst: \"%s\".\n",
         sizeof(gas), gaz.gp, gaz.cc,
         gaz.ii, gaz.ss, gaz.ul, gaz.st);
  putchar('\n');

  snap(sizeof(gas), &gaz);

  return 0;
}
