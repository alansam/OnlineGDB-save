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

/**
 * main entry point
 */
int main(int argc, char const * argv[]) {
  int RC { EXIT_SUCCESS };

  std::cout << std::boolalpha;

//  auto cmdl = argh::parser(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);
  argh::parser cmdl;
  cmdl.add_param("max");
  cmdl.add_param("min");
  cmdl.add_param({ "f", "file" });

  cmdl.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

  auto exe_name { cmdl[0] };
  std::print("Exe name is: {0}\n", exe_name);

  auto f_verbose = cmdl[{ "-v", "verbose" }];
  std::print("Verbose mode is {0}\n", f_verbose ? "on"sv : "off"sv);

  auto f_help = cmdl[{"-h", "--help"}];
  std::print("Help has been requested {0}\n", f_help ? "on"sv : "off"sv);

  std::print("--threshold {0}\n", cmdl("--threshold").str());
  std::print("--i         {0}\n", cmdl("--i").str());
  cmdl("-q");

  auto command { ""s };
  cmdl(0) >> command;
  std::cout << "Exe. name is still: "s << command << '\n';

  std::print("--v       flag     : {0}\n", cmdl[{ "v", "verbose" }]);
  std::print("--v       flag -   : {0}\n", cmdl[{ "-v", "verbose" }]);
  std::print("--v       flag - - : {0}\n", cmdl[{ "-v", "-verbose" }]);
  std::print("--v       flag - --: {0}\n", cmdl[{ "-v", "--verbose" }]);
  std::print("--v       flag     : {0}\n", cmdl[  "v" ]);
  std::print("--verbose flag     : {0}\n", cmdl[  "verbose" ]);
  std::cout << '\n';

  std::print("--h       flag     : {0}\n", cmdl[{ "h", "help" }]);
  std::print("--h       flag -   : {0}\n", cmdl[{ "-h", "help" }]);
  std::print("--h       flag - - : {0}\n", cmdl[{ "-h", "-help" }]);
  std::print("--h       flag - --: {0}\n", cmdl[{ "-h", "-help" }]);
  std::print("--h       flag     : {0}\n", cmdl[{ "h" }]);
  std::print("--help    flag     : {0}\n", cmdl[  "help" ]);
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
  std::print("Inputs:\n");
  for (auto & inp : cmdl.params("i")) {
    std::print("  -{1}[{0:02}] = {2}\n", ct++, inp.first, inp.second);
  }
  ct = 0;
  for (auto & inp : cmdl.params("q")) {
    std::print("  -{1}[{0:02}] = {2}\n", ct++, inp.first, inp.second);
  }
  ct = 0;
  for (auto & inp : cmdl.params("min")) {
    std::print("  -{1}[{0:02}] = {2}\n", ct++, inp.first, inp.second);
  }
  ct = 0;
  for (auto & inp : cmdl.params("max")) {
    std::print("  -{1}[{0:02}] = {2}\n", ct++, inp.first, inp.second);
  }
  ct = 0;
  for (auto & inp : cmdl.params("f")) {
    std::print("  -{1}[{0:02}] = {2}\n", ct++, inp.first, inp.second);
  }
  std::cout << '\n';

  return RC;
}

