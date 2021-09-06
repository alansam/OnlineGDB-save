
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>

int main() {
  auto it = std::find_if(std::istream_iterator<int>(std::cin),
                         std::istream_iterator<int>(),
                         [](int i){ return i % 2 == 0; });
  if (it != std::istream_iterator<int>()) {
    std::cout << "\nThe first even number is " << *it << ".\n";
  }

  return 0;
}
