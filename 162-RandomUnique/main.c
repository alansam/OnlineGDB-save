
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int * brute_force(size_t nr, int rn[nr]);

int main() {

  int rn01[10] = { 0, };
  size_t rn01_l = sizeof(rn01) / sizeof(*rn01);

  brute_force(rn01_l, rn01);

  printf("Brute Force:\n");
  for (size_t ix = 0; ix < rn01_l; ++ix) {
    printf("%3d", rn01[ix]);
  }
  putchar('\n');

  return 0;
}

int * brute_force(size_t rn_l, int rn[rn_l]) {
  printf("In function %s()\n", __func__);

  for (size_t ix = 0; ix < rn_l; ++ix) {
    bool duplicate = false;
    do {
      duplicate = false;
      int rv = (random() % 10) + 1;
      for (size_t jx = 0; jx < rn_l; ++jx) {
        if (rv == rn[jx]) {
          duplicate = true;
          break;
        }
      }

      if (!duplicate) {
        rn[ix] = rv;
      }
    } while (duplicate);
  }

  for (size_t ix = 0; ix < rn_l; ++ix) {
    rn[ix] -= 1;
  }

  return rn;
}

