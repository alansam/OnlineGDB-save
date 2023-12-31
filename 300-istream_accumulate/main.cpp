
#include <iostream>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <vector>

int main() {
  auto count { 0u };
  auto ct { 0u };
  std::cin >> ct;
  std::cout << "count: " << ct << '\n';
  auto nums = std::vector<int>();
  std::copy_if(std::istream_iterator<int>(std::cin),
               std::istream_iterator<int>(),
               std::back_inserter(nums),
               [&count, &ct](auto nr) {
                 auto c1 { false };
                 if (count <= ct) {
                   c1 = nr >= 1 && nr <= 100 ? (count++ < ct ? true : false) : false;
                 }
                 return c1;
               });
  std::cout << " nums: ";
  std::for_each(nums.begin(), nums.end(), [](auto nr){
    std::cout << std::setw(3) << nr;
  });
  std::cout << std::endl;
  auto sum = std::accumulate(nums.begin(), nums.end(), 0);
  std::cout << "  sum: " << sum << '\n';
  std::cout << std::endl;

  return 0;
}

