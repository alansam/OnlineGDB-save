
#include "Village.hpp"

Village::Village(std::string const & cy,
                 std::string const & pe,
                 std::string const & dt,
                 std::string const & sr,
                 std::string const & cl,
                 std::string const & ve) :
  country_   { cy },
  province_  { pe },
  district_  { dt },
  sector_    { sr },
  cell_      { cl },
  village_   { ve }
{
  std::clog << "@["s << std::setw(18) << this << "]"s
            << " In "s << __func__
            << "(std::string const &,std::string const &,std::string const &,std::string const &std::string const &,std::string const &) - Default c'tor\n"s;
}

Village::Village(Village const & that) :
  country_   { that.country_ },
  province_  { that.province_ },
  district_  { that.district_ },
  sector_    { that.sector_ },
  cell_      { that.cell_ },
  village_   { that.village_ } {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &) - Copy c'tor\n"s;
}

Village::Village(Village && that) {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village &&) - Move c'tor\n"s;
  country_  = std::move(that.country_);
  province_ = std::move(that.province_);
  district_ = std::move(that.district_);
  sector_   = std::move(that.sector_);
  cell_     = std::move(that.cell_);
  village_  = std::move(that.village_);
}

Village::~Village() {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s
            << __func__
            << "() - D'tor\n"s;
}

Village const & Village::operator=(Village const & that) {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &) - Copy assignment\n"s;
  country_  = that.country_;
  province_ = that.province_;
  district_ = that.district_;
  sector_   = that.sector_;
  cell_     = that.cell_;
  village_  = that.village_;

  return *this;
}

Village & Village::operator=(Village && that) {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village &&) - Move assignment\n"s;
  country_  = std::move(that.country_);
  province_ = std::move(that.province_);
  district_ = std::move(that.district_);
  sector_   = std::move(that.sector_);
  cell_     = std::move(that.cell_);
  village_  = std::move(that.village_);

  return *this;
}

#ifndef SPOCK_
bool Village::operator==(Village const & that)
const noexcept {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &)\n"s;
  return country_  == that.country_
      && province_ == that.province_
      && district_ == that.district_
      && sector_   == that.sector_
      && cell_     == that.cell_
      && village_  == that.village_;
}

bool Village::operator!=(Village const & that)
const noexcept {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &)\n"s;
  return !(*this == that);
}

bool Village::operator<(Village const & that)
const noexcept {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &)\n"s;
  return  (country_  <  that.country_)

  ||     ((country_  == that.country_)
  &&      (province_ <  that.province_))

  ||     ((country_  == that.country_)
  &&      (province_ == that.province_)
  &&      (district_ <  that.district_))

  ||     ((country_  == that.country_)
  &&      (province_ == that.province_)
  &&      (district_ == that.district_)
  &&      (sector_   <  that.sector_))

  ||     ((country_  == that.country_)
  &&      (province_ == that.province_)
  &&      (district_ == that.district_)
  &&      (sector_   == that.sector_)
  &&      (cell_     <  that.cell_))

  ||     ((country_  == that.country_)
  &&      (province_ == that.province_)
  &&      (district_ == that.district_)
  &&      (sector_   == that.sector_)
  &&      (cell_     == that.cell_)
  &&      (village_  <  that.village_))
  ;
}

bool Village::operator>(Village const & that)
const noexcept {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &)\n"s;
  return that < *this;
}

bool Village::operator<=(Village const & that)
const noexcept {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &)\n"s;
  return !(that < *this);
}

bool Village::operator>=(Village const & that)
const noexcept {
  std::clog << "@["s << std::setw(18)  << this << "]"s
            << " In "s << __func__
            << "(Village const &)\n"s;
  return !(*this < that);
}

#endif // SPOCK_

std::ostream & operator<<(std::ostream & os,
                          Village const & that) {
  os << that.country_  << ", "s
     << that.province_ << ", "s
     << that.district_ << ", "s
     << that.sector_   << ", "s
     << that.cell_     << ", "s
     << that.village_;

  return os;
}
