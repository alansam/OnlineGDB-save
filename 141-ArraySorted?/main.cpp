
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>

int main() {
  int32_t arry1[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
  int32_t arry2[] { 9, 8, 7, 6, 5, 4, 2, 2, 1, 0, };
  int32_t arry3[] { 4, 2, 2, 1, 0, 5, 9, 8, 7, 6, };

  auto fn = [](auto const & ary) -> int32_t {
    auto tf = 0;
    auto sa = std::is_sorted(std::begin(ary), std::end(ary));
    auto sd = std::is_sorted(std::rbegin(ary), std::rend(ary));
    tf = sa ? 1 : sd ? -1 : 0;
    return tf;
  };

  for (auto const st : { fn(arry1), fn(arry2), fn(arry3), }) {
    if (st > 0) {
      std::cout << "Array is sorted ascending\n";
    }
    else if (st < 0) {
      std::cout << "Array is sorted decending\n";
    }
    else {
      std::cout << "Array is not sorted\n";
    }
  }

  return 0;
}

