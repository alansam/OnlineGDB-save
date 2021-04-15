
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

template<typename T>
auto vsum(std::vector<T> things, T start) {
  auto sum = std::accumulate(things.cbegin(), things.cend(), start, std::plus<>());
  return sum;
}

auto main(int argc, char const * argv[]) -> decltype(argc) {
  std::vector<double> vd { 1.0, 503.6, 42.222, -556.765, 432.11, };
  std::vector<long long> vL { 1LL, 503LL, 42LL, -556LL, 432LL, };
  std::vector<std::string> vs { "1~", "503~", "42~", "-556~", "432~", };

  std::cout << vsum<double>(vd, 0.0) << std::endl;
  std::cout << vsum<long long>(vL, 0LL) << std::endl;
  std::cout << vsum<std::string>(vs, "~") << std::endl;

  return 0;
}
