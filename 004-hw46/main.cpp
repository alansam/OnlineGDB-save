// Example program
//  @see: http://cpp.sh/2ukm4
#include <iostream>
#include <string>

template<typename T>
void add(T const & addend1, T const & addend2, T & sum) {
  sum = addend1 + addend2;
  return;
}

int main() {
  int ai1, ai2, sumi;
  ai1 = 33;
  ai2 = 44;
  add(ai1, ai2, sumi);
  std::cout << "sum of " << ai1 << " and " << ai2 << " is " << sumi << std::endl;

  double ad1, ad2, sumd;
  ad1 = 33.3;
  ad2 = 44.4;
  add(ad1, ad2, sumd);
  std::cout << "sum of " << ad1 << " and " << ad2 << " is " << sumd << std::endl;

  std::string as1, as2, sums;
  as1 = "33.3";
  as2 = "44.4";
  add(as1, as2, sums);
  std::cout << "sum of " << as1 << " and " << as2 << " is " << sums << std::endl;

  char ac1, ac2, sumc;
  ac1 = 'G';
  ac2 = '!';
  add(ac1, ac2, sumc);
  std::cout << "sum of " << ac1 << " and " << ac2 << " is " << sumc << std::endl;

  return 0;
}

