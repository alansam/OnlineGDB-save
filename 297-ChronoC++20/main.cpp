
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

static
auto constexpr cpp { __cplusplus / 100L - 2000L };

typedef std::chrono::duration<int32_t, std::ratio<    86'400>> d_days;
typedef std::chrono::duration<int32_t, std::ratio<   604'800>> d_weeks;
typedef std::chrono::duration<int32_t, std::ratio< 2'629'746>> d_months;
typedef std::chrono::duration<int32_t, std::ratio<31'556'952>> d_years;

static
void otherway(void);

int main(int argc, char const * argv[]) {
  std::cout << "C++ version : " << __cplusplus << '\n';
  std::cout << std::endl;

  auto time = std::chrono::system_clock::now();

#if __cplusplus >= 202002L
  std::cout << "C++" << cpp << " days  : "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::days>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " weeks : "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::weeks>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " months: "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::months>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " years : "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::years>(time.time_since_epoch()).count()
            << '\n';
#else
  // std::cout << "C++" << cpp << ' ' << std::chrono::duration_cast<std::chrono::hours>(time.time_since_epoch()).count() / 24 << '\n';

  std::cout << "C++" << cpp << " days  : "
            << std::setw(6)
            << std::chrono::duration_cast<d_days>(time.time_since_epoch()).count()
            // << std::chrono::duration_cast<std::chrono::duration<int32_t, std::ratio<86'400>>>(time.time_since_epoch()).count() 
            << '\n';
  std::cout << "C++" << cpp << " weeks : "
            << std::setw(6)
            << std::chrono::duration_cast<d_weeks>(time.time_since_epoch()).count()
            // << std::chrono::duration_cast<std::chrono::duration<int32_t, std::ratio<604'800>>>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " months: "
            << std::setw(6)
            << std::chrono::duration_cast<d_months>(time.time_since_epoch()).count()
            // << std::chrono::duration_cast<std::chrono::duration<int32_t, std::ratio<2'629'746>>>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " years : "
            << std::setw(6)
            << std::chrono::duration_cast<d_years>(time.time_since_epoch()).count()
            // << std::chrono::duration_cast<std::chrono::duration<int32_t, std::ratio<31'556'952>>>(time.time_since_epoch()).count()
            << '\n';
#endif
  std::cout << std::endl;

  otherway();

  return 0;
}


#if __cplusplus < 202002L
namespace std::chrono {
  typedef std::chrono::duration<int32_t, std::ratio<    86'400>> days;
  typedef std::chrono::duration<int32_t, std::ratio<   604'800>> weeks;
  typedef std::chrono::duration<int32_t, std::ratio< 2'629'746>> months;
  typedef std::chrono::duration<int32_t, std::ratio<31'556'952>> years;
}
#endif

static
void otherway(void) {
  std::cout << "In function " << __func__ << "()\n\n";

  auto time = std::chrono::system_clock::now();

  std::cout << "C++" << cpp << " days  : "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::days>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " weeks : "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::weeks>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " months: "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::months>(time.time_since_epoch()).count()
            << '\n';
  std::cout << "C++" << cpp << " years : "
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::years>(time.time_since_epoch()).count()
            << '\n';

  return;
}
