
#include <stdio.h>
#include <stdint.h>

void left_shifts(uint64_t nr, size_t shft);
void right_shifts(uint64_t nr, size_t shft);

int main() {
  putchar('\n');

  puts("ripple 1 bit through a double-word");
  uint64_t nr = 0x01ull;
  left_shifts(nr, 64ull);

  nr = 0x01ull << 63;
  right_shifts(nr, 64ull);

  puts("ripple 2 evenly spaced bits through two words");
  nr = 0x01ull << 32;
  nr |= 0x01ull;
  left_shifts(nr, 32ull);

  nr = 0x01ull << 63;
  nr |= 0x80000000ull;
  right_shifts(nr, 32ull);

  puts("ripple 4 evenly spaced bits through four half-word");
  nr   = 0x01ull << 16;
  nr  |= 0x01ull;
  nr <<= 16;
  nr  |= 0x01ull;
  nr <<= 16;
  nr  |= 0x01ull;
  left_shifts(nr, 16ull);

  nr   = 0x01ull << 16;
  nr  |= 0x01ull;
  nr <<= 16;
  nr  |= 0x01ull;
  nr <<= 16;
  nr  |= 0x01ull;
  nr <<= 15;
  right_shifts(nr, 16ull);

  puts("ripple 8 evenly spaced bits through eight bytes");
  nr   = 0x01ull << 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  left_shifts(nr, 8ull);

  nr   = 0x01ull << 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 8;
  nr  |= 0x01ull;
  nr <<= 7;
  right_shifts(nr, 8ull);

  return 0;
}

void left_shifts(uint64_t nr, size_t shft) {
  for (size_t b_ = 0; b_ < shft; ++b_) {
    printf("%4zu: %016lx\n", b_, nr);
    nr <<= 1;
  }
  putchar('\n');
}

void right_shifts(uint64_t nr, size_t shft) {
  for (ssize_t b_ = shft - 1; b_ >= 0; --b_) {
    printf("%4zu: %016lx\n", b_, nr);
    nr >>= 1;
  }
  putchar('\n');
}

