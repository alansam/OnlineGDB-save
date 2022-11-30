//  @see: https://www.lemoda.net/c/maths-constants/

#include <iostream>
#include <iomanip>
#include <string>
#if __cplusplus >= 202002
#include <numeric>
#include <numbers>
#include <utility>
#include <tuple>
#endif
#include <cmath>

#define V(x) { x, #x, }

struct constant {
  double value;
  const char * name;
};

using namespace std::literals::string_literals;

void mconsts(void);
#if __cplusplus >= 202002
void nconsts(void);
void nmrcs(void);
#endif

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  auto dlm = std::string(60, '-');

   std::cout << std::fixed << std::setprecision(3);
  for (auto x_ : { 0., 1., 2., 3., 5., 7., 11., 13., 19., 23., 29., 31., }) {
    std::cout << dlm << '\n';
    std::cout << "X = "s << std::setw(6) << x_ << '\n';
    for (auto p_ : { 0, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, }) {
      auto pwr  = p_ != 0 ? 1. / p_ : 0;

      auto root = ::pow(x_, pwr);
      auto rtle = ::exp(::log(x_) / p_);
      std::cout << " Power: "s << std::setw(6) << pwr
                << " ("s << std::setw(3) << p_ << "\u221aX)"s
                << ", Root = "s << std::setw(6) << root
                << ", Via log = "s << std::setw(6) << rtle
                << '\n';
    }
    std::cout.put('\n');
  }
  std::cout.put('\n');

  std::cout << std::setprecision(6);
  for (auto xx : { 2000., 1500., 1000., 500., 250., 200., 100., 50., 25., 20., 10., 5., 4., M_PI, 3., M_E, 2., 1., .5, .25, .2, .125, .1, .02, .01, .002, .001, .0002, .0001, 0., }) {
    auto xxl10 = ::log10(xx);
    auto xxi10 = ::pow(10, xxl10);
    auto xxle  = ::log(xx);
    auto xxie  = ::exp(xxle);
    auto xxl2  = ::log2(xx);
    auto xxi2  = ::pow(2, xxl2);

    std::cout << std::setw(12) << xx
              << ", log\u2081\u2080"s
              << std::setw(12) << xxl10
              << " == "s
              << std::setw(12) << xxi10
              << ", log\u2091"s
              << std::setw(12) << xxle
              << " == "s
              << std::setw(12) << xxie
              << ", log\u2082"s
              << std::setw(12) << xxl2
              << " == "s
              << std::setw(12) << xxi2
              << '\n';
  }

  std::cout.put('\n');
  std::cout << dlm << '\n';

  mconsts();

#if __cplusplus >= 202002
  std::cout.put('\n');
  std::cout << dlm << '\n';

  nconsts();

  std::cout.put('\n');
  std::cout << dlm << '\n';

  nmrcs();

  std::cout.put('\n');
#endif

  std::cout << std::endl;

  return 0;
}

/*
 *  MARK: mconsts()
 */
void mconsts(void) {
  constant constants[] = {
    V(M_E),
    V(M_LOG2E),
    V(M_LOG10E),
    V(M_LN2),
    V(M_LN10),
    V(M_PI),
    V(M_PI_2),
    V(M_PI_4),
    V(M_1_PI),
    V(M_2_PI),
    V(M_2_SQRTPI),
    V(M_SQRT2),
    V(M_SQRT1_2),
    V(HUGE_VALF),
    V(MAXFLOAT),
    V(HUGE_VAL),
  };
  size_t n_constants = sizeof constants / sizeof *constants;

  for (size_t i_ = 0; i_ < n_constants; i_++) {
    printf ("%-10s: %12.6g\n", constants[i_].name, constants[i_].value);
  }
}

#if __cplusplus >= 202002
/*
 *  MARK: nconsts()
 */
void nconsts(void) {
  constant constants[] {
    V(std::numbers::e),
    V(std::numbers::log2e),
    V(std::numbers::log10e),
    V(std::numbers::pi),
    V(std::numbers::inv_pi),
    V(std::numbers::inv_sqrtpi),
    V(std::numbers::ln2),
    V(std::numbers::ln10),
    V(std::numbers::sqrt2),
    V(std::numbers::sqrt3),
    V(std::numbers::inv_sqrt3),
    V(std::numbers::egamma),
    V(std::numbers::phi),
  };

  for (auto cc : constants) {
    std::cout << std::setw(24) << cc.name 
              << std::setw(12) << cc.value
              << '\n';
  }
}
#endif

#if __cplusplus >= 202002
static
auto constexpr lcm(auto l_, auto r_) {
  return std::lcm(l_, r_);
}
static
auto constexpr lcm(auto head, auto ... tail) {
  return std::lcm(head, lcm(tail ...));
}
static
auto constexpr gcd(auto l_, auto r_) {
  return std::gcd(l_, r_);
}
static
auto constexpr gcd(auto head, auto ... tail) {
  return std::gcd(head, gcd(tail ...));
}
/*
 *  MARK: nmrcs()
 */
void nmrcs(void) {
  for (auto const & p_ : {
    std::make_pair(4, 7),
    std::make_pair(24, 17),
    std::make_pair(2, 1),
  }) {
    auto l_ = p_.first;
    auto r_ = p_.second;
    std::cout << "gcd("s
              << std::setw(2) << l_
              << ','
              << std::setw(2) << r_
              << ") = "s
              << std::setw(4) << gcd(l_, r_)
              << '\n';
    std::cout << "lcm("s
              << std::setw(2) << l_
              << ','
              << std::setw(2) << r_
              << ") = "s
              << std::setw(4) << lcm(l_, r_)
              << '\n';
    std::cout.put('\n');
  }

 for (auto t_ : {
    std::make_tuple(5, 4, 7),
    std::make_tuple(25, 14, 17),
    std::make_tuple(55, 43, 71),
    std::make_tuple(1, 2, 3),
  }) {
    auto t0 = std::get<0>(t_);
    auto t1 = std::get<1>(t_);
    auto t2 = std::get<2>(t_);
    std::cout << "gcd("s
              << std::setw(2) << t0
              << ','
              << std::setw(2) << t1
              << ','
              << std::setw(2) << t2
              << ") = "s
              << std::setw(7) << gcd(t0, t1, t2)
              << '\n';
    std::cout << "lcm("s
              << std::setw(2) << t0
              << ','
              << std::setw(2) << t1
              << ','
              << std::setw(2) << t2
              << ") = "s
              << std::setw(7) << lcm(t0, t1, t2)
              << '\n';
    std::cout.put('\n');
  }
}
#endif
