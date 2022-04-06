
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class Product {
private:
  std::string name;

public:
  // Product() : Product("dflt") {}
  // Product() = default;
  // Product(std::string name) : name(name) {}
  Product(std::string name = "dflt") : name(name) {}

  std::string getName() {
    return name;
  }

  static
  void oddly(void);
};


int main() {

  Product::oddly();

  Product product;
  std::cout << product.getName() << '\n';
  
  return 0;
}

void Product::oddly(void) {
  auto show = [](auto const & nums) {
    std::cout << '\n' << std::setw(3) << nums.size() << '\n';
    auto cc_max = 25ul;
    auto cc = 1ul;
    for (auto nr : nums) {
      std::cout << std::setw(3) << nr << ((cc++ % cc_max == 0) ? "\n" : "");
    }
    std::cout << std::endl;
  };

  auto odds1 = std::vector<uint16_t>();
  auto even1 = std::vector<uint16_t>();

  for (uint16_t i_ = 0; i_ < 100; ++i_) {
    if (i_ % 2 == 0) {
      even1.push_back(i_);
    }
    else {
      odds1.push_back(i_);
    }
  }

  show(even1);
  show(odds1);

  auto odds2 = std::vector<uint16_t>();
  auto even2 = std::vector<uint16_t>();

  
  for (uint16_t i_ = 0; i_ < 100; ++i_) {
    if ((i_ & 0x01)) {
      odds2.push_back(i_);
    }
    else {
      even2.push_back(i_);
    }
  }

  show(even2);
  show(odds2);

  return;
}

