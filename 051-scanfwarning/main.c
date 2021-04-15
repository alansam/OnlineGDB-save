// compile with -O
// if warning not issued use -O -DWSCANF
#include <stdio.h>

#if defined(WSCANF)
int  scanf(const char * __restrict, ...) //__scanflike(1, 2)
__attribute__ ((warn_unused_result));
#endif

int main() {
  int n;
  printf("? ");
#if defined(WSCANF)
  int s = 
#endif
  scanf("%d", &n);
  printf("> %d\n", n);

  return 0;
}

/*

$ uname -a
Linux Check 5.4.0-1036-gcp #39~18.04.1-Ubuntu SMP Sun Jan 17 11:08:21 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
$ gcc --version
gcc (Ubuntu 6.5.0-2ubuntu1~14.04.1) 6.5.0 20181026
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 */