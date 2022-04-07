
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

int addlastN(int nr, size_t);

int main() {

  struct sdata {
    int nr;
    int check;
    int digits;
  };
  
  auto sds = std::vector<sdata> {
    { 21013789,         7 + 8 + 9, 3, },
    { 21013789,     3 + 7 + 8 + 9, 4, },
    { 21013789, 1 + 3 + 7 + 8 + 9, 5, },
    {     9999,     9 + 9 + 9 + 9, 4, },
    {      999,         9 + 9 + 9, 3, },
    {       99,            9 + 9,  2, },
    {        9,                 9, 1, },
    {     8888,     8 + 8 + 8 + 8, 4, },
    {     8888,     8 + 8 + 8 + 8, 5, },
    {     8888,                 8, 1, },
    {     8888,                 0, 0, },
  };

  for (auto sd : sds) {
    std::cout << std::setw(10) << sd.nr << ',' << std::setw(3) << sd.digits << '\n'
              << std::setw(10) << sd.check << '\n'
              << std::setw(10) << addlastN(sd.nr, sd.digits) << '\n'
              << std::endl;
  }

  return 0;
}

int addlastN(int nr, size_t last) {
  auto sum { 0 };
  nr = abs(nr);
  size_t p10 = pow(10, last - 1);
  if (nr > p10) {
    for (size_t n_ { 0 }; n_ < last; ++n_) {
      sum += nr % 10;
      nr  /= 10;
    }
  }
  else {
    sum = -1;
  }

  return sum;
}

