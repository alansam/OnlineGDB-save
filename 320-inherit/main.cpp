/*
 *  Make a program for me in which a public proTected and private
 *  inheritance use in one  code
 */
//  compiler options: -Wall -Wpedantic -fsanitize=leak

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std::literals::string_literals;

class if00 {
public:
  if00(uint16_t id)
  : ID_ { id } {
    std::clog << "[@"s << this << "] "s << "In if00::" << __func__ << "()\n"s;
  }
  virtual
  ~if00() {
    std::clog << "[@"s << this << "] "s << "In if00::" << __func__ << "()\n"s;
  }

  virtual std::string toString(void) const = 0; //  PV function

  friend
  std::ostream & operator<<(std::ostream & os, if00 const & that) {
    os << "if00::" << __func__ << "() - " << that.toString();
    return os;
  }

protected:
  uint16_t ID_;
};

class pif0 {
public:
  pif0() {
    std::clog << "[@"s << this << "] "s << "In pif0::" << __func__ << "()\n"s;
  }
  virtual
  ~pif0() {
    std::clog << "[@"s << this << "] "s << "In pif0::" << __func__ << "()\n"s;
  }

  std::string pif0x(void const * obj) const {
    std::stringstream ss;
    ss << "pif0::"s << __func__ << "(@" << std::hex << obj << std::dec << ")"s;
    return ss.str();
  }
};

class pif1 {
public:
  pif1() {
    std::clog << "[@"s << this << "] "s << "In pif1::" << __func__ << "()\n"s;
  }
  virtual
  ~pif1() {
    std::clog << "[@"s << this << "] "s << "In pif1::" << __func__ << "()\n"s;
  }

  std::string pif1x(void const * obj) const {
    std::stringstream ss;
    ss << "pif1::"s << __func__ << "(@" << std::hex << obj << std::dec << ")"s;
    return ss.str();
  }
};

class pif2 {
public:
  pif2() {
    std::clog << "[@"s << this << "] "s << "In pif2::" << __func__ << "()\n"s;
  }
  ~pif2() {
    std::clog << "[@"s << this << "] "s << "In pif2::" << __func__ << "()\n"s;
  }
  
  std::string pif2x(void const * obj) const {
    std::stringstream ss;
    ss << "pif2::"s << __func__ << "(@" << std::hex << obj << std::dec << ")"s;
    return ss.str();
  }
};

class imp00
: public if00,
  private pif0, private pif1,
  protected pif2 {
public:
  imp00(uint16_t id = 0u, std::string nm = ""s)
  : if00(id), name_ { nm } {
    std::clog << "[@"s << this << "] "s << "In ipm00::"s << __func__ << "()\n"s;
    if (name_.size() == 0) {
      name_ = __func__;
    }
  }
  virtual
  ~imp00() {
    std::clog << "[@"s << this << "] "s << "In ipm00::"s << __func__ << "()\n"s;
    if (name_.size() == 0) {
      name_ = __func__;
    }
  }

  std::string toString(void) const {
    std::clog << "[@"s << this << "] "s << "In ipm00::"s << __func__ << "()\n"s;
    std::stringstream ss;
    ss << std::setw(4) << ID_ << ' ' << std::quoted(name_);
    return ss.str();
  }

  virtual
  std::string f0x(void) const {
    std::clog << "[@"s << this << "] "s << "In ipm00::"s << __func__ << "()\n"s;
    return pif0x(this);
  }

  virtual
  std::string f1x(void) const {
    std::clog << "[@"s << this << "] "s << "In ipm00::"s << __func__ << "()\n"s;
    return pif1x(this);
  }

  virtual
  std::string f2x(void) const {
    std::clog << "[@"s << this << "] "s << "In ipm00::"s << __func__ << "()\n"s;
    return pif2x(this);
  }

  friend
  std::ostream & operator<<(std::ostream & os, imp00 const & that) {
    os << "imp00::"s << __func__ << "() - "s << that.toString();
    return os;
  }

private:
  std::string name_;
};

class imp01
: public imp00 {
public:
  imp01(uint16_t id = 0, std::string name = ""s) :
    imp00(id, name) {
    std::clog << "[@"s << this << "] "s << "In ipm01::"s << __func__ << "()\n"s;
  }
  virtual
  ~imp01() {
    std::clog << "[@"s << this << "] "s << "In ipm01::"s << __func__ << "()\n"s;
  }

  virtual
  std::string f2x(void) const {
    std::clog << "[@"s << this << "] "s << "In ipm01::"s << __func__ << "()\n"s;
    return pif2x(this);
  }
};

int main() {
  std::cout << "320-Inherit\n"s;

  imp00 i000;
  imp01 i010(1000, "imp01"s);
  std::cout << i000 << " - "s << i000.f0x() << ' ' << i000.f1x() << ' ' << i000.f2x() << '\n';
  std::cout << i010 << " - "s << i010.f0x() << ' ' << i010.f1x() << ' ' << i010.f2x() << '\n';

  return 0;
}

