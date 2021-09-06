
#include <stdio.h>
#include <limits.h>

void bit_pattern(int u) {
  int i, x, word;
  unsigned mask = 1;
  word = CHAR_BIT * sizeof(int);
  mask = mask << (word - 1); /* shift 1 to the leftmost position */
  for(i = 1; i <= word; i++)
  {
    x = (u & mask) ? 1 : 0; /* identify the bit */
    printf("%d", x); /* print bit value */
    mask >>= 1; /* shift mask to the right by 1 bit */
  }
}

int main() {
  int bp = 13 << 16;
  bp |= 0xc1 << 4;
  printf("%#018x\n", bp);
  bit_pattern(bp);

  return 0;
}
