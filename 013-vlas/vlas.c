/*
 * works when compiled with gcc -c99 -pedantic main.c
 * fails when compiled with gcc -ansi -pedantic main.c
 *
 * run with: ./a n
 *   where: n is any integer
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const * argv[]) {

  size_t vla_sz = 0;
  size_t v_;

  if (argc > 1) {
    vla_sz = atoi(argv[1]);
  }

  if (vla_sz > 0) {
    int vla[vla_sz];
    for (v_ = 0; v_ < vla_sz; ++v_) {
      vla[v_] = rand();
    }

    printf("Results:\n");

    for (v_ = 0; v_ < vla_sz; ++v_) {
      printf("%3lu: %15d\n", v_, vla[v_]);
    }
  }
  else {
    printf("Nothing!\n");
  }
  
  return 0;
}


