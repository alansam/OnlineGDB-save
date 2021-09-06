
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

class VariableDef {
public:
  VariableDef(char const var = ' ') : varType_ { var } {};
  ~VariableDef() = default;

  char varType(char var) {
    varType_ = var;
    return varType_;
  }
  char varType(void) const {
    return varType_;
  }

  bool operator ==(auto const that) const {
    return varType_ == that.varType();
  }

  bool operator !=(auto const that) const {
    return varType_ != that.varType();
  }

  bool operator <(auto const that) const {
    return varType_ < that.varType();
  }

  bool operator >(auto const that) const {
    return varType_ > that.varType();
  }

  bool operator <=(auto const that) const {
    return varType_ <= that.varType();
  }

  bool operator >=(auto const that) const {
    return varType_ >= that.varType();
  }

  friend
  std::ostream & operator <<(std::ostream & oss, VariableDef const & thing) {
    oss << "\""  << thing.varType() << "\"" << ' '
        << std::hex << std::setw(2)
        << std::setfill('0')
        << static_cast<unsigned short>(thing.varType() & 0x00ff)
        << std::setfill(' ')
        << std::dec;
    return oss;
  }

private:
  char varType_;
};

std::vector<VariableDef> & getdata(std::vector<VariableDef> & varCall);
void verify(void);
void samp11(void);
void samp17(void);

int main() {
  std::cout << "C++ Version: " << __cplusplus << std::endl;

#if (__cplusplus < 201700L)
  samp11();
#else
  samp17();
#endif
  verify();

  return 0;
}

void samp11(void) {
  std::cout << "In function " << __func__ << std::endl;

  std::vector<VariableDef> varCall;
  varCall = getdata(varCall);

  std::cout << "VariableDef contents ...\n";
  for (auto const vc : varCall) { std::cout << vc.varType(); }
  std::cout << std::endl;

  for (auto vc : varCall) { std::cout << vc << '\n'; }

  std::cout << "VariableDef sorted [default] ...\n";
  std::sort(varCall.begin(), varCall.end());
  for (auto vc : varCall) { std::cout << vc << '\n'; }

  std::cout << "VariableDef sorted [descending lambda] ...\n";
  std::sort(varCall.begin(), varCall.end(), [](auto lh, auto rh) {
    return lh.varType() > rh.varType();
  });
  for (auto vc : varCall) { std::cout << vc << '\n'; }

  std::cout << "VariableDef sorted [ascending functional] ...\n";
  std::sort(varCall.begin(), varCall.end(), std::less<VariableDef>());
  for (auto vc : varCall) { std::cout << vc << '\n'; }

  std::cout << "VariableDef sorted [descending functional] ...\n";
  std::sort(varCall.begin(), varCall.end(), std::greater<VariableDef>());
  for (auto vc : varCall) { std::cout << vc << '\n'; }
  std::cout << std::endl;
}

void samp17(void) {
  std::cout << "In function " << __func__ << std::endl;

  auto varCall = std::vector<VariableDef>();
  varCall = getdata(varCall);

  std::cout << "VariableDef contents ...\n";
  std::for_each(varCall.cbegin(), varCall.cend(), [](auto const vc) { std::cout << vc.varType(); });
  std::cout << std::endl;
  std::for_each(varCall.cbegin(), varCall.cend(), [](auto const vc) { std::cout << vc << '\n'; });

  std::cout << "VariableDef sorted [default] ...\n";
  std::sort(varCall.begin(), varCall.end());
  std::for_each(varCall.cbegin(), varCall.cend(), [](auto const vc) { std::cout << vc << '\n'; });

  std::cout << "VariableDef sorted [descending lambda] ...\n";
  std::sort(varCall.begin(), varCall.end(), [](auto lh, auto rh) { return lh.varType() > rh.varType(); });
  std::for_each(varCall.cbegin(), varCall.cend(), [](auto const vc) { std::cout << vc << '\n'; });

  std::cout << "VariableDef sorted [ascending functional] ...\n";
  std::sort(varCall.begin(), varCall.end(), std::less<VariableDef>());
  std::for_each(varCall.cbegin(), varCall.cend(), [](auto const vc) { std::cout << vc << '\n'; });

  std::cout << "VariableDef sorted [descending functional] ...\n";
  std::sort(varCall.begin(), varCall.end(), std::greater<VariableDef>());
  std::for_each(varCall.cbegin(), varCall.cend(), [](auto const vc) { std::cout << vc << '\n'; });
  std::cout << std::endl;
}

