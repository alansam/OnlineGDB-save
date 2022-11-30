
#pragma once
#ifndef IDENTIFY_H
#define IDENTIFY_H

#ifdef __cplusplus
# include <iostream>
#else
# include <stdio.h>
#endif

#ifdef __cplusplus
namespace avi {
#else
static
#endif

inline
void identify(void) {
#if defined(__clang__)
# ifdef __cplusplus
  std::cout << "Compiler: clang\n\n";
# else
  puts("Compiler: clang");
# endif
#elif defined(__GNUC__) && !defined(__clang__)
# ifdef __cplusplus
  std::cout << "Compiler: gnu c\n\n";
# else
  puts("Compiler: gnu c");
# endif
#else
# ifdef __cpluplus
  std::cout << "Compiler:: other\n\n";
# else
  puts("Compiler:: other");
# endif
#endif

  return;
}

#ifdef __cplusplus
} /* namespace avi */
#endif

#endif
