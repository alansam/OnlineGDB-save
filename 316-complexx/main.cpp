//  compiler options: -Wall -Wpedantic -fsanitize=address -std=gnu++XX
//  where XX is 11, 14, 17, 20, etc. but 11 at a minimum
#include <iostream>
#include <iomanip>
#include <cmath>

#define INTERACTIVE

//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: - Constants
static constexpr bool LOG { true };

//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: - Definitions
//  MARK: Class complexx
class complexx {
private:
    double real_;
    double ima_;

public:
    complexx(double a = 2.0, double b = 3.0)
    : real_ { a }, ima_ { b } {
      if (LOG) { std::clog << "complexx::" << __func__ << "() default c'tor\n"; }
    }

    // implement default c'tors etc. to prevent automaic generation.
    complexx(complexx const & that)
    : real_ { that.real_ }, ima_ { that.ima_ } {
        if (LOG) { std::clog << "complexx::" << __func__ << "() copy c'tor\n"; }
    }
    complexx(complexx const && that)
    : real_ { std::move(that.real_) }, ima_ { std::move(that.ima_) } {
        if (LOG) { std::clog << "complexx::" << __func__ << "() move c'tor\n"; }
    }
    complexx & operator=(complexx const & that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "() copy\n"; }
        real_ += that.real_;
        ima_ += that.ima_;
        return *this;
    }
    complexx & operator=(complexx && that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "() move\n"; }
        real_ = std::move(that.real_);
        ima_ = std::move(that.ima_);
        return *this;
    }
    ~complexx() = default;

    void rdcmplx(void) {
        std::cout << "enter real & imaginary: ";
        std::cin >> real_ >> ima_;
        std::cout << std::endl;
    }

    void wrcmplx(void) {
        if (LOG) { std::clog << "complexx::" << __func__ << "()\n"; }
        std::cout << std::fixed << std::setprecision(3);
        std::cout << std::setw(9)
                  << real_;
        if (ima_ < 0.0) {
            std::cout << " - i" << ::fabs(ima_) << '\n';
        }
        else {
            std::cout << " + i" << ima_ << '\n';
        }
    }

    complexx sum(complexx x, complexx y) const {
        if (LOG) { std::clog << "complexx::" << __func__ << "(complexx,complexx)\n"; }
        complexx temp;
        temp.real_ = x.real_ + y.real_;
        temp.ima_ = x.ima_ + y.ima_;
        return temp;
    }

    complexx sum(complexx const & that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "(complexx)\n"; }
        complexx temp;
        temp.real_ = real_ + that.real_;
        temp.ima_ = ima_ + that.ima_;
        return temp;
    }

    // complexx operator+(complexx const & that) const {
    //     complexx temp;
    //     temp.real_ = real_ + that.real_;
    //     temp.ima_ = ima_ + that.ima_;
    //     return temp;
    // }

    complexx & operator+=(complexx const & that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "()\n"; }
        real_ += that.real_;
        ima_ += that.ima_;
        return *this;
    }

    complexx & operator-=(complexx const & that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "()\n"; }
        real_ -= that.real_;
        ima_ -= that.ima_;
        return *this;
    }

    //  etc.

    double real(void) const {
        return real_;
    }

    double real(double rl) {
        return (real_ = rl);
    }

    double ima(void) const {
        return ima_;
    }

    double ima(double im) {
        return (ima_ = im);
    }

    friend
    std::ostream & operator<<(std::ostream & os, complexx const & that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "()\n"; }
        os << std::fixed << std::setprecision(3);
        os << std::setw(9)
           << that.real_;
        if (that.ima_ < 0.0) {
            os << " - i" << ::fabs(that.ima_);
        }
        else {
            os << " + i" << that.ima_;
        }
        return os;
    }

    //  TODO: this doesn't seem logical, it needs too much knlowledge of the class
    //  probably safer to read data into temp vars. and insert them into the
    //  via the setter methods.
    friend
    std::istream & operator>>(std::istream & in, complexx & that) {
        if (LOG) { std::clog << "complexx::" << __func__ << "()\n"; }
        std::cin >> that.real_ >> that.ima_;
        return in;
    }

    //  MARK: operator+() - Helper function
    friend
    complexx operator+(complexx const & lft, complexx const & rgt) {
        if (LOG) { std::clog << "complexx::" << __func__ << "(complexx,complexx)\n"; }
        complexx temp;
        temp.real_ = lft.real_ + rgt.real_;
        temp.ima_ = lft.ima_ + rgt.ima_;
        return temp;
    }

    //  MARK: operator-() - Helper function
    friend
    complexx operator-(complexx const & lft, complexx const & rgt) {
        if (LOG) { std::clog << "complexx::" << __func__ << "(complexx,complexx)\n"; }
        complexx temp;
        temp.real_ = lft.real_ - rgt.real_;
        temp.ima_ = lft.ima_ - rgt.ima_;
        return temp;
    }
};

