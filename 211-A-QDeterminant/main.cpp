/*
hello?
i want to check my system smillitenously
its work like this when you have three unkown object 
if you want to check what the values of that object ?
you must to declare the initial value of matrix determinant of 12 values of data
you must have 3 line of unkown values i done to work that but i am not understand
why my finaly value of that object was not give me real true answer
so letus to check my system is this?
 */

#ifndef  __SYSTEM
#define  __SYSTEM

#include <iostream>
#include <iomanip>
#include <cstdlib>

struct line_1 {
  int x;
  int y;
  int z;
  int det_line;
  void set_line(int set_x , int set_y , int set_z , int set_det);
  int get_x();
  int get_y();
  int get_z();
  int get_det();
} line1_set;

//initializing the datas for line 1

int line_1::get_x() { return x; }
int line_1::get_y() { return y; }
int line_1::get_z() { return z; }
int line_1::get_det() { return det_line; }
void line_1::set_line(int set_x , int set_y , int set_z , int set_det) {
  x = set_x;
  y = set_y;
  z = set_z;
  det_line = set_det;
}

//line 2

struct line_2 {
  int x;
  int y;
  int z;
  int det_line;
  void set_line(int set_x , int set_y , int set_z , int set_det);
  int get_x();
  int get_y();
  int get_z();
  int get_det();
} line2_set;

/* initializing and definition of line 2 */

int line_2::get_x() { return x; }
int line_2::get_y() { return y; }
int line_2::get_z() { return z; }
int line_2::get_det() { return det_line; }
void line_2::set_line(int set_x , int set_y , int set_z , int set_det) {
  x = set_x;
  y = set_y;
  z = set_z;
  det_line = set_det;
}

struct line_3 {
  int x;
  int y;
  int z;
  int det_line;
  void set_line(int set_x , int set_y , int set_z , int set_det);
  int get_x();
  int get_y();
  int get_z();
  int get_det();
} line3_set;

/* initializing line 3 */
int line_3::get_x() { return x; }
int line_3::get_y() { return y; }
int line_3::get_z() { return z; }
int line_3::get_det() { return det_line; }
void line_3::set_line(int set_x , int set_y , int set_z , int set_det) {
  x = set_x;
  y = set_y;
  z = set_z;
  det_line = set_det; 
}

// printing the system 

void print_system() {
  std::cout << " you have this sytem" << std::endl;
  std::cout << line1_set.get_x() << " X + "
            << line1_set.get_y() << " Y + "
            << line1_set.get_z() << " Z = "
            << line1_set.get_det()
            << std::endl;
  std::cout << line2_set.get_x() << " X + "
            << line2_set.get_y() << " Y + "
            << line2_set.get_z() << " Z = "
            << line2_set.get_det()
            << std::endl;
  std::cout << line3_set.get_x() << " X + "
            << line3_set.get_y() << " Y + "
            << line3_set.get_z() << " Z = "
            << line3_set.get_det()
            << std::endl;
}

/* calculating the system search the value of x , y  and z  and their dertimant*/

double determinat() {
  double det =
    ((line2_set.get_y() * line3_set.get_z() - line2_set.get_z() * line3_set.get_y()) * line1_set.get_x()) -
    ((line2_set.get_x() * line3_set.get_z() - line2_set.get_z() * line3_set.get_x()) * line1_set.get_y()) +
    ((line2_set.get_x() * line3_set.get_y() - line2_set.get_y() * line3_set.get_x()) * line1_set.get_z());

  return det; 
}

// determinant of x

double det_x() {
  double x =
    ((line2_set.get_y()   * line3_set.get_z()  - line2_set.get_y() * line3_set.get_z())   * line1_set.get_det()) - 
    ((line2_set.get_det() * line3_set.get_z()  - line2_set.get_z() * line3_set.get_det()) * line1_set.get_y())   + 
    ((line2_set.get_det() * line3_set.get_y()  - line2_set.get_y() * line3_set.get_det()) * line1_set.get_z());

  return x / determinat();
}

// determinant of y
double det_y() {
  double y =
    ((line2_set.get_det() * line3_set.get_z()   - line2_set.get_z()   * line3_set.get_det()) * line1_set.get_x())   - 
    ((line2_set.get_x()   * line3_set.get_z()   - line2_set.get_z()   * line3_set.get_det()) * line1_set.get_det()) +
    ((line2_set.get_x()   * line3_set.get_det() - line2_set.get_det() * line3_set.get_x())   * line1_set.get_z());

  return y / determinat();
}

