#pragma once

#include <iostream>
#include <iomanip>

class Cls {
private:
  double len_ = 0.0;
  double breadth_ = 0.0;
  double area_ = 0.0;

public:
  Cls() = default;
  Cls(Cls const & that) = default;
  Cls(Cls && that) = default;
  ~Cls();
  Cls & operator=(Cls const & that) = default;
  Cls & operator=(Cls && that) = default;

  double CalcArea(double const len = 0.0, double const breadth = 0.0);

  inline
  double area(void) const;
  inline
  double len(void) const;
  inline
  double breadth(void) const;

  friend
  std::ostream & operator<<(std::ostream & os, Cls const & that);
};

inline
double Cls::area(void) const {
  return area_;
}
inline
double Cls::len(void) const {
  return len_;
}
inline
double Cls::breadth(void) const {
  return breadth_;
}
