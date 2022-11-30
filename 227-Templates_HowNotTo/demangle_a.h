//  @see: https://gist.github.com/koko-u/9562379

#pragma once
#ifndef DEMANGLE_A_H
#define DEMANGLE_A_H

#include <cxxabi.h>
#include <typeinfo>
#include <memory>
#include <iostream>
#include <string>
#include <cstdlib>

struct FreeDeleter {
    void operator()(char* ptr) {
        free(ptr);
    }
};

static
inline
std::string demangle(char const* name) {
    int status;
    std::unique_ptr<char, FreeDeleter> demangled_name(__cxxabiv1::__cxa_demangle(name, nullptr, nullptr, &status));
    switch (status) {
    case 0:
        return std::string(demangled_name.get());
    case -1:
        return "A memory allocation failure occurred.";
    case -2:
        return "name is not a valid name under the C++ ABI mangling rules.";
    case -3:
        return "One of the arguments is invalid.";
    default:
        return "Unknown error.";
    }
}

#ifdef INCLUDE_MAIN_
int main() {
#else
static
inline
int demangle_a_sampler(void) {
  std::cout << "In fnuction " << __func__ << "()\n";
#endif /* INCLUDE_MAIN_ */
  std::cout << demangle(typeid("hello").name()) << std::endl;
  std::cout << demangle(typeid(FreeDeleter).name()) << std::endl;
  return 0;
}

#endif /* DEMANGLE_A_H */
