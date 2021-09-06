
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

//  +....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: Class Animal
 */
class Animal {
public:
  Animal() = delete;
  Animal(std::string name, double cost) : name_ { name }, cost_ { cost } {}
  ~Animal() = default;
  Animal(Animal const & that) = default;
  Animal(Animal && that) = default;
  Animal & operator = (Animal const & that) = default;
  Animal & operator = (Animal && that) = default;

  bool operator == (Animal const & that) const {
    if (name_ == that.name_) {
      if (cost_ == cost_) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }

  bool operator <  (Animal const & that) const {
    if (name_ < that.name_) {
      return true;
    }
    else if (name_ == that.name_ && cost_ < that.cost_) {
      return true;
    }
    else {
      return false;
    }
  }

  bool operator >  (Animal const & that) const {
    if (name_ > that.name_) {
      return true;
    }
    else if (name_ == that.name_ && cost_ > that.cost_) {
      return true;
    }
    else {
      return false;
    }
  }

  bool operator >= (Animal const & that) const {
    if (name_ >= that.name_) {
      return true;
    }
    else if (name_ == that.name_ && cost_ >= that.cost_) {
      return true;
    }
    else {
      return false;
    }
  }

  bool operator <= (Animal const & that) const {
    if (name_ <= that.name_) {
      return true;
    }
    else if (name_ == that.name_ && cost_ <= that.cost_) {
      return true;
    }
    else {
      return false;
    }
  }

  std::string toString(void) const {
    std::ostringstream oss;
    oss << std::setw(20) << name() 
        << ' '
        << std::fixed << std::setprecision(2) << std::setw(10) << cost();
    return oss.str();
  }

  std::string const & name(void) const {
    return name_;
  }

  double cost(void) const {
    return cost_;
  }

  static
  long const version(void) {
    return version_;
  }

private:
  std::string name_;
  double cost_;

  static
  long const version_ = 1;
};

//  +....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: main()
 */
int main() {
  std::cout << "C++ Version: " << __cplusplus << '\n' << std::endl;

  std::cout << "Animal version: " << Animal::version() << std::endl;

  auto animals = std::vector<Animal> {
    { "cat", 25.0, }, { "dog", 50.0, }, { "zebra", 2575.0, },
    { "aardvark", 1250.0, }, { "gnu", 2300.0, },
  };

  std::cout << std::string(80, '~') << std::endl;
  std::for_each(animals.cbegin(), animals.cend(), [](auto & anml) {
    std::cout << anml.toString() << '\n';
  });

  std::sort(animals.begin(), animals.end(), [](auto & lhs, auto & rhs) {
    return lhs > rhs;
  });

  std::cout << std::string(80, '~') << std::endl;
  std::for_each(animals.cbegin(), animals.cend(), [](auto & anml) {
    std::cout << anml.toString() << '\n';
  });

  return 0;
}
