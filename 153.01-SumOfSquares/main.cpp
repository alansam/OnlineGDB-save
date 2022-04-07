
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <vector>
#include <cstdlib>

// #define MAX_LIMIT_
#ifdef MAX_LIMIT_
static
size_t constexpr maximum_limit { 1'000'000'000 };
#else   /* MAX_LIMIT_ */
static
size_t constexpr maximum_limit { 20 };
#endif  /* MAX_LIMIT_ */

int main() {

  auto show = [](auto const & col) {
    for (auto const nr : col) {
      std::cout << std::setw(20) << nr << '\n';
    }
  };
  auto count = 0ul;

  do {
    std::cout << "Number [0 to stop]: ";
    std::cout.flush();
    std::cin >> count;
    std::cout << "[echo] " << count << '\n';
    if (count == 0ul) {
      std::cout << "Terminating ...\n";
      break;
    }
    if (count > maximum_limit) {
      std::cerr << count << " exceeds maximum\n";
      exit(EXIT_FAILURE);
    }

    auto nrs = std::vector<uint64_t>(count);

    std::iota(nrs.begin(), nrs.end(), 1ul);
    std::cout << "iota\n";
    // show(nrs);

    auto sqr_of_evens = [](auto nr) -> uint64_t {
      // std::cout << ": " << nr;
      nr <<= 0x01;
      // std::cout << " : " << nr << '\n';
      return nr * nr;
    };

// #define DISCRETE_
#ifdef DISCRETE_

    std::transform(nrs.begin(), nrs.end(), nrs.begin(), sqr_of_evens);
    std::cout << "transform\n";
    // show(nrs);
    auto result = std::reduce(nrs.begin(), nrs.end(), 0ul, std::plus<>{});
    std::cout << "reduce\n";
    std::cout << "result: " << std::setw(20) << result << std::endl;

#else   /* DISCRETE_ */

    auto result = std::transform_reduce(nrs.begin(), nrs.end(), 0ul, std::plus<>{}, sqr_of_evens);
    std::cout << "transform_reduce\n";
    // show(nrs);
    std::cout << "result: " << std::setw(20) << result << std::endl;

#endif  /* DISCRETE_ */

  } while (count != 0ul);

  return EXIT_SUCCESS;
}

