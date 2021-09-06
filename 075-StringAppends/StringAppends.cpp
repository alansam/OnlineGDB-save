//
//  strappend.cpp
//  CF.StringAppends
//
//  Created by Alan Sampson on 6/2/21.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <cstring>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "075-StringAppends\n"sv;
  std::cout << "C++ Version: "s << __cplusplus << std::endl;

  char c1[50] = { '\0', };
  char c2[50] = { '\0', };

  auto run_nr_c { 0u };
  auto run_nr_s { 0u };

  ///  C style char strings
  try {
    std::ostringstream oss;
    oss << "c+"sv << std::setw(2) << std::setfill('0') << ++run_nr_c << ": "sv;
    std::cout << '\n' << oss.str() << "C style char strings\n"s;

    strcpy(c1, "Bangala");
    strcpy(c2, "desh");

    std::cout << std::quoted(c1) << ' ' << std::quoted(c2) << '\n';

    size_t ci;
    size_t cj;
    for (ci = 0; c1[ci] != '\0'; ci++); // find index to end of c1
    for (cj = 0; c2[cj] != '\0'; cj++, ci++) {
      c1[ci] = c2[cj];
    }

    std::cout << oss.str() << std::quoted(c1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  std::string s1;
  std::string s2;

  ///  C++ std::string - the obvious way; use .operator+=()
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string - the obvious way; use .operator+=()\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';

    s1 += s2;

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.push_back() - loop over each char in s2
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.push_back() - loop over each char in s2\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';

    for (size_t cj = 0; s2[cj] != '\0'; cj++) {
      s1.push_back(s2.at(cj));
    }

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.append() - loop over each char in s2
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.append() - loop over each char in s2\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';

    for (size_t cj = 0; s2[cj] != '\0'; cj++) {
      s1.append(1, s2[cj]);
    }

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.operator+=() - ranged based for loop over each char in s2
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.operator+=() - ranged based for loop over each char in s2\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';
    for (auto ch : s2) {
      s1 += ch;
    }

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.operator+() - for loop over an iterator
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.operator+() - for loop over an iterator\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';
    for (auto si = s2.cbegin(); si != s2.cend();) {
      s1 = s1 + *si++;
    }

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string - for loop over iterators, insert with std::back_inserter()
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string - for loop over iterators, insert with std::back_inserter()\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';
    auto bi = std::back_inserter(s1);
    for (auto e2 = s2.cbegin(); e2 != s2.cend(); ++e2) {
      *bi++ = *e2;
    }

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string - std::for_each(), insert with std::back_inserter()
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string - std::for_each(), insert with std::back_inserter()\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';
    auto bi = std::back_inserter(s1);
    std::for_each(s2.cbegin(), s2.cend(), [&](auto ch) {
      *bi++ = ch;
    });

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.insert() - using iterators.
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.insert() - using iterators.\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';
    s1.insert(s1.end(), s2.cbegin(), s2.cend());

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.insert() - using iterator.
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.insert() - using iterator.\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';
    for (auto ch : s2) {
      s1.insert(s1.end(), ch);
    }

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C++ std::string.data() - C style index lookup, direct access to underlyiing data
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C++ std::string.data() - C style index lookup, direct access to underlyiing data\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << s1.capacity() << ' ' << s1.size() << '\n';
    s1.resize(s1.size() + 50, '\0');  //  make sure there's enough space for inserts
    std::cout << s1.capacity() << ' ' << s1.size() << '\n';
    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';

    size_t ci;
    size_t cj;
    for (ci = 0; s1[ci] != '\0'; ci++); // find index to end of c1
    for (cj = 0; s2[cj] != '\0'; cj++, ci++) {
      s1.data()[ci] = s2.data()[cj];
    }

    auto cc { 0u };
    auto constexpr cc_max { 16u };
    for (auto ch : s1) {
      std::printf("%02x %s", ch, (++cc % cc_max == 0 ? "\n" : ""));
    }
    std::cout << std::endl;

    s1.erase(s1.find('\0'));  //  trim from (first) '\0' to end of string
    s1.shrink_to_fit();
    std::cout << s1.capacity() << ' ' << s1.size() << '\n';

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  ///  C style using std::strings
  try {
    std::ostringstream oss;
    oss << "s+"sv << std::setw(2) << std::setfill('0') << ++run_nr_s << ": "sv;
    std::cout << '\n'
              << oss.str()
              << "C style using std::string.operator[]()\n"s;

    s1 = "Bangala"s;
    s2 = "desh"s;

    std::cout << s1.capacity() << ' ' << s1.size() << '\n';
    s1.resize(s1.size() + 50, '\0');  //  make sure there's enough space for inserts
    std::cout << s1.capacity() << ' ' << s1.size() << '\n';
    std::cout << std::quoted(s1) << ' ' << std::quoted(s2) << '\n';

    size_t si;
    size_t sj;
    for (si = 0; s1[si] != '\0'; si++); // find index to end of c1
    for (sj = 0; s2[sj] != '\0'; sj++, si++) {
      s1[si] = s2[sj];
    }

    s1.erase(s1.find('\0'));  //  trim from (first) '\0' to end of string
    s1.shrink_to_fit();
    std::cout << s1.capacity() << ' ' << s1.size() << '\n';

    std::cout << oss.str() << std::quoted(s1) << '\n' << std::endl;
  }
  catch (std::exception & ex) {
    std::cerr << "GRONK! "sv << ex.what() << std::endl;
  }

  return 0;
}
