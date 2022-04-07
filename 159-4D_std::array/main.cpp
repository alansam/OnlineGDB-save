
#include <iostream>
#include <iomanip>
#include <array>
#include <memory>
#include <string_view>
#include <cctype>

auto constexpr DM { 4ul };

template <typename P = int, size_t D = DM>
using four_D_array = std::array<std::array<std::array<std::array<P, D>, D>, D>, D>;

void excercise(four_D_array<int, DM> * my_array, std::unique_ptr<four_D_array<int, DM>> & sp_array);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  auto ex = false;
  if (argc > 1) {
    auto a1 = std::string_view(argv[1]);
    ex = a1.size() <= 0 ? false : (std::tolower(a1[0]) == 'e') ? true : false;
  }

  std::cout << "dynamic allocation of array of array" << std::endl;
  { //  smart pointer will auto delete at end of scope
    auto my_array = new four_D_array<int, DM> {};
    auto sp_array = std::make_unique<four_D_array<>>();

    std::cout << "address of object:          " << my_array << '\n';
    std::cout << "address from smart pointer: " << sp_array.get() << '\n';

    if (ex) {
      excercise(my_array, sp_array);
    }

    delete my_array;
  }
  std::cout << std::endl;

  {
    std::cout << "realloc for crude check to see if memory is reused\n";
    auto xx_array = new four_D_array<> {};
    auto yy_array = std::make_unique<four_D_array<>>();

    std::cout << "address of object:          " << xx_array << '\n';
    std::cout << "address from smart pointer: " << yy_array.get() << '\n';

    delete xx_array;
  }
  std::cout << std::endl;

  return 0;
}

/*
 *  MARK: excercise()
 */
void excercise(four_D_array<int, DM> * my_array, std::unique_ptr<four_D_array<int, DM>> & sp_array) {
    auto my_start =  1000 -  10;
    auto sp_start = 10000 - 100;
    for (auto w_ { 0ul }; w_ < DM; ++w_) {
      for (auto x_ { 0ul }; x_ < DM; ++x_) {
        for (auto y_ { 0ul }; y_ < DM; ++y_) {
          for (auto z_ { 0ul }; z_ < DM; ++z_) {
            (*my_array)[w_][x_][y_][z_] = z_ == 0 ? my_start +=  10 : my_start + z_;
            (*sp_array)[w_][x_][y_][z_] = z_ == 0 ? sp_start += 100 : sp_start + z_;
          }
        }
      }
    }

    for (auto w_ { 0ul }; w_ < DM; ++w_) {
      std::cout << "index W:" << std::setw(3) << w_ << '\n';
      for (auto x_ { 0ul }; x_ < DM; ++x_) {
        std::cout << "index X:" << std::setw(5) << x_ << '\n';
        for (auto y_ { 0ul }; y_ < DM; ++y_) {
          std::cout << "index Y:" << std::setw(7) << y_ << '\n';
          for (auto z_ { 0ul }; z_ < DM; ++z_) {
            std::cout << "index Z:" << std::setw(9) << z_ << '\n';
            std::cout << '[' << std::setw(2) << w_ << ']'
                      << '[' << std::setw(2) << x_ << ']'
                      << '[' << std::setw(2) << y_ << ']'
                      << '[' << std::setw(2) << z_ << ']'
                      << ':' << (*my_array)[w_][x_][y_][z_]
                      << ':' << (*sp_array)[w_][x_][y_][z_]
                      << '\n';
          }
        }
      }
    }
  
}

