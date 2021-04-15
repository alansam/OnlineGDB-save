
#include "Circle.h"
#include <iostream>

int main() {
  double area, circumference;
  Circle x;

  double rad;
  std::cout << "enter the radius " << std::endl;
  std::cin >> rad;
  x.set_radius(rad);

  area = x.area();
  circumference = x.circum();
  
  std::cout << "the area is " << area << " and the circumference is " << circumference << std::endl;

  return 0;
}
