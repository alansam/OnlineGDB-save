/*
 * works when compiled with gcc -c99 -pedantic main.c
 * fails when compiled with gcc -ansi -pedantic main.c
 *
 * run with: ./a n
 *   where: n is any integer
 */
#include <stdio.h>
#include <stdlib.h>

#if _SVID_SOURCE || _BSD_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
typedef long int (*frandom)(void);
char const * frandom_mthd = "random";
frandom randomize = random;
#else
typedef int (*frandom)(void);
char const * frandom_mthd = "rand";
frandom randomize = rand;
#endif

int main(int argc, char const * argv[]) {

#ifndef __STDC_VERSION__  
  printf("VLAs not supported pre C99\n");
#elif __STDC_VERSION__ < 199899
  printf("VLAs not supported pre C99\n");
#else
  printf("VLAs are supported for C %ld\n", __STDC_VERSION__);

  size_t vla_sz = 0;
  size_t v_;

  if (argc > 1) {
    vla_sz = atoi(argv[1]);
  }

  if (vla_sz > 0) {
    int vla[vla_sz];
    for (v_ = 0; v_ < vla_sz; ++v_) {
      vla[v_] = randomize();
    }

    printf("Results (using %s()):\n", frandom_mthd);

    for (v_ = 0; v_ < vla_sz; ++v_) {
      printf("%3lu: %15d\n", v_, vla[v_]);
    }
  }
  else {
    printf("Nothing!\n");
  }
#endif
  
  return 0;
}




