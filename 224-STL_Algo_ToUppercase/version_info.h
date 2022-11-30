//
//  version_info.h
//
//  Created by Alan Sampson on 3/21/22.
//

#ifndef version_info_h
#define version_info_h

#ifdef __cplusplus
#   include <iostream>
#   include <cstdio>
#   include <cstdlib>
#else
#   include <stdio.h>
#   include <stdlib.h>
#endif

#ifdef __cplusplus
namespace avi {
#endif  /* __cplusplus */

//  MARK: - Macro Definitions
#ifdef __GNUC__
//#   pragma message ("__GNUC__ found ")
#   ifndef _GNUC_VER_NEW
//#     pragma message ("_GNUC_VER_NEW not found")
#     ifndef GCC_VERSION
#       define GCC_VERSION (__GNUC__ * 10000 \
                          + __GNUC_MINOR__ * 100 \
                          + __GNUC_PATCHLEVEL__)
#     endif /* GCC_VERSION */
#   else  /* _GNUC_VER_NEW */
//#     pragma message ("_GNUC_VER_NEW found")
#     ifndef GCC_VERSION
#       define GCC_VERSION _GNUC_VER_NEW
#     endif /* GCC_VERSION */
#   endif /* _GNUC_VER_NEW */
#endif  /* __GNUC__ */

#ifdef __GNU_MP_VERSION
#   ifndef GNU_MP_VERSION
#   define GNU_MP_VERSION (__GNU_MP_VERSION * 10000 \
                          + __GNU_MP_VERSION_MINOR * 100 \
                          + __GNU_MP_VERSION_PATCHLEVEL)
#   endif
#endif  /* __GNU_MP_VERSION */

//  MARK: - Inline Implementations
/*
 *  MARK: version_details()
 */
#ifndef __cplusplus
static
#endif
inline
void version_details(void) {
#ifdef __cplusplus
  std::cout << "C++ version: " << __cplusplus << '\n'
#   ifdef _LIBCPP_STD_VER
            << "libcpp standard version: " <<  _LIBCPP_STD_VER << '\n'
#   endif
#   ifdef __STDC_VERSION__
            << "C version: iso9899:" << __STDC_VERSION__ << '\n'
#   endif
            << "Compiler version: " << __VERSION__ << '\n'
#   ifdef GCC_VERSION
            << "GNU C version: " << GCC_VERSION << '\n'
#   endif
#   ifdef __GNU_MP_RELEASE
            << "GNU MP Version Number: " << gmp_version << '\n'
            << "GNU multiple precision arithmetic library (GMP): " << __GNU_MP_RELEASE << '\n'
            << "GNU MP Compiler: " << __GMP_CC << '\n'
            << "GNU MP Compiler flags: " << __GMP_CFLAGS << '\n'
#   endif
            << std::endl;
#else /* __cplusplus */
#   ifdef _LIBCPP_STD_VER
  printf("libcpp standard version: %s\n", _LIBCPP_STD_VER );
#   endif
#   ifdef __STDC_VERSION__
  printf("C version: iso9899:%ld\n", __STDC_VERSION__);
#   endif
  printf("Compiler version: %s\n", __VERSION__);
#   ifdef GCC_VERSION
  printf("GNU C version: %d\n", GCC_VERSION);
#   endif
#   ifdef __GNU_MP_RELEASE
  printf("GNU MP Version Number: %s\n", gmp_version);
  printf("GNU multiple precision arithmetic library (GMP): %d\n", __GNU_MP_RELEASE);
  printf("GNU MP Compiler: %s\n", __GMP_CC);
  printf("GNU MP Compiler flags: %s\n", __GMP_CFLAGS);
#   endif
  puts("");
#endif  /* __cplusplus */

  return;
}

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* version_info_h */
