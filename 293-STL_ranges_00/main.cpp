//  Compiler flags: -Wall -Wpedantic -Werror=vla -std=gnu++23

#include <iostream>
#include <iomanip>
#include <ranges>

int main() {
  std::cout << "C++ version " << __cplusplus << '\n' << '\n';

  auto constexpr even = [](auto v) { return v % 2 == 0; };
  for (auto const & it : std::ranges::views::iota(2, 31)
                       | std::ranges::views::filter(even)) {
    auto x = it;

    std::cout << std::setw(19) << "x =" << std::setw(4) << x << '\n';

    std::cout << std::fixed << std::setprecision(3);

    //  8 ÷ x(x + x)
    auto rv0 = 8. / (x * x + x * x);
    std::cout << std::setw(20) << "8 ÷ x(x + x) =" << std::setw(8) << rv0 << '\n';

    //  8 ÷ (2x²)
    auto rv1 = 8. / (2 * x * x);
    std::cout << std::setw(21) << "8 ÷ (2x\u00b2) =" << std::setw(8) << rv1 << '\n';

    //  8 ÷ x * (x + x)
    auto rv2 = 8. / x * (x + x);
    std::cout << std::setw(20) << "8 ÷ x * (x + x) =" << std::setw(8) << rv2 << '\n';
    std::cout << std::endl;
  }

  return 0;
}
