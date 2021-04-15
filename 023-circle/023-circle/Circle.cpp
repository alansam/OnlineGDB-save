
#include "Circle.h"
#include <iostream>

Circle::Circle(void) {
  std::cout << "Area and circumference of a circle" << std::endl;
}

void Circle::set_radius(double rad) {
  radius = rad;
}

double Circle::area() {
  return 3.1412 * radius * radius;
}

double Circle::circum() {
  return 2 * 3.1412 * radius;
}
