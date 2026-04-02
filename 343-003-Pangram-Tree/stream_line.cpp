#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <string_view>
#include <print>
#include <algorithm>
#include <climits>

using namespace std::string_literals;       // for ""s suffix
using namespace std::string_view_literals;  // for ""sv suffix

//..+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
namespace pang {

inline
static
constexpr
auto filename = "pangrams"s;

// program information
constexpr
struct pgm_info {
  static constexpr std::uint16_t ver { 0u };
  static constexpr std::uint16_t rel { 1u };
  static constexpr std::uint16_t mod { 0u };
  static constexpr std::string_view pgm { "stream_line.cpp"sv };
} vi;

inline
static
constexpr
auto sep = "....+....1....+....2....+....3....+....4....+....5"sv
           "....+....6....+....7....+....8....+....9....+....0"sv
           "....+....1....+....2....+....3....+....4....+....5"sv
           "....+....6....+....7....+....8....+....9....+....0"sv
           "....+....1....+....2....+....3....+....4....+....5"sv;

int perform_lines(void);

} // end namespace pang
//..+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8

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

  std::print("<<< Begin Run. >>>\n");

  RC = pang::perform_lines();

  std::print("<<< End Run. >>>\n");

  return RC;
}

//..+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
namespace pang {

/**
 * Function perform_lines(void)
 * @see https://stackoverflow.com/questions/2291802/is-there-a-c-iterator-that-can-iterate-over-a-file-line-by-line
 */
int perform_lines(void) {
  int RC { 0 };

  std::ifstream ifile(filename);
  std::istreambuf_iterator<char> fit { ifile };
  std::istreambuf_iterator<char> eof;

  std::string sbuff;

  auto lc { 0u };
  auto ls { 0u };
  auto rl { 0u };
  auto rs { UINT_MAX };
  while (fit != eof) {
    sbuff += *fit;
    if (*fit == '\n') {
      ++lc;
      sbuff.erase(std::remove(sbuff.begin(),sbuff.end(), '\n'), sbuff.end());
      if (sbuff.length() > 0) {
        auto cmnt = sbuff.find("--"s);
        switch (cmnt) {
          case 0:
            break;
          default:
            ++ls;
            auto ss = sbuff.find("//"s);
            if (ss != std::string::npos) {
              sbuff.resize(ss);
              auto sw = sbuff.find_last_not_of(' ');
#ifdef AS_DEBUG
              std::print("--{0:3}-- --{1:3}-- --{2:3}--\n", ss, sw, sbuff.size());
#endif /* AS_DEBUG */
              if (sw > 1 && sw < sbuff.size()) {
                sbuff.resize(sw + 1);
              }
            }

            auto sz_sbuff = sbuff.size();
            rs = rs > sz_sbuff ? sz_sbuff : rs;
            rl = rl < sz_sbuff ? sz_sbuff : rl;

            std::print("\u00ab{0}\u00bb\n", sbuff);
            break;
        }
      }
      sbuff.clear();
    }
    ++fit;
  }

  std::print("\n{0}\n", sep);
  std::print("  data file       : {0}\n"
             "  lines counted   : {1:5}.\n"
             "  lines selected  : {2:5}.\n"
             "  lines discarded : {3:5}.\n"
             "  shortest line   : {4:5}.\n"
             "  longest line    : {5:5}.\n"
             "\n", filename, lc, ls, (lc - ls), rs, rl);

  return RC;
}

} // end namespace pang
//..+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8

