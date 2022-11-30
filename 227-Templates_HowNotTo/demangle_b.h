//  @see: https://cplusplus.com/forum/beginner/175177/

#pragma once
#ifndef DEMANGLE_B_H
#define DEMANGLE_B_H

#include <string>
#include <typeinfo>
#include <cstdlib>
#include <cxxabi.h>

static
inline
std::string demangle(char const * mangled_name) {

  std::string result;
  std::size_t len = 0;
  int status = 0;
  char * ptr = __cxxabiv1::__cxa_demangle(mangled_name, nullptr, &len, &status);

  if (status == 0) {
    result = ptr; // hope that this won't throw
  }
  else {
    result = "demangle error";
  }

  ::free(ptr);
  return result;
}

#endif /* DEMANGLE_B_H */
