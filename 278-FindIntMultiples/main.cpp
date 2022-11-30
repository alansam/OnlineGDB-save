/*
I'm relatively new to coding, and I have a need to work out if a group of variables can be multiplied together in a way that outputs all integer values within a set range.
The question is:
A = 254 (Starting Regular Numbers 1 to 255)
B = 254 (Multiplication 1 to 255 ( A * B )
C = 249 (Multiplication 1 to 255 ( B * C )
D = 4 (Last Multiplication 1 to 5 ( A * B * C ) * D
I know that ( A * B * C ) * D = 64,257,936
How do I check to see if the logic of A,B,C,D will make all values between 1 - 64,257,936 ?
I want to know if its possible, and if its not possible, what numbers can not be made?
Thank you in advance!
 */
 
#include <iostream>
#include <iomanip>
#include <memory>

// #define TO_THE_MAX_

#ifdef TO_THE_MAX_

//  large scale test
static
size_t constexpr A { 254ul };
static
size_t constexpr B { 254ul };
static
size_t constexpr C { 249ul };
static
size_t constexpr D {   4ul };

static
bool show_list { false };

#else   /* TO_THE_MAX_ */

//  small scale test
static
size_t constexpr A {  13ul };
static
size_t constexpr B {   2ul };
static
size_t constexpr C {   1ul };
static
size_t constexpr D {   3ul };

static
bool show_list { true };

#endif  /* TO_THE_MAX_ */

static
size_t constexpr found_sz { A * B * C * D };


int main() {
  // bool *found = new bool[found_sz + 1] { false, };
  auto found = std::make_unique<bool[]>(found_sz + 1);

  for (size_t a_ { 1ul }; a_ <= A; ++a_) {
    for (size_t b_ { 1ul }; b_ <= B; ++b_) {
      for (size_t c_ { 1ul }; c_ <= C; ++c_) {
        for (size_t d_ { 1ul }; d_ <= D; ++d_) {
          size_t ix = a_ * b_ * c_ * d_;
          found[ix] = true;
        }
      }
    }
  }

  std::cout << "max value: " << std::setw(9) << found_sz << '\n';
  std::cout << "\nFound\n";
  size_t found_t { 0ul };
  std::cout << std::string(100, '-') << '\n';
  for (size_t ix { 1ul }, lc = 1; ix <= found_sz; ++ix) {
    if (found[ix]) {
      found_t++;
      if (show_list) {
        std::cout << std::setw(9) << ix << (lc++ % 10 != 0 ? ' ' : '\n');
      }
    }
  }
  std::cout << "\nFound:\n"
            << std::string(9, '-') << '\n'
            << std::setw(9) << found_t << '\n';
  std::cout << std::endl;

  std::cout << "\nNot found\n";
  std::cout << std::string(100, '-') << '\n';
  size_t found_f { 0ul };
  for (size_t ix { 1ul }, lc = 1; ix <= found_sz; ++ix) {
    if (!found[ix]) {
      found_f++;
      if (show_list) {
        std::cout << std::setw(9) << ix << (lc++ % 10 != 0 ? ' ' : '\n');
      }
    }
  }
  std::cout << "\nUnfound:\n"
            << std::string(9, '-') << '\n'
            << std::setw(9) << found_f << '\n';
  std::cout << std::endl;

  // delete [] found;

  return 0;
}

