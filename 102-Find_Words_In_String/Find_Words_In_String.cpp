
#if (__cplusplus < 201400L)
# error "Needs C++ 2014 or greater"
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <cstring>
#include <cctype>

using namespace std::literals::string_literals;

//  TODO: probably shouldn't use
std::string extractStringAtKey(std::string str, int key) {
  char * st = strtok(const_cast<char *>(str.c_str()), " ");
  while (key > 1) {
    st = strtok(NULL, " ");
    key--;
  }
  return std::string(st);
  // return (std::string) st;
}

std::string use_getline(std::string const str, int const key) {
  auto words = std::vector<std::string>();
  auto word = ""s;
  auto iss = std::istringstream(str);
  // std::cout << ". " << std::quoted(str) << '\n';
  while (std::getline(iss, word, ' ')) {
    // std::cout << ".. " << std::quoted(word) << '\n';
    words.push_back(word);
  }
  return words[key - 1];
}

std::vector<std::string> use_operator_shftrt(std::string const & Text) {
    std::vector<std::string> Words;
    std::stringstream ss(Text);
    std::string Buf;

    while (ss >> Buf) {
      Words.push_back(Buf);
    }

    return Words;
}

std::string use_regex(std::string const str, int const key) {
  std::regex const ws_re("\\s+"); // whitespace
  std::sregex_token_iterator wit(str.cbegin(), str.cend(), ws_re, -1);
  std::sregex_token_iterator wit_end;
  auto words = std::vector<std::string>();
  for (; wit != wit_end; ++wit) {
    words.push_back(wit->str());
  }
  return words[key - 1];
}

int main() {
  std::cout << "C++ Version: " << __cplusplus << "\n\n";
  std::string sv("10 20 30 40");
  int key;
  while (true) {
    std::cout << "Key [1-4]? ";
    std::cout.flush();
    std::cin >> key;
    if (key < 1) {
      std::cout << "Key " << key << " out of range. Key reset to 1\n";
      key = 1;
    }
    else if (key > 4) {
      std::cout << "Key " << key << " out of range. Key reset to 4\n";
      key = 4;
    }

    std::cout << std::quoted(sv) << '\n';
    std::cout << "1: "s << std::quoted(extractStringAtKey(sv, key)) << std::endl;
    // std::cout << std::quoted(sv) << '\n' << '\n';
  
    sv = "10 20 30 40"s;
    std::cout << "2: "s << std::quoted(use_getline(sv, key)) << std::endl;
    // std::cout << std::quoted(sv) << '\n' << '\n';
  
    sv = "10 20 30 40"s;
    auto wds = use_operator_shftrt(sv);
    // for (auto wd : wds) {
    //   std::cout << std::quoted(wd) << '\n';
    // }
    std::cout << "3: "s << std::quoted(wds[key - 1]) << std::endl;
    // std::cout << std::quoted(sv) << '\n' << '\n';
  
    sv = "10 20 30 40"s;
    std::cout << "4: "s << std::quoted(use_regex(sv, key)) << std::endl;
    // std::cout << std::quoted(sv) << '\n' << '\n';

    auto y_n = 'y';
    std::cout << "again [y-n]? ";
    std::cout.flush();
    std::cin >> y_n;
    if (std::tolower(y_n) != 'y') {
      break;
    }
  }

  return 0;
}
