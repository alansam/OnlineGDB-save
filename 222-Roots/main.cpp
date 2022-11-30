
#include <iostream>
#include <iomanip>
#include <cmath>

#define RANGED_ /* define this to use a ranged loop over literal list */

static
auto constexpr WFSZ { 12 };
static
auto constexpr WISZ { 4 };
static
auto constexpr DLMSZ { 60 };
static
auto constexpr DLM { '-' };

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "Roots:\n";
  auto nrs = { 5.0, 7.0, 9.0, 11.0, 16.0, 27.0, };
  std::cout << std::fixed;

  for (auto root { 0.0 }; auto nr : nrs) {
    //  square and cube roots.
    std::cout << std::string(DLMSZ, DLM) << '\n';
    root = std::sqrt(nr);
    std::cout << "square root of "
              << std::setw(WFSZ) << nr << " = "
              << std::setw(WFSZ) << root << " [sqrt]" << '\n';
    root = std::pow(nr, 1. / 2);
    std::cout << "square root of "
              << std::setw(WFSZ) << nr << " = "
              << std::setw(WFSZ) << root << " [pow]" << '\n';
    root = std::cbrt(nr);
    std::cout << "  cube root of "
              << std::setw(WFSZ) << nr << " = "
              << std::setw(WFSZ) << root << " [cbrt]" << '\n';
    root = ::pow(nr, 1. / 3);
    std::cout << "  cube root of "
              << std::setw(WFSZ) << nr << " = "
              << std::setw(WFSZ) << root << " [pow]" << '\n';

    //  other roots (4th through 12th).
#ifndef RANGED_
    //  loop over fixed range.
    for (auto divi { 4 }; divi <= 12; ++divi) {
#else
    //  ranged loop with literal list.
    for (auto divi : { 4, 5, 7, 9, 12, 13, 17, 256, 1000, }) {
#endif
      root = std::pow(nr, 1. / divi);
      std::cout << std::setw(WISZ) << divi << "th root of "
                << std::setw(WFSZ) << nr << " = "
                << std::setw(WFSZ) << root << " [pow]" << '\n';
    }

    std::cout << std::endl;
  }

  return 0;
}


