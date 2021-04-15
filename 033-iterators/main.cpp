
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

void accum(void);
void collect(void);

int main() {

//  accum();
  collect();

  return 0;
}

void accum(void) {
  std::cout << "Enter numbers to accumulate. Enter any non-numeric value to terminate." << std::endl;
  auto const sum = std::accumulate(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), 0, std::plus<>());
  std::cout << sum << std::endl;
}

void collect(void) {
  size_t cmax;
  std::cout << "Enter max. number of values to accumulate." << std::endl;
  std::cin >> cmax;
  std::vector<int> collect(cmax);
  std::cout << "Enter numbers to accumulate. Enter any non-numeric value to terminate." << std::endl;

  size_t ec(0);
  std::copy_if(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), collect.begin(), [&ec](auto n_){
    ++ec;
    return n_;
  });
  collect.resize(ec);

  auto const sum = std::accumulate(collect.cbegin(), collect.cend(), 0, std::plus<>());
  auto const [vmin, vmax] = std::minmax_element(collect.cbegin(), collect.cend());

  std::cout << "vector contents:\n";
  std::copy(collect.cbegin(), collect.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  std::sort(collect.begin(), collect.end());

  std::cout << "vector sorted:\n";
  std::copy(collect.cbegin(), collect.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  auto collect_sz(collect.size());

  std::cout << "vector size: " << collect_sz
            << ", min: "  << *vmin
            << ", max: "  << *vmax
            << ", sum: "  << sum
            << ", mean: " << std::fixed << (static_cast<double>(sum) / collect_sz)
            << std::endl;
}
