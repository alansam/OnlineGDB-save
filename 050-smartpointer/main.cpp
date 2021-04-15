//
//  main.cpp
//  CF.SmartPointers01
//
//  Created by Alan Sampson on 2/23/21.
//

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <utility>

using namespace std::literals::string_literals;

/*
 *  MARK: Class X
 */
class X {
public:
  X(std::string str = ""s) : x_str_(str) {
    instance = instance_ctr++;
    std::cout << std::setw(20)
              << this
              << " X Dflt c'tor >"s
              << std::setw(4)
              << instance
              << std::setw(4)
              << x_str_.size()
              << ' '
              << '\"'
              << x_str_
              << '\"'
              << '\n';
  }

  X(X const & that) {
    x_str_ = that.x_str_;
    instance = instance_ctr++;
    std::cout << std::setw(20)
              << this
              << " X Copy c'tor >"s
              << std::setw(4)
              << instance
              << std::setw(4)
              << x_str_.size()
              << ' '
              << '\"'
              << x_str_
              << '\"'
              << '\n';
  }

  X(X && that) {
    x_str_ = std::move(that.x_str_);
    instance = std::move(that.instance);
    std::cout << std::setw(20)
              << this
              << " X Move c'tor >"s
              << std::setw(4)
              << instance
              << std::setw(4)
              << x_str_.size()
              << ' '
              << '\"'
              << x_str_
              << '\"'
              << '\n';
  }

  X & operator=(X const & that) {
    x_str_ = that.x_str_;
    return *this;
  }

  X & operator=(X && that) {
    x_str_ = std::move(that.x_str_);
    return *this;
  }

  virtual ~X() {
    std::cout << std::setw(20)
              << this
              << " X ~~~~ d'tor <"s
              << std::setw(4)
              << instance
              << std::setw(4)
              << x_str_.size()
              << ' '
              << '\"'
              << x_str_
              << '\"'
              << '\n';
  }

  std::string x_str(void) {
    return x_str_;
  }
  std::string x_str(std::string str) {
    x_str_ = str;
    return x_str_;
  }

private:
  std::string x_str_;
  size_t instance;

  static
  size_t instance_ctr;
};

size_t X::instance_ctr(0ULL);

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "050-SmartPointer01" << std::endl;

  X x0;
  X x1(">x");
  X * x2 = new X("->x");
  std::unique_ptr<X> x3 = std::make_unique<X>(X("-->a"));
  auto x4 = std::make_unique<X>("--->a");

  std::vector<X> vx { x0, x1, *x2, *x3.get(), *x4.get(), };
  for (auto x_ : vx) {
    std::cout << ' '
              << x_.x_str().size()
              << " -- \'"
              << x_.x_str()
              << "\'"
              << std::endl;
  }

  delete x2;

  return 0;
}