double det_z() {
  double z =
    ((line2_set.get_det() * line3_set.get_y()   - line2_set.get_y()   * line3_set.get_det()) * line1_set . get_x()) - 
    ((line2_set.get_x()   * line3_set.get_det() - line2_set.get_det() * line3_set.get_x())   * line1_set.get_y())   +
    ((line2_set.get_x()   * line3_set.get_y()   - line2_set.get_y()   * line3_set.get_x())   * line1_set.get_det());

  return z / determinat();
}

#define ECHO_
void print() {
 int a0 , b0 , c0 , d0;
 int a1 , b1 , c1 , d1;
 int a2 , b2 , c2 , d2;
 char answer;

  for (size_t i = 0; i < 100; ++i) {
    std::cout << "setting your system data\n" << std::endl;
    std::cout << "\n line 1" << std::endl;
    std::cout << "a = "; std::cin >> a0;
#ifdef ECHO_
    std::cout << a0 << '\n';
#endif /* ECHO_ */
    std::cout << "b = "; std::cin >> b0;
#ifdef ECHO_
    std::cout << b0 << '\n';
#endif /* ECHO_ */
    std::cout << "c = "; std::cin >> c0;
#ifdef ECHO_
    std::cout << c0 << '\n';
#endif /* ECHO_ */
    std::cout << "d = "; std::cin >> d0;
#ifdef ECHO_
    std::cout << d0 << '\n';
#endif /* ECHO_ */

    std::cout << "\n line 2" << std::endl;
    std::cout << "a = "; std::cin >> a1;
#ifdef ECHO_
    std::cout << a1 << '\n';
#endif /* ECHO_ */
    std::cout << "b = "; std::cin >> b1;
#ifdef ECHO_
    std::cout << b1 << '\n';
#endif /* ECHO_ */
    std::cout << "c = "; std::cin >> c1;
#ifdef ECHO_
    std::cout << c1 << '\n';
#endif /* ECHO_ */
    std::cout << "d = "; std::cin >> d1;
#ifdef ECHO_
    std::cout << d1 << '\n';
#endif /* ECHO_ */

    std::cout << "\n line 3" << std::endl;
    std::cout << "a = "; std::cin >> a2;
#ifdef ECHO_
    std::cout << a2 << '\n';
#endif /* ECHO_ */
    std::cout << "b = "; std::cin >> b2;
#ifdef ECHO_
    std::cout << b2 << '\n';
#endif /* ECHO_ */
    std::cout << "c = "; std::cin >> c2;
#ifdef ECHO_
    std::cout << c2 << '\n';
#endif /* ECHO_ */
    std::cout << "d = "; std::cin >> d2;
#ifdef ECHO_
    std::cout << d2 << '\n';
#endif /* ECHO_ */

    std::cout.put('\n');

    line1_set.set_line(a0 , b0 , c0 ,d0);
    line2_set.set_line(a1 , b1 , c1 ,d1);
    line3_set.set_line(a2 , b2 , c2 ,d2);

    print_system();

    std::cout << std::fixed;
    std::cout << "     the value of x is " << std::setw(20) << det_x() << std::endl;
    std::cout << "     the value of y is " << std::setw(20) << det_y() << std::endl;
    std::cout << "     the value of z is " << std::setw(20) << det_z() << std::endl;
    std::cout << " Matrix determinant is " << std::setw(20) << determinat() << std::endl;
    std::cout << std::endl;

    std::cout << "\n\n setting another system (y/n) ? " << std::endl;
    std::cin >> answer;
    if (answer == 'n' || answer == 'N') {
      exit(0);
      break;
    }
    std::cout.put('\n');
  }
}

#endif

int main(int argc, char const * argv[]) {
  print();

  return 0;
}

/*
  Sample data:
100 110 120 10
120 110 110 15
300 310 320 10
N

  Result set:
 you have this sytem
100 X + 110 Y + 120 Z = 10
120 X + 110 Y + 110 Z = 15
300 X + 310 Y + 320 Z = 10
     the value of x is             0.950000
     the value of y is           -19.950000
     the value of z is            38.000000
 Matrix determinant is         20000.000000
 */
