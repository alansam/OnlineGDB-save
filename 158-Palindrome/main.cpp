
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

namespace asu {

bool is_palindrome(std::string const & palindrome);
bool is_palindrome(uint64_t const palindrome);

} /* namespace asu */

int main(int argc, char const * argv[]) {

  auto smp = std::vector<std::string> {
    "322101223",
    "3221001223",
    "12343321",
    "a man, a plan, a canal - panama",
    "a man, a plan, a canal - panamint",
    "Able was I ere I saw Elba",
    "Lewd did I live, & evil I did dwel",
    "Madam, I'm Adam",
    "Never odd or even",
    "",
    " ",
    " Aa",
  };

  auto isp = false;

  for (auto const & ps : smp) {
    isp = asu::is_palindrome(ps);
    std::cout << std::boolalpha;
    std::cout << std::quoted(ps) << ' ' << ps.size() << ' ' <<  isp << '\n';
  }
  std::cout.put('\n');

  for (auto vl : { 322'101'223ul, 3'221'001'223ul, 12'343'321ul, 1'000'000'000ul, 1'000'000'001ul, 0ul, 1ul, }) {
    auto pv = asu::is_palindrome(vl);
    std::cout << std::setw(20) << vl << ' ' <<  pv << '\n';
  }

  std::cout << std::endl;

  return 0;
}

namespace asu {

/*
 *  MARK: asu::is_palindrome()
 */
bool is_palindrome(std::string const & palindrome) {
  auto pal = palindrome;
  pal.erase(std::remove_if(pal.begin(), pal.end(), [](auto ch) {
    return std::isspace(ch) || std::ispunct(ch);
  }), pal.end());
  std::transform(pal.begin(), pal.end(), pal.begin(), [](auto ch) {
    return std::tolower(ch);
  });
  auto is_p = true;
  auto il = std::cbegin(pal);
  auto ir = std::cend(pal) - 1;

  while ((il != ir) && (il < ir)) {
    if (*il != *ir) {
      is_p = false;
      break;
    }
    il++;
    ir--;
  }

  return is_p;
}

/*
 *  MARK: asu::is_palindrome()
 */
bool is_palindrome(uint64_t const palindrome) {
  auto reversed { 0ul };
  auto copy     { palindrome };

  while (copy > 0ul) {
    auto rm = copy % 10ul;
    reversed = reversed * 10ul + rm;
    copy /= 10ul;
  }
  // std::cout << std::setw(20) << palindrome << '\n'
  //           << std::setw(20) << reversed   << '\n';

  return (palindrome == reversed);
}

} /* namespace asu */

