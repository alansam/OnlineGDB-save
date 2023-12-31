/*
 *  GNU MP Sample.
 *  @see: https://gmplib.org
 *
 *  Compiled with: -Wall -Wpedantic -std=gnu++2b -lgmpxx -lgmp
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cstdarg>
#include <gmpxx.h>
#include <gmp.h>
#include <obstack.h>

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "GNU MP Sample.\n";
  std::cout << "GNU MP V.M.P: "
            << __GNU_MP_VERSION << '.' 
            << __GNU_MP_VERSION_MINOR << '.'
            << __GNU_MP_VERSION_PATCHLEVEL <<'\n';
  putchar('\n');
  std::cout << "GMP Version:  " << gmp_version << '\n';
  std::cout.put('\n');
  std::cout << "GNU MP compiler:       " << __GMP_CC << '\n';
  std::cout << "GNU MP compiler flags: " << __GMP_CFLAGS << '\n';
  std::cout << std::endl;

  auto samples = std::vector<std::pair<std::string, std::string>> {
    std::make_pair("2", "1"),
    std::make_pair("1230382819298383892929938373", "190382829938388229929292"),
  };

  for (auto const & [str_addendl, str_addendr] : samples) {
    mpz_class addendl;
    mpz_class addendr;
    mpz_class sum;
    addendl = str_addendl;
    addendr = str_addendr;
    sum = addendl + addendr;

    std::cout << "  " << addendl << " + " << addendr << " = " << sum << '\n' << std::endl;
  }

  return 0;
}
