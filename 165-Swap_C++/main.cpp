
#include <iostream>
#include <iomanip>

void swap(int is, int js) {
  int ts = is;
  is = js;
  js = ts;
}

void swapr(int & is, int & js) {
  int ts = is;
  is = js;
  js = ts;
}

void swapp(int * is, int * js) {
  int ts = *is;
  *is = *js;
  *js = ts;
}

int main() {
  std::cout << "Swapper - call-by-reference" << std::endl;

  int i1, j1;
  i1 = 5;
  j1 = 11;

  std::cout << "I: " << std::setw(2) << i1 <<" J: " << std::setw(2) << j1 << '\n';
  swap(i1, j1);
  std::cout << "I: " << std::setw(2) << i1 <<" J: " << std::setw(2) << j1 << '\n';
  swapr(i1, j1);
  std::cout << "I: " << std::setw(2) << i1 <<" J: " << std::setw(2) << j1 << '\n';
  swapp(&i1, &j1);
  std::cout << "I: " << std::setw(2) << i1 <<" J: " << std::setw(2) << j1 << '\n';

  return 0;
}

