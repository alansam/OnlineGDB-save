#include <iostream>
#include <iomanip>
#include <bitset>

int main() {
  auto show = [](uint8_t const a, uint8_t const b) {
    std::bitset<8> aa(a);
    std::bitset<8> bb(b);
    std::cout << std::hex;
    std::cout << "0x" << static_cast<uint16_t>(a)
              << ", "
              << "0x" << static_cast<uint16_t>(b)
              << " - ";
    std::cout << std::dec;
    std::cout << static_cast<uint16_t>(a)
              << ", "
              << static_cast<uint16_t>(b)
              << " - ";
    std::cout << "0b" << aa << ", "
              << "0b" << bb << '\n';
  };

  uint8_t a { 0b0010'1000 };  // 40, 0x28, 0b0010'1000
  uint8_t b { 0b0011'1100 };  // 60, 0x3c, 0b0011'1100
  show(a, b);
  a = a xor b;    // TODO: use a = a ^ b; or a ^= b;
  show(a, b);
  b = b xor a;    // TODO: use b = b ^ a; or b ^= a;
  show(b, a);
  a = a xor b;    // TODO: use a = a ^ b; or a ^= b;
  show(a, b);

  return 0;
}
