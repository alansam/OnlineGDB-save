/*
 *  Program: StringUpperLower.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std::literals::string_literals;

// #define ARRAY_ /* Enable C style array */
#define LAMBDA_ /* Enable lambda functions */

auto constexpr LOGGING { true };  //  TODO: toggle trace log.

#ifndef LAMBDA_
//  MARK: tupp()
inline
static
auto tupp(std::string const & lc) -> std::string {
  if (LOGGING ) { std::clog << "Function "s << __func__ << "()\n"s; }
  std::string uc(lc);
  std::transform(uc.begin(), uc.end(), uc.begin(), ::toupper);
  return uc;
}

//  MARK: tlow()
inline
static
auto tlow(std::string const & lc) -> std::string {
  if (LOGGING ) { std::clog << "Function "s << __func__ << "()\n"s; }
  std::string uc(lc);
  std::transform(uc.begin(), uc.end(), uc.begin(), ::tolower);
  return uc;
}
#else
//  MARK: lambda tupp()
auto tupp = [](std::string const & lc) -> std::string {
  if (LOGGING ) { std::clog << "Lambda "s << __func__ << " tupp()\n"s; }
  std::string uc(lc);
  std::transform(uc.begin(), uc.end(), uc.begin(), ::toupper);
  return uc;
};

//  MARK: lambda tlow()
auto tlow = [](std::string const & lc) -> std::string {
  if (LOGGING ) { std::clog << "Lambda "s << __func__ << " tlow()\n"s; }
  std::string uc(lc);
  std::transform(uc.begin(), uc.end(), uc.begin(), ::tolower);
  return uc;
};
#endif /* LAMBDA_ */

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  if (LOGGING ) { std::clog << "Function "s << __func__ << "()\n"s; }
  std::cout << "StringUpperLower"s << '\n' << std::endl;

#ifdef ARRAY_
  std::string const come[] = {
    "Brcusdt"s,  "Adaust"s,
    "Dogeusdt"s, "Ltcusdt"s,
    "Galaustd"s, "Shibusdt"s,
    "Bchusdt"s,  "Solusdt"s, "Roseusdt"s,
  };
  size_t constexpr come_sz = sizeof come / sizeof *come;
#else
  std::vector<std::string> const come = {
    "Brcusdt"s,  "Adaust"s,
    "Dogeusdt"s, "Ltcusdt"s,
    "Galaustd"s, "Shibusdt"s,
    "Bchusdt"s,  "Solusdt"s, "Roseusdt"s,
  };
  size_t const come_sz { come.size() };
#endif /* ARRAY_ */

  std::cout << "Original.\n"s;
  std::cout << std::string(60, '-') << '\n';
  //  TODO: std::begin() etc. works with both std::vector and locally scoped arrays.
  std::for_each(std::cbegin(come), std::cend(come), [](auto const & s_) {
    std::cout << s_ << '\n';
  });
  std::cout << std::endl;

  std::cout << "Lower Case.\n"s;
  std::cout << std::string(60, '-') << '\n';
  //  TODO: range-based arrays work with both std::vector and locally scoped arrays.
  for (auto const & s_ : come) {
    std::cout << tlow(s_) << '\n';
  }
  std::cout << std::endl;

  std::cout << "Upper Case.\n"s;
  std::cout << std::string(60, '-') << '\n';
  for (size_t i_ = 0ul; i_ < come_sz; ++i_ ) {
    std::cout << tupp(come[i_]) << '\n';
  }
  std::cout << std::endl;

  return 0;
}
