
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>

#include "Car.h"
#include "Person.h"
#include "Engine.h"

using namespace std::literals::string_literals;

/*
 *  Three classes: Person, Car, Engine
 *
 *  Person & Car have aggregation association
 *
 *  Car & Engine have composition association
 *
 *  Each class has one variable
 *
 *  Each class has one constructor, one Destructor
 *
 *  Create object to imply the relation between Person and Car, and Engine and Car so that
 *  when you destroy the object of Person the Car will not be destroyed.
 *
 *  When you destroy the object of Car, the object of Engine will be destroyed too.
 */

auto show_car = [](auto const & cv) -> void {
  std::cout << std::endl;
  std::cout << "Show Car details:"s << '\n';

  for (auto const & car : cv) {
    std::cout << std::endl;
    std::cout << "Car type is a "s << car.get_carType() << std::endl;
    std::cout << "Car has a "s << car.get_carEngine().get_engType() << " engine."s << std::endl;
    std::cout << "Person who owns the car is: "s << car.get_owner()->get_personName() << std::endl;
    std::cout << std::endl;
  }
  std::cout << "Display complete."s << '\n';
  std::cout << std::endl;
};

/*
 *  MARK: main()
 */
int main([[maybe_unused]] int argc, [[maybe_unused]] char const * argv[]) {
  std::cout << "\nBegin main scope"s << '\n';
  Person owner0("Ahmad"s);
  { //  block 1
    std::cout << "\nBegin scope 1"s << '\n';

    Car auto0("Chrysler"s, "V-6"s, &owner0);
    owner0.set_car(&auto0);
  
    auto auto1 = Car("Honda"s, "Flat-4"s);
    { //  block 2
      std::cout << "\nBegin scope 2"s << '\n';

      auto owner1 = Person("Norma Snockers"s, &auto1);
      auto1.set_owner(&owner1);

      std::cout << std::endl;
      std::cout << "Create vector of Car"s << '\n';
      std::vector<Car> cv { auto0, auto1, };
      std::cout << "Vector created"s << '\n';

      std::cout << "Call lambda to display details"s << '\n';
      show_car(cv);
      std::cout << "Lambda returned"s << '\n';
      std::cout << std::endl;

      std::cout << "\nEnd scope 2"s << '\n';
    } // block 2

    { // block 3
      std::cout << "\nBegin scope 3"s << '\n';

      auto owner1 = Person("Norma Snockers"s, &auto1);
      auto1.set_owner(&owner1);

      std::cout << std::endl;
      std::cout << "Show Car details:"s << '\n';

      std::cout << "Inline loop to display details"s << '\n';
      for (auto const & car : { auto0, auto1, }) {
        std::cout << std::endl;
        std::cout << "Car type is a "s << car.get_carType() << std::endl;
        std::cout << "Car has a "s << car.get_carEngine().get_engType() << " engine."s << std::endl;
        std::cout << "Person who owns the car is: "s << car.get_owner()->get_personName() << std::endl;
        std::cout << std::endl;
      }
      std::cout << "Loop complete"s << '\n';

      std::cout << "Display complete."s << '\n';
      std::cout << std::endl;
      
      std::cout << "\nEnd scope 3"s << '\n';
    }

    std::cout << "\nEnd scope 1"s << '\n';
  } // block 1

  std::cout << "\nEnd main scope"s << '\n';

  return 0;
}
