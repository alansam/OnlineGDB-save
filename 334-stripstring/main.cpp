#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <span>
#include <cctype>

using namespace std::literals::string_literals;

// strip from start
constexpr
auto strip_l = [](std::string & str) {
  str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
    return !std::isspace(ch);
  }));
  return str;
};

// strip spaces from end
constexpr
auto strip_r = [](std::string & str) {
  str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
    return !std::isspace(ch);
  }).base(), str.end());
  return str;
};

// strip spaces - general function
constexpr
auto strip = [](char const end = 'B', std::string & str) {
  switch (std::toupper(end)) {
    case 'L':
      strip_l(str);
      break;

    case 'R':
      strip_r(str);
      break;

    default:
    case 'B':
      strip_r(str);
      strip_l(str);
      break;
  } 
  return str;
};

// strip spaces from both ends
constexpr
auto strip_b = [](std::string & str) {
  return strip('B', str);
};

static
auto const ws = " \t\n\r\f\v"s;

// trim from end of string (right)
static
inline
std::string & trim_r(std::string & str, std::string tc = ws) {
  str.erase(str.find_last_not_of(tc) + 1);
  return str;
}

// trim from beginning of string (left)
static
inline
std::string & trim_l(std::string & str, std::string tc = ws) {
  str.erase(0, str.find_first_not_of(tc));
  return str;
}

// trim from both ends of string (right then left)
static
inline
std::string & trim_b(std::string & str, std::string tc = ws) {
  return trim_l(trim_r(str, tc), tc);
}

// trim general function
static
inline
std::string & trim(std::string & str, std::string tc = ws, char const end = 'B') {
  switch (std::toupper(end)) {
    case 'L':
      trim_l(str, tc);
      break;

    case 'R':
      trim_r(str, tc);
      break;

    case 'B':
    default:
      trim_b(str, tc);
      break;
  }
  return str;
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {

  //  copy contents of argv into a string
  //  span over argv array
  auto argsp = std::span<char const *>(argv, argc);
  auto argstr = " \t "s;
  for (auto const arg : argsp) {
    argstr += std::string(arg) + " "s;
  }
  std::cout << std::quoted(argstr) << '\n';
  std::cout << std::quoted(strip_b(argstr)) << '\n';
  std::cout.put('\n');

  //  copy contents of argv into a vector of string
  auto args = std::vector<std::string>();
  for (auto const & arg : argsp) {
    args.push_back(std::string(arg));
  }
  for (auto ct { 0ul }; auto const & arg : args) {
    std::cout << std::setw(3) << ct++ << ' ' << arg << '\n';
  }
  std::cout.put('\n');

  //  span over args vector, ignoring first element
  argstr.clear();
  // auto argssp = std::span<std::string>(args.begin() + 1, args.size() - 1);
  auto argssp = std::span<std::string>(args).last(args.size() - 1);
  for (auto ct { 0ul }; auto const & arg : argssp) {
    std::cout << std::setw(3) << ct++ << ' ' << arg << '\n';
    argstr += arg + " "s;
  }
  std::cout << std::quoted(argstr) << '\n';
  std::cout << std::quoted(strip_b(argstr)) << '\n';
  std::cout.put('\n');

  auto sample = " \t hello world! \t "s;
  std::cout << sample << " L: " << std::quoted(strip('l', sample)) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << " R: " << std::quoted(strip('r', sample)) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << " B: " << std::quoted(strip('b', sample)) << '\n';
  std::cout.put('\n');

  sample = " \t hello world! \t "s;
  std::cout << sample << " L: " << std::quoted(trim(sample, ws + "hd!", 'l')) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << " R: " << std::quoted(trim(sample, ws + "hd!", 'r')) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << " B: " << std::quoted(trim(sample, ws + "hd!", 'b')) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << " v: " << std::quoted(trim(sample, ws + "hd!", 'v')) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << "  : " << std::quoted(trim(sample, ws + "hd!")) << '\n';
  sample = " \t hello world! \t "s;
  std::cout << sample << "  : " << std::quoted(trim(sample)) << '\n';
  std::cout.put('\n');

  return 0;
}
