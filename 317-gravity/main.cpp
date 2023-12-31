// Could anyone help me to resolve error of this code its my assignment in Dev-C++
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define ALGO_

double fallDistance(double t) {
  constexpr double g = 9.81;
  double d = 0.5 * g * pow(t, 2);
  return d;
}

int main() {
  double times[] = { 1., 3., 5., 7., };
  constexpr size_t NUM_TIMES = sizeof times / sizeof *times;
  double sum = 0.0;
  std::cout << std::fixed << std::setprecision(3);

#ifdef ALGO_
  std::for_each(std::cbegin(times), std::cend(times), [&sum](auto const & tm) {
    double distance = fallDistance(tm);
    sum += distance;
    std::cout << "Time " << tm << " seconds "
              << std::setw(7) << distance << "m"<< std::endl;
  });
#else
  for (size_t i_ = 0ul; i_ < NUM_TIMES; ++i_) {
    double distance = fallDistance(times[i_]);
    sum += distance;
    std::cout << "Time " << times[i_] << " seconds "
              << std::setw(7) << distance << "m"<< std::endl;
  }
#endif

  double average = sum / NUM_TIMES;
  std::cout << "Average Distance covered: "
            << std::setw(7) << average << "m" << std::endl;

  return 0;
}
