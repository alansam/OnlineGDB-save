
#include <iostream>
#include <iomanip>
#include <array>
#include <set>
#include <random>
#include <stdexcept>

using namespace std::literals::string_literals;

//  MARK: even / odd
auto even = [](auto & tv) -> bool { return (tv % 2 == 0); };

//  MARK: line break
auto nb = [](auto & ic, auto const & cc) -> std::string {
  return (ic++ % cc == 0 ? "\n"s : ""s);
};

//  MARK: show contents of a collection
auto show = [](auto const & coll) {
  for (auto ic { 1 }, cc { 10 }; auto & rv : coll) {
    std::cout << std::setw(5) << rv << nb(ic, cc);
  }
  std::cout << std::endl;
};

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  auto constexpr ect {  20ul };
  auto constexpr min {  60ul };
  auto constexpr max { 150ul };
  auto RC = EXIT_SUCCESS;

  try {
    if (ect > (max - min)) {
      throw std::range_error("too many elements");
    }

    auto rd = std::random_device();

    auto generator = std::mt19937_64(rd());

    auto dist = std::uniform_int_distribution<uint64_t> { min, max };

    auto results = std::set<uint64_t>();

    while (results.size() != ect) {
      auto rv = dist(generator);
      if (even(rv)) {
        results.insert(rv);
      }
    }

    auto rarry = std::array<uint64_t, ect>();
    std::copy(results.cbegin(), results.cend(), rarry.begin());

    show(rarry);
  }
  catch (std::exception const & ex) {
    std::cerr << ex.what() << std::endl;
    RC = EXIT_FAILURE;
  }

  return RC;
}


