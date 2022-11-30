
#include <stdio.h>
#include <string.h>

#include "d0.h"
#include "d1.h"
#include "dups.h"

int main(int argc, char const * argv[]) {
  dups parent = { .pbck = NULL, .pfwd = NULL, .id = 0u, .flag = false, };
  strcpy(parent.name, "parent");

  printf("%p %p, %hu, %hhu, '%s'\n",
         (void *) parent.pbck,
         (void *) parent.pfwd,
         parent.id,
         parent.flag,
         parent.name);

  return 0;
}
