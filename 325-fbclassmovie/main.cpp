
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std::literals::string_literals;

//  MARK: - Definitions.
/*
 *  MARK: Class Movie
 */
class Movie {
public:
  enum Rating : size_t { PG13, PG18, NR, };

  Movie(std::string nname = ""s,
        std::string ddirector = ""s,
        uint32_t pprod_date = 0ull,
        Rating rrating = Movie::Rating::NR)
  : name_ { nname }, director_ { ddirector },
    prod_date_ { pprod_date } , rating_ { rrating } {}
  Movie(Movie const &) = default;
  Movie(Movie &&) = default;
  ~Movie() = default;
  Movie & operator=(Movie const &) = default;
  Movie & operator=(Movie &&) = default;

  Rating rating(void) const { return rating_; }
  Rating rating(Rating rt) { return (rating_ = rt); }
  std::string name(void) const { return name_; }
  std::string name(std::string nm) { return (name_ = nm); }
  std::string director(void) const { return director_; }
  std::string director(std::string dr) { return (director_ = dr); }
  uint32_t prod_date(void) const { return prod_date_; }
  uint32_t prod_date(uint32_t pd) { return (prod_date_ = pd); }
  std::string rating_string(void) const { return Movie::rtg[rating_]; }

  std::string toString(void) const {
    std::stringstream oss;
    oss << "|[@"s << this << "]|"s
        << name_ << "|"s
        << rtg[rating_] << "|"s
        << prod_date_ << "|"s;

    return oss.str();
  }

  friend
  std::ostream & operator<<(std::ostream & os, Movie const & that) {
    os << that.toString();
    return os;
  }

private:
  Rating rating_;
  std::string name_;
  std::string director_;
  uint32_t prod_date_;

  static
  std::string rtg[];
};

//  MARK: - Implementation
/*
 *  MARK: Movie::rtg[] - Ratings strings.
 */
std::string Movie::rtg[] { "PG-13"s, "PG-18"s, "NR"s, };

/*
 *  MARK: main()
 */
int main() {
  Movie drno("Dr. No"s, "Terence Young"s, 1962, Movie::Rating::PG13);
  Movie frwl("From Russia with Love"s, "Terence Young"s, 1963, Movie::Rating::PG13);
  std::cout << drno.toString() << '\n';
  std::cout << frwl << '\n';

  return 0;
}
