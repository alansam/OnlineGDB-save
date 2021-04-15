/// MARK: - References.
/// @see: https://www.fluentcpp.com/2019/05/24/how-to-fill-a-cpp-collection-with-random-values/


#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

namespace ft1 {
void fit_the_first(void);
}
namespace ft2 {
void fit_the_second(void);
}
namespace ft3 {
void fit_the_third(void);
}

/// MARK: - Implementation.
/// MARK: main()
int main(int argc, char const * argv[]) {
  ft1::fit_the_first();
  ft2::fit_the_second();
  ft3::fit_the_third();
}

/// MARK: fit_the_first()
namespace ft1 {
void fit_the_first(void) {
  std::cout << "Function: " << __func__ << std::endl;

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_int_distribution<int> distribution_1_100(1, 100);

  auto const randomNumber = distribution_1_100(random_engine);

  std::cout << randomNumber << '\n' << std::endl;
}
} /* namespace ft1 */

/// MARK: fit_the_second()
namespace ft2 {
void fit_the_second(void) {
  std::cout << "Function: " << __func__ << std::endl;

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_int_distribution<int> distribution_1_100(1, 100);

  std::vector<int> numbers(10);
  std::iota(numbers.begin(), numbers.end(), 1);

  for (size_t i = 0; i < numbers.size(); ++i) {
    numbers[i] = distribution_1_100(random_engine);
  }

  std::copy(numbers.cbegin(), numbers.cend(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n' << std::endl;
}
} /* namespace ft2 */

/// MARK: - Class RandomNumberBetween
namespace ft3 {

namespace ranges
{
template<typename Range, typename Generator>
void generate(Range & range, Generator generator) {
  return std::generate(begin(range), 
                       end(range),    
                       generator);
}

} /* namespace ranges */

/// MARK: Class RandomNumberBetween
// C++11
class RandomNumberBetween
{
public:
  RandomNumberBetween(int low = 1, int high = 100)
    : random_engine_{std::random_device{}()},
      distribution_{low, high} {
    instance_id = instance_counter++;
    std::cout << "RandomNumberBetween:"
              << std::setw(3) << instance_id
              << std::endl;
  }

  int operator()() {
    return distribution_(random_engine_);
  }

private:
  std::mt19937 random_engine_;
  std::uniform_int_distribution<int> distribution_;
  size_t instance_id;
  static size_t instance_counter;
};
size_t RandomNumberBetween::instance_counter(0);

//C++14
auto randomNumberBetween = [](int low, int high) {
  auto randomFunc = [distribution_ =
    std::uniform_int_distribution<int>(low, high),
                      random_engine_ = std::mt19937 {
                      std::random_device{}() }]() mutable {
    auto rret = distribution_(random_engine_);
    return rret;
  };
  return randomFunc;
};

/// MARK: fit_the_third()
void fit_the_third(void) {
  std::cout << "Function: " << __func__ << std::endl;

  std::vector<int> numbers1;
  std::generate_n(std::back_inserter(numbers1), 500, 
    RandomNumberBetween(1, 100));
  // or ranges::generate(numbers, RandomNumberBetween(1, 100));

  size_t constexpr cc_max(20);
  size_t cc;
  cc = 0;
  for (int number : numbers1) {
    std::cout << std::setw(4) << number
              << (++cc % cc_max == 0 ? "\n" : "");
  }
  std::cout << '\n' << std::endl;

  std::vector<int> numbers2(500);
  ranges::generate(numbers2, RandomNumberBetween(0, 99));
  cc = 0;
  for (int number : numbers2) {
    std::cout << std::setw(4) << number
              << (++cc % cc_max == 0 ? "\n" : "");
  }
  std::cout << '\n' << std::endl;


  std::vector<int> numbers3;
  std::generate_n(std::back_inserter(numbers3), 500,
    randomNumberBetween(100, 200));
  for (int number : numbers3) {
    std::cout << std::setw(4) << number
              << (++cc % cc_max == 0 ? "\n" : "");
  }
  std::cout << '\n' << std::endl;

  std::vector<int> numbers4(500);
  ranges::generate(numbers4, randomNumberBetween(-99, 0));
  cc = 0;
  for (int number : numbers4) {
    std::cout << std::setw(4) << number
              << (++cc % cc_max == 0 ? "\n" : "");
  }
  std::cout << '\n' << std::endl;

}
} /* namespace ft3 */
