// why my template class dont accept class template

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <typeinfo>

#include "demangle_a.h"

//  MARK: - Definitions
#ifdef THIS_WILL_NEVER_WORK_
//  MARK: Don't do this
template <class Q>
class T<Q> {
private:
  Q n;

public:
  template <class Qn>
  Q getValue() {
    return n;
  }

  void assign(const T<Qn> & d) {
    n = d.getValue();
  }

  void setValue(Q x) {
    n = x;
  }
};
#else /* maybe do this instead */
//  MARK: template class Q
template <class T>
class Q {
private:
  T n_;

public:
  T getValue() const {
    return n_;
  }

  template <class O>
  void assign(Q<O> const & other) {
    n_ = other.getValue();
  }

  void setValue(T x_) {
    n_ = x_;
  }
};
#endif /* THIS_WILL_NEVER_WORK_ */

#ifdef THIS_WILL_NEVER_WORK_
//  MARK: Don't do this either
// i can understand but i dont understand why rhis never work
template <class Q>
class T<Q> {
private:
  Q n;

public:
  template <class Qn>
  Q getValue() {
    return n;
  }

  void assign(const T<Qn> & d) {
    n = d.getValue();
  }

  void setValue(Q x) {
    n = x;
  }
};
#endif

// but this works

//  MARK: template class someclass
template <class T>
class someclass {
private:
  T t_;

public:
  T get() const {
    return t_;
  }

  T set(T const & tv) {
    t_ = tv;
    return t_;
  }

  template <class Q>
  void assign(someclass<Q> const & sx) {
    t_ = sx.get();
  }
};

//  MARK: template class Tcls
template <class Q, typename Qn = int>
class Tcls {
private:
  Q n_;

public:
  Tcls() {
    std::cout << "In default ctor Tcls::" << __func__ << "()\n";
    std::cout << "  type ID of 'this': " << typeid(this).name()
              << ", demangled: " << demangle(typeid(this).name())
              << '\n';
  }

  Tcls(Tcls const & that) {
    std::cout << "In copy ctor Tcls::" << __func__ << "()\n";
    n_ = that.n_;
  }

  Tcls(Tcls && that) {
    std::cout << "In move ctor Tcls::" << __func__ << "()\n";
    n_ = std::move(that.n_);
  }

  Tcls & operator=(Tcls const & that) {
    std::cout << "In copy assignment method Tcls::" << __func__ << "()\n";
    n_ = that.n_;
    return *this;
  }

  Tcls & operator=(Tcls && that) {
    std::cout << "In move assignment method Tcls::" << __func__ << "()\n";
    n_ = std::move(that.n_);
    return *this;
  }

  friend
  std::ostream & operator<<(std::ostream & os, Tcls const & that) {
    os << std::fixed << '{' << that.n_ << '}';
    return os;
  }

  Q getValue() const {
    std::cout << std::fixed << "In method Tcls::" << __func__ << "() -> " << n_ << '\n';
    return n_;
  }

  void assign(Tcls<Qn> const & dq) {
    std::cout << std::fixed << "In method Tcls::" << __func__ << "() <- " << dq << '\n';
    std::cout << "  arg 1 type ID: " << typeid(dq).name()
              << ", demangled: " << demangle(typeid(dq).name())
              << '\n';
    n_ = dq.getValue();
  }

  void setValue(Q xv) {
    std::cout << std::fixed << "In method Tcls::" << __func__ << "() <- " << xv << '\n';
    n_ = xv;
  }
};

//  MARK: call_Q()
void call_Q(void) {
  std::cout << "In fnuction " << __func__ << "()\n";

  std::cout << std::fixed;

  Q<int> qg;
  qg.setValue(78);
  std::cout << "qg: " << qg.getValue() << '\n';

  Q<double> qf;
  qf.assign(qg);
  std::cout << "qf: " << qf.getValue() << '\n';

  Q<std::string> qs;
  qs.assign(qg);
  std::cout << "qs: " << qs.getValue() << '\n';

#ifdef BREAK_ME_
  Q<std::pair<int, int>> qp;
  qp.assign(qg);
  std::cout << "qp: " << qp.getValue().first << ' ' << qp.getValue().second << '\n';
#endif /* BREAK_ME_ */
}

//  MARK: call_someclass()
void call_someclass(void) {
  std::cout << "In fnuction " << __func__ << "()\n";

  std::cout << std::fixed;

  someclass<int> scg;
  scg.set(80);
  std::cout << "scg: " << scg.get() << '\n';

  someclass<double> scd;
  scd.assign(scg);
  std::cout << "scd: " << scd.get() << '\n';

  someclass<char> scc;
  scc.assign(scg);
  std::cout << "scc: " << scc.get() << '\n';
}

//  MARK: call_Tcls()
void call_Tcls(void) {
  std::cout << "In fnuction " << __func__ << "()\n";

  std::cout << std::fixed;

  std::cout << std::string(60, '-') << '\n';
  {
    Tcls<int> ccg;
    ccg.setValue(0x41);
    std::cout << "ccg: " << ccg.getValue() << '\n';
  
    Tcls<double> ccd;
    ccd.assign(ccg);
    std::cout << "ccd: " << ccd.getValue() << '\n';
  }
  std::cout.put('\n');

  std::cout << std::string(60, '-') << '\n';
  {
    Tcls<double> ccd;
    ccd.setValue(65);
    std::cout << "ccd: " << ccd.getValue() << '\n';
  
    Tcls<int, double> ccg;
    ccg.assign(ccd);
    std::cout << "ccg: " << ccg.getValue() << '\n';
  }
  std::cout.put('\n');

  std::cout << std::string(60, '-') << '\n';
  {
    Tcls<double> ccd;
    ccd.setValue(66);
    std::cout << "ccd: " << ccd.getValue() << '\n';

    Tcls<char, double> ccc;
    ccc.assign(ccd);
    std::cout << "ccc: " << ccc.getValue() << '\n';
  }
  std::cout.put('\n');

  std::cout << std::string(60, '-') << '\n';
  {
    Tcls<double> ccd;
    ccd.setValue(67);
    std::cout << "ccd: " << ccd.getValue() << '\n';

    Tcls<std::string, double> ccs;
    ccs.assign(ccd);
    std::cout << "ccs: " << ccs.getValue() << '\n';
  }
  std::cout.put('\n');
}

//  MARK: main()
int main() {
  call_Q();

  std::cout << std::endl;
  call_someclass();

  std::cout << std::endl;
  call_Tcls();

#ifdef DEMANGLE_A_H
  demangle_a_sampler();
#endif /* DEMANGLE_A_H */

  return 0;
}
