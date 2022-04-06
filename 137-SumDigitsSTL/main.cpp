
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>

int addLastThree(int64_t number) {
  int result = 0;

  std::string str = std::to_string(number);
  for(size_t i=str.size() - 3; i < str.size(); ++i){
    result += (str[i] - 48);
  }

  return result;
}

/*
 *  Really contrived implementation just to demonstrate std::accumulate
 */
int addLastNacc(int64_t number, size_t count) {
  std::string str = std::to_string(number);
  count = (count >= str.size()) ? str.size() : count;
  auto sum3 = std::accumulate(str.rbegin(), str.rbegin() + count, '0', [](auto lhs, auto rhs) -> char {
    return (lhs - '0') + (rhs - '0') + '0';
  });
  return sum3 - '0';
}

/*
 *  Really contrived implementation just to demonstrate std::reduce
 */
int addLastNrdu(int64_t number, size_t count) {
  std::string str = std::to_string(number);
  count = (count >= str.size()) ? str.size() : count;
  auto sum3 = std::reduce(str.rbegin(), str.rbegin() + count, '0', [](auto lhs, auto rhs) -> char {
    return (lhs - '0') + (rhs - '0') + '0';
  });
  return sum3 - '0';
}

/*
 *  Obvious solution using modulous (remainder) and division
 */
int64_t addLastNmod(int64_t number, size_t count) {
  auto sum = 0L;
  for (size_t i_ = 1UL; i_ <= count; ++i_) {
    auto nr = number % 10;
    number /= 10;
    sum += nr;
  }

  return sum;
}

int main() {
  int64_t num = 21013789;

  std::cout << "The number " << num << " has a last   3 digit sum of " <<std::setw(3) << addLastThree(num) << '\n' << '\n';

  for (size_t nr = 0ul; nr <= 10ul; ++nr) {
    std::cout << "The number " << num << " has a last " << std::setw(3) << nr <<  " digit sum of " << std::setw(3) << addLastNacc(num, nr) << "\n";
    std::cout << "The number " << num << " has a last " << std::setw(3) << nr <<  " digit sum of " << std::setw(3) << addLastNrdu(num, nr) << "\n";
    std::cout << "The number " << num << " has a last " << std::setw(3) << nr <<  " digit sum of " << std::setw(3) << addLastNmod(num, nr) << "\n";
  }
  std::cout << std::endl;

  return 0;
}

