//  @see: http://shakespeare.mit.edu/index.html

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <map>
#include <vector>
#include <string>

using namespace std::literals::string_literals;

static
size_t constexpr LFL { 26UL };

#define USE_TEMPLATES_
#ifdef USE_TEMPLATES_

/*
 *  MARK: Template print_analysis_array() - STL collections
 */
template<class COL>
void print_analysis_array(COL const & count) {
  std::cout << "In template function: "s << __func__ << "() - collection\n"s;

  auto cc = 'a';
  for (auto ix : count) {
    std::cout << std::setw(2) << cc++ << ": "s << std::setw(5) << ix << '\n';
  }
}

/*
 *  MARK: Template print_analysis_array() - STL specialization for std::map<KY,VL>
 */
template<typename KY, typename VL>
void print_analysis_array(std::map<KY, VL> const & count) {
  std::cout << "In template function: "s << __func__ << "() - map\n"s;

  for (auto const & [key, val] : count) {
    std::cout << std::setw(2) << key << ": "s << std::setw(5) << val << '\n';
  }
}

/*
 *  MARK: Template print_analysis_array() - STL specialization for int[]
 */
template<typename TYP, size_t SZ>
void print_analysis_array(TYP const count[SZ]) {
  std::cout << "In template function: "s << __func__ << "() - C-array, size: " << SZ << "\n"s;

  auto cc = 'a';
  for (size_t i_ = 0UL; i_ < SZ; ++i_) {
    std::cout << std::setw(2) << cc++ << ": "s << std::setw(5) << count[i_] << '\n';
  }
}

#else   /* USE_TEMPLATES_ */

//  MARK: - Overloaded priint function prototypes
void print_analysis_array(size_t const sz, int const count[]);
void print_analysis_array(std::array<int, LFL> const & count);
void print_analysis_array(std::map<char, int> const & count);
void print_analysis_array(std::vector<int> const & count);

#endif  /* USE_TEMPLATES_ */

void v1_carray(void);
void v2_stlarray(void);
void v3_stlmap(void);
void v4_stlvector(void);

static
std::string const fname { "./what.txt"s };

/*
 *  MARK: main()
 */
int main([[maybe_unused]] int argc, [[maybe_unused]] char const * argv[]) {
  v1_carray();

  v2_stlarray();

  v3_stlmap();

  v4_stlvector();

  return 0;
}

/*
 *  MARK: v1_carray()
 */
void v1_carray(void) {
  std::cout << '\n' << std::string(70, '-') << '\n';
  std::cout << "In function: "s << __func__ << "()\n\n"s;

  //  ifstream encrypted_file;
  //  encrypted_file.open("encrypted_text.txt");

  std::string text;
  std::ifstream encrypted_file(fname);
  if (encrypted_file.is_open()) {
    while (encrypted_file) {
      char mychar = encrypted_file.get();
      text.push_back(mychar);
      // text += mychar;
    }
  }
  encrypted_file.close();

  int letter_frequency[LFL] = { };
  size_t const string_length = text.length();
  for (size_t i_ = 0ul; i_ < string_length; ++i_) {
    if (isalpha(text[i_]) != 0) {
      if (isupper(text[i_]) != 0) {
        letter_frequency[(text[i_] - 'A')]++; // letter_frequency[(text[i_] - 65)];
      }
      else if (islower(text[i_]) != 0) {
        letter_frequency[(text[i_] - 'a')]++; // letter_frequency[(text[i_] - 97)];
      }
    }
  }

#ifdef USE_TEMPLATES_
  print_analysis_array<int, LFL>(letter_frequency);
#else   /* USE_TEMPLATES_ */
  print_analysis_array(LFL, letter_frequency);
#endif  /* USE_TEMPLATES_ */

  std::cout << std::endl;
}

/*
 *  MARK: v2_stlarray()
 */
