
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

void fit_the_first(void);
void fit_the_second(void);

int main() {
  std::cout << "060-ReverseIteration\n";
  std::cout << "C++ Version: " << __cplusplus << '\n' << std::endl;

  fit_the_first();
  fit_the_second();

  return 0;
}

void fit_the_first(void) {
  std::cout << "In: " << __func__ << '\n';
  std::cout << std::string(80, '=') << '\n';
  
  //  given an array like this:
  int things[] { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, };
  auto things_e = sizeof(things) / sizeof(*things);

  //  display the contents
  std::for_each(std::begin(things), std::end(things), [](auto nr) {
    std::cout << nr << ' ';
  });
  std::cout << '\n';

  //  display the contents in reverse order
  std::for_each(std::rbegin(things), std::rend(things), [](auto nr) {
    std::cout << nr << ' ';
  });
  std::cout << '\n';

  //  ditto, using a reverse iterator
  for (auto nr = std::rbegin(things); nr != std::rend(things); ++nr) {
    std::cout << *nr << ' ';
  }
  std::cout << '\n';

  //  and again the C way
  for (auto nr = things_e; nr-- != 0; ) {
    std::cout << things[nr] << ' ';
  }
  std::cout << '\n';

  std::cout << std::endl;

  return;
}

void fit_the_second(void) {
  std::cout << "In: " << __func__ << '\n';
  std::cout << std::string(80, '=') << '\n';

  //  using a C++ array
  auto things = std::array { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, };
  auto things_e = things.size();

  //  display the contents
  std::for_each(things.begin(), things.end(), [](auto nr) {
    std::cout << nr << ' ';
  });
  std::cout << '\n';

  //  display the contents in reverse order
  std::for_each(things.rbegin(), things.rend(), [](auto nr) {
    std::cout << nr << ' ';
  });
  std::cout << '\n';

  //  ditto, using a reverse iterator
  for (auto nr = things.rbegin(); nr != things.rend(); ++nr) {
    std::cout << *nr << ' ';
  }
  std::cout << '\n';

  //  and again the C way
  for (auto nr = things_e; nr-- != 0; ) {
    std::cout << things[nr] << ' ';
  }
  std::cout << '\n';

  std::cout << std::endl;

  return;
}
