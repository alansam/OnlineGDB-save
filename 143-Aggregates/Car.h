
#pragma once
#ifndef CAR_H
#define CAR_H

#include <string>
#include <utility>

using namespace std::literals::string_literals;

#include "Engine.h"

//  pre-define Person class
class Person;

/*
 *  MARK: Class Car
 */
class Car {
private:
  std::string carType;
  Engine carEngine;
  Person const * owner;

public:
  Car(std::string type = "default"s, std::string etype = "default"s, Person * owner_ = nullptr) : carType(type), carEngine(etype), owner { owner_ } {
    std::cout << " [@"s << this << "] Car default ctor() "s << __func__ << std::endl;
  }

  Car(Car const & that) {
    std::cout << " [@"s << this << "] Car copy ctor() "s << __func__ << std::endl;
    carType = that.carType;
    carEngine = that.carEngine;
    owner = that.owner;
  }

  Car(Car && that) noexcept {
    std::cout << " [@"s << this << "] Car move ctor() "s << __func__ << std::endl;
    carType = std::move(that.carType);
    carEngine = std::move(that.carEngine);
    owner = std::exchange(that.owner, nullptr);
  }

  Car & operator=(Car const & that) {
    std::cout << " [@"s << this << "] Car operator=() "s << __func__ << std::endl;
    carType = that.carType;
    carEngine = that.carEngine;
    return *this;
    owner = that.owner;
  }

  ~Car() {
    std::cout << " [@"s << this << "] Car dtor() "s << __func__ << std::endl;
  }

  Engine const & get_carEngine(void) const {
    return carEngine;
  }

  std::string get_carType(void) const {
    return carType;
  }

  Person const * set_owner(Person const * owner_) {
    owner = owner_;
    return owner;
  }

  Person const * get_owner(void) const {
    return owner;
  }
};

#endif
