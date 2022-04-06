
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <utility>

using namespace std::literals::string_literals;

//  pre-define Car class
class Car;

/*
 *  MARK: Class Person
 */
class Person {
private:
  std::string personName;
  Car const * car;

public:
  Person(std::string name = "default"s, Car const * car_ = nullptr) : personName { name }, car { car_ } {
    std::cout << " [@"s << this << "] Person default ctor() "s << __func__ << std::endl;
  }

  Person(Person const & that) {
    std::cout << " [@"s << this << "] Person copy ctor() "s << __func__ << std::endl;
    personName = that.personName;
    car = that.car;
  }

  Person(Person && that) noexcept {
    std::cout << " [@"s << this << "] Person move ctor() "s << __func__ << std::endl;
    personName = std::move(that.personName);
    car = std::exchange(that.car, nullptr);
  }

  Person & operator=(Person const & that) {
    std::cout << " [@"s << this << "] Person operator=() "s << __func__ << std::endl;
    personName = that.personName;
    car = that.car;
    return *this;
  }

  ~Person() {
    std::cout << " [@"s << this << "] Person dtor() "s << __func__ << std::endl;
  }

  std::string get_personName(void) const {
    return personName;
  }

  Car const * set_car(Car const * car_) {
    car = car_;
    return car;
  }

  Car const * get_car(void) const {
    return car;
  }
};

#endif
