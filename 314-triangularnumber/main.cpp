// @see: https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_⋯
// @see: https://en.wikipedia.org/wiki/Triangular_number
//  (triangular number)
// partial sum of series 1 + 2 + 3 + ...:
// ∑ (k = 1 to n) k = n(n + 1) / 2

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std::literals::string_literals;

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  auto v100 = std::vector<int>(100);

  std::cout << std::string(80, '-') << '\n';
  std::cout << "vector size:"s
            << std::setw(5) << v100.size() << '\n';

  std::cout << "vector contents:\n"s;
  std::iota(v100.begin(), v100.end(), 1);
  auto cc = 1ul;
  std::for_each(v100.cbegin(), v100.cend(), [&cc](auto const & v_) {
    std::cout << std::setw(4) << v_ << (cc++ % 20ul == 0 ? "\n"s : ""s);
  });
  std::cout << std::endl;

  std::cout << std::string(80, '-') << '\n';
  auto sum = std::accumulate(v100.cbegin(), v100.cend(), 0);
  std::cout << "sum via accumulation:"s
            << std::setw(5) << sum << '\n' << std::endl;

  std::cout << std::string(80, '-') << '\n';
  std::cout << "sum via iteration\n"s;
  std::cout << "   n  sum\n"s;
  std::cout << " --- ----\n"s;
  sum = 0;
  for (auto el : v100) {
    sum += el;
    std::cout << std::setw(4) << el << std::setw(5) << sum << '\n';
  }
  std::cout << std::endl;

  std::cout << std::string(80, '-') << '\n';
  // @see: https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_⋯
  // partial sum of series 1 + 2 + 3 + ... from 1 to 100:
  std::cout << "partial sum via iteration\n"s;
  std::cout << " ∑ (k = 1 to n) k = n(n + 1) / 2\n"s;
  int k_ = 0;
  std::cout << "   n    k\n"s;
  std::cout << " --- ----\n"s;
  for (int n_ = 1; n_ <= 100; ++n_) {
    k_ = n_ * (n_ + 1) / 2;
    std::cout << std::setw(4) << n_ << std::setw(5) << k_ << '\n';
  }
  std::cout << '\n' << std::endl;

  std::cout << std::string(80, '-') << '\n';
  std::cout << "triangular number - partial sum algorithmically\n"s;
  std::cout << " ∑ (k = 1 to n) k = n(n + 1) / 2\n"s;
  std::cout << "   n    k\n"s;
  std::cout << " --- ----\n"s;
  std::for_each(v100.cbegin(), v100.cend(), [](auto const & n_) {
    auto k_ = n_ * (n_ + 1) / 2;
    std::cout << std::setw(4) << n_ << std::setw(5) << k_ << '\n';
  });
  std::cout << '\n' << std::endl;

  std::cout << std::string(80, '-') << '\n';
  std::cout << "series - partial sum algorithmically\n"s;
  std::cout << " ∑ (j = 1 to n) j = n * n           [1\u00b2 + 2\u00b2 + 3\u00b2 + ... +  + n\u00b2]\n"s;
  std::cout << " ∑ (k = 1 to n) k = n * (n + 1) / 2 [1 + 2 + 3 + ... + n]\n"s;
  std::cout << " ∑ (l = 1 to n) l = n * (n + 1)     [(1+1) + (2+2) + (3+3) + ... + (n+n)]\n"s;
  std::cout << " ∑ (m = 1 to n) m = n * n / 2       [?]\n"s;
  std::cout << "   n     j     k     l     m\n"s;
  std::cout << " --- ----- ----- ----- -----\n"s;
  std::for_each(v100.cbegin(), v100.cend(), [](auto const & n_) {
    auto j_ = n_ * n_;
    auto k_ = n_ * (n_ + 1) / 2;
    auto l_ = n_ * (n_ + 1);
    auto m_ = n_ * n_ / 2;
    std::cout << std::setw(4) << n_
              << std::setw(6) << j_
              << std::setw(6) << k_
              << std::setw(6) << l_
              << std::setw(6) << m_
              << '\n';
  });
  std::cout << '\n' << std::endl;
  
  return 0;
}
