
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <array>
#include <numeric>
#include <utility>
#include <fstream>

using namespace std::literals::string_literals;

auto const file_name { "./salaries.txt"s };

int main() {
  auto payroll = std::map<std::string, std::array<double, 12>>();

  auto infl = std::ifstream(file_name);
  if (infl.is_open()) {
    auto line { ""s };
    auto ln { 0u };
    while (std::getline(infl, line)) {
      std::cout << ++ln << ": "s << std::quoted(line) << '\n';
      auto rlin = std::istringstream { line };
      auto nom = ""s;
      auto sal = std::array<double, 12>();
      std::getline(rlin, nom, ':');
      nom.erase(nom.find_last_not_of(" \t\r\n"s) + 1);
      rlin >> sal[ 0] >> sal[ 1] >> sal[ 2] >> sal[ 3] >> sal[ 4] >> sal[ 5]
           >> sal[ 6] >> sal[ 7] >> sal[ 8] >> sal[ 9] >> sal[10] >> sal[11];
      payroll.emplace(std::make_pair(nom, sal));
    }
    infl.close();
  }
  else {
    std::cerr << "Unable to open "s << file_name << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << std::endl;

  std::cout << std::setprecision(2) << std::fixed;
  for (auto const & [name, salary] : payroll) {
    auto sum = std::accumulate(salary.cbegin(), salary.cend(), 0.0);
    std::cout << std::setw(20) << name << ':' << std::setw(12) << sum << '\n';
  }

  return EXIT_SUCCESS;
}
