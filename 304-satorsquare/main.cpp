/*
 *  @see: https://en.wikipedia.org/wiki/Sator_Square
 *
 *  S A T O R  -  R O T A S 
 *  A R E P O  -  O P E R A 
 *  T E N E T  -  T E N E T 
 *  O P E R A  -  A R E P O 
 *  R O T A S  -  S A T O R
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <initializer_list>
#include <algorithm>

using namespace std::literals::string_literals;

int main(int argc, char const * argv[]) {
  std::cout << "304-SatorSquare.\n"s
            << "  @see: https://en.wikipedia.org/wiki/Sator_Square\n"s
            << std::string(80, '=')
            << '\n'
            << std::endl;

  auto const sator = std::array<std::array<char, 5>, 5> {
    std::array<char, 5> { 'S', 'A', 'T', 'O', 'R', },
                        { 'A', 'R', 'E', 'P', 'O', },
                        { 'T', 'E', 'N', 'E', 'T', },
                        { 'O', 'P', 'E', 'R', 'A', },
                        { 'R', 'O', 'T', 'A', 'S', },
  };

  std::cout << "SATOR Form:\n"s
            << std::string(60, '~')
            << std::endl;
  for (auto const row : sator) {
    std::for_each(row.cbegin(), row.cend(), [](auto const ch) {
      std::cout << std::setw(2) << ch;
      });
    std::cout.put('\n');
  }
  std::cout << std::endl;

  std::cout << "ROTAS Form:\n"s
            << std::string(60, '~')
            << std::endl;
  for (auto row : sator) {
    std::reverse(row.begin(), row.end());
    std::for_each(row.cbegin(), row.cend(), [](auto const ch) {
      std::cout << std::setw(2) << ch;
      });
    std::cout.put('\n');
  }
  std::cout << std::endl;

  return 0;
}

