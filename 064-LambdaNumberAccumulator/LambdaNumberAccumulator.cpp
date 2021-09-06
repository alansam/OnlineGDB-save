
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <cmath>

int main(int argc, char const * argv[]) {
  auto accum = [](size_t count, size_t start) {
    std::ostringstream so;
    auto vi = std::vector<int>(count - start + 1);
    std::generate(vi.begin(), vi.end(), [nr = start]() mutable { return nr++; });
    std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(so, ", "));
    auto sum = std::accumulate(vi.cbegin(), vi.cend(), 0, std::plus<>());
    so << "sum = " << sum;
    return so.str();
  };

  std::cout << '\n';
  std::cout << accum(10, 1) << std::endl;
  std::cout << accum(30, 1) << std::endl;
  std::cout << accum(30, 10) << std::endl;
  std::cout << std::endl;

  return 0;
}

