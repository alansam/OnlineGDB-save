/*
 *  @see: https://atechdaily.com/posts/algorithm-for-armstrong-number
 *  @see: https://en.wikipedia.org/wiki/Narcissistic_number
 *  @see: https://rosettacode.org/wiki/Narcissistic_decimal_number
 *  @see: https://oeis.org/A005188
 *  @see: https://mathworld.wolfram.com/NarcissisticNumber.html
 *  @see:
 */

#include <iostream>
#include <iomanip>
#include <vector>

bool is_armstrong(uint64_t nr);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "321-ArmstrongNumbers\n";
  auto results = std::vector<uint64_t>();
  for (uint64_t result = 0ull; results.size() <= 2; ++result) {
    if (is_armstrong(result)) {
      results.push_back(result);
    }
  }

  for (auto cc = 1ul; auto anum : results) {
    std::cout << std::setw(7) << anum << (cc++ % 5 == 0 ? "\n" : "");
  }

  return 0;
}

/*
 *  MARK: is_armstrong()
 */
bool is_armstrong(uint64_t nr) {
  auto sum { 0ull };
  auto nr_save { nr };
  std::clog << "1: " << nr_save << '\n';

  while (nr >= 0ull) {
    auto nrem = (nr % 10);
    std::clog << "2: " << nrem << '\n';
    sum += nrem * nrem * nrem;
    std::clog << "3: " << sum << '\n';
    nr /= 10ull;
  }

  return (sum == nr_save);
}

