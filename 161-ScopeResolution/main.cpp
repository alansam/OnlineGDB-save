
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std::literals::string_literals;

auto const data { "2 3\n"s
                  "Hermis 6 1 2\n"s
                  "Hera   2 6 6\n"s
                };

//  getline in global scopee
std::istream & getline(std::istream & input, std::string & str, char delim = '\n') {
  std::cout << "Hello from ::" << __func__ << '\n';
  return input;
}

namespace fbcxx {
  //  getline in namespace fbcxx
  std::istream & getline(std::istream & input, std::string & str, char delim = '\n') {
    std::cout << "Hello from fbcxx::" << __func__ << '\n';
    return input;
  }

  //  use the getline() function defined in global scope
  std::istream & getline_global(std::istream & input, std::string & str, char delim = '\n') {
    std::cout << "Hello from fbcxx::" << __func__ << '\n';
    return ::getline(input, str, delim);
  }
}

int main(int argc, char const * argv[]) {
  auto strin { std::stringstream(data) };
  auto line { ""s };
  std::cout << "Use std::getline\n";
  while (std::getline(strin, line)) {
    std::cout << line << '\n';
  }
  std::cout << std::endl;

  fbcxx::getline(std::cin, line);
  std::cout << std::endl;

  getline(std::cin, line);
  std::cout << std::endl;

  fbcxx::getline_global(std::cin, line);
  std::cout << std::endl;

  return 0;
}
