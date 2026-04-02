/*
 * @see https://github.com/adishavit/argh
 * NOTE: repository cloned to ~/usr/stc/GitHub, argh.h linked locally
 *       > ln ~/usr/src/github/argh/argh.h
 */

#include <iostream>
#include <string>
#include <string_view>
#include <print>

#include "argh.h"

using namespace std::string_literals;       // for ""s suffix
using namespace std::string_view_literals;  // for ""sv suffix

namespace t01 {

static
argh::parser cmdl;

static
constexpr
const
auto dlm = "....+....1....+....2....+....3....+....4"sv
           "....+....5....+....6....+....7....+....8"sv;

void report(void);
void perform_args(void);

} /* end of namespace t01 */

/**
 * main entry point
 */
int main(int argc, char const * argv[]) {
  int RC { EXIT_SUCCESS };

  std::cout << std::boolalpha;

  t01::cmdl.add_param({"-f, --file"});
  t01::cmdl.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

  t01::perform_args();

  return RC;
}

namespace t01 {

/**
 *
 */
void perform_args(void) {

  auto vrbs = cmdl[{ "-v", "--verbose" }];
  auto hlp  = cmdl[{ "-h", "--help" }];

  auto file_name = cmdl({ "-f", "--file" }).str();

  std::cout << dlm << '\n';

  std::cout << "verbose: " << vrbs << '\n';
  std::cout <<    "help: " << hlp << '\n';

  auto exe_name { cmdl[0] };
  std::print("Exe name is: {0}\n", exe_name);

  auto f_verbose = cmdl[{ "-v", "verbose" }];
  std::print("Verbose mode is {0}\n", f_verbose ? "on"sv : "off"sv);

  auto f_help = cmdl[{"-h", "--help"}];
  std::print("Help mode is {0}\n", f_help ? "on"sv : "off"sv);
  std::cout << std::endl;

  std::cout << dlm << '\n';

  report();
  std::cout << std::endl;

  std::cout << dlm << '\n';

  std::cout << "Source file: `" << file_name << "'" << std::endl;

  if (vrbs) {
    std::cout << "This is as chatty as it gets." << '\n';
  }

  if (hlp) {
    std::cout << "Sorry, there's no help for this function yet." << '\n';
  }
  std::cout << '\n';

  // stream to a string buffer
  auto command { ""s };
  cmdl(0) >> command;
  std::cout << "Exe. name is still: "s << command << '\n';

  std::cout << std::endl;

  return;
}

/**
 *
 */
void report(void) {

  std::cout << '\n';

  std::print("-v --verbose flag: {0}\n", cmdl[{ "-v", "--verbose" }]);
  std::print("-h --help    flag: {0}\n", cmdl[{ "-h", "--help" }]);
  std::cout << '\n';

  if (cmdl(1)) {
    std::print("  Arg 1 is: {0}\n", cmdl[1]);
  }
  else {
    std::print("  Arg 1 missing!\n");
  }
  std::cout << '\n';

  std::print("Positional args:\n");
  auto ct { 0 };
  for (auto & pos_arg : cmdl) {
    std::print("pos {0:2}: val: {1}\n", ct++, pos_arg);
  }
  std::cout << '\n';

  std::print("Flags:\n");
  for (auto & flag : cmdl.flags()) {
    std::print("  {0}\n", flag);
  }
  std::cout << '\n';

  std::print("Parameters:\n");
  for (auto & param : cmdl.params()) {
    std::print("{0:6} : {1}\n", param.first, param.second);
  }
  std::cout << '\n';

  ct = 0;
  for (auto & inp : cmdl.params("f")) {
    std::print("  -{1}[{0:02}] = {2}\n", ct++, inp.first, inp.second);
  }
  std::cout << '\n';

  return;
}

} /* end of namespace t01 */


