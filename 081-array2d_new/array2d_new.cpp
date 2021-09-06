
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <typeinfo>
#include <cxxabi.h>

//  @see: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
//  @see: https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-api-4.6/a00851.html

size_t constexpr rows { 4 };
size_t constexpr cols { 4 };
auto const dlm = std::string(80, '.');

auto show2d = [](auto & a2d) {
  std::cout << "....";
  for (size_t c_ { 0 }; c_ < cols; ++c_) {
    std::cout << std::setw(10) << c_;
  }
  std::cout << '\n';
  for (size_t r_ { 0 }; r_ < rows; ++r_) {
    std::cout << '[' << std::setw(2) << r_ << ']';
    for (size_t c_ { 0 }; c_ < cols; ++c_) {
      std::cout << std::setw(10) << std::fixed << a2d[r_][c_];
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
};

auto showpseudo2d = [](auto & a2d) {
  std::cout << "....";
  for (size_t c_ { 0 }; c_ < cols; ++c_) {
    std::cout << std::setw(10) << c_;
  }
  std::cout << '\n';
  for (size_t r_ { 0 }; r_ < rows; ++r_) {
    std::cout << '[' << std::setw(2) << r_ << ']';
    for (size_t c_ { 0 }; c_ < cols; ++c_) {
      std::cout << std::setw(10) << std::fixed << a2d[r_ * cols + c_];
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
};


int main() {
  std::cout << dlm << std::endl;
  {
    auto a2d = new double [rows][cols](); //  NOTE: array of pointers to double[cols]

    std::cout << "new double [" << rows << "][" << cols << "] is " << typeid(a2d).name() << '\n';
    int info;
    std::cout << "new double [" << rows << "][" << cols << "] is " << abi::__cxa_demangle(typeid(a2d).name(), 0, 0, &info) << '\n';
    std::cout << std::endl;

    show2d(a2d);

    for (size_t r_ { 0 }; r_ < rows; ++r_) {
      for (size_t c_ { 0 }; c_ < cols; ++c_) {
        a2d[r_][c_] = static_cast<double>(c_ + 1.0) * r_ + c_ * 0.25;
      }
    }

    show2d(a2d);

    for (size_t e_ { 0 }; e_ < rows; ++e_) {
      std::cout << std::setw(10) << std::fixed << a2d[e_] << '\n';
      auto a1d = a2d[e_];
      std::cout << "  double [" << rows << "] is " << typeid(a1d).name() << '\n';
      int info;
      std::cout << "  double [" << rows << "] is " << abi::__cxa_demangle(typeid(a1d).name(), 0, 0, &info) << '\n';
      for (size_t ee { 0 }; ee < cols; ++ee) {
        std::cout << std::setw(10) << std::fixed << a1d[ee];
      }
      std::cout << '\n';
    }
    std::cout << std::endl;

    delete [] a2d;
  }

  std::cout << dlm << std::endl;
  {
    auto a2d = new double[rows * cols];

    std::cout << "new double [" << rows << " * " << cols << "] is " << typeid(a2d).name() << '\n';
    int info;
    std::cout << "new double [" << rows << " * " << cols << "] is " << abi::__cxa_demangle(typeid(a2d).name(), 0, 0, &info) << '\n';
    std::cout << std::endl;

    for (size_t r_ { 0 }; r_ < rows; ++r_) {
      for (size_t c_ { 0 }; c_ < cols; ++c_) {
        a2d[r_ * cols +  c_] = static_cast<double>(c_ + 1.0) * r_ + c_ * 0.25;
      }
    }

    showpseudo2d(a2d);

    for (size_t ee { 0 }, cc { 0 }; ee < rows * cols; ++ee) {
      std::cout << std::setw(10) << std::fixed << a2d[ee]
                << (++cc % 8 == 0 ? "\n" : "");
    }
    std::cout << std::endl;

    delete [] a2d;
  }

  std::cout << dlm << std::endl;
  {
    double (*a2d)[cols] = new double[rows][cols]();

    std::cout << "new double [" << rows << "][" << cols << "] is " << typeid(a2d).name() << '\n';
    int info;
    std::cout << "new double [" << rows << "][" << cols << "] is " << abi::__cxa_demangle(typeid(a2d).name(), 0, 0, &info) << '\n';
    std::cout << std::endl;

    show2d(a2d);

    for (size_t r_ { 0 }; r_ < rows; ++r_) {
      for (size_t c_ { 0 }; c_ < cols; ++c_) {
        a2d[r_][c_] = static_cast<double>(c_ + 1.0) * r_ + c_ * 0.25;
      }
    }

    show2d(a2d);

    for (size_t e_ { 0 }; e_ < rows; ++e_) {
      std::cout << std::setw(10) << std::fixed << a2d[e_] << '\n';
      auto a1d = a2d[e_];
      std::cout << "  double [" << rows << "] is " << typeid(a1d).name() << '\n';
      int info;
      std::cout << "  double [" << rows << "] is " << abi::__cxa_demangle(typeid(a1d).name(), 0, 0, &info) << '\n';
      for (size_t ee { 0 }; ee < cols; ++ee) {
        std::cout << std::setw(10) << std::fixed << a1d[ee];
      }
      std::cout << '\n';
    }
    std::cout << std::endl;

    delete [] a2d;
  }

  std::cout << dlm << std::endl;
  {
    double a2d[rows][cols] { 0 };

    std::cout << "new double [" << rows << "][" << cols << "] is " << typeid(a2d).name() << '\n';
    int info;
    std::cout << "new double [" << rows << "][" << cols << "] is " << abi::__cxa_demangle(typeid(a2d).name(), 0, 0, &info) << '\n';
    std::cout << std::endl;

    show2d(a2d);

    for (size_t r_ { 0 }; r_ < rows; ++r_) {
      for (size_t c_ { 0 }; c_ < cols; ++c_) {
        a2d[r_][c_] = static_cast<double>(c_ + 1.0) * r_ + c_ * 0.25;
      }
    }

    show2d(a2d);

    for (size_t e_ { 0 }; e_ < rows; ++e_) {
      std::cout << std::setw(10) << std::fixed << a2d[e_] << '\n';
      auto a1d = a2d[e_];
      std::cout << "  double [" << rows << "] is " << typeid(a1d).name() << '\n';
      int info;
      std::cout << "  double [" << rows << "] is " << abi::__cxa_demangle(typeid(a1d).name(), 0, 0, &info) << '\n';
      for (size_t ee { 0 }; ee < cols; ++ee) {
        std::cout << std::setw(10) << std::fixed << a1d[ee];
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  }

  return 0;
}
