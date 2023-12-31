/*
 *  Hi Everyone, I always wonder why some of the operations I use in C++ have
 *  the wrong solutions is there a problem with that, I am new to programming
 *  and C++ is the language I chose to use. anyone can help thanks. this is the code 
 */
 
#include <iostream>
#include <cmath>

//WAP a hypotenuse calculator
int main() {
  std::cout << std::fixed;
  auto form { 0 };
  do {
    std::cout << "******************** Geometry Calculator ********************\n";
    std::cout << "Please Choose from (1-6) for a corresponding formula to use\n";
    std::cout << "1. Square.    Formula: A = x\u00b2\n"
              << "2. Triangle.  Formula: A = \u00bd\u22c5b\u22c5h\n"
              << "3. Circle.    Formula: A = \u03c0\u22c5r\u00b2\n"
              << "4. Rectangle. Formula: A = b\u22c5h\n"
              << "5. Eclipse.   Formula: A = \u03c0\u22c5a\u22c5b\n"
              << "6. Trapezoid. Formula: A = \u00bd\u22c5(a\u002bb)\u22c5ah\n"
              << "0. Exit\n";
 
    std::cin >> form;
 
    switch (form) {
    case 0:
      std::cout << "Bye!\n";
      break;

    case 1:
      //  square
      {
        auto x { 0.0 };
        auto area { 0.0 };
        std::cout << "Square:\n";
        std::cout << "A = x\u00b2 is the Formula\n";
        std::cout << "Please Write the Value of x\n";
        std::cin >> x;
        area = pow(x, 2);
        std::cout << "The result is: "<< area << '\n';
      }
      break;

    case 2:
      //  triangle
      {
        auto base { 0.0 };
        auto height { 0.0 };
        auto area { 0.0 };
        std::cout << "Triangle:\n";
        std::cout << "A = \u00bd\u22c5b\u22c5h is the Formula\n";
        std::cout << "Please Write the Value of base\n";
        std::cin >> base;
        std::cout << "Please Write the Value of height\n";
        std::cin >> height;
        area = (0.5 * base * height);
        std::cout << "The result is: "<< area << '\n';
      }
      break;

    case 3:
      //  circle
      {
        auto radius { 0.0 };
        auto area { 0.0 };
        std::cout << "Circle:\n";
        std::cout << "A = \u03c0\u22c5r\u00b2 is the Formula\n";
        std::cout << "Please Write the Value of the radius\n";
        std::cin >> radius;
        area = M_PI * pow(radius, 2);
        std::cout << "The result is: "<< area << '\n';
      }
      break;

    case 4:
      //  rectangle
      {
        auto area { 0.0 };
        auto base { 0.0 };
        auto height { 0.0 };
        std::cout << "Rectangle:\n";
        std::cout << "A = b\u22c5h is the Formula\n";
        std::cout << "Please Write the Value of base\n";
        std::cin >> base;
        std::cout << "Please Write the Value of height\n";
        std::cin >> height;
        area = base * height;
        std::cout << "The result is: " << area << '\n';
      }
      break;

    case 5:
      //  elipse
      {
        double radius_a;
        double radius_b;
        auto area { 0.0 };
        std::cout << "Elipse:\n";
        std::cout << "A = \u03c0\u22c5a\u22c5b is the formula\n";
        std::cout << "Enter radius of major axis\n";
        std::cin >> radius_a;
        std::cout << "Enter radius of minor axis\n";
        std::cin >> radius_b;
        area = M_PI * radius_a * radius_b;
        std::cout << "The result is: " << area << '\n';
      }
      break;

    case 6:
      //  trapezoid
      {
        auto area { 0.0 };
        auto base_a { 0.0 };
        auto base_b { 0.0 };
        auto height { 0.0 };
        std::cout << "Trapezoid:\n";
        std::cout << "A = \u00bd\u22c5(a\u002bb)\u22c5h is the formula\n";
        std::cout << "Enter length of base a\n";
        std::cin >> base_a;
        std::cout << "Enter length of base b\n";
        std::cin >> base_b;
        std::cout << "Enter length of height\n";
        std::cin >> height;
        area = 1.0 / 2.0 * (base_a + base_b) * height;
        std::cout << "The result is: " << area << '\n';
      }
      break;

    default:
      {
        std::cout << "not implemented yet\n";
      }
      break;
    }
    std::cout << std::endl;
  } while (form != 0);
 
  std::cout<< "*****************************************************************\n";

  return 0;
}

/*
 *  this is incomplete since, I am searching a solution in the case number
 *  4 when I try to calculate 20*21.1 the result is 420 not 422.
 */