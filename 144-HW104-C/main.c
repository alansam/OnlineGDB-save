//
//  hw104.c
//  CF.Homework104
//
//  Created by Alan Sampson on 12/11/21.
//
// now I wanted to ue dynamic memory allocation for first argument of
// function( for array of pointer to string) and pass it to function
// char *pptr[] = /*  in this way using malloc  */
// but how do I do?

#include <stdio.h>
#include <stdlib.h>

#include "version_info.h"
#include "snap.h"

char const ** test(char const * pptr[]);

static
char const round_objects[][10] = {
  "apple",  "balls",  "mango", "pears", "egg",
  "tomato", "turnip", "globe", "peach", "apricot",
  };
static
size_t const round_objects_sz = sizeof(round_objects);
static
size_t const round_objects_ec = round_objects_sz / sizeof(round_objects[0]);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  version_details();

  size_t const str_ptrs_sz = round_objects_ec * sizeof(char const *);
  char const ** str_ptrs = malloc(str_ptrs_sz);
  char const ** pptr = NULL;

  printf("SNAP: \"round_objects[%zu]\", snap size: %6zu [%#08zx]\n",
         round_objects_ec, round_objects_sz, round_objects_sz);
  snap(stdout, round_objects, round_objects_sz);

  printf("\n%p %p\n", str_ptrs, pptr);
  pptr = test(str_ptrs);
  printf("\n%p %p\n", str_ptrs, pptr);
  putchar('\n');
  printf("SNAP: \"str_ptrs[%zu]\", snap size: %6zu [%#08zx]\n",
         round_objects_ec, str_ptrs_sz, str_ptrs_sz);
  snap(stdout, str_ptrs, str_ptrs_sz);
  printf("SNAP: \"pptr\", snap size %6zu [%#08zx]\n", str_ptrs_sz, str_ptrs_sz);
  snap(stdout, pptr, str_ptrs_sz);

  for (size_t eex = 0; eex < round_objects_ec; ++eex) {
    char const * str = str_ptrs[eex];
    printf("%p %s\n", str, str);
  }

  free(str_ptrs);

  return 0;
}

/*
 *  MARK: test()
 */
char const ** test(char const * pptr[]) {
  printf("In function %s()\n", __func__);

  printf("%p %p\n\n", &round_objects, pptr);
  for (size_t x_ = 0; x_ < round_objects_ec; x_++) {
    pptr[x_] = round_objects[x_];
    printf("%p %p %s\n", round_objects[x_], pptr[x_], round_objects[x_]);
  }
  printf("Exiting function %s()\n", __func__);
  return pptr;
}
