
#include <iostream>
#include <iomanip>

typedef void (*PFNCT)(int);
void foo(PFNCT x);
void bar(int);

void foo(PFNCT func) {
  std::cout << "In: " << __func__ << std::endl;
  func(42);
}

void bar(int val) {
  std::cout << "In: " << __func__ << std::endl;
  std::cout << val << std::endl;
}

int main() {
  PFNCT vv = bar;
  foo(vv);

  return 0;
}