//  MARK: - Implementation
//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: operator+() - Helper function
// complexx operator+(complexx const & lft, complexx const & rgt) {
//     if (LOG) { std::clog << __func__ << "(complexx,complexx)\n"; }
//     complexx temp;
//     temp.real(lft.real() + rgt.real());
//     temp.ima(lft.ima() + rgt.ima());
//     return temp;
// }

//  MARK: operator-() - Helper function
// complexx operator-(complexx const & lft, complexx const & rgt) {
//     if (LOG) { std::clog << __func__ << "(complexx,complexx)\n"; }
//     complexx temp;
//     temp.real(lft.real() - rgt.real());
//     temp.ima(lft.ima() - rgt.ima());
//     return temp;
// }

//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: main()
int main(int argc, char const * argv[]) {
    std::string dlm = "A: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    complexx p1(1.0, 1.0);
    complexx p2(-33.0, -11.0);
    complexx p3;
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n";

//    p1.rdcmplx();
//    p2.rdcmplx();
    dlm = "B: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    std::cout << "sum(p1, p2)\n";
    p3 = p3.sum(p1, p2);
    std::cout << ":::\n";
    p3.wrcmplx();
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n";

    dlm = "C: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    std::cout << "p1.sum(p2)\n";
    p3 = complexx();
    p3 = p1.sum(p2);
    std::cout << ":::\n";
    p3.wrcmplx();
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n";

    dlm = "D: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    std::cout << "(p3 = p1 + p2)\n";
    std::cout << ":::\n";
    p3 = complexx();
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n"
              << "}}} p3 " << (p3 = p1 + p2) << ";\n";

    dlm = "E: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    std::cout << "(p3 += p2)\n";
    std::cout << ":::\n";
    p3 = complexx();
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n"
              << "}}} p3 " << (p3 += p2) << ";\n";

    dlm = "F: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    std::cout << "(p3 = p1 - p2)\n";
    std::cout << ":::\n";
    p3 = complexx();
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n"
              << "}}} p3 " << (p3 = p1 - p2) << ";\n";

    dlm = "G: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (LOG) { std::clog << dlm << '\n'; }
    std::cout << "(p3 -= p2)\n";
    std::cout << ":::\n";
    p3 = complexx();
    std::cout << "}}} p1 " << p1 << ";\n"
              << "}}} p2 " << p2 << ";\n"
              << "}}} p3 " << p3 << ";\n"
              << "}}} p3 " << (p3 -= p2) << ";\n";

#ifdef INTERACTIVE
    {
      dlm = "H: ....+....|....+....|....+....|....+....|....+....|";
      std::cout << dlm << '\n';
      if (LOG) { std::clog << dlm << '\n'; }
      std::cout << "std::cin >> t1 >> t2\n";
      std::cout << ":::\n";
      p3 = p1;
      double r_;
      double i_;
      std::cout << "enter real & imaginary: ";
      std::cin >> r_ >> i_;
      std::cout << '\n';
      p3.real(r_);
      p3.ima(i_);
      std::cout << "}}} p3 " << p3 << ";\n";
    }
#endif

#ifdef INTERACTIVE
    {
      dlm = "I: ....+....|....+....|....+....|....+....|....+....|";
      std::cout << dlm << '\n';
      if (LOG) { std::clog << dlm << '\n'; }
      std::cout << "std::cin >> r3\n";
      std::cout << ":::\n";
      std::cout << "enter real & imaginary: ";
      std::cin >> p3;
      std::cout << '\n';
      std::cout << "}}} p3 " << p3 << ";\n";
    }
#endif

    std::cout << "Done ...\n";
    if (LOG) { std::clog << "Done ...\n"; }

    return 0;
}
