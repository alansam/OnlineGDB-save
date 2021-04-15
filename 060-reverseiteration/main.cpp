
#include <iostream>
#include <algorithm>

int main()
{
  int things[] { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, };
  auto things_e = sizeof(things) / sizeof(*things);

  std::for_each(std::begin(things), std::end(things), [](auto nr) {
    std::cout << nr << ' ';
  });
  std::cout << '\n';

  std::for_each(std::rbegin(things), std::rend(things), [](auto nr) {
    std::cout << nr << ' ';
  });
  std::cout << '\n';

  for (auto nr = std::rbegin(things); nr != std::rend(things); ++nr) {
    std::cout << *nr << ' ';
  }
  std::cout << '\n';

  for (auto nr = things_e; nr-- != 0; ) {
    std::cout << things[nr] << ' ';
  }
  std::cout << '\n';

  return 0;
}
