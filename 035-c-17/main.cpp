#if __cplusplus < 201700L
# error Needs C++17 or greater
#endif
#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <algorithm>
#include <iterator>

namespace a::b::c {
  inline constexpr std::string_view str { "hello" };
}

template<class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args) {
  return { sizeof ...(T), (args + ...) };
}

auto main(int argc, char const * argv[]) -> decltype(argc) {
  std::cout << "C++ " << __cplusplus << std::endl;

  auto [iNumbers, iSum] { sum(1, 2, 3) };
  std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';

  std::array ary { 1, 2, 3, };

  std::cout << std::size(ary) << ' ' << ary.size() << '\n';
  std::copy(ary.cbegin(), ary.cend(), std::ostream_iterator<decltype(1)>(std::cout, " "));

  std::cout << std::endl;

  return 0;
}

