
#include <iostream>

class Point {
private:
  double x;
  double y;

public:
  void point() { x = 0; y = 0; }
  Point(double x1, double y1) : x(x1), y(y1) {}
  void print() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
  }

  friend
  std::ostream & operator <<(std::ostream & os, Point const & that) {
    os << "(" << that.x << "," << that.y << ")";
    return os;
  }
};

class Rectangle {
private:
  Point & upperLeft;
  Point & lowerRight;

public:
  Rectangle(Point & upperLeft1, Point & lowerRight1) : upperLeft(upperLeft1), lowerRight(lowerRight1) {}
  void print() {
    std::cout << "upper left corner  " << &upperLeft << std::endl;
    std::cout << "lower right corner " << &lowerRight << std::endl;
  }

  friend
  std::ostream & operator <<(std::ostream & os, Rectangle const & that) {
    os << "upper left corner " << that.upperLeft
       << ", lower right corner " << that.lowerRight;
    return os;
  }
};

int main() {
  Point o(0, 0);
  Point u(-3, 3);
  Point l(2, 1.5);
  Rectangle * r = new Rectangle(u, l);

  // std::cout << "point o: ";
  // o.print();
  std::cout << "point o: " << o << std::endl;

  // std::cout << "rectangle r: ";
  // r->print();
  std::cout << "rectangle r: " << *r << std::endl;

  delete r;

  return 0;
}

