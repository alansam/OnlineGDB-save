/*
 * Minimum compiler conformity: C++ 11
 * GNU g++ compiler flags: -Wall -pedantic -std=c++11
 */

#include <iostream>
#include <exception>

char const * f1(char const * str) {
  std::cout << __func__ << ": ";
  try {
    if (str) {
      return str;
    }
    else {
      throw "Error";
    }
  }
  catch (char const * exp) {
    return exp;
  }
}

char const * f2(char const * str) {
  std::cout << __func__ << ": ";
  try {
    if (str) {
      return str;
    }
    else {
      throw std::runtime_error("Runtime Exception");
    }
  }
  catch (std::exception & exp) {
    return exp.what();
  }
}

int main() {
  int i;
  printf("** \n");
  for (i = 1; i++ <= 1; i++)
//    printf("- %d\n", i);
    for (i++; i++ <= 6; i++)
      i++;
  //    printf("-- %d\n", i);
    
  
  printf("--- %d\n", i);
  return 0;
  std::cout << "C++ " << __cplusplus << '\n' << std::endl;

  char lo[] = "Hello";
  std::cout << ' ' << f1(lo) << std::endl;
  std::cout << ' ' << f1("L.O.") << std::endl;
  std::cout << ' ' << f1(nullptr) << '\n' << std::endl;

  std::cout << ' ' << f2(lo) << std::endl;
  std::cout << ' ' << f2("L.O.") << std::endl;
  std::cout << ' ' << f2(nullptr) << '\n' << std::endl;

  return 0;
}