void v2_stlarray(void) {
  std::cout << '\n' << std::string(70, '-') << '\n';
  std::cout << "In function: "s << __func__ << "()\n\n"s;

  std::array<int, LFL> letter_frequency { 0, };
  std::ifstream encrypted_file(fname);
  if (encrypted_file.is_open()) {
    while (encrypted_file) {
      char mychar = encrypted_file.get();
      if (std::isalpha(mychar)) {
        mychar = std::islower(mychar) ? mychar : std::tolower(mychar);
        size_t ix = 0ul;
        for (auto ap : "abcdefghijklmnopqrstuvwxyz"s) {
          if (mychar == ap) {
            break;
          }
          ix++;
        }
        letter_frequency[ix]++;
      }
    }
  }
  encrypted_file.close();

  print_analysis_array(letter_frequency);

  std::cout << std::endl;
}

/*
 *  MARK: v3_stlmap()
 */
void v3_stlmap(void) {
  std::cout << '\n' << std::string(70, '-') << '\n';
  std::cout << "In function: "s << __func__ << "()\n\n"s;

  std::map<char, int> letter_frequency;
  std::ifstream encrypted_file(fname);
  if (encrypted_file.is_open()) {
    while (encrypted_file) {
      char mychar = encrypted_file.get();
      if (std::isalpha(mychar)) {
        mychar = std::islower(mychar) ? mychar : std::tolower(mychar);
        letter_frequency[mychar]++;
      }
    }
  }
  encrypted_file.close();

  print_analysis_array(letter_frequency);
}

/*
 *  MARK: v4_stlvector()
 */
void v4_stlvector(void) {
  std::cout << '\n' << std::string(70, '-') << '\n';
  std::cout << "In function: "s << __func__ << "()\n\n"s;

  std::vector<int> letter_frequency(LFL);
  std::ifstream encrypted_file(fname);
  if (encrypted_file.is_open()) {
    while (encrypted_file) {
      char mychar = encrypted_file.get();
      if (std::isalpha(mychar)) {
        mychar = std::islower(mychar) ? mychar : std::tolower(mychar);
        size_t ix = 0;
        for (auto ap : "abcdefghijklmnopqrstuvwxyz"s) {
          if (mychar == ap) {
            break;
          }
          ix++;
        }
        letter_frequency[ix]++;
      }
    }
  }
  encrypted_file.close();

  print_analysis_array(letter_frequency);

  std::cout << std::endl;
}

#ifndef USE_TEMPLATES_

//  MARK: - Overloaded priint functions
/*
 *  MARK: print_analysis_array()
 */
void print_analysis_array(size_t const sz, int const count[]) {
  std::cout << "In function: "s << __func__ << "() - C-array, size: " << sz << "\n"s;
  auto cc = 'a';
  for (size_t i_ = 0; i_ < sz; ++i_) {
    std::cout << std::setw(2) << cc++ << ": "s << std::setw(5) << count[i_] << '\n';
  }
}

/*
 *  MARK: print_analysis_array()
 */
void print_analysis_array(std::array<int, LFL> const & count) {
  std::cout << "In function: "s << __func__ << "() - std::array\n"s;
  auto cc = 'a';
  for (auto ix : count) {
    std::cout << std::setw(2) << cc++ << ": "s << std::setw(5) << ix << '\n';
  }
}

/*
 *  MARK: print_analysis_array()
 */
void print_analysis_array(std::map<char, int> const & count) {
  std::cout << "In function: "s << __func__ << "() - std::map\n"s;
  for (auto const & [key, val] : count) {
    std::cout << std::setw(2) << key << ": "s << std::setw(5) << val << '\n';
  }
}

/*
 *  MARK: print_analysis_array()
 */
void print_analysis_array(std::vector<int> const & count) {
  std::cout << "In function: "s << __func__ << "() - std::vector\n"s;
  char cc = 'a';
  for (auto ix : count) {
    std::cout << std::setw(2) << cc++ << ": "s << std::setw(5) << ix << '\n';
  }
}

#endif  /* USE_TEMPLATES_ */
