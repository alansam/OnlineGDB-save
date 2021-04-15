//
//  main.cpp
//  CF.Typeid000
//
//  Created by Alan Sampson on 2/6/21.
//

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <vector>
#if __cplusplus > 201703L
# include <span>
#endif

using namespace std::literals::string_literals;

#if __cplusplus > 201703L
/*
 *  MARK: prtview()
 */
template <typename T>
void prtview(std::ostream & outie, std::span<T> container, int const col) {
  auto cc(0);
  auto constexpr cc_max(10);
  for (auto value : container) {
    outie << std::setw(col) << value
    << (++cc % cc_max == 0 ? "\n" : " " );
  }
  outie << std::endl;

  return;
}
#endif

/*
 *  MARK: Class Sum()
 */
template <class T>
class Sum {
public:
  Sum(T a = 0, T b = 0) {
    a_ = a;
    b_ = b;
    sum_ = a_ + b_;
  }

  T sum(T a, T b) {
    a_ = a;
    b_ = b;
    sum_ = a_ + b_;
    return sum_;
  }
  T sum() const {
    return sum_;
  }

private:
  T a_;
  T b_;
  T sum_;
};

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {

  int iry[] = { 10, 20, 30, 40, };
  long lry[1] = { 0 };
  char c_ = 0x41;
  signed char sc_ = 0x41 | 0x01;
  unsigned char uc_ = 0x41 | 0x20;
  short s_ = 0x1666;
  unsigned short us_ = 0x1666;
  int iv = 666;
  unsigned int uiv = 666;
  long lv = 666L;
  unsigned long ulv = 666L;
  long long llv = 666LL;
  unsigned long long ullv = 666LL;
  float fv = 66.6;
  double dv = 66.6;
  long double ldv = 66.6;
  double * dvp = &dv;
  char cc[] = { "C style array" };
  auto str = std::string{ "abc"s };
  auto strp = &str;
  auto vl = std::vector<long>( {
     0L, 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L, 90L,
    01L, 11L, 22L, 33L, 44L, 55L, 66L, } );
  auto vlp = &vl;
#if __cplusplus > 201703L
  auto wi = std::span<int>(iry, sizeof(iry) / sizeof(*iry));
  auto wip = &wi;
#endif

  struct Ms {
    int a1;
    short s1;
  } ms;
  auto msp = &ms;

  class Mc {
  public:
    int a1;
    short s1;
  } mc;
  auto mcp = &mc;

  class Hp {
  protected:
    int v1;
  };
  class Hc : public Hp {
  public:
    int v2;
  };
  auto hc1 = Hc();
  auto hp1 = Hp();
  Hp hp2 = Hc();

  union Mu {
    Mc mc;
    unsigned char bytes[sizeof(Mc)];
  } mu;
  auto mup = &mu;

  enum Me { A, B, C, } me;
  auto mep = &me;

  auto la1 = [](auto a_) -> int { return a_ * a_; };
  auto la2 = [](auto a_, auto b_) -> int { return a_ * b_; };
  auto la3 = [](auto a_, auto b_) -> int { return a_ / b_; };
  auto la4 = [](auto a_, auto b_, auto c_) -> double { return a_ / b_ * c_; };
  auto si  = Sum<int>(5, 7);
  auto sip = &si;
  auto sd  = Sum<double>(25.4, 25.4 * 2.);
  auto sdp = &sd;
  auto ss  = Sum<std::string>("Justin"s, "Tyme"s);
  auto ssp = &ss;

  std::cout << "c_    : " << std::setw(20) << c_       << ", " << typeid(c_).name()     << '\n';
  std::cout << "sc_   : " << std::setw(20) << sc_      << ", " << typeid(sc_).name()    << '\n';
  std::cout << "uc_   : " << std::setw(20) << uc_      << ", " << typeid(uc_).name()    << '\n';
  std::cout << "s_    : " << std::setw(20) << s_       << ", " << typeid(s_).name()     << '\n';
  std::cout << "us_   : " << std::setw(20) << us_      << ", " << typeid(us_).name()    << '\n';
  std::cout << "iv    : " << std::setw(20) << iv       << ", " << typeid(iv).name()     << '\n';
  std::cout << "uiv   : " << std::setw(20) << uiv      << ", " << typeid(uiv).name()    << '\n';
  std::cout << "lv    : " << std::setw(20) << lv       << ", " << typeid(lv).name()     << '\n';
  std::cout << "ulv   : " << std::setw(20) << ulv      << ", " << typeid(ulv).name()    << '\n';
  std::cout << "llv   : " << std::setw(20) << llv      << ", " << typeid(llv).name()    << '\n';
  std::cout << "ullv  : " << std::setw(20) << ullv     << ", " << typeid(ullv).name()   << '\n';
  std::cout << "fv    : " << std::setw(20) << fv       << ", " << typeid(fv).name()     << '\n';
  std::cout << "dv    : " << std::setw(20) << dv       << ", " << typeid(dv).name()     << '\n';
  std::cout << "ldv   : " << std::setw(20) << ldv      << ", " << typeid(ldv).name()    << '\n';
  std::cout << "dvp   : " << std::setw(20) << dvp      << ", " << typeid(dvp).name()    << '\n';
  std::cout << "*dvp  : " << std::setw(20) << *dvp     << ", " << typeid(*dvp).name()   << '\n';
  std::cout << "iry   : " << std::setw(20) << iry      << ", " << typeid(iry).name()    << '\n';
  std::cout << "iry[0]: " << std::setw(20) << iry[0]   << ", " << typeid(iry[0]).name() << '\n';
  std::cout << "lry   : " << std::setw(20) << lry      << ", " << typeid(lry).name()    << '\n';
  std::cout << "lry[0]: " << std::setw(20) << lry[0]   << ", " << typeid(lry[0]).name() << '\n';
  std::cout << "cc    : " << std::setw(20) << cc       << ", " << typeid(cc).name()     << '\n';
  std::cout << "&cc   : " << std::setw(20) << &cc      << ", " << typeid(&cc).name()    << '\n';
  std::cout << "*cc   : " << std::setw(20) << *cc      << ", " << typeid(*cc).name()    << '\n';
  std::cout << "&cc[0]: " << std::setw(20) << &cc[0]   << ", " << typeid(&cc[0]).name() << '\n';
  std::cout << "&cc[2]: " << std::setw(20) << &cc[2]   << ", " << typeid(&cc[2]).name() << '\n';
  std::cout << "&cc[4]: " << std::setw(20) << &cc[4]   << ", " << typeid(&cc[4]).name() << '\n';
  std::cout << "str   : " << std::setw(20) << str      << ", " << typeid(str).name()    << '\n';
  std::cout << "strp  : " << std::setw(20) << strp     << ", " << typeid(strp).name()   << '\n';
  std::cout << "vl    : " << std::setw(20) << ' '      << ", " << typeid(vl).name()     << '\n';
  std::cout << "vlp   : " << std::setw(20) << vlp      << ", " << typeid(vlp).name()    << '\n';
#if __cplusplus > 201703L
  std::cout << "wi    : " << std::setw(20) << ' '      << ", " << typeid(wi).name()     << '\n';
  std::cout << "wip   : " << std::setw(20) << wip      << ", " << typeid(wip).name()    << '\n';
#endif
  std::cout << "ms    : " << std::setw(20) << ' '      << ", " << typeid(ms).name()     << '\n';
  std::cout << "msp   : " << std::setw(20) << msp      << ", " << typeid(msp).name()    << '\n';
  std::cout << "mc    : " << std::setw(20) << ' '      << ", " << typeid(mc).name()     << '\n';
  std::cout << "mcp   : " << std::setw(20) << mcp      << ", " << typeid(mcp).name()    << '\n';
  std::cout << "uc    : " << std::setw(20) << ' '      << ", " << typeid(mu).name()     << '\n';
  std::cout << "ucp   : " << std::setw(20) << mup      << ", " << typeid(mup).name()    << '\n';
  std::cout << "me    : " << std::setw(20) << ' '      << ", " << typeid(me).name()     << '\n';
  std::cout << "mep   : " << std::setw(20) << mep      << ", " << typeid(mep).name()    << '\n';
  std::cout << "hp1   : " << std::setw(20) << ' '      << ", " << typeid(hp1).name()    << '\n';
  std::cout << "hc1   : " << std::setw(20) << ' '      << ", " << typeid(hc1).name()    << '\n';
  std::cout << "hp2   : " << std::setw(20) << ' '      << ", " << typeid(hp2).name()    << '\n';
  std::cout << "ls1   : " << std::setw(20) << ' '      << ", " << typeid(la1).name()    << '\n';
  std::cout << "ls2   : " << std::setw(20) << ' '      << ", " << typeid(la2).name()    << '\n';
  std::cout << "ls3   : " << std::setw(20) << ' '      << ", " << typeid(la3).name()    << '\n';
  std::cout << "ls4   : " << std::setw(20) << ' '      << ", " << typeid(la4).name()    << '\n';
  std::cout << "si    : " << std::setw(20) << si.sum() << ", " << typeid(si).name()     << '\n';
  std::cout << "sip   : " << std::setw(20) << sip      << ", " << typeid(sip).name()    << '\n';
  std::cout << "sd    : " << std::setw(20) << sd.sum() << ", " << typeid(sd).name()     << '\n';
  std::cout << "sdp   : " << std::setw(20) << sdp      << ", " << typeid(sdp).name()    << '\n';
  std::cout << "ss    : " << std::setw(20) << ss.sum() << ", " << typeid(ss).name()     << '\n';
  std::cout << "ssp   : " << std::setw(20) << ssp      << ", " << typeid(ssp).name()    << '\n';
  std::cout << std::endl;

#if __cplusplus > 201703L
  prtview<int>(std::cout, iry, 3);
  prtview<long>(std::cout, vl, 3);
  prtview<int>(std::cout,  wi, 3);
#endif

  return 0;
}
