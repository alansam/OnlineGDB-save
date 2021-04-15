#include <iostream>
#include <iomanip>

/*
 * Create classes Rectangle and RectangleArea
 */
 
class Rectangle {
public:
  void read_input() {
    std::cout << "provide length and breadth: ";
    std::cin >> a >> b;
  }

  void display() {
    std::cout << "length " << a << ", breadth " << b << std::endl;
  }

protected:
  //  hide implementation details from the interface
  double a;
  double b;
};

class RectangleArea : public Rectangle {
public:
  void display() {
    area = a * b;
    std::cout << "area " << std::fixed << area << std::endl;
  }

private:
  //  hide implementation details from the interface
  double area;
};

int main() {
  /* Declare a RectangleArea object */
  RectangleArea r_area;

  /* Read the width and height */
  r_area.read_input();

  /* Print the width and height */
  r_area.Rectangle::display();

  /* Print the area */
  r_area.display();

  return 0;
}
