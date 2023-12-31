//  @see: https://www.gnu.org/software/libc/manual/html_node/Mathematical-Constants.html
//  #see: https://en.cppreference.com/w/cpp/numeric/constants
//  @see: https://codebrowser.dev/gcc/include/math.h.html

#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <string>

using namespace std::literals::string_literals;

#ifndef __cpp_lib_math_constants
#   error "GRONK! C++ math constants are required. Refer to feature test macro: __cpp_lib_math_constants"
#endif

template <class FloatType>
struct K {
    std::string name;
    FloatType k_c;
    FloatType k_cpp;
};

static
K<double> const k_d[] {
    { "M_E          e_v          e"s,         M_E,                            std::numbers::e_v<double>,                  },
    { "M_LOG2E      log2e_v      log2e"s,     M_LOG2E,                        std::numbers::log2e_v<double>,              },
    { "M_LOG10E     log10e_v     log10e"s,    M_LOG10E,                       std::numbers::log10e_v<double>,             },
    { "M_LN2        ln2_v        ln2"s,       M_LN2,                          std::numbers::ln2_v<double>,                },
    { "M_LN10       ln10_v       ln10"s,      M_LN10,                         std::numbers::ln10_v<double>,               },
    { "M_PI         pi_v         π"s,         M_PI,                           std::numbers::pi_v<double>,                 },
    { "M_PI_2       -            π/2"s,       M_PI_2,                         std::numbers::pi_v<double> / 2.0,           },
    { "M_PI_4       -            π/4"s,       M_PI_4,                         std::numbers::pi_v<double> / 4.0,           },
    { "M_1_PI       inv_pi_v     1/π"s,       M_1_PI,                         std::numbers::inv_pi_v<double>,             },
    { "M_2_PI       -            2/π"s,       M_2_PI,                         std::numbers::inv_pi_v<double> * 2.0,       },
    { "-            inv_sqrtpi_v 1/√π"s,      M_2_SQRTPI / 2.0,               std::numbers::inv_sqrtpi_v<double>,         },
    { "M_2_SQRTPI   -            2*1/√π"s,    M_2_SQRTPI,                     std::numbers::inv_sqrtpi_v<double> * 2.0,   },
    { "M_SQRT2      sqrt2_v      √2"s,        M_SQRT2,                        std::numbers::sqrt2_v<double>,              },
    { "-            sqrt3_v      √3"s,        std::sqrt(3.0),                 std::numbers::sqrt3_v<double>,              },
    { "-            inv_sqrt3_v  1/√3"s,      1.0 / std::sqrt(3.0),           std::numbers::inv_sqrt3_v<double>,          },
    { "M_SQRT1_2    sqrt2_v      1/(√2)"s,    M_SQRT1_2,                      1.0 / std::numbers::sqrt2_v<double>,        },
    { "-            phi_v        phi"s,       (1.0 + std::sqrt(5.0)) / 2.0,   std::numbers::phi_v<double>,                },
    { "*            egamma_v     egamma"s,    0x1.2788cfc6fb619p-1,           std::numbers::egamma_v<double>,             },
    // { "*            egamma_v     egamma"s,    0.57721566490153287,            std::numbers::egamma_v<double>,             },
};

