//
//  main.c
//  080-VLAAgain
//
//  Created by Alan Sampson on 6/16/21.
//
/*
 *  Compile with -Werror=vla to prevent VLA
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "snap.h"

#define SIZE 16

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  printf("080-VLAAgain\n");
  printf("C Version: %ld\n", __STDC_VERSION__);

  size_t size = SIZE;
  int32_t vla[size];
  size_t vla_sz = sizeof vla;
  size_t vla_el = vla_sz / sizeof(*vla);
  int32_t lcl[SIZE];
  size_t lcl_sz = sizeof vla;
  size_t lcl_el = lcl_sz / sizeof(*lcl);
  int32_t * dyn = malloc(size * sizeof(int32_t));

  putchar('\n');
  printf("address of size: %16p %16p\n",
         (void *) &size,
         (void *) ((int8_t *) &size + sizeof size));
  printf("address of vla : %16p %16p %16p\n",
         (void *) &vla,
         (void *) ((int8_t *) &vla + sizeof(vla)),
         (void *) &vla[size]);
  printf("address of lcl : %16p %16p %16p\n",
         (void *) &lcl,
         (void *) ((int8_t *) &lcl + sizeof(lcl)),
         (void *) &lcl[size]);
  printf("address of dyn : %16p %16p %16p\n",
         (void *) dyn,
         (void *) ((int8_t *) dyn + size * sizeof(int32_t)),
         (void *) &dyn[size]);
  putchar('\n');

  printf("vla size: %zu, elements: %zu\n", vla_sz, vla_el);
  printf("lcl size: %zu, elements: %zu\n", lcl_sz, lcl_el);
  putchar('\n');

  for (size_t e_ = 0; e_ < size; ++e_) {
    vla[e_] = (int32_t) e_ * 7;
  }
  memcpy(lcl, vla, sizeof(lcl));
  memcpy(dyn, vla, size * sizeof(int32_t));

  printf("&size, bytes: %zu [%#04zx]\n", sizeof(size), sizeof(size));
  snap(stdout, &size, sizeof(size));

  printf("&vla, bytes: %zu [%#04zx]\n", sizeof vla, sizeof vla);
  snap(stdout, &vla,  sizeof vla);

  printf("&lcl, bytes: %zu [%#04zx]\n", sizeof lcl, sizeof lcl);
  snap(stdout, &lcl,  sizeof lcl);

  printf("dyn, bytes: %zu [%#zx]\n", size * sizeof(int32_t), size * sizeof(int32_t));
  snap(stdout, dyn, size * sizeof(int32_t));
  putchar('\n');

  free(dyn);
  dyn = NULL;

  return 0;
}
