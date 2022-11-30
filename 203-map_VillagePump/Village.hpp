
#pragma once

// enable when compiler can support spaceships
//#define SPOCK_

#include <iostream>
#include <iomanip>
#include <string>
#ifdef SPOCK_
#include <compare>
#endif

using namespace std::literals::string_literals;

class Village {
public:
  Village(std::string const & cy = ""s,
          std::string const & pe = ""s,
          std::string const & dt = ""s,
          std::string const & sr = ""s,
          std::string const & cl = ""s,
          std::string const & ve = ""s);
  Village(Village const & that);
  Village(Village && that);
  ~Village();

  Village const & operator=(Village const & that);
  Village & operator=(Village && that);

#ifdef SPOCK_
  auto operator<=>(Village const &)
  const = default;
#else
  bool operator==(Village const & that)
  const noexcept;
  bool operator!=(Village const & that)
  const noexcept;
  bool operator<(Village const & that)
  const noexcept;
  bool operator>(Village const & that)
  const noexcept;
  bool operator<=(Village const & that)
  const noexcept;
  bool operator>=(Village const & that)
  const noexcept;
#endif  // SPOCK_

  //  getters & setters
  std::string const & village(void)
  const noexcept {
    return village_;
  }
  std::string & village(std::string const & vl)
  noexcept {
    return (village_ = vl);
  }

  std::string const & cell(void)
  const noexcept {
    return cell_;
  }
  std::string & cell(std::string const & cl)
  noexcept {
    return (cell_ = cl);
  }

  std::string const & sector(void)
  const noexcept {
    return sector_;
  }
  std::string & sector(std::string const & sr)
  noexcept {
    return (sector_ = sr);
  }

  std::string const & district(void)
  const noexcept {
    return district_;
  }
  std::string & district(std::string & dt)
  noexcept {
    return (district_ = dt);
  }

  std::string const & province(void)
  const noexcept {
    return sector_;
  }
  std::string & province(std::string const & pe)
  noexcept {
    return (province_ = pe);
  }

  std::string const & country(void)
  const noexcept {
    return country_;
  }
  std::string & country(std::string const & cy)
  noexcept {
    return (country_ = cy);
  }

  friend
  std::ostream & operator<<(std::ostream & os,
                            Village const & that);

private:
  std::string country_;
  std::string province_;
  std::string district_;  
  std::string sector_;
  std::string cell_;
  std::string village_;
};
