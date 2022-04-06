
// #define NDEBUG

#include <iostream>
#include <iomanip>
#include <string>

using namespace std::literals::string_literals;

/*
 *  MARK: Class thing
 */
class thing {
public:
  thing() = default;
  thing(thing const & that) = delete;
  thing(thing && that) = delete;
  virtual ~thing() = default;
  thing & operator=(thing const & that) = delete;
  thing & operator=(thing && that) = delete;

  double setlength(double l) {
#ifndef NDEBUG
    std::cout << thing::id() << "::" << __func__ << '(' << l << ')' << '\n';
#endif
    if (l > 0.0 && l < 21.0) {
      length_ = l;
    }
    else {
      std::cerr << "invalid length " << l << '\n';
    }
    return length_;
  }

  double getlength() const {
#ifndef NDEBUG
    std::cout << thing::id() << "::" << __func__ << "()" << '\n';
#endif
    return length_;
  }

  int type(void) const {
    return type_;
  }

  virtual std::string const & id(void) const {
    static
    std::string const id_ = "thing"s;
    return id_;
  }

protected:
  double length_;
  int type_ { 0 };
};

/*
 *  MARK: Class thingie
 */
class thingie : public thing {
public:
  thingie(double l = 0.0) {
#ifndef NDEBUG
    std::cout << id() << "::" << __func__ << "()" << '\n';
#endif
    // setlength(l);
    length_ = l;
    type_ = 1;
  }
  thingie(thingie const & that) = delete;
  thingie(thingie && that) = delete;
  virtual ~thingie() = default;
  thingie & operator=(thingie const & that) = delete;
  thingie & operator=(thingie && that) = delete;

  virtual std::string const & id(void) const override {
    static
    std::string const id_ = "thingie"s;
    return id_;
  }
};

/*
 *  MARK: Templare ttest()
 */
template<class T>
void ttest(T & thingy, double val = 4.0) {
  // std::cout << "Type: " << (thingy.type() == 0 ? "thing" : "thingie") << '\n';
  std::cout << "Type: " << thingy.id() << '\n';
  std::cout << "Address: " << &thingy << '\n';
  std::cout << thingy.getlength() << '\n';
  std::cout << thingy.setlength(45.0) << '\n';
  std::cout << thingy.setlength(val) << '\n';
  std::cout << thingy.getlength() << '\n';
  std::cout << std::endl;
}

/*
 *  MARK: ctest()
 */
void ctest(thing & thingy, double val = 3.0) {
  // std::cout << "Type: " << (thingy.type() == 0 ? "thing" : "thingie") << '\n';
  std::cout << "Type: " << thingy.id() << '\n';
  std::cout << "Address: " << &thingy << '\n';
  std::cout << thingy.getlength() << '\n';
  std::cout << thingy.setlength(45.0) << '\n';
  std::cout << thingy.setlength(val) << '\n';
  std::cout << thingy.getlength() << '\n';
  std::cout << std::endl;
}

/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  auto const dlm = std::string(60, '~');

  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
  std::cout << dlm << std::endl;
  thing thing01;
  // std::cout << "Type: " << (thing01.type() == 0 ? "thing" : "thingie") << '\n';
  std::cout << "Type: " << thing01.id() << '\n';
  std::cout << "Address: " << &thing01 << '\n';
  std::cout << thing01.getlength() << '\n';
  std::cout << thing01.setlength(45.0) << '\n';
  std::cout << thing01.setlength(10.0) << '\n';
  std::cout << thing01.getlength() << '\n';
  std::cout << std::endl;

  std::cout << dlm << std::endl;
  thingie thing02;
  // std::cout << "Type: " << (thing02.type() == 0 ? "thing" : "thingie") << '\n';
  std::cout << "Type: " << thing02.id() << '\n';
  std::cout << "Address: " << &thing02 << '\n';
  std::cout << thing02.getlength() << '\n';
  std::cout << thing02.setlength(45.0) << '\n';
  std::cout << thing02.setlength(20.0) << '\n';
  std::cout << thing02.getlength() << '\n';
  std::cout << std::endl;

  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
  std::cout << dlm << std::endl;
  thing thing03;
  ttest(thing03, 5.0);

  std::cout << dlm << std::endl;
  thingie thing04;
  ttest(thing04);

  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
  std::cout << dlm << std::endl;
  thing thing05;
  ctest(thing05, 6.0);

  std::cout << dlm << std::endl;
  thingie thing06;
  ctest(thing06, 7.0);

  return 0;
}

