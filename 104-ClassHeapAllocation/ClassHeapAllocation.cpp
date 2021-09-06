
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <memory>

class myclass {
private:
  int * x_;
  std::unique_ptr<long> uplval;
public:
/*
  myclass(int num = 24, long lval = 666L) {
    x_ = new int { num };
    uplval = std::make_unique<long>(lval);
  }
*/
  myclass(int num = 24, long lval = 666L)
  : x_ { new int { num } },
    uplval { std::make_unique<long>(lval) } {}
  ~myclass() {
    delete x_;
  }
  int x(void) const { return *x_; }
  int x(int x) {
    *x_ = x;
    return *x_;
  }
  long lval(void) const { return *uplval; }
  long lval(long val) {
    uplval.reset(new long { val });
    return *uplval;
  }
  std::string const toString() const {
    std::ostringstream oss;
    oss << "Class @" << this
        << "\n... " << "x    @" << x_ << ", value " << x()
        << "\n... " << "lval @" << uplval.get() << ", value " << lval();
    return oss.str();
  };
  friend
  std::ostream & operator<<(std::ostream & oss, myclass const & me) {
    oss << me.toString();
    return oss;
  }
};

int main() {
  myclass mcd;
  std::cout << mcd << std::endl;
  mcd.x(42);
  mcd.lval(633l);
  std::ostringstream oss;
  oss << mcd;
  std::cout << oss.str() << std::endl;

  myclass mcv(666, 616L);
  std::cout << mcv << std::endl;
}
