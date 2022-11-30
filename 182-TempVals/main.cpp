
#include <iostream>
#include <iomanip>

int main() {
  double dval { 1024 };
  int const & r = dval;
  std::cout << std::fixed << dval << std::endl;
  std::cout << std::fixed << r << std::endl;

  auto * rp { &r };
  std::cout << rp << ' ' << sizeof(r) << '\n';

  union du {
    double dd;
    uint8_t cd[8];
  };
  du dox { dval, };
  for (auto i_ { 0ul }; i_ < sizeof(dval); ++i_) {
    printf("%02x", dox.cd[i_]);
  }
  std::cout.put('\n');
  dox.dd = r;
  for (auto i_ { 0ul }; i_ < sizeof(dval); ++i_) {
    printf("%02x", dox.cd[i_]);
  }
  std::cout.put('\n');

  printf("%p: %016x %0.3f\n", static_cast<void *>(&dval), static_cast<uint32_t>(dval), dval);
  printf("%p: %016x %d\n", static_cast<void const *>(&r), r, r);

  std::cout.put('\n');

  return 0;
}
