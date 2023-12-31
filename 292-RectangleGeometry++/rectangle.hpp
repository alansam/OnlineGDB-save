#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "point.hpp"

using namespace std::literals::string_literals;

/*
 *  MARK: Class rectangle.
 */
class rectangle {
public:
  //  MARK: Constructors & destructor
  rectangle(point const & lu = point(), point const & rl = point())
  : u_l_ { lu }, l_r_ { rl } {
    std::clog << "In rectangle::rectangle() default c'tor\n";
    auto hlen = length() / 2.0;
    auto hhgt = height() / 2.0;
    ctr_ = point(hlen + u_l_.X(), hhgt + l_r_.Y());
  }
  rectangle(rectangle const & that) {
    std::clog << "In rectangle::rectangle() copy c'tor\n";
    u_l_ = that.u_l_;
    l_r_ = that.l_r_;
    ctr_ = that.ctr_;
  }
  rectangle(rectangle && that) {
    std::clog << "In rectangle::rectangle() move c'tor\n";
    u_l_ = std::move(that.u_l_);
    l_r_ = std::move(that.l_r_);
    ctr_ = std::move(that.ctr_);
  }
  ~rectangle() {
    std::clog << "In rectangle::~rectangle() d'tor\n";
    
  }

  //  MARK: operator=()
  rectangle & operator=(rectangle const & that) {
    std::clog << "In rectangle::operator=() copy\n";
    u_l_ = that.u_l_;
    l_r_ = that.l_r_;
    ctr_ = that.ctr_;
    return *this;
  }
  rectangle & operator=(rectangle && that) {
    std::clog << "In rectangle::operator=() move\n";
    u_l_ = std::move(that.u_l_);
    l_r_ = std::move(that.l_r_);
    ctr_ = std::move(that.ctr_);
    return *this;
  }

  //  MARK: Getters & setters
  point const & upper_left(void) const { return u_l_; }
  point const & upper_left(point const & ul) {
    u_l_ = point(ul.X(), ul.Y());
    return u_l_;
  }
  point const & lower_right(void) const { return l_r_; }
  point const & lower_right(point const & lr) {
    l_r_ = point(lr.X(), lr.Y());
    return l_r_;
  }

  /*
   *  MARK: length()
   */
  double length(void) const { return l_r_.X() - u_l_.X(); }

  /*
   *  MARK: height()
   */
  double height(void) const { return u_l_.Y() - l_r_.Y(); }

  /*
   *  MARK: area()
   */
  double area(void) const { return length() * height(); }

  /*
   *  MARK: centre()
   */
  point const & centre(void) const { return ctr_; }

  /*
   *  MARK: is_inside()
   */
  bool is_inside(point const & pt) const {
    auto inside = false;
    if ((pt.X() >= u_l_.X() && pt.X() <= l_r_.X())
    &&  (pt.Y() >= l_r_.Y() && pt.Y() <= u_l_.Y())) {
      inside = true;
    }
    return inside;
  }

  /*
   *  MARK: crosses_X()
   */
  bool crosses_X(void) const {
    return u_l_.X() * l_r_.X() < 0.0 ? true : false;
  }

  /*
   *  MARK: crosses_Y()
   */
  bool crosses_Y(void) const {
    return u_l_.Y() * l_r_.Y() < 0.0 ? true : false;
  }

private:
  point u_l_;
  point l_r_;
  point ctr_;
};
