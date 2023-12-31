
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

#include "point.hpp"
#include "rectangle.hpp"

using namespace std::literals::string_literals;

/*
 *  MARK: show_me()
 */
auto show_me = [](rectangle const & rec) {
    std::cout << std::string(80, '=') << '\n';
    std::cout << "upper left  - "s << rec.upper_left() << '\n'
              << "lower right - "s << rec.lower_right() << '\n'
              << "dimensions  - "s << "l:"s << std::setw(8) << rec.length() << ' '
                                   << "h:"s << std::setw(8) << rec.height() << '\n'
              << "centre      - "s << rec.centre() << '\n'
              << "area        - "s << std::setw(10) << rec.area() << '\n';
    std::cout << "rectangle   - "s
              << (rec.crosses_X() ? "crosses X axis"s : "does not cross X axis"s) << '\n';
    std::cout << "            - "s
              << (rec.crosses_Y() ? "crosses Y axis"s : "does not cross Y axis"s) << '\n'
              << std::endl;
    auto find = point();
    std::cout << "point       - "s << find
              << (rec.is_inside(find) ? " is inside"s : " is outside"s) << '\n';
    find = point(3.0, 3.0);
    std::cout << "point       - "s << find
              << (rec.is_inside(find) ? " is inside"s : " is outside"s) << '\n';
    find = point(-3.0, -3.0);
    std::cout << "point       - "s << find
              << (rec.is_inside(find) ? " is inside"s : " is outside"s) << '\n'
              << std::endl;

  return;
};

/*
 *  MARK: main()
 */
int main() {
  auto recs = std::vector<rectangle> {
    rectangle(point( 2.0, 2.0), point( 4.0,  0.0)),
    rectangle(point(-1.0, 1.0), point( 1.0, -1.0)),
    rectangle(point( 2.0, 5.0), point( 4.0,  1.0)),
    rectangle(point(-2.0, 5.0), point( 4.0, -2.0)),
    rectangle(point(-2.0, 5.0), point( 4.0,  1.0)),
    rectangle(point(12.0, 5.0), point(14.0, -1.0)),
  };

  std::for_each(recs.cbegin(), recs.cend(), show_me);

  return 0;
}
