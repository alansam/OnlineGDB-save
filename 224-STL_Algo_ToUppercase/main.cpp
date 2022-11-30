//
//  main.cpp
//  CF.STL_Algo_ToUppercase
//
//  Created by Alan Sampson on 10/19/22.
//

//  MARK: - Reference
//  @see: //  @see: https://stackoverflow.com/questions/49719117/how-to-properly-apply-tolower-on-german-capital-letters-Ä-Ö-Ü-ẞ-in-c

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <locale>
#include <exception>

#include "version_info.h"
#include "identify.h"

// trim from start (in place)
static
inline
void ltrim(std::string & s) {
  s.erase(s.begin(),
    std::find_if(s.begin(),
                 s.end(),
      [](unsigned char ch) {
        return !std::isspace(ch);
  }));
}

// trim from end (in place)
static
inline
void rtrim(std::string & s) {
  s.erase(
    std::find_if(s.rbegin(),
                 s.rend(),
      [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(),
    s.end());
}

// trim from both ends (in place)
static
inline
void trim(std::string & s) {
  ltrim(s);
  rtrim(s);
}

// trim from start (copying)
[[maybe_unused]]
static
inline
std::string ltrim_copy(std::string s) {
  ltrim(s);
  return s;
}

// trim from end (copying)
[[maybe_unused]]
static
inline
std::string rtrim_copy(std::string s) {
  rtrim(s);
  return s;
}

// trim from both ends (copying)
[[maybe_unused]]
static
inline
std::string trim_copy(std::string s) {
  trim(s);
  return s;
}

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "CF.STL_Algo_ToUppercase\n";

  avi::version_details();
  avi::identify();

  //  @see: https://www.fileformat.info/info/unicode/char/00df/index.htm
  auto lc = std::string("ß to uppercase ß");  // ß == U+00df == UTF-8 0xc3 0x9f
  auto uc = std::string(lc.length() + 10, ' ');

  std::cout << std::quoted(lc) << ' ' << lc.length() << std::endl;
  std::cout << std::quoted(uc) << ' ' << uc.length() << std::endl;

  std::transform(lc.cbegin(), lc.cend(), uc.begin(), ::toupper);

  rtrim(uc);

  std::cout << std::quoted(lc) << ' ' << lc.length() << std::endl;
  std::cout << std::quoted(uc) << ' ' << uc.length() << std::endl;
  std::cout << '\n' << std::string(60, '-') << "\n\n";

  auto px = [](auto const & sc) {
    for (size_t i_ = 0; sc[i_] != '\0'; ++ i_) {
      ::printf("%02x ", (uint8_t) sc[i_]);
    }
    std::cout << std::endl;
  };

  auto wpx = [](auto const & sc) {
    for (size_t i_ = 0; sc[i_] != '\0'; ++ i_) {
      ::printf("%04x ", (uint16_t) sc[i_]);
    }
    std::cout << std::endl;
  };

  auto const slc = lc.c_str();
  auto const suc = uc.c_str();

  px(slc);
  px(suc);

  try {
    auto stp = 1u;
    std::cout << "\nlet's give this a shot!\n";

    std::cout << "step " << stp++ << '\n';

    [[maybe_unused]]
    char const * de = "de_DE.UTF-8";
    [[maybe_unused]]
    char const * en = "en_US.UTF-8";
    std::locale::global(std::locale(en));

    std::cout << "step " << stp++ << '\n';
    std::wcout.imbue(std::locale());

    std::cout << "step " << stp++ << '\n';
    auto & fct = std::use_facet<std::ctype<wchar_t>>(std::locale());

    std::cout << "step " << stp++ << '\n';
    // UTF-16 code points : \u00e4\u00e4 \u00f6\u00f6 \u00fc\u00fc \u1e9e\u00df \u00f6rebro
    std::wstring str = L"Ää Öö Üü ẞß Örebro";
    std::wcout << "'" << str << "'\n";
    wpx(str);

    std::cout << "step " << stp++ << '\n';
    fct.tolower(&str[0], &str[0] + str.size());

    std::cout << "step " << stp++ << '\n';
    std::wcout << "'" << str << "'\n";
    wpx(str);
  }
  catch (std::exception & ex) {
    std::cout << "GRONK! " << ex.what() << std::endl;
  }

  return 0;
}