void verify(void) {
  std::cout << "In function " << __func__ << std::endl;

  auto vdA0 = VariableDef('A');
  auto vdA1 = VariableDef('A');
  auto vdB0 = VariableDef('B');
  std::cout << vdA0 << " == " << vdA1 << " ? " << std::boolalpha << (vdA0 == vdA1) << '\n';
  std::cout << vdA0 << " == " << vdB0 << " ? " << std::boolalpha << (vdA0 == vdB0) << '\n';
  std::cout << vdB0 << " == " << vdA0 << " ? " << std::boolalpha << (vdB0 == vdA0) << '\n';
  std::cout << vdA0 << " != " << vdA1 << " ? " << std::boolalpha << (vdA0 != vdA1) << '\n';
  std::cout << vdA0 << " != " << vdB0 << " ? " << std::boolalpha << (vdA0 != vdB0) << '\n';
  std::cout << vdB0 << " != " << vdA0 << " ? " << std::boolalpha << (vdB0 != vdA0) << '\n';
  std::cout << vdA0 << " <  " << vdA1 << " ? " << std::boolalpha << (vdA0 <  vdA1) << '\n';
  std::cout << vdA0 << " >  " << vdA1 << " ? " << std::boolalpha << (vdA0 >  vdA1) << '\n';
  std::cout << vdA0 << " <  " << vdB0 << " ? " << std::boolalpha << (vdA0 <  vdB0) << '\n';
  std::cout << vdA0 << " >  " << vdB0 << " ? " << std::boolalpha << (vdA0 >  vdB0) << '\n';
  std::cout << vdB0 << " <  " << vdA0 << " ? " << std::boolalpha << (vdB0 <  vdA0) << '\n';
  std::cout << vdB0 << " >  " << vdA0 << " ? " << std::boolalpha << (vdB0 >  vdA0) << '\n';
  std::cout << vdA0 << " <= " << vdA0 << " ? " << std::boolalpha << (vdA0 <= vdA0) << '\n';
  std::cout << vdA0 << " >= " << vdA0 << " ? " << std::boolalpha << (vdA0 >= vdA0) << '\n';
  std::cout << vdA0 << " >= " << vdA0 << " ? " << std::boolalpha << (vdA0 >= vdA0) << '\n';
  std::cout << vdB0 << " <= " << vdA0 << " ? " << std::boolalpha << (vdB0 <= vdA0) << '\n';
  std::cout << vdB0 << " >= " << vdA0 << " ? " << std::boolalpha << (vdB0 >= vdA0) << '\n';
  std::cout << std::endl;
}

std::vector<VariableDef> & getdata(std::vector<VariableDef> & varCall) {
  std::cout << "In function " << __func__ << std::endl;

  int vc;
  int lc = ' ';
  std::cout << "Enter characters [CTRL-D or \\n\\n to stop] ...\n";
  while ((vc = std::getchar()) != EOF) {
    if (vc == '\n') {
      if (lc == '\n') {
        break;
      }
      lc = vc;
      continue;
    } //  discard NEWLINE chars.
    lc = vc;

#if (__cplusplus < 201700L)
    VariableDef vd;
    vd.varType(vc);
#else
    auto vd = VariableDef(vc);
#endif
    varCall.push_back(vd);
  }

  return varCall;
}
