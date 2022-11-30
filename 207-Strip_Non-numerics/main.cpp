/*
If you have a    char c [ 10]= "x4ey3";
How do you extract each integer and make them as integer data type each one??
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <regex>

void fit_the_first(char const *);
void fit_the_second(char const *);

//  print integers
auto printegers = [](auto const & nums) {
  for (auto ln = 1; auto nr : nums) {
    std::cout << std::setw(3) << ln++
              << ": "
              << std::setw(5) << nr
              << '\n';
  }
};

int main(int argc, char const * argv[]) {
  char cc[] = "x4ey -  3 ; -44-";
  fit_the_first(cc);
  fit_the_second(cc);

  return 0;
}

void fit_the_first(char const * cc) {
  std::string sc(cc);
  std::cout << std::quoted(sc) << '\n';  //  display string

  // remove non-integer things from string by converting them to space
  std::replace_if(sc.begin(), sc.end(), [](auto ch) {
    return !(ch == '-' || ::isdigit(ch)); //  keep digits and -ve signs
  }, ' ');
  //  strip trailing whitespace
  sc.erase(std::find_if(sc.rbegin(), sc.rend(), [](auto ch) {
    return !::isspace(ch);
  }).base(), sc.end());
  std::cout << std::quoted(sc) << '\n';  //  display cleaned-up string

  //  load string into a stream
  std::istringstream istr(sc);
  int ival;
  std::string word;

  //  read a number from the stream and store it in the vector
  std::vector<int> nums;
  while (!istr.eof()) {
    istr >> word;
    // try to read integers from word; discards widowed -ve signs
    if (std::istringstream(word) >> ival) {
      nums.push_back(ival);
    }
  }
  //  on completion, vector contains all the integers in the string
  printegers(nums);

  return;
}

//  Alan Sampson here's a regular expression that can extract signed numbers
//  including floating points  from string
//
//    /[-]?[0-9]+[.]?[0-9]*/gm
//
//  We can #include<regex> and use  regex_match
//  https://cplusplus.com/reference/regex/regex_match/
void fit_the_second(char const * cc) {
  auto sc = std::string(cc);
  auto patrn = std::regex("/[-]?[0-9]+[.]?[0-9]*/gm");
  auto bits = std::smatch();

  if (std::regex_match(sc, bits, patrn)) {
    for (size_t i_ = 0; i_ < bits.size(); ++i_) {
      auto sub_match = std::ssub_match(bits[i_]);
      auto bit = std::string(bits[i_]);
      std::cout << bit << '\n';
    }
  }

  return;
}

