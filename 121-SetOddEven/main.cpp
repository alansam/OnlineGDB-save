
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
  std::cout << "C++ Version: " << __cplusplus << std::endl;

  auto show = [](auto & ct) {
    for (auto vl : ct) {
      std::cout << std::setw(3) << vl;
    }
    std::cout << std::endl;
  };

  auto is_even = [] (auto val) {
    return (val % 2 == 0);
  };
  auto is_odd = [] (auto val) {
    return (val % 2 != 0);
  };

  std::set<int> s1 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
  show(s1);

  for (auto it = s1.begin(); it != s1.end(); ) {
    if (!is_even(*it)) {
      it = s1.erase(it);
    }
    else {
      it++;
    }
  }
  show(s1);

  std::cout << std::endl;

  std::set<int> s2 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
  std::set<int> sc;
  show(s2);

  std::copy_if(s2.cbegin(), s2.cend(),
               std::inserter(sc, sc.begin()),
               is_odd);
  show(sc);

  std::cout << std::endl;

#if (__cplusplus > 202001L)
  std::set<int> s3 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
  show(s3);

  std::erase_if(s3, is_even);
  show(s3);

  std::cout << std::endl;
#endif

  int a = 4;
  printf("%s %08x\n", (a ? "true" : "false"), a);
  printf("%s %08x\n", (!a ? "true" : "false"), !a);
  printf("%s %08x\n", (!!a ? "true" : "false"), !!a);
  printf("%s %08x\n", (!!!a ? "true" : "false"), !!!a);

  return 0;
}

