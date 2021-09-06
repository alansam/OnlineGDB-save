
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>

void adding(size_t const nr, int const myArrays[]);

/*
 *  Template for summing two elements
 */
template <class T>
void adding(T & myArrays) {
 for (size_t i_ { 0 }; i_ < myArrays.size() - 1; ++i_) {
    std::cout << myArrays[i_] + myArrays[i_ + 1] << ' ';
 }
  std::cout << std::endl;
}

/*
 *  MARK: main()
 */
int main() {
  int myArray[] { 1, 2, 3, 4, 5, };
  size_t const myArray_e = sizeof(myArray) / sizeof(*myArray);
  auto sary = std::array<int, 5> { 1, 2, 3, 4, 5, };
  auto svec = std::vector<int> { 1, 2, 3, 4, 5, };

  std::cout << "Function (1, array)\n";
  adding(myArray_e, myArray);
  std::cout  << std::endl;

  std::cout << "Function (2, std::array)\n";
  adding(sary.size(), sary.data());
  std::cout  << std::endl;

  std::cout << "Function (3, std::vector)\n";
  adding(svec.size(), svec.data());
  std::cout  << std::endl;

  std::cout << "Template (1, std::array)\n";
  adding(sary);
  std::cout << std::endl;

  std::cout << "Template (2, std::vector)\n";
  adding(svec);
  std::cout << std::endl;

  /*
   *  Λ - Lambda for summing two elements - λ
   */
  auto ladding = [](auto & container) {
    for (size_t i_ { 0 }; i_ < container.size() - 1; ++i_) {
      std::cout << container[i_] + container[i_ + 1] << ' ';
    }
    std::cout << std::endl;
  };

  std::cout << "Λ (1, std::array)\n";
  ladding(sary);
  std::cout << std::endl;

  std::cout << "λ (2, std::vector)\n";
  ladding(svec);
  std::cout << std::endl;

  std::cout << "std::transform (1, std::array)\n";
  std::transform(sary.cbegin() + 1, sary.cend(),
                 sary.cbegin(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](auto lhs, auto rhs) { return lhs + rhs; });
  std::cout << '\n' << std::endl;

  std::cout << "std::transform (2, std::vector)\n";
  std::transform(svec.cbegin() + 1, svec.cend(),
                 svec.cbegin(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](auto lhs, auto rhs) { return lhs + rhs; });
  std::cout << '\n' << std::endl;

  return 0;
}

/*
 *  MARK: adding()
 */
void adding(size_t const nr, int const myArrays[]) {
  for (size_t i { 0 }; i < nr - 1; i++) {
    std::cout << myArrays[i] + myArrays[i + 1] << ' ';
  }
  std::cout  << std::endl;
}
