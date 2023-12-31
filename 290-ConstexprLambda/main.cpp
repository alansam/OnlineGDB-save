
#include <iostream>
#include <cmath>

auto constexpr pwr = [](size_t const val, size_t const expn) constexpr -> size_t {
  auto pwr = val;
  for (auto e_ = 1ul; e_ < expn; ++e_) {
    pwr *= val;
  }
  return pwr;
};

#ifdef __cpp_consteval
auto consteval pwv = [](size_t const val, size_t const expn) consteval -> size_t {
  auto pwr = val;
  for (auto e_ = 1ul; e_ < expn; ++e_) {
    pwr *= val;
  }
  return pwr;
};
#endif

int main() {
  std::cout << "__cplusplus: " << __cplusplus << '\n';

#ifdef __cpp_constexpr
  std::cout << "__cpp_constexpr: " << __cpp_constexpr << '\n';
#endif
#ifdef __cpp_constexpr_in_decltype
  std::cout << "__cpp_constexpr_in_decltype: " << __cpp_constexpr_in_decltype << '\n';
#endif
#ifdef __cpp_constexpr_dynamic_alloc
  std::cout << "__cpp_constexpr_dynamic_alloc: " << __cpp_constexpr_dynamic_alloc << '\n';
#endif
#ifdef __cpp_consteval
  std::cout << "__cpp_consteval: " << __cpp_consteval << '\n';
#endif
  std::cout << std::endl;

  auto constexpr dim_p { static_cast<size_t>(pow(2, 8)) };
  auto constexpr dim_l { 2ul * 2 * 2 * 2 * 2 * 2 * 2 * 2 };
  auto constexpr dim_f { pwr(2, 8) };

  puts("dim_p");
  std::printf("%zu %zu\n", sizeof dim_p, dim_p);
  int ar_p[dim_p] = { 0, };
  std::printf("%zu %zu\n", sizeof ar_p, sizeof ar_p / sizeof *ar_p);
  putchar('\n');

  puts("dim_l");
  std::printf("%zu %zu\n", sizeof dim_l, dim_l);
  int ar_l[dim_l] = { 0, };
  std::printf("%zu %zu\n", sizeof ar_l, sizeof ar_l / sizeof *ar_l);
  putchar('\n');

  puts("dim_f");
  std::printf("%zu %zu\n", sizeof dim_f, dim_f);
  int ar_f[dim_f] = { 0, };
  std::printf("%zu %zu\n", sizeof ar_f, sizeof ar_f / sizeof *ar_f);
  putchar('\n');

  puts("dim_F");
  std::printf("%zu %zu\n", sizeof pwr(2, 9), pwr(2, 8));
  int ar_F[pwr(2, 8)] = { 0, };
  std::printf("%zu %zu\n", sizeof ar_F, sizeof ar_F / sizeof *ar_F);
  putchar('\n');

  return 0;
}
