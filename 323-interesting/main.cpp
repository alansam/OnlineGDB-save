
#include <iostream>
#include <iomanip>
#include <cmath>

double simple(double Principal, double Time, double Rate);
double compound(double Principal, double Time, double Rate, double Number_of_times);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "323-Interesting\n";

  auto Principal { 10'000.0 };
  auto Time { 7.0 };
  auto Rate { 6.25 };
  auto si { 0.0 };
  auto ci { 0.0 };

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Simple Interest:\n";
  si = simple(Principal, Time, Rate);
  std::cout << "  Interest for " << Principal
            << " with ROI " << Rate << "\%"
            << " over " << Time << " periods"
            << " is " << si
            << '\n';
  std::cout << "  Total amount is " << Principal + si << '\n';
  std::cout << std::endl;

  std::cout << "Compound Interest:\n";
  for (auto No_of_times : { 4.0, 12.0 }) {
    ci = compound(Principal, Time, Rate, No_of_times);
    std::cout << "  Interest for " << Principal
              << " with ROI " << Rate << "\%"
              << " over " << Time << " periods"
              << " calculating " << No_of_times << " times per period"
              << " is " << ci
              << '\n';
    std::cout << "  Total amount is " << Principal + ci << '\n';
  }
  std::cout << std::endl;

  return 0;
}

/*
 *  MARK: simple()
 *
 *  Calculate SI = (P.T.R)/100
 */
double simple(double Principal, double Time, double Rate) {
  auto SI { 0.0 };
  SI = (Principal * Time * Rate) / 100.0;
  return SI;
}

/*
 *  MARK: compound()
 *
 *  Calculate FA = P * (1 + (R/(N*100)))^(N.T)
 */
double compound(double Principal, double Time, double Rate, double Number_of_times) {
  auto FA { 0.0 };
  auto CI { 0.0 };
  FA = Principal * ::pow(1.0 + (Rate / (Number_of_times * 100.0)), (Number_of_times * Time));
  CI = FA - Principal;
  return CI;
}


