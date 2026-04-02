/*
 * Program: Pangram-Too
 *
 * A pangram or holoalphabetic sentence is a sentence using every
 * letter of a given alphabet at least once.
 * Pangrams have been used to display typefaces, test equipment,
 * and develop skills in handwriting, calligraphy, and typing.
 *
 * @see https://github.com/adishavit/argh
 * NOTE: repository cloned to ~/usr/stc/GitHub, argh.h linked locally
 *       > ln ~/usr/src/github/argh/argh.h
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <print>
#include <cctype>
#include <iterator>
#include <fstream>
#include <climits>

#include "argh.h"

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
  static constexpr std::uint16_t mod { 0u };
  static constexpr std::string_view pgm { "Pangram-Tree"sv };
} vi;

enum input_chooser { C_FILE, C_USER, };

// proram arguments
struct pgm_args {
  int argc { 0 };
  char ** argv { nullptr };
  bool verbose;
  bool help;
  enum input_chooser choice { C_FILE }; 
  std::string file_name { ""s };
  std::string user_input { ""s };
} run_parms;

static
constexpr
const
auto k_dlm {
  "....+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8"
};

static
constexpr
const
std::string default_file_name { "pangrams"s };

static
constexpr
const
auto F_PAN000 { "[{2:0>3}] {0:>8} | \u00ab{1}\u00bb \n"sv };

/**
 *  Function prototypes
 */
inline
bool isPangram(std::string_view const & ps, std::string & missing);
inline
void perform_pangram(std::string & pg);
inline
void perform_file_process(std::string const & file_name);
inline
void perform_args(void);

} // end of namespace pang

/**
 *  Program main entry point
 */
int main([[maybe_unused]] int const argc, [[maybe_unused]] char const * const argv[]) {
  int RC { 0 };
  std::print("Program         : {0}\n"
             "Version [V.R.M] : {1:02}.{2:02}.{3:02}\n"
             "Compiler Ver    : {4}\n"
             "\n",
             pang::vi.pgm,
             pang::vi.ver,
             pang::vi.rel,
             pang::vi.mod,
             __cplusplus);

  pang::run_parms.argc = argc;
  pang::run_parms.argv = const_cast<char **>(argv);

  auto file_name = pang::default_file_name; // data file name - initializet to default

  std::print("<<< Begin Run. >>>\n");

  pang::perform_args();

  switch (pang::run_parms.choice) {
    case pang::C_FILE:
      file_name = pang::run_parms.file_name; // data file name
      pang::perform_file_process(file_name);
      break;

    case pang::C_USER:
      pang::perform_pangram(pang::run_parms.user_input);
      break;

    default:
    // GRONK!
    // TODO: make a good choice of what to do here
    break;
  }

  std::print("<<< End Run. >>>\n");

  return RC;
}

