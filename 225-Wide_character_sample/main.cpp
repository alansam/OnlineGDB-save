//  @see: https://stackoverflow.com/questions/12015571/how-to-print-unicode-character-in-c
//  @see: https://stackoverflow.com/questions/16944750/c-unicode-characters-printing

#include <iostream>
#include <iomanip>
#include <string>
#include <codecvt>

int main(int argc, char const * argv[]) {
  std::cout << "Hello World\nф\n\u0444\n\n";
  char16_t fe = u'\u0444';
  std::string sfe = "\u0444";
  std::cout << std::hex
            << std::setfill('0')
            << std::setw(4)
            << fe
            << std::setfill(' ')
            << std::dec
            << '\n'
            << '\n';
  std::cout << sfe << '\n' << '\n';
  std::printf("%04x\n", (char16_t) fe);

  auto afe = sfe.c_str();
  auto fsz = sfe.size();
  for (size_t f_ { 0ul }; f_ < fsz; ++f_) {
    std::printf("%#02x ", (uint8_t) afe[f_]);
  }
  std::cout.put('\n');

  char xfe[] = "\u0444";
  [[maybe_unused]]
  auto xfesz = sizeof xfe / sizeof *xfe;
  std::cout << '\n' << xfe << '\n' << '\n';
  for (size_t f_ { 0ul }; f_ < xfesz && xfe[f_] != '\0'; ++f_) {
    printf("%#02x ", (char8_t) xfe[f_]);
  }
  std::cout.put('\n');
  std::cout.put('\n');

  char32_t base = U'\u2780';

  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
  std::string sbase = convert.to_bytes(base + 5);
  std::cout << std::hex
            << std::setfill('0')
            << std::setw(8)
            << base
            << std::setfill(' ')
            << std::dec
            << '\n';
  for (size_t f_ { 0ul }; sbase[f_] != '\0'; ++f_) {
    printf("%#02x ", (char8_t) sbase[f_]);
  }
  std::cout.put('\n');
  std::cout << sbase << '\n';

  return 0;
}
