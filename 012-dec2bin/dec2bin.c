
#include <stdio.h>

unsigned char * dec2bin(unsigned, unsigned char[32]);

int main(int argc, char const * argv[]) {

  unsigned samp[] = {
    0xffffffffu, 0x80000000u, 0x00000000u, 0xf0f0f0f0u,
    42,
  };
  size_t samp_c = sizeof(samp) / sizeof(*samp);

  unsigned char * pbitties;
  for (size_t i_ = 0; i_ < samp_c; ++i_) {
    unsigned val = samp[i_];
    unsigned char bitties[32] = { 0, };
    pbitties = dec2bin(val, bitties);

    printf("%1$12u, %1$08x: ", val);
    size_t sp = 0;
    for (size_t b_ = 0; b_ < 32; ++b_) {
      printf("%01x%s", pbitties[b_], ++sp % 4 == 0 ? " " : "");
    }
    putchar('\n');
  }

  return 0;
}

unsigned char * dec2bin(unsigned val, unsigned char bitties[32]) {

  unsigned work = val;
  unsigned char * bit = &bitties[31];
  while (work != 0) {
    *bit-- = work % 2;
    work /= 2;
  }

  return bitties;
}