namespace pang {

/*
 *  Function to perform the work
 */
inline
void perform_pangram(std::string & pg) {

// control how 'missing' is allocated via a compiler macro. default is 'auto'
#ifdef AS_USE_EXPLICIT
  std::string missing; // missing letters - explicitly defined as a std::string
#else
  auto missing = ""s;  // missing letters - auto defined as a std::string via the ""s suffix
#endif

//  std::for_each(pangrams.cbegin(), pangrams.cend(), [&missing](auto const & pg) {
  if (!pg.empty() && iscntrl(pg[0])) {
    std::cout << std::endl; // 1st char is newline, print and skip
  }
  else {
    auto is_pangram = isPangram(pg, missing); //  call the pangram function

    // count of alphabetic characters in the string (as defined by std::alpha)
    auto alfas = std::count_if(pg.cbegin(), pg.cend(), [](unsigned char ch) {
      return std::isalpha(ch);
    });

    // report
//  std::print("[{2:0>3}] {0:>8} | \u00ab{1}\u00bb \n", is_pangram, pg, alfas);
    std::print(F_PAN000, is_pangram, pg, alfas);

    if (!is_pangram) {
      // GRONK! string is not a pangram, find out why
      if (pg.length() < LETTER_ARRAY_SZ) {
        // string too short to be a pangram
 //     std::print("[{2:0>3}] {0:>8} | \u00ab{1}\u00bb \n", "error", "string too short", 0);
        std::print(F_PAN000, "error", "string too short", 0);
      }
      else {
        // string is missing one or more alpabetics
        // count of alphabetic characters in the string (as defined by std::alpha)
        auto ma = std::count_if(missing.cbegin(), missing.cend(), [](unsigned char mc) {
          return std::isalpha(mc);
        });
        // display the list of alpabetics missing from the string
//      std::print("[{2:0>3}] {0:>8} | \u00ab{1}\u00bb \n", "missing", missing, ma);
        std::print(F_PAN000, "missing", missing, ma);
      }
    }
  }
//  });

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

/**
 * file processing
 */
inline
void perform_file_process(std::string const & file_name) {
  // working storage
  std::ifstream ifile(file_name);
  std::istreambuf_iterator<char> fit { ifile };
  std::istreambuf_iterator<char> eof;

  std::string sbuff;  // string buffer for file operations

  while (fit != eof) {
    // file read loop
    sbuff += *fit;  // copy this record to string buffer
    if (*fit == '\n') {
      sbuff.erase(std::remove(sbuff.begin(),sbuff.end(), '\n'), sbuff.end());

      if (sbuff.length() > 0) { // only use records that have data
        auto cmnt = sbuff.find("--"s); // look for '==' comments
        switch (cmnt) { 
          case 0: // there's a '--' comment at position 0 - discard record
            break;

          default: // work to do
            auto ss = sbuff.find("//"s); // look for embedded '//' comments
            if (ss != std::string::npos) {
              // remove the comment from the record
              sbuff.resize(ss); // shorten record to discard comment text
              auto sw = sbuff.find_last_not_of(" \t"); // look fro trailing whitespace
              if (sw > 1 && sw < sbuff.size()) {
                sbuff.resize(sw + 1); // trailing whitespace removed
              }
            }

            // process the record - see if it's a pangram
            pang::perform_pangram(sbuff);

            break;
        }
      }
      sbuff.clear();
    }
    ++fit;
  }
}

/*
 *
 * struct pgm_args {
 *   bool verbose;
 *   bool help;
 *   input_chooser choice { input_chooser.File }; 
 *   std::string file_name { ""s };
 *   std::string user_input { ""s };
 *}  run_parms;
 */
inline
void perform_args(void) {

  //run_parms
  argh::parser cmdl;
  cmdl.add_param({ "-f", "--file" });
  cmdl.parse(run_parms.argc, run_parms.argv);
//cmdl.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

  run_parms.verbose = cmdl[{ "-v", "--verbose" }];
  run_parms.help    = cmdl[{ "-h", "--help" }];

  auto file_name = cmdl({ "-f", "--file" }).str();
  auto file_text = ""s;

  if (file_name.size() > 0) {
    run_parms.choice = C_FILE;
    run_parms.file_name = file_name;
    run_parms.user_input = ""s;
  }
  else {
    run_parms.file_name = ""s;
    if (!cmdl(1)) {
      file_text = ""s;
    }
    else {
      run_parms.choice = C_USER;
      file_text = cmdl[1];
    }
    run_parms.user_input = file_text;
  }

  // Mighty Mouse to save the day
  if (run_parms.file_name.length() == 0 && run_parms.user_input.length() == 0) {
    run_parms.choice = C_FILE;
    run_parms.file_name = default_file_name;
  }

  // print report if verbose printing is requested
  if (run_parms.verbose) {
    auto t_choice { ""s };
    switch (run_parms.choice) {
      case C_FILE:
        t_choice = "File"s;
        break;

      case C_USER:
        t_choice = "User"s;
        break;

      default:
        t_choice = "GRONK!"s;
        break;
    }

    std::print("{}\n", pang::k_dlm);

    std::print("  verbose    : {0}\n", run_parms.verbose);
    std::print("  help       : {0}\n", run_parms.help);
    std::print("  choice     : {0}\n", t_choice);
    std::print("  file name  : {0}\n", run_parms.file_name);
    std::print("  user input : {0}\n", run_parms.user_input);

    std::print("{}\n\n", pang::k_dlm);
  }

  return;
}

} // end of namespace pang

