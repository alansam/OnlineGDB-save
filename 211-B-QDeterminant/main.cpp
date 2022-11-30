
#include <iostream>
#include <iomanip>
#include <array>
#include <tuple>

size_t constexpr X(0ul);
size_t constexpr Y(1ul);
size_t constexpr Z(2ul);
size_t constexpr D(3ul);

size_t constexpr L1(0ul);
size_t constexpr L2(1ul);
size_t constexpr L3(2ul);

double determinat(std::array<std::tuple<int, int, int, int>, 3> const & ln);
double det_x(std::array<std::tuple<int, int, int, int>, 3> const & ln);
double det_y(std::array<std::tuple<int, int, int, int>, 3> const & ln);
double det_z(std::array<std::tuple<int, int, int, int>, 3> const & ln);
void print_system(std::array<std::tuple<int, int, int, int>, 3> const & ln);
void print(std::array<std::tuple<int, int, int, int>, 3> const & ln);

int main() {
  std::cout << "QDererminant\n";

  std::array<std::tuple<int, int, int, int>, 3> lines {
    std::make_tuple(100, 110, 120, 10),
    std::make_tuple(120, 110, 110, 15),
    std::make_tuple(300, 310, 320, 10),
  };

  print_system(lines);
  print(lines);

  return 0;
}

/* calculating the system search the value of x , y  and z  and their dertimant*/
double determinat(std::array<std::tuple<int, int, int, int>, 3> const & ln) {
  double det =
    ((std::get<Y>(ln[L2]) * std::get<Z>(ln[L3]) - std::get<Z>(ln[L2]) * std::get<Y>(ln[L3])) * std::get<X>(ln[L1]) ) -
    ((std::get<X>(ln[L2]) * std::get<Z>(ln[L3]) - std::get<Z>(ln[L2]) * std::get<X>(ln[L3])) * std::get<Y>(ln[L1]) ) +
    ((std::get<X>(ln[L2]) * std::get<Y>(ln[L3]) - std::get<Y>(ln[L2]) * std::get<X>(ln[L3])) * std::get<Z>(ln[L1]) );
 // ((line2_set.get_y() * line3_set.get_z() - line2_set.get_z() * line3_set.get_y()) * line1_set.get_x()) -
 // ((line2_set.get_x() * line3_set.get_z() - line2_set.get_z() * line3_set.get_x()) * line1_set.get_y()) +
 // ((line2_set.get_x() * line3_set.get_y() - line2_set.get_y() * line3_set.get_x()) * line1_set.get_z());

  return det;
}

// determinant of x
double det_x(std::array<std::tuple<int, int, int, int>, 3> const & ln) {
  double x =
    ((std::get<Y>(ln[L2]) * std::get<Z>(ln[L3]) - std::get<Y>(ln[L2]) * std::get<Z>(ln[L3])) * std::get<D>(ln[L1]) ) -
    ((std::get<D>(ln[L2]) * std::get<Z>(ln[L3]) - std::get<Z>(ln[L2]) * std::get<D>(ln[L3])) * std::get<Y>(ln[L1]) ) +
    ((std::get<D>(ln[L2]) * std::get<Y>(ln[L3]) - std::get<Y>(ln[L2]) * std::get<D>(ln[L3])) * std::get<Z>(ln[L1]) );
 // ((line2_set.get_y()   * line3_set.get_z()  - line2_set.get_y() * line3_set.get_z())   * line1_set.get_det()) - 
 // ((line2_set.get_det() * line3_set.get_z()  - line2_set.get_z() * line3_set.get_det()) * line1_set.get_y())   + 
 // ((line2_set.get_det() * line3_set.get_y()  - line2_set.get_y() * line3_set.get_det()) * line1_set.get_z());

  return x / determinat(ln);
}

// determinant of y
double det_y(std::array<std::tuple<int, int, int, int>, 3> const & ln) {
  double y =
    ((std::get<D>(ln[L2]) * std::get<Z>(ln[L3]) - std::get<Z>(ln[L2]) * std::get<D>(ln[L3])) * std::get<X>(ln[L1]) ) -
    ((std::get<X>(ln[L2]) * std::get<Z>(ln[L3]) - std::get<Z>(ln[L2]) * std::get<D>(ln[L3])) * std::get<D>(ln[L1]) ) +
    ((std::get<X>(ln[L2]) * std::get<D>(ln[L3]) - std::get<D>(ln[L2]) * std::get<X>(ln[L3])) * std::get<Z>(ln[L1]) );
 // ((line2_set.get_det() * line3_set.get_z()   - line2_set.get_z()   * line3_set.get_det()) * line1_set.get_x())   - 
 // ((line2_set.get_x()   * line3_set.get_z()   - line2_set.get_z()   * line3_set.get_det()) * line1_set.get_det()) +
 // ((line2_set.get_x()   * line3_set.get_det() - line2_set.get_det() * line3_set.get_x())   * line1_set.get_z());

  return y / determinat(ln);
}

// determinant of z
double det_z(std::array<std::tuple<int, int, int, int>, 3> const & ln) {
  double z =
    ((std::get<D>(ln[L2]) * std::get<Y>(ln[L3]) - std::get<Y>(ln[L2]) * std::get<D>(ln[L3])) * std::get<X>(ln[L1]) ) -
    ((std::get<X>(ln[L2]) * std::get<D>(ln[L3]) - std::get<D>(ln[L2]) * std::get<X>(ln[L3])) * std::get<Y>(ln[L1]) ) +
    ((std::get<X>(ln[L2]) * std::get<Y>(ln[L3]) - std::get<Y>(ln[L2]) * std::get<X>(ln[L3])) * std::get<D>(ln[L1]) );
 // ((line2_set.get_det() * line3_set.get_y()   - line2_set.get_y()  * line3_set.get_det()) * line1_set . get_x()) - 
 // ((line2_set.get_x()   * line3_set.get_det() - line2_set.get_det() * line3_set.get_x())  * line1_set.get_y()) +
 // ((line2_set.get_x()   * line3_set.get_y()   - line2_set.get_y()   * line3_set.get_x())  * line1_set.get_det());

  return z / determinat(ln);
}

void print_system(std::array<std::tuple<int, int, int, int>, 3> const & ln) {
  std::cout << " you have this sytem" << std::endl;
  std::cout << "X: " << std::get<X>(ln[L1]) << ' '
            << "Y: " << std::get<Y>(ln[L1]) << ' '
            << "Z: " << std::get<Z>(ln[L1]) << ' '
            << "D: " << std::get<D>(ln[L1])
            << std::endl;
  std::cout << "X: " << std::get<X>(ln[L2]) << ' '
            << "Y: " << std::get<Y>(ln[L2]) << ' '
            << "Z: " << std::get<Z>(ln[L2]) << ' '
            << "D: " << std::get<D>(ln[L2])
            << std::endl;
  std::cout << "X: " << std::get<X>(ln[L3]) << ' '
            << "Y: " << std::get<Y>(ln[L3]) << ' '
            << "Z: " << std::get<Z>(ln[L3]) << ' '
            << "D: " << std::get<D>(ln[L3])
            << std::endl;
}

void print(std::array<std::tuple<int, int, int, int>, 3> const & ln) {
    std::cout << std::fixed;
    std::cout << "     the value of x is " << std::setw(20) << det_x(ln) << std::endl;
    std::cout << "     the value of y is " << std::setw(20) << det_y(ln) << std::endl;
    std::cout << "     the value of z is " << std::setw(20) << det_z(ln) << std::endl;
    std::cout << " Matrix determinant is " << std::setw(20) << determinat(ln) << std::endl;
    std::cout << std::endl;
}

