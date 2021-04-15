#ifndef __cplusplus
# include <stdio.h>
# define STGCLASS_AUTO_ auto
# define STGCLASS_REG_ register
#else
# include <iostream>
# include <cstdio>
# define STGCLASS_AUTO_
# if __cplusplus >= 201700L
#   define STGCLASS_REG_
# else
#   define STGCLASS_REG_ register
# endif
#endif

extern int ae;
static int aa = 6;

int ae = 2;

int main() {
#ifdef __cplusplus
  std::cout << __cplusplus << std::endl;
#endif

  printf("%d, &aa %p\n", aa, (void *) &aa);

  STGCLASS_AUTO_ int aa = 5;
  printf("%d, &aa %p\n", aa, (void *) &aa);

  {
    int aa = 4;
    printf("%d, &aa %p\n", aa, (void *) &aa);
  }

  {
    printf("%d, &ae %p\n", ae, (void *) &ae);
  }

  {
    STGCLASS_REG_ int aa = 4;
    printf("%d.\n", aa);
  }

  return 0;
}
