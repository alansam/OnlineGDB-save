//
//  cubes.cpp
//  CF.Cube_Odd_Values
//
//  Created by Alan Sampson on 8/18/21.
//

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std::literals::string_literals;

//  MARK: - Constants.
static
size_t constexpr ASZ { 80ull };
static
auto const dlm = std::string(100, '~');

//  MARK: - Definitions.
static
auto sa(void) -> std::vector<int>;
static
auto sb(void) -> std::vector<int>;
static
auto sc(void) -> std::vector<int>;
static
auto sd(void) -> std::vector<int>;

//  MARK: - Implementation.
//  MARK: Global lambda functions
/*
 *  MARK: prtcontainer()
 *
 *  pretty-print a container
 */
static
auto prtcontainer = [](auto const & ctr) {
  std::for_each(std::cbegin(ctr), std::cend(ctr), [cc = 0ull, cc_max = 10ull](auto nr) mutable {
    std::cout << std::setw(10) << nr << (++cc % cc_max == 0 ? "\n" : "");
  });
  std::cout << std::endl;
};

/*
 *  MARK: get_random_engine()
 *
 *  create a random number generator engine
 */
static
auto get_random_engine = [](void) {
  std::random_device rd;
#ifdef RE_DEFAULT
  std::default_random_engine re(rd());
#else
  std::mt19937 re(rd());
#endif /* RE_DEFAULT */

  return re;
};

/*
 *  MARK: main()
 */
int main([[maybe_unused]] int argc, [[maybe_unused]] const char * argv[]) {
  std::cout << "C++ Version: " << __cplusplus << '\n' << std::endl;

  auto rv = [&](auto const & icpy) {
    std::cout << "cubes of odd numbers ("s << icpy.size() << " total):"s << std::endl;
    prtcontainer(icpy);
    std::cout << std::endl;
  };

  std::cout << dlm << std::endl;
  rv(sa());

  std::cout << dlm << std::endl;
  rv(sb());

  std::cout << dlm << std::endl;
  rv(sc());

  std::cout << dlm << std::endl;
  rv(sd());

  return 0;
}

/*
 *  MARK: sa()
 *
 *  sample using a std::array<int>
 */
auto sa(void) -> std::vector<int> {
  std::cout << "std::array<int>:"s << std::endl;

  auto re = get_random_engine();
  std::uniform_int_distribution<int> ruid(0, 500);

  std::array<int, ASZ> iary;
  for (auto i_ { 0ull }; i_ < ASZ; ++i_) {
    iary[i_] = ruid(re);
  }

  prtcontainer(iary);

  std::transform(iary.begin(), iary.end(), iary.begin(), [](auto nr) {
    return nr % 2 == 0 ? nr : nr * nr * nr;
  });

  prtcontainer(iary);

  auto icpy = std::vector<int>();
  std::remove_copy_if(iary.cbegin(), iary.cend(), std::back_inserter(icpy), [](auto nr) {
    return nr % 2 == 0;
  });

  return icpy;
}

/*
 *  MARK: sb()
 *
 *  sample using an int[] array
 */
auto sb(void) -> std::vector<int> {
  std::cout << "int[]:"s << std::endl;

  auto re = get_random_engine();
  std::uniform_int_distribution<int> ruid(0, 500);

  int iary[ASZ] { 0, };
  for (auto i_ { 0ULL }; i_ < ASZ; ++i_) {
    iary[i_] = ruid(re);
  }

  prtcontainer(iary);

  std::transform(std::cbegin(iary), std::cend(iary), std::begin(iary), [](auto nr) {
    return nr % 2 == 0 ? nr : nr * nr * nr;
  });

  prtcontainer(iary);

  auto icpy = std::vector<int>();
  std::remove_copy_if(std::cbegin(iary), std::cend(iary), std::back_inserter(icpy), [](auto nr) {
    return nr % 2 == 0;
  });

  return icpy;
}

/*
 *  MARK: sc()
 *
 *  sample using a std::array<int>
 */
auto sc(void) -> std::vector<int> {
  std::cout << "std::array<int>:"s << std::endl;

  auto re = get_random_engine();
  std::uniform_int_distribution<int> ruid(0, 500);

  std::array<int, ASZ> iary;
  for (auto i_ { 0ull }; i_ < ASZ; ++i_) {
    iary[i_] = ruid(re);
  }

  prtcontainer(iary);

  std::transform(iary.begin(), iary.end(), iary.begin(), [ix = 0](auto nr) mutable {
    return ix++ % 2 != 0 ? nr : nr * nr * nr;
  });

  prtcontainer(iary);

  auto icpy = std::vector<int>();
  std::remove_copy_if(iary.cbegin(), iary.cend(), std::back_inserter(icpy),
                      [ix = 0]([[maybe_unused]] auto nr) mutable {
    return ix++ % 2 != 0;
  });

  return icpy;
}

/*
 *  MARK: sd()
 *
 *  sample using an int[] array
 */
auto sd(void) -> std::vector<int> {
  std::cout << "int[]:"s << std::endl;

  auto re = get_random_engine();
  std::uniform_int_distribution<int> ruid(0, 500);

  int iary[ASZ] { 0, };
  for (auto i_ { 0ULL }; i_ < ASZ; ++i_) {
    iary[i_] = ruid(re);
  }

  prtcontainer(iary);

  std::transform(std::cbegin(iary), std::cend(iary), std::begin(iary),
                 [ix = 0](auto nr) mutable {
    return ix++ % 2 != 0 ? nr : nr * nr * nr;
  });

  prtcontainer(iary);

  auto icpy = std::vector<int>();
  std::remove_copy_if(std::cbegin(iary), std::cend(iary), std::back_inserter(icpy),
                      [ix = 0]([[maybe_unused]] auto nr) mutable {
    return ix++ % 2 != 0;
  });

  return icpy;
}
