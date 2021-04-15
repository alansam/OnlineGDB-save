#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

class Shape {
public:
  virtual std::string display() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(double length = 0, double breadth = 0) : length_(length), breadth_(breadth) {}
  virtual ~Rectangle() = default;

  std::string display() const {
    std::ostringstream disp;
    disp << "length "<< length_
         << ", breadth " << breadth_
         << ", perimeter " << perimeter()
         << ", area " << std::fixed << area();
    return disp.str();
  }

  virtual double area() const {
    return length_ * breadth_;
  }

  virtual double perimeter() const {
    return 2 * (length_ + breadth_);
  }

protected:
  //  hide implementation details from the interface
  double length_;
  double breadth_;
};

class Square : public Rectangle {
public:
  Square(double length = 0) {
    length_ = length;
    breadth_ = length;
  }
  virtual ~Square() = default;

  std::string display() const {
    std::ostringstream disp;
    disp << "length " << length_
         << ", perimeter " << perimeter()
         << ", area " << std::fixed << area();
    return disp.str();
  }
};

class Triangle : public Shape {
public:
  Triangle(double base = 0, double height = 0) : base_(base), height_(height) {}
  virtual ~Triangle() = default;


  virtual std::string display() const {
    std::ostringstream disp;
    disp << "base " << base_
         << ", height " << height_
         << ", area " << std::fixed << area();
    return disp.str();
  }

  virtual double perimeter() const {
    //  TODO: calculate perimeter
    return NAN;
  }

  double area() const {
    return (base_ / 2.0) * height_;
  }

protected:
  double base_;
  double height_;
};

class Circle : public Shape {
public:
  Circle(double radius = 0) : radius_(radius) {}
  virtual ~Circle() = default;

  std::string display() const {
    std::ostringstream disp;
    disp << "radius " << radius_
         << ", circumference " << circumference()
         << ", area " << area();
    return disp.str();
  }

  double area() const {
    return M_PI * (radius_ * radius_);
  }

  double perimeter() const {
    return circumference();
  }

  double circumference() const {
    return M_PI * (radius_ * 2.0);
  }

private:
  double radius_;
};

class RightTriangle : public Triangle {
public:
  RightTriangle(double base = 0, double height = 0) {
    base_ = base;
    height_ = height;
    hypotenuse_ = std::sqrt((base_ * base_) + (height_ * height_));
  }
  virtual ~RightTriangle() = default;

  std::string display() const {
    std::ostringstream disp;
    disp << "base " << base_
         << ", height " << height_
         << ", hypotenuse " << hypotenuse_
         << ", perimeter " << perimeter()
         << ", area " << std::fixed << area();
    return disp.str();
  }

  double perimeter() const {
    return hypotenuse_ + base_ + height_;
  }

private:
  double hypotenuse_;
};

class EquilateralTriangle : public Triangle {
public:
  EquilateralTriangle(double base = 0) {
    base_ = base;
    height_ = sqrt(3.0) / 2 * base_;
  }
  virtual ~EquilateralTriangle() = default;

  std::string display() const {
    std::ostringstream disp;
    disp << "base " << base_
         << ", height " << height_
         << ", perimeter " << perimeter()
         << ", area " << std::fixed << area();
    return disp.str();
  }

  double perimeter() const {
    return base_ + base_ + base_;
  }

  double area() const {
    return sqrt(3.0) / 4 * (base_ * base_);
  }

};

int main() {
  auto rshape = Rectangle(54.3, 21.09);
  auto sshape = Square(45.6);
  auto tshape = Triangle(3., 4.);
  auto cshape = Circle(10.0);
  auto xshape = RightTriangle(3., 4.);
  auto qshape = EquilateralTriangle(4.0);

  std::cout << "Rectangle            : " << rshape.display() << std::endl;
  std::cout << "Square               : " << sshape.display() << std::endl;
  std::cout << "Triangle             : " << tshape.display() << std::endl;
  std::cout << "Circle               : " << cshape.display() << std::endl;
  std::cout << "Right Triangle       : " << xshape.display() << std::endl;
  std::cout << "Equilateral Triangle : " << qshape.display() << std::endl;

  return 0;
}
