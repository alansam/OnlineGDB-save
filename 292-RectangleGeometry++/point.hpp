#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std::literals::string_literals;

/*
 *  MARK: Class point.
 */
class point {
public:
  //  MARK: Constructors & destructor
  point(double const X = 0.0, double const Y = 0.0)
  : X_ { X }, Y_ { Y } {
    std::clog << "In point::point() default c'tor\n";
  }
  point(point const & that) {
    std::clog << "In point::point() copy c'tor\n";
    X_ = that.X_;
    Y_ = that.Y_;
  }
  point(point && that) {
    std::clog << "In point::point() move c'tor\n";
    X_ = std::move(that.X_);
    Y_ = std::move(that.Y_);
  }
  ~point() {
    std::clog << "In point::~point() d'tor\n";
  }

  //  MARK: operator=()
  point & operator=(point const & that) {
    std::clog << "In point::operator=() copy\n";
    X_ = that.X_;
    Y_ = that.Y_;
    return *this;
  }
  point & operator=(point && that) {
    std::clog << "In point::operator=() move\n";
    X_ = std::move(that.X_);
    Y_ = std::move(that.Y_);
    return *this;
  }

  //  MARK: Getters & setters
  double X(void) const     { return X_; }
  double X(double const X) { return (X_ = X); }
  double Y(void) const     { return Y_; }
  double Y(double const Y) { return (Y_ = Y); }

  /*
   *  MARK: operator<<() friend function.
   */
  friend
  std::ostream & operator<<(std::ostream & os, point const & that) {
    os << std::setprecision(3) << std::fixed
       << "X:"s << std::setw(8) << that.X_ << ' '
       << "Y:"s << std::setw(8) << that.Y_;
    return os;
  }

private:
  double X_;
  double Y_;
};
