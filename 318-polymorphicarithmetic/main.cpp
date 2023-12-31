
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <tuple>
#include <functional>
#include <stdexcept>

using namespace std::literals::string_literals;

/*
 *  MARK: class Arithmetic - abstract class
 */
class Arithmetic {
public:
  //  MARK: Arithmetic::Arithmetic() - default c'tor
  Arithmetic(double val0 = 0, double val1 = 0)
  : val0_ { val0 }, val1_ { val1 }, oper_ { ""s } {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "() default c'tor\n"s;
  }
  //  MARK: Arithmetic::Arithmetic() - copy c'tor
  Arithmetic(Arithmetic const & that)
  : val0_ { that.val0_ }, val1_ { that.val1_ }, oper_ { that.oper_ } {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "() copy c'tor\n"s;
  }
  //  MARK: Arithmetic::Arithmetic() - move c'tor
  Arithmetic(Arithmetic && that)
  : val0_ { std::move(that.val0_) },
    val1_ { std::move(that.val1_) },
    oper_ { std::move(that.oper_) } {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "() move c'tor\n"s;
  }
  //  MARK: Arithmetic::~Arithmetic() - d'tor
  virtual
  ~Arithmetic() {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "() d'tor\n"s;
  }
  //  MARK: Arithmetic::operator=() - copy oper
  Arithmetic & operator=(Arithmetic const & that) {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "() copy assignment\n"s;
    if (this != &that) {
      val0_ = that.val0_;
      val1_ = that.val1_;
      oper_ = that.oper_;
    }
    return *this;
  }
  //  MARK: Arithmetic::operator=() - move oper
  Arithmetic & operator=(Arithmetic && that) {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "() move assignment\n"s;
    if (this != &that) {
      val0_ = std::move(that.val0_);
      val1_ = std::move(that.val1_);
      oper_ = std::move(that.oper_);
    }
    return *this;
  }

  //  MARK: accessors [getters] & mutators [setters]
  virtual
  double val0(void) const { return val0_; }
  virtual
  double val0(double v_) { return (val0_ = v_); }
  virtual
  double val1(void) const { return val1_; }
  virtual
  double val1(double v_) { return (val1_ = v_); }
  virtual
  std::string oper(void) const { return oper_; }
  virtual
  std::string oper(std::string const op) { return (oper_ = op); }

  //  MARK: Arithmetic::run() - function runner - pure abstract function
  virtual
  double run(void) = 0;

  //  MARK: Arithmetic::operator()() - functor - drives concrete run() methods
  virtual
  double operator()(void) {
    std::clog << "-: [@"s << this << "] Arithmetic::"s << __func__ << "()\n"s;
    return run();
  }

  //  Arithmetic::toString()
  virtual
  std::string toString(void) const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << std::setw(7) << val0_ << oper_ << val1_;
    return ss.str();
  }

  //  operator<<() friend method
  friend
  std::ostream & operator<<(std::ostream & os, Arithmetic const & that) {
    os << that.toString();
    return os;
  }

protected:
  double val0_;
  double val1_;
  std::string oper_;

private:
  // TODO: add private data members here
};

/*
 *  MARK: class Adder
 */
class Adder : public Arithmetic {
public:
  //  MARK: Adder::Adder() - default c'tor
  Adder(double val0 = 0.0, double val1 = 0.0)
  : Arithmetic(val0, val1) {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "() default c'tor\n"s;
    oper(" \u002b "s);
  }
  //  MARK: Adder::Adder() - copy c'tor
  Adder(Adder const & that)
  : Arithmetic(that.val0_, that.val1_) {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "() copy c'tor\n"s;
    oper(that.oper());
  }
  //  MARK: Adder::Adder() - move c'tor
  Adder(Adder && that)
  : Arithmetic(std::move(that.val0_), std::move(that.val1_)) {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "() move c'tor\n"s;
    oper(std::move(that.oper_));
  }
  //  MARK: Adder::~Adder() - d'tor
  virtual
  ~Adder() {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "() d'tor\n"s;
  }
  //  MARK: Adder::operator=() - copy assignment oper
  Adder & operator=(Adder const & that) {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "() copy assignment\n"s;
    val0_ = that.val0_;
    val1_ = that.val1_;
    return *this;
  }
  //  MARK: Adder::operator=() - move assignment oper
  Adder & operator=(Adder && that) {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "() move assignment\n"s;
    val0_ = std::move(that.val0_);
    val1_ = std::move(that.val1_);
    return *this;
  }

