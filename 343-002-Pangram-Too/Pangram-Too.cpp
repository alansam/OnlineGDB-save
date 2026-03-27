/*
 * Program: Pangram-Too
 *
 * A pangram or holoalphabetic sentence is a sentence using every
 * letter of a given alphabet at least once.
 * Pangrams have been used to display typefaces, test equipment,
 * and develop skills in handwriting, calligraphy, and typing.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <print>
#include <cctype>

#include "Pangram.hpp"

using namespace std::string_literals;       // for ""s suffix
using namespace std::string_view_literals;  // for ""sv suffix

//  compiler macro for allocation of letters present array
#define LETTER_ARRAY_SZ 26

namespace pang {

// program information
constexpr
struct pgm_info {
  static constexpr std::uint16_t ver { 0u };
  static constexpr std::uint16_t rel { 1u };
  static constexpr std::uint16_t mod { 1u };  // FIXME: AS000 - weirdness with gcc 15.2.0_1
  static constexpr std::string_view pgm { "Pangram-Too"sv };
} vi;

/**
 *  Function prototypes
 */
inline
bool isPangram(std::string_view const & ps, std::string & missing);
inline
void perform_pangram();

} // end of namespace pang

/**
 *  Program main entry point
 */
int main([[maybe_unused]] int const argc, [[maybe_unused]] char const * const argv[]) {
  int RC { 0 };
  std::print("Program         : {0}\n"
             "Version [V.R.M] : {1:02}.{2:02}.{3:02}\n"
             "Compiler Ver    : {4}\n" // FIXME: AS000 - weirdness with gcc 15.2.0_1
             "\n",
             pang::vi.pgm,
             pang::vi.ver,
             pang::vi.rel,
             pang::vi.mod,
             __cplusplus); // FIXME: AS000 - weirdness with gcc 15.2.0_1

  std::print("<<< Begin Run. >>>\n");

  pang::perform_pangram();

  std::print("<<< End Run. >>>\n");

  return RC;
}

namespace pang {

/*
 *  Function to perform the work
 */
inline
void perform_pangram() {

// control how 'missing' is allocated via a compiler macro. default is 'auto'
#ifdef AS_USE_EXPLICIT
  std::string missing;  // explicitly defined as a std::string
#else
  auto missing = ""s;   // auto defined as a std::string via the ""s suffix
#endif

  // loop through the sample data checking each entry for pangrams
  std::for_each(pangrams.cbegin(), pangrams.cend(), [&missing](auto const & pg) {
    if (!pg.empty() && iscntrl(pg[0])) { //FIXME - AS000 - handle empty string gracefully
    //FIXME if (pg[0] == '\n') {
      std::cout << std::endl; // 1st char is newline, print and skip
    }
    else {
      auto is_pangram = isPangram(pg, missing); //  call the pangram function

      // count of alphabetic characters in the string (as defined by std::alpha)
      auto alfas = std::count_if(pg.cbegin(), pg.cend(), [](unsigned char ch) {
        return std::isalpha(ch);
      });

    // report
      std::print("{0:>8} : \u00ab{1}\u00bb [{2:0>3}]\n", is_pangram, pg, alfas);
  
      if (!is_pangram) {
        // GRONK! string is not a pangram, find out why
        if (pg.length() < LETTER_ARRAY_SZ) {
          // string too short to be a pangram
          std::print("{0:>8} : {1}\n", "error", "string too short");
        }
        else {
          // string is missing one or more alpabetics
          // count of alphabetic characters in the string (as defined by std::alpha)
          auto ma = std::count_if(missing.cbegin(), missing.cend(), [](unsigned char mc) {
            return std::isalpha(mc);
          });
          // display the list of alpabetics missing from the string
          std::print("{0:>8} : \u00ab{1}\u00bb [{2:0>2}]\n", "missing", missing, ma);
        }
      }
    }
  });

  return;
}

/**
 *  Function to determine if the input string is a pangram
 */
inline
bool isPangram(std::string_view const & ps, std::string & missing) {
  auto is_pangram { true };

#ifdef AS_USE_EXPLICIT
  std::string transformed;
#else
  auto transformed = ""s;
#endif

  if (ps.length() < LETTER_ARRAY_SZ) {
    // less than 26 letters in the string means it's not a pangram
    is_pangram = false; // and we're done!
  }
  else {
    transformed.resize(ps.size(), ' ');

    // create a work string by converting input to lower case
    std::transform(ps.cbegin(), ps.cend(), transformed.begin(), [](unsigned const char & ch) {
      auto lc = std::tolower(ch);
      return lc;
    });

    missing.clear();  // make sure the 'missing' string is empty

    // Create a boolean array, of size 26. Distinct letter indices will be set to true
    std::array<bool, LETTER_ARRAY_SZ> present = { false };
    auto distinct = 0u; // counter of number of distinct letters

    // loop over the work string and examine individual letters
    for (auto tc : transformed) {
      if (std::isalpha(static_cast<unsigned char>(tc))) { // is the char alphabetic?
        // Calculate the index (0-25) for the letter.
        std::size_t idx = tc - 'a';

        // Mark the letter as present if not already marked.
        if (!present[idx]) {
          present[idx] = true;
          distinct++; // increment # of distinct letters we've identified
        }
      }

      if (distinct >= present.size()) { break; } // we got 26 different letters, quit the for loop
    }

    // set the return value to 'true' if we got 26 different letters (default is 'false')
    is_pangram = (distinct == present.size());  // assign result of the boolean == operation

    //  if it's not a pangram, create the list of missing letters
    if (!is_pangram) {
      //  loop over the letters present array and collect missing letters in the missing string
      for (auto ix = 0ul; ix < present.size(); ++ix) {
        if (!present[ix]) {
          auto mc = static_cast<char>(ix + 'a');
          missing += mc;    // append this letter
          missing += " "s;  // append a space
        }
      }

      // remove trailing space
      if (!missing.empty() && missing.back() == ' ') {
        missing.pop_back();
      }
    }
  }

  return is_pangram;
}

} // end of namespace pang