#ifdef M_Ef
static
K<float> const k_f[] {
    { "M_Ef         e_v          e"s,         M_Ef,                               std::numbers::e_v<float>,                   },
    { "M_LOG2Ef     log2e_v      log2e"s,     M_LOG2Ef,                           std::numbers::log2e_v<float>,               },
    { "M_LOG10Ef    log10e_v     log10e"s,    M_LOG10Ef,                          std::numbers::log10e_v<float>,              },
    { "M_LN2f       ln2_v        ln2"s,       M_LN2f,                             std::numbers::ln2_v<float>,                 },
    { "M_LN10f      ln10_v       ln10"s,      M_LN10f,                            std::numbers::ln10_v<float>,                },
    { "M_PIf        pi_v         π"s,         M_PIf,                              std::numbers::pi_v<float>,                  },
    { "M_PI_2f      -            π/2"s,       M_PI_2f,                            std::numbers::pi_v<float> / 2.0f,           },
    { "M_PI_4f      -            π/4"s,       M_PI_4f,                            std::numbers::pi_v<float> / 4.0f,           },
    { "M_1_PIf      inv_pi_v     1/π"s,       M_1_PIf,                            std::numbers::inv_pi_v<float>,              },
    { "M_2_PIf      -            2/π"s,       M_2_PIf,                            std::numbers::inv_pi_v<float> * 2.0f,       },
    { "-            inv_sqrtpi_v 1/√π"s,      M_2_SQRTPIf / 2.0f,                 std::numbers::inv_sqrtpi_v<float>,          },
    { "M_2_SQRTPIf  -            2*1/√π"s,    M_2_SQRTPIf,                        std::numbers::inv_sqrtpi_v<float> * 2.0f,   },
    { "M_SQRT2f     sqrt2_v      √2"s,        M_SQRT2f,                           std::numbers::sqrt2_v<float>,               },
    { "-            sqrt3_v      √3"s,        std::sqrt(3.0f),                    std::numbers::sqrt3_v<float>,               },
    { "-            inv_sqrt3_v  1/√3"s,      1.0f / std::sqrt(3.0f),             std::numbers::inv_sqrt3_v<float>,           },
    { "M_SQRT1_2f   sqrt2_v      1/(√2)"s,    M_SQRT1_2f,                         1.0f / std::numbers::sqrt2_v<float>,        },
    { "-            phi_v        phi"s,       (1.0f + std::sqrt(5.0f)) / 2.0f,    std::numbers::phi_v<float>,                 },
    { "*            egamma_v     egamma"s,    0x1.2788dp-1f,                      std::numbers::egamma_v<float>,              },
    // { "*            egamma_v     egamma"s,    0.577215672f,            std::numbers::egamma_v<float>,              },
    
};
#else
//  lifted from https://codebrowser.dev/gcc/include/math.h.html
K<float> const k_f[] {
    { "M_Ef*        e_v          e"s,         2.7182818284590452354f,             std::numbers::e_v<float>,                   },
    { "M_LOG2Ef*    log2e_v      log2e"s,     1.4426950408889634074f,             std::numbers::log2e_v<float>,               },
    { "M_LOG10Ef*   log10e_v     log10e"s,    0.43429448190325182765f,            std::numbers::log10e_v<float>,              },
    { "M_LN2f*      ln2_v        ln2"s,       0.69314718055994530942f,            std::numbers::ln2_v<float>,                 },
    { "M_LN10f*     ln10_v       ln10"s,      2.30258509299404568402f,            std::numbers::ln10_v<float>,                },
    { "M_PIf*       pi_v         π"s,         3.14159265358979323846f,            std::numbers::pi_v<float>,                  },
    { "M_PI_2f*     -            π/2"s,       1.57079632679489661923f,            std::numbers::pi_v<float> / 2.0f,           },
    { "M_PI_4f*     -            π/4"s,       0.78539816339744830962f,            std::numbers::pi_v<float> / 4.0f,           },
    { "M_1_PIf*     inv_pi_v     1/π"s,       0.31830988618379067154f,            std::numbers::inv_pi_v<float>,              },
    { "M_2_PIf*     -            2/π"s,       0.63661977236758134308f,            std::numbers::inv_pi_v<float> * 2.0f,       },
    { "M_2_SQRTPIf* -            2*1/√π"s,    1.12837916709551257390f,            std::numbers::inv_sqrtpi_v<float> * 2.0f,   },
    { "M_SQRT2f*    sqrt2_v      √2"s,        1.41421356237309504880f,            std::numbers::sqrt2_v<float>,               },
    { "-            sqrt3_v      √3"s,        std::sqrt(3.0f),                    std::numbers::sqrt3_v<float>,               },
    { "-            inv_sqrt3_v  1/√3"s,      1.0f / std::sqrt(3.0f),             std::numbers::inv_sqrt3_v<float>,           },
    { "M_SQRT1_2f*  sqrt2_v      1/(√2)"s,    0.70710678118654752440f,            1.0f / std::numbers::sqrt2_v<float>,        },
    { "-            phi_v        phi"s,       (1.0f + std::sqrt(5.0f)) / 2.0f,    std::numbers::phi_v<float>,                 },
    { "*            egamma_v     egamma"s,    0x1.2788dp-1f,                      std::numbers::egamma_v<float>,              },
    // { "*            egamma_v     egamma"s,    0.577215672f,                       std::numbers::egamma_v<float>,              },
};
#endif