  //  MARK: Adder::run() - function runner
  virtual
  double run(void) {
    std::clog << "-: [@"s << this << "] Adder::"s << __func__ << "()\n"s;
    double sum = val0() + val1();
    return sum;
  }
};

/*
 *  MARK: class Subtractor
 */
class Subtractor : public Arithmetic {
public:
  //  MARK: Subtractor::Subtractor() - default c'tor
  Subtractor(double val0 = 0.0, double val1 = 0.0)
  : Arithmetic(val0, val1) {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "() default c'tor\n"s;
    oper(" \u2212 "s);
  }
  //  MARK: Subtractor::Subtractor() - copy c'tor
  Subtractor(Subtractor const & that)
  : Arithmetic(that.val0_, that.val1_) {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "() copy c'tor\n"s;
    oper(that.oper_);
  }
  //  MARK: Subtractor::Subtractor() - move c'tor
  Subtractor(Subtractor && that)
  : Arithmetic(std::move(that.val0_), std::move(that.val1_)) {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "() move c'tor\n"s;
    oper(std::move(that.oper_));
  }
  //  MARK: Subtractor::~Subtractor() - d'tor
  virtual
  ~Subtractor() {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "() d'tor\n"s;
  }
  //  MARK: Subtractor::operator=() - copy assignment oper
  Subtractor & operator=(Subtractor const & that) {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "() copy assignment\n"s;
    val0_ = that.val0_;
    val1_ = that.val1_;
    return *this;
  }
  //  MARK: Subtractor::operator=() - move assignment oper
  Subtractor & operator=(Subtractor && that) {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "() move assignment\n"s;
    val0_ = std::move(that.val0_);
    val1_ = std::move(that.val1_);
    return *this;
  }

  //  MARK: Subtractor::run() - function runner
  virtual
  double run(void) {
    std::clog << "-: [@"s << this << "] Subtractor::"s << __func__ << "()\n"s;
    double difference = val0_ - val1_;
    return difference;
  }
};

/*
 *  MARK: class Multiplier
 */
class Multiplier : public Arithmetic {
public:
  //  MARK: Multiplier::Multiplier() - default c'tor
  Multiplier(double val0 = 0.0, double val1 = 0.0)
  : Arithmetic(val0, val1) {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "() default c'tor\n"s;
    oper(" \u00d7 "s);
  }
  //  MARK: Multiplier::Multiplier() - copy c'tor
  Multiplier(Multiplier const & that)
  : Arithmetic(that.val0_, that.val1_) {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "() copy c'tor\n"s;
    oper(that.oper_);
  }
  //  MARK: Multiplier::Multiplier() - move c'tor
  Multiplier(Multiplier && that)
  : Arithmetic(std::move(that.val0_), std::move(that.val1_)) {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "() move c'tor\n"s;
    oper(std::move(that.oper_));
  }
  //  MARK: Subtractor::Subtractor() - d'tor
  virtual
  ~Multiplier() {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "() d'tor\n"s;
  }
  //  MARK: Multiplier::operator=() - copy assignment oper
  Multiplier & operator=(Multiplier const & that) {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "() copy assignment\n"s;
    val0_ = that.val0_;
    val1_ = that.val1_;
    return *this;
  }
  //  MARK: Multiplier::operator=() - move assignment oper
  Multiplier & operator=(Multiplier && that) {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "() move assignment\n"s;
    val0_ = std::move(that.val0_);
    val1_ = std::move(that.val1_);
    return *this;
  }

  //  MARK: Multiplier::run() - function runner
  virtual
  double run(void) {
    std::clog << "-: [@"s << this << "] Multiplier::"s << __func__ << "()\n"s;
    double product = val0() * val1();
    return product;
  }
};

/*
 *  MARK: class Divider
 */
class Divider : public Arithmetic {
public:
  //  MARK: Divider::Divider() - default c'tor
  Divider(double val0 = 0.0, double val1 = 0.0)
  : Arithmetic(val0, val1) {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "() default c'tor\n"s;
    oper(" \u00f7 "s);
  }
  //  MARK: Divider::Divider() - copy c'tor
  Divider(Divider const & that)
  : Arithmetic(that.val0_, that.val1_) {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "() copy c'tor\n"s;
    oper(that.oper_);
  }
  //  MARK: Divider::Divider() - move c'tor
  Divider(Divider && that)
  : Arithmetic(std::move(that.val0_), std::move(that.val1_)) {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "() move c'tor\n"s;
    oper(std::move(that.oper_));
  }
  //  MARK: Divider::~Divider() - d'tor
  virtual
  ~Divider() {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "() d'tor\n"s;
  }
  //  MARK: Divider::operator=() - copy assignment oper
  Divider & operator=(Divider const & that) {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "() copy assignment\n"s;
    val0_ = that.val0_;
    val1_ = that.val1_;
    return *this;
  }
  //  MARK: Divider::operator=() - move assignment oper
  Divider & operator=(Divider && that) {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "() move assignment\n"s;
    val0_ = std::move(that.val0_);
    val1_ = std::move(that.val1_);
    return *this;
  }

