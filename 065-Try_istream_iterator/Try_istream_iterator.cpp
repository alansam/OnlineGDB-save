
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

using namespace std::literals::string_literals;

static
std::string const fname { "./texts"s };

int main() {
  try {
    auto ifs = std::ifstream(fname);
    if (!ifs.is_open()) {
      auto ers = std::ostringstream();
      ers << "error: failed to open "s << fname;
      throw std::runtime_error(ers.str());
    }
    else {
      auto strings = std::vector<std::string>();
      auto isi = std::istream_iterator<std::string>(ifs);
      auto end = std::istream_iterator<std::string>();
      while (isi != end) {
        strings.push_back(*isi++);
      }
  
      ifs.close();
  
      std::for_each(strings.cbegin(), strings.cend(), [el = 0](auto const & str) mutable {
        std::cout << std::setw(3) << el++ << ": "s << str << '\n';
      });
      std::cout << std::endl;
    }
  }
  catch (std::exception & ex) {
    std::cerr << ex.what() << std::endl;
  }

  return 0;
}
