
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>

static
inline
void snap(size_t sz, void const * gaz) {
  uint8_t * gaz_p = (uint8_t *) gaz;
  printf("base address: %p, size: %zu\n", gaz, sz);
  for (size_t x_ = 0ul, cc = 0ul; x_ < sz; ++x_) {
    printf("%02x%s", *gaz_p++,
           (++cc % 16 == 0 ? "\n" : (cc % 8 == 0 ? "   " : " ")));
  }
}

int main() {
  char aa { 0x61 };
  std::cout << std::setw(5) << static_cast<int16_t>(aa) << std::endl;
  aa <<= 1;
  std::cout << std::setw(5) << static_cast<int16_t>(aa) << std::endl;

  std::string u_00ae = "\u00ae";
  std::cout << "Valor " << u_00ae << '\n';

  std::ostringstream oss;
  oss << "Valor " << u_00ae << " victor" << std::ends;
  std::cout << oss.str() << ": " << oss.str().size() << std::endl;
  snap(oss.str().size(), oss.str().data());

  std::cout << "\n\nUnicode, Code points U+0080 to U+00FF\n";
  std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
  for (int16_t u = 0x80, lb = 0; u <= 0xff; ++u) {
    std::u16string utf16 = converter.from_bytes(u);
    std::wcout << utf16 << '\n';
  }

  return 0;
}
