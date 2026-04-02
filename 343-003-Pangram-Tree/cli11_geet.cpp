/**
 * @see https://cliutils.github.io/CLI11/book/
 */

#include "CLI/CLI.hpp"
#include <iostream>

/**
 * Let's try our hand at a little git clone, called geet. It will just print
 * it's intent, rather than running actual code, since it's just a demonstration.
 */
int main(int argc, char **argv) {
  // Let's start by adding an app and requiring 1 subcommand to run:
  CLI::App app{"Geet, a command line git lookalike that does nothing"};
  app.require_subcommand(1);

  // Now, let's define the first subcommand, add, along with a few options:
  auto add = app.add_subcommand("add", "Add file(s)");

  bool add_update;
  add->add_flag("-u,--update", add_update, "Add updated files only");

  std::vector<std::string> add_files;
  add->add_option("files", add_files, "Files to add");

  add->callback([&]() {
    std::cout << "Adding:";
    if (add_files.empty()) {
      if (add_update) {
        std::cout << " all updated files";
      }
      else {
        std::cout << " all files";
      }
    }
    else {
      for (auto file : add_files) {
        std::cout << " " << file;
      }
    }
  });

  // Now, let's add commit:
  auto commit = app.add_subcommand("commit", "Commit files");

  std::string commit_message;
  commit->add_option("-m,--message", commit_message, "A message")->required();

  commit->callback([&]() { std::cout << "Commit message: " << commit_message; });

  // All that's need now is the parse call. We'll print a little message after
  // the code runs, and then return:
  CLI11_PARSE(app, argc, argv);

  std::cout << "\nThanks for using geet!\n" << std::endl;

  return 0;
}

