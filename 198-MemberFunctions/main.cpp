
#include <memory>

#include "Cls.hpp"

int main(int argc, char const * argv[]) {
  std::cout << "Cls::Cls driver\n";

  {
    auto c1 = Cls();
    std::cout << std::fixed
              << std::setprecision(3);
    std::cout << c1.CalcArea(6. + 2. / 3., 3. + 1. / 3.) << std::endl;
    std::cout << c1.area() << std::endl;
    std::cout << c1 << std::endl;

    auto c2 = Cls();
    std::cout << c2 << std::endl;
  }

  {
    auto c3 = new Cls();
    c3->CalcArea(22.4, 10.0);
    std::cout << *c3 << std::endl;

    {
      auto c4 = std::make_unique<Cls>();
      c4->CalcArea(5.0, 22.4);
      std::cout << *c4 << std::endl;
      c4 = nullptr;
    }

    delete c3;
    c3 = nullptr;
  }

  return 0;
}
