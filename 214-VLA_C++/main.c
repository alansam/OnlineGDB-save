//  compile with: -Werror=vla
#define VLA
#ifdef __cplusplus
#include <cstdio>
#else
// #define VLA_ENUM
#include <stdio.h>
#endif


int main() {
#ifdef VLA
  size_t nutz = 10ul;
#else
# ifdef __cplusplus
  size_t constexpr nutz { 10ul };
# else
#   ifdef VLA_ENUM
  enum { nutz = 10ul };
#   else
#     define nutz 10ul
#   endif
# endif
#endif

  int deze[nutz];

  printf("size of these nuts: %zu\n", sizeof deze);
  printf("count of these nuts: %zu\n", sizeof deze / sizeof *deze);

  return 0;
}

