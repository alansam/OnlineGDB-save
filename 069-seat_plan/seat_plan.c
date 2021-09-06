
#include <stdio.h>
#include <stdint.h>

int main() {
  uint8_t const seatidx[] = { 0x08, 0x04, 0x02, 0x01, };
  size_t const seatidx_sz = sizeof(seatidx) / sizeof(*seatidx);

  char const seat[] = { 'a', 'b', 'c', 'd', };

  uint8_t seats[5] = { 0, };
  seats[0] = seats[0] | seatidx[0];
  seats[1] = seats[1] | seatidx[1];
  seats[2] = seats[2] | seatidx[2];
  seats[4] = seats[4] | seatidx[3];
  putchar('\n');

  for (size_t x_ = 0; x_ < 5; ++x_) {
    printf("%zu  : ", x_ + 1);
    for (size_t s_ = 0; s_ < seatidx_sz; ++s_) {
      if (seats[x_] & seatidx[s_]) {
        printf("%4c", 'X');
      }
      else {
        printf("%4c", seat[s_]);
      }
    }
    putchar('\n');
  }
  putchar('\n');

  return 0;
}