  //  MARK: Divider::run() - function runner
  virtual
  double run(void) {
    std::clog << "-: [@"s << this << "] Divider::"s << __func__ << "()\n"s;
    if (val1() == 0.0) {
      throw std::overflow_error("Divide by zero exception"s);
    }

    double quotient = val0() / val1();
    return quotient;
  }
};

// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << std::fixed << std::setprecision(3);
  auto a1 = Adder(1.5, 2.0);
  auto s1 = Subtractor(1.5, 2.0);
  auto m1 = Multiplier(1.5, 2.0);
  auto d1 = Divider(1.5, 2.0);

  {
    auto a1r = a1();
    auto s1r = s1();
    auto m1r = m1();
    auto d1r = d1();
  
    std::cout << std::endl;
    std::cout << std::string(80, '-') << '\n';
    std::cout << std::setw(10) << "add: "s
              << std::setw(7)  << a1.val0() << a1.oper()
              << std::setw(7)  << a1.val1() << " = "s
              << std::setw(7)  << a1r << '\n';
    std::cout << std::setw(10) << "subtract: "
              << std::setw(7)  << s1.val0() << s1.oper()
              << std::setw(7)  << s1.val1() << " = "s
              << std::setw(7)  << s1r << '\n';
    std::cout << std::setw(10) << "multiply: "
              << std::setw(7)  << m1.val0() << m1.oper()
              << std::setw(7)  << m1.val1() << " = "s
              << std::setw(7)  << m1r << '\n';
    std::cout << std::setw(10) << "divide: "
              << std::setw(7)  << d1.val0() << m1.oper()
              << std::setw(7)  << d1.val1() << " = "s
              << std::setw(7)  << d1r << '\n';
    std::cout << std::string(80, '-') << '\n';
    std::cout << std::endl;

    std::vector<std::unique_ptr<Arithmetic>> arith;
  
    arith.push_back(std::unique_ptr<Arithmetic>(new Adder(a1)));
    arith.push_back(std::unique_ptr<Arithmetic>(new Subtractor(s1)));
    arith.push_back(std::unique_ptr<Arithmetic>(new Multiplier(m1)));
    arith.push_back(std::unique_ptr<Arithmetic>(new Divider(d1)));
  
    auto results = std::vector<std::tuple<double, std::string, double, double>>();
    for (auto const & _ath : arith) {
      results.push_back(
        std::make_tuple(
          (*_ath).val0(),
          (*_ath).oper(),
          (*_ath).val1(),
          (*_ath)()));
    }

    std::cout << std::endl;
    std::cout << std::string(80, '=') << '\n';
    for (auto const & rslt : results) {
      std::cout << std::setw(7) << std::get<0>(rslt)
                << std::get<1>(rslt)
                << std::setw(7) << std::get<2>(rslt)
                << " = "s
                << std::setw(7) << std::get<3>(rslt)
                << '\n';
    }
    std::cout << std::string(80, '=') << '\n';
    std::cout << std::endl;
  }
  std::cout << std::endl;

  {
    auto d2 = Divider();
    std::cout << d2 << '\n';
    d2 = d1;
    auto d3(d1);
    auto d1r = d1();
    auto d2r = d2();
    auto d3r = d3();
  
    std::cout << std::endl;
    std::cout << std::string(80, '~') << '\n';
  
    std::cout << d1 << " = " << std::setw(7) << d1r << '\n';
    std::cout << d2 << " = " << std::setw(7) << d2r << '\n';
    std::cout << d3 << " = " << std::setw(7) << d3r << '\n';
  
    std::cout << std::string(80, '~') << '\n';
    std::cout << std::endl;

    try {
      d3.val1(0.0);
      d3r = d3();
      std::cout << d3 << " = " << std::setw(7) << d3r << '\n';
    }
    catch (std::exception & ex) {
      std::cerr << "X: [@" << &ex << "] GRONK! "s
                << ex.what()
                << " Divider: «"s << d3 << "»"s << '\n';
    }
  }
  std::cout << std::endl;

  return 0;
}

