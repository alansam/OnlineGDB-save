
#include <iostream>
#include <iomanip>
#include <string>

#define NO_DEFAULT

class Product {
private:
  std::string name;

public:
#ifdef NO_DEFAULT
  Product(std::string name = "") : name(name) {}
#else
  Product() = default;
  Product(std::string name) : name { name } {}
#endif
  std::string getName() {
    return name;
  }
};

int main() {
  Product product1;
  Product product2("Norma Snockers");
  Product product3("");
  std::cout << std::setw(4) << product1.getName().size() << " " << product1.getName() << std::endl;
  std::cout << std::setw(4) << product2.getName().size() << " " << product2.getName() << std::endl;
  std::cout << std::setw(4) << product3.getName().size() << " " << product3.getName() << std::endl;

  return 0;
}

