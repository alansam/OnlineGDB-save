
#include <iostream>
#include <iomanip>
#include <vector>
// #include <execution>
#include <algorithm>
#include <string>

using namespace std::literals::string_literals;

int main() {
  auto show = [](auto & v) {
    for (auto cc { 1ul }, cc_m { 20ul }; auto & x : v) {
      std::cout << std::setw(5) << x << ((cc++ % cc_m == 0) ? "\n"s : ""s);
    }
    std::cout.put('\n');
    std::cout.put('\n');
  };

  auto v = std::vector<int>(2000);
  auto count { 0 };

  show(v);

  std::for_each(/*std::execution::par_unseq,*/ v.begin(), v.end(), [&](auto & x) { x = ++count; });

  show(v);

  std::cout << count << std::endl;
}
