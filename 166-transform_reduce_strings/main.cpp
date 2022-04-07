
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std::literals::string_literals;

int main() {
  auto s1 = "a string"s;
  auto s2 = ""s;
  auto ef = [](auto & ss) {
    return ss.empty() ? "is empty"s : "is not empty"s;
  };

  std::cout << "String 1: " << std::quoted(s1) << ' ' << ef(s1) << '\n';
  std::cout << "String 2: " << std::quoted(s2) << ' ' << ef(s2) << '\n';

  std::cout << "\nVector of strings:\n"s;
  auto v1 = std::vector<std::string> {
    "String 01"s,
    "String 01 String 02"s,
    "String 01 String 02 String 03"s,
    "String 01 String 02 String 03 String 04"s,
    "String 01 String 02 String 03 String 04 String 05"s,
    "String 01 String 02 String 03 String 04 String 05 String 06"s,
    ""s,
  };

  //  range-based for loop
  auto lc { 0ul };
  auto sm { 0ul };
  for (auto const & str : v1) {
    std::cout << std::setw(2) << ++lc << ": "s << std::setw(3) << str.size() << ", "s << std::quoted(str) << '\n';
    sm += str.size();
  }
  std::cout.put('\n');

  std::cout << "\nCalculate average string lengths:\n"s;
  std::cout << std::setw(30) << "range-based for loop: "s << sm / v1.size() << '\n';

  auto avg { 0ul };
  std::for_each(v1.cbegin(), v1.cend(), [&](auto const & col) {
    avg += col.size();
  });
  avg /= v1.size();
  std::cout << std::setw(30) << "std::for_each: "s << avg << '\n';

  //  std::accumulate()
  auto acc = std::accumulate(v1.cbegin(), v1.cend(), ""s, [](auto const & lhs, auto const & rhs) {
    return std::string(lhs.size() + rhs.size(), '~');
  });
  std::cout << std::setw(30) << "std::accumulate: "s << acc.size() / v1.size() << '\n';

  //  std::reduce()
  auto red = std::reduce(v1.cbegin(), v1.cend(), ""s, [](auto const & lhs, auto const & rhs) {
    return std::string(lhs.size() + rhs.size(), '~');
  });
  std::cout << std::setw(30) << "std::reduce: "s << red.size() / v1.size() << '\n';

  //  std::transform_reduce()
  auto trd = std::transform_reduce(v1.cbegin(), v1.cend(), 0, std::plus<>(), [](auto const & lhs) {
    return lhs.size();
  });
  std::cout << std::setw(30) << "std::transform_reduce: "s << trd / v1.size() << '\n';

  return 0;
}

