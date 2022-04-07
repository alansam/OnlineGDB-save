
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#ifdef VECTOR
#include <execution>
#endif

using namespace std::literals::string_literals;

int main() {
  float number[] = { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, };
  float product = 1.0F;

  std::cout << "the product of the first 10 numbers\n";
  for (auto nr : number) {
    product *= nr;
  }
  std::cout << std::fixed << product << std::endl;

  {
    auto prod = std::accumulate(std::begin(number), std::end(number), 1.0F, std::multiplies<float>());
    std::cout << std::fixed << prod << std::endl;
  }

  {
#ifdef VECTOR
    auto msg { " : reduce using std::execution::unsequenced_policy (std::execution::unseq)"s };
    auto prod = std::reduce(std::execution::unseq, std::begin(number), std::end(number), 1.0F, std::multiplies<float>());
#else
    auto msg { ""s };
    auto prod = std::reduce(std::begin(number), std::end(number), 1.0F, std::multiplies<float>());
#endif
    std::cout << std::fixed << prod << msg << std::endl;
  }

  return 0;
}

