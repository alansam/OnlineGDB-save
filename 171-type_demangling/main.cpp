// Works with g++ & and clang++. Needs C++14 minimum (-std=c++14)
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <cxxabi.h>

using namespace std::literals::string_literals;

template <class T>
std::string type_name() {
  typedef typename std::remove_reference<T>::type TR;
  std::unique_ptr<char, void(*)(void *)> own (
    abi::__cxa_demangle(typeid(TR).name(),
                        nullptr,
                        nullptr,
                        nullptr),
    std::free);
  std::string r_ = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const<TR>::value) { r_ += " const"s; }
  if (std::is_volatile<TR>::value) { r_ += " volatile"s; }
  if (std::is_lvalue_reference<T>::value) { r_ += "&"s; }
  else if (std::is_rvalue_reference<T>::value) { r_ += "&&"s; }
  return r_;
}

template <typename T>
auto tostring = [](T ti) {
  auto out = std::string(typeid(ti).name()) + " - "s + type_name<decltype(ti)>();
  return out;
};

struct schain {
  schain * next;
  schain * last;
  char data[128];
};

int main() {
  auto greeting = "Hello World!\n\n"s;
  std::cout << greeting;
  auto searchfor = "Wo"s;
  auto pos = greeting.find(searchfor);
  std::cout << "pos: "s << pos << '\n';
  std::cout << "pos: "s << tostring<decltype(pos)>(pos) << '\n';
  std::cout << std::endl;

  auto volatile vole = 123LL;
  std::cout << "vole: "s << vole << '\n';
  std::cout << "vole: "s << tostring<decltype(vole)>(vole) << '\n';
  std::cout << std::endl;

  schain chainhome { nullptr, nullptr, { '\0' }, };
  size_t constexpr chainhome_sz = sizeof(chainhome);
  std::cout << "struct schain: "s << chainhome.next << ' ' << chainhome.last << ' ' << std::quoted(chainhome.data) << '\n';
  std::cout << "struct schain: "s << tostring<decltype(chainhome)>(chainhome) << '\n';
  std::cout << std::endl;
  std::cout << "chainhome_sz: "s << chainhome_sz << '\n';
  std::cout << "chainhome_sz: "s << tostring<decltype(chainhome_sz)>(chainhome_sz) << '\n';
  std::cout << std::endl;
}

