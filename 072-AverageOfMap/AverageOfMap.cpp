
#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <map>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

enum province { North, East, South, West, };
auto province_name = std::map<province, std::string_view> {
  { province::North, "North"sv },
  { province::East,  "East"sv, },
  { province::South, "South"sv },
  { province::West,  "West"sv  },
};
auto province_to_sv = [](province name) -> std::string_view {
  auto rv = province_name[name];
  return rv;
};

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << '\n' << "C++ Version: "sv << __cplusplus << '\n' << std::endl;

  auto temps = std::map<province, int32_t> {
    { province::North, 20, },
    { province::East,  37, },
    { province::South, 41, },
    { province::West,  35, },
  };
  
  std::for_each(temps.cbegin(), temps.cend(), [](auto & pm) {
    auto & [prov, temp] = pm;
    std::cout << std::setw(7) << province_to_sv(prov) << ": "sv
              << std::setw(5) << temp << "\u00b0 C"sv
              << std::endl;
  });
  std::cout << std::endl;

  auto avgtemp = std::accumulate(temps.cbegin(), temps.cend(), 0.0, [](auto total, auto & pm) {
    auto & [prov, temp] = pm;
    return total + temp;
  }) / temps.size();

  std::cout << " Avg. Temp: "sv
            << std::fixed << std::setprecision(2) << avgtemp << "\u00b0 C"sv
            << std::endl;

  return 0;
}

