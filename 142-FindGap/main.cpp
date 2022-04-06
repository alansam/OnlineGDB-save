
#include <iostream>
#include <iomanip>
#include <iterator>
#include <utility>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>

void find_gap00(void);
void find_gap01(void);

int main() {
  auto msgs = std::vector<std::string> {
    "ayush kumar", "roll no 9", "class 12",
  };
  std::copy(msgs.cbegin(), msgs.cend(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
  std::cout << std::endl;

  find_gap00();
  find_gap01();

  return 0;
}

void find_gap00(void) {
  std::cout << "In function: " << __func__ << std::endl;

  int const array[] = { 1, 3, 4, 2, 10, 22, 15, 9, 11, 42, 666, 0, 9, };
  size_t constexpr array_l = sizeof(array) / sizeof(*array);
  size_t const maxi = *std::max_element(std::begin(array), std::end(array));

  auto vv = std::vector<int>(maxi + 1, 0);
  std::cout << maxi << ' ' << vv.size() << '\n';
  for (auto iv : array) {
    std::cout << std::setw(4) << iv << ' ' << std::setw(4) << vv[iv] << ' ';
    vv[iv] += 1;
    std::cout << std::setw(4) << vv[iv] << '\n';
  }
  std::cout << std::endl;

#ifdef DEBUGGIT_
  auto cc_max = 10UL;
  for (auto i_ = 0UL, cc = 1UL; i_ < vv.size(); ++i_, ++cc) {
    std::cout << std::setw(4) << vv[i_] << (cc % cc_max == 0 ? "\n" : "");
  }
  std::cout << std::endl;
#endif

  size_t mx = ULONG_MAX;
  for (auto i_ = 0ul; i_ < vv.size(); ++i_) {
    if (vv[i_] == 0) {
      mx = i_;
      break;
    }
  }
  std::cout << "first gap " << std::setw(4) << mx << '\n' << std::endl;

  return;  
}

void find_gap01(void) {
  std::cout << "In function: " << __func__ << std::endl;

  int const array[] = { 1, 3, 4, 2, 10, 22, 15, 9, 11, 42, 666, 0, 9, };
  size_t constexpr array_l = sizeof(array) / sizeof(*array);
  size_t const maxi = *std::max_element(std::begin(array), std::end(array));
  std::cout << maxi << '\n';

  auto find = std::map<size_t, uint8_t>();

  for (auto iv : array) {
    find[iv] = 1;
  }

  size_t mx = ULONG_MAX;
  for (size_t i_ = 0; i_ < maxi; ++i_) {
    if (find.find(i_) == find.end()) {
      mx = i_;
      break;
    }
  }
  std::cout << "first gap " << std::setw(4) << mx << '\n' << std::endl;

  return;
}


