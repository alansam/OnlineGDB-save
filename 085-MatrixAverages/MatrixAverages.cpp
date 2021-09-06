
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

auto constexpr ELMTS = 10ull;
auto constexpr LoVal = -5.0;
auto constexpr HiVal = 5.0;

inline
double randLoToHi(double const LO, double const HI) {
  return LO + static_cast<double>(random()) / (static_cast<double>(RAND_MAX / (HI - LO)));
}

int main() {
  std::cout << "C++ Version: " << __cplusplus << "\n\n";

  auto display = [](auto & arrayA) {
    for (auto & row : arrayA) {
      for (auto el : row) {
        std::cout << std::fixed << std::setw(10) << el;
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  };

  auto collect = [](auto & arrayA) {
    auto vec = std::vector<double>();
    for (auto & row : arrayA) {
      for (auto el : row) {
        vec.push_back(el);
      }
    }
    return vec;
  };

  auto arrayA = std::array<std::array<double, ELMTS>, ELMTS>();
  std::cout << arrayA.size() << '\n';
  std::cout << arrayA[0].size() << '\n';

  for (auto & row : arrayA) {
    for (size_t el { 0 }; el < ELMTS; ++el) {
      auto rv = randLoToHi(LoVal, HiVal);
      row.at(el) = rv;
    }
  }

  display(arrayA);
  
  auto clct = collect(arrayA);
  auto const & [min, max] = std::minmax_element(clct.cbegin(), clct.cend());
  std::cout << "Min: " << std::setw(10) << std::fixed << *min
            << ", max: " << std::setw(10) << std::fixed << *max
            << '\n';

  auto sum = 0.0;
  for (size_t el { 0 }; el < ELMTS; ++el) {
    auto val = arrayA.at(el).at(el);
    sum += val;
    std::cout << std::setw(10) << std::fixed << val << '\n';
  }
  std::cout << '\n' << std::setw(10) << std::fixed << sum << '\n';
  std::cout << std::endl;

  std::cout << "Average of diagonal: "
            << std::setw(10) << std::fixed << sum / static_cast<double>(ELMTS) << '\n';
  std::cout << std::endl;

  auto elm = 0ull;
  sum = 0.0;
  for (size_t r_ { 0 }; r_ < ELMTS; ++r_) {
    for (size_t c_ { 0 }; c_ <= r_; ++c_) {
      elm++;
      auto val = arrayA.at(r_).at(c_);
      sum += val;
      std::cout << std::setw(10) << std::fixed << val;
    }
    std::cout << std::endl;
  }
  std::cout << '\n' << std::setw(10) << std::fixed << sum
            << std::setw(10) << std::fixed << elm << '\n';
  std::cout << std::endl;
  std::cout << "Average under diagonal: "
            << std::setw(10) << std::fixed << sum / static_cast<double>(elm) << '\n';
  std::cout << std::endl;

  return 0;
}
