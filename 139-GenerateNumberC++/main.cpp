
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

#define DEBUG_

enum tens {
  T00 =           1, T01 =           10, T02 =           100, T03 =      1000, T04 =      10000,
  T05 =      100000, T06 =      1000000, T07 =      10000000, T08 = 100000000, T09 = 1000000000,
};

int32_t integer_wise(int32_t min, int32_t max, size_t len) {
  if (len > 9) {
    fprintf(stderr, "%zu is too large\n", len);
    exit(EXIT_FAILURE);
  }

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int16_t> dist(min, max);

  size_t const rn_l = len;
  auto rn = std::vector<int32_t>(len);

  int32_t acc = 0;
  for (size_t i_ = 0; i_ < rn_l; ++i_) {
    int32_t factor;
    switch (i_) {
      case  0: factor = ::tens::T00; break;
      case  1: factor = ::tens::T01; break;
      case  2: factor = ::tens::T02; break;
      case  3: factor = ::tens::T03; break;
      case  4: factor = ::tens::T04; break;
      case  5: factor = ::tens::T05; break;
      case  6: factor = ::tens::T06; break;
      case  7: factor = ::tens::T07; break;
      case  8: factor = ::tens::T08; break;
      case  9: factor = ::tens::T09; break;
    }
    rn[i_] = dist(mt) * factor;
    acc += rn[i_];
  }

#ifdef DEBUG_
  std::for_each(rn.begin(), rn.end(), [](auto const nr) {
    std::cout << std::setw(14) << nr << '\n';
  });
  std::cout << std::endl;
#endif

  int32_t nnr = std::accumulate(rn.begin(), rn.end(), 0);

  return nnr;
}

int32_t string_wise(int32_t min, int32_t max, size_t len) {
  if (len > 9) {
    fprintf(stderr, "%zu is too large\n", len);
    exit(EXIT_FAILURE);
  }

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int16_t> dist(min, max);

  auto nr_str = std::string(len, ' ');

  for (size_t n_ = 0; n_ < len; ++n_) {
    nr_str[n_] = dist(mt) | '0';
  }

#ifdef DEBUG_
  for (auto cc : nr_str) {
    std::cout << std::hex << std::setw(4) << std::setfill('0') << std::showbase << static_cast<uint16_t>(cc) << '\n';
  }
  std::cout << std::setfill(' ') << std::noshowbase << std::dec << std::endl;
#endif

  int32_t acc;
  auto iss = std::istringstream(nr_str);
  iss >> acc;

  return acc;
}

int main() {

  int32_t min = 1;
  int32_t max = 9;

  int32_t nnr;
  nnr = ::integer_wise(min, max, 9);
  std::cout << std::setw(14) << nnr << '\n';
  std::cout << std::endl;

  nnr = ::string_wise(min, max, 9);
  std::cout << std::setw(14) << nnr << '\n';
  std::cout << std::endl;

  return 0;
}

