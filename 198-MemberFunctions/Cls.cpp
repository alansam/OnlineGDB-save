
#include "Cls.hpp"

Cls::~Cls() {
  std::cout << "@[" << std::setw(18) << this << "] - destroyed here!" << std::endl;
}

double Cls::CalcArea(double const len, double const breadth) {
  len_ = len;
  breadth_ = breadth;
  area_ = len_ * breadth_;
  return area_;
}

std::ostream & operator<<(std::ostream & os, Cls const & that) {
  os << "@[" << std::setw(18) << &that << "] - ";
  os << "Length: "    << std::setw(8) << that.len()
     << ", Breadth: " << std::setw(8) << that.breadth()
     << ", Area: "    << std::setw(8) << that.area();

  return os;
}
