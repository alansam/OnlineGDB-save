//  @see: https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c

#include <iostream>
#include <string>
#include <typeinfo>
#include <memory>
#include <cstdlib>
#include <cxxabi.h>

using namespace std::literals::string_literals;

template <class T>
std::string type_name() {
  typedef typename std::remove_reference<T>::type TR;
  std::unique_ptr<char, void(*)(void*)> own (
    abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
    std::free
 );
  std::string r = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const<TR>::value) {
    r += " const";
  }
  if (std::is_volatile<TR>::value) {
    r += " volatile";
  }
  if (std::is_lvalue_reference<T>::value) {
    r += "&";
  }
  else if (std::is_rvalue_reference<T>::value) {
    r += "&&";
  }
  return r;
}

int main() {
  auto s1 = "hello 1";
  auto s2 = std::string("hello 2");
  auto s3 = "hello 3"s;
  std::cout << s1 << " - " << typeid(s1).name() << " - " << type_name<decltype(s1)>() << '\n';
  std::cout << s2 << " - " << typeid(s2).name() << " - " << type_name<decltype(s2)>() << '\n';
  std::cout << s3 << " - " << typeid(s3).name() << " - " << type_name<decltype(s3)>() << '\n';

  return 0;
}

