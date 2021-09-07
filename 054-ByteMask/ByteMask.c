
#include <stdio.h>
#include <stdint.h>

uint8_t * print(size_t len, uint8_t * data) {
  for (size_t i_ = 0; i_ < len; ++i_) {
    printf("%02x", data[i_]);
  }
  putchar('\n');
}

uint8_t * mask(size_t len, uint8_t * data, size_t pick) {
  size_t fix = len - pick > 4 ? 4 : len - pick;
  uint8_t * here = data + pick;
  for (size_t p_ = 0; p_ < fix; ++p_) {
    *here = 0x00;
    here++;
  }
  return data;
}

int main() {
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }; 
  size_t const data_s = sizeof(data) / sizeof(*data);
  print(data_s, data);
  mask(data_s, data, 1);
  print(data_s, data);
  mask(data_s, data, 8);
  print(data_s, data);

  return 0;
}
