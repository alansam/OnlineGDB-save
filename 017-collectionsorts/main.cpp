
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

int main() {

  std::cout << "std::array" << std::endl;

  std::array<std::string, 3> list { "people", "animals", "places", };
  for (auto const & str : list) { std::cout << str << " "; }
  std::cout << std::endl;
  std::sort(list.begin(), list.end());
  for (auto const & str : list) { std::cout << str << " "; }
  std::cout << std::endl;
  std::reverse_copy(list.begin(), list.end(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  std::cout << "std::list" << std::endl;

  std::list<std::string> array { "tree people", "tree animals", "tree places", };
  for (auto const & str : array) { std::cout << str << " "; }
  std::cout << std::endl;
  array.sort();
  for (auto const & str : array) { std::cout << str << " "; }
  std::cout << std::endl;
  std::reverse_copy(array.begin(), array.end(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  std::cout << "std::vector" << std::endl;
  
  std::vector<std::string> victor { "vic people", "vic animals", "vic places", };
  for (auto const & str : victor) { std::cout << str << " "; }
  std::cout << std::endl;
  std::sort(victor.begin(), victor.end());
  for (auto const & str : victor) { std::cout << str << " "; }
  std::cout << std::endl;
  std::reverse_copy(victor.begin(), victor.end(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
  
  return 0;
}
