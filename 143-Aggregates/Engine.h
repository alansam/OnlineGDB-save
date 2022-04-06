
#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <utility>

using namespace std::literals::string_literals;

/*
 *  MARK: Class Engine
 */
class Engine {
private:
  std::string engType;

public:
  Engine(std::string type = "default"s) {
    std::cout << " [@"s << this << "] Engine default ctor() "s << __func__ << std::endl;
    engType = type;
  }

  Engine(Engine const & that) {
    std::cout << " [@"s << this << "] Engine copy ctor() "s << __func__ << std::endl;
    engType = that.engType;
  }

  Engine(Engine && that) noexcept {
    std::cout << " [@"s << this << "] Engine move ctor() "s << __func__ << std::endl;
    engType = std::move(that.engType);
  }

  Engine & operator=(Engine const & that) {
    std::cout << " [@"s << this << "] Engine operator=() "s << __func__ << std::endl;
    engType = that.engType;
    return *this;
  }

  ~Engine() {
    std::cout << " [@"s << this << "] Engine dtor() "s << __func__ << std::endl; 
  }

  std::string get_engType() const {
    return engType;
  }
};

#endif