//   The above constants are not adequate for computation using `long double's.
//   Therefore we provide as an extension constants with similar names as a
//   GNU extension.  Provide enough digits for the 128-bit IEEE quad.
static
K<long double> const k_l[] {
    { "M_El         e_v          e"s,         M_El,                               std::numbers::e_v<long double>,                 },
    { "M_LOG2El     log2e_v      log2e"s,     M_LOG2El,                           std::numbers::log2e_v<long double>,             },
    { "M_LOG10El    log10e_v     log10e"s,    M_LOG10El,                          std::numbers::log10e_v<long double>,            },
    { "M_LN2l       ln2_v        ln2"s,       M_LN2l,                             std::numbers::ln2_v<long double>,               },
    { "M_LN10l      ln10_v       ln10"s,      M_LN10l,                            std::numbers::ln10_v<long double>,              },
    { "M_PIl        pi_v         π"s,         M_PIl,                              std::numbers::pi_v<long double>,                },
    { "M_PI_2l      -            π/2"s,       M_PI_2l,                            std::numbers::pi_v<long double> / 2.0l,         },
    { "M_PI_4l      -            π/4"s,       M_PI_4l,                            std::numbers::pi_v<long double> / 4.0l,         },
    { "M_1_PIl      inv_pi_v     1/π"s,       M_1_PIl,                            std::numbers::inv_pi_v<long double>,            },
    { "M_2_PIl      -            2/π"s,       M_2_PIl,                            std::numbers::inv_pi_v<long double> * 2.0l,     },
    { "M_2_SQRTPIl  -            2*1/√π"s,    M_2_SQRTPIl,                        std::numbers::inv_sqrtpi_v<long double> * 2.0l, },
    { "M_SQRT2l     sqrt2_v      √2"s,        M_SQRT2l,                           std::numbers::sqrt2_v<long double>,             },
    { "-            sqrt3_v      √3"s,        std::sqrt(3.0l),                    std::numbers::sqrt3_v<double>,                  },
    { "-            inv_sqrt3_v  1/√3"s,      1.0l / std::sqrt(3.0l),             std::numbers::inv_sqrt3_v<double>,              },
    { "M_SQRT1_2l   sqrt2_v      1/(√2)"s,    M_SQRT1_2l,                         1.0l / std::numbers::sqrt2_v<long double>,      },
    { "-            phi_v        phi"s,       (1.0l + std::sqrt(5.0l)) / 2.0l,    std::numbers::phi_v<long double>,               },
    { "*            egamma_v     egamma"s,    0x9.3c467e37db0c7a5p-4l,            std::numbers::egamma_v<long double>,            },
    // { "*            egamma_v     egamma"s,    0.577215664901532860616l,           std::numbers::egamma_v<float>,                  },
};

/*
 *  MARK:   main()
 */
int main(int argc, char const * argv[]) {
    std::cout << "C++ Version: "s << __cplusplus << '\n';
    std::cout << "  Feature test macro: __cpp_lib_math_constants = "s << __cpp_lib_math_constants << "\n\n"s;

    std::cout << "- float:\n";
    std::cout << std::string(60, '-') << '\n';
    std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10 + 1);
    for (auto const & el : k_f) {
        std::cout << std::setw(24) << el.k_c << std::setw(24) << el.k_cpp << " : "s << el.name << '\n';
    }
    std::cout << std::endl;

    std::cout << "- double:\n";
    std::cout << std::string(60, '-') << '\n';
    std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10 + 1);
    for (auto const & el : k_d) {
        std::cout << std::setw(24) << el.k_c << std::setw(24) << el.k_cpp << " : "s << el.name << '\n';
    }
    std::cout << std::endl;

    std::cout << "- long double:\n";
    std::cout << std::string(60, '-') << '\n';
    std::cout << std::fixed << std::setprecision(std::numeric_limits<long double>::digits10 + 1);
    for (auto const & el : k_l) {
        std::cout << std::setw(24) << el.k_c << std::setw(24) << el.k_cpp << " : "s << el.name << '\n';
    }
    std::cout << std::endl;

    std::cout << "Note:\n"s
              << "  - derived value.\n"s
              << "  * hard-coded value.\n\n"s;
    auto d10_f  { std::numeric_limits<float>::digits10 };
    auto d10m_f { std::numeric_limits<float>::max_digits10 };
    auto d10_d  { std::numeric_limits<double>::digits10 };
    auto d10m_d { std::numeric_limits<double>::max_digits10 };
    auto d10_l  { std::numeric_limits<long double>::digits10 };
    auto d10m_l { std::numeric_limits<long double>::max_digits10 };
    std::cout << "digits10, max_digits10:\n"
              << std::setw(15) << "float"
              << std::setw(3) << d10_f << std::setw(3) << d10m_f << '\n'
              << std::setw(15) << "double"
              << std::setw(3) << d10_d << std::setw(3) << d10m_d << '\n'
              << std::setw(15) << "long double"
              << std::setw(3) << d10_l << std::setw(3) << d10m_l << '\n';

    std::cout << "egamma\n";
    std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::max_digits10) //(20)
              << std::numbers::egamma_v<float>
              << std::setw(d10m_l - d10m_f + 1) << ' '
              << std::hexfloat
              << std::numbers::egamma_v<float>
              << '\n';
    std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::max_digits10) //(24)
              << std::numbers::egamma_v<double>
              << std::setw(d10m_l - d10m_d + 1) << ' '
              << std::hexfloat
              << std::numbers::egamma_v<double>
              << '\n';
    std::cout << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10) //(36)
              << std::numbers::egamma_v<long double> << ' '
              << std::hexfloat
              << std::numbers::egamma_v<long double>
              << '\n';

    return 0;
}

