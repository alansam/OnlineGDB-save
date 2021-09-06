
#include <stdio.h>

typedef union mix mix;
union mix {
  char chars[4][sizeof(int)];
  int ints[4];
};

int main() {
  mix mixer;
  mixer.ints[0] = 6;
  mixer.ints[1] = 4 <<  8;
  mixer.ints[2] = 8 << 16;
  mixer.ints[3] = 9 << 24;

  for (size_t i_ = 0; i_ < 4; ++i_) {
    printf("%p: %08x\n",
           &mixer.ints[i_],
            mixer.ints[i_]);

    printf("%p: %02x-%02x-%02x-%02x\n",
           mixer.chars[i_],
           mixer.chars[i_][0],
           mixer.chars[i_][1],
           mixer.chars[i_][2],
           mixer.chars[i_][3]);
  }
  putchar('\n');

  char chars[4][sizeof(int)];
  int * inty;
  inty = (int *) chars[0];
  *inty = 6;
  inty++;
  *inty = 4; /* chars[1] */
  inty++;
  *inty = 8; /* chars[2] */
  inty++;
  *inty = 9; /* chars[3] */

  printf("%p: %2d\n", chars[0], chars[0][0]);
  printf("%p: %2d\n", chars[1], chars[1][0]);
  printf("%p: %2d\n", chars[2], chars[2][0]);
  printf("%p: %2d\n", chars[3], chars[3][0]);

  for (size_t i_ = 0; i_ < 4; ++i_) {
    printf("%p: %02x-%02x-%02x-%02x\n",
           chars[i_],
           chars[i_][0],
           chars[i_][1],
           chars[i_][2],
           chars[i_][3]);
  }
  putchar('\n');

  return 0;
}
