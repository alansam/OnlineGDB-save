
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std::literals::string_literals;


//  Author.hpp
namespace bkrp {

//  MARK: Enumeration Gender
enum Gender { UNSPECIFIED, MALE = 'M', FEMALE = 'F', };

//  MARK: Structure Author
struct Author {
public:
  std::string name;
  std::string email;
  Gender gender;
};

} /* namespace bkrp */

//  Author.hpp
namespace bkrp {

//  Class Book
class Book {
public:
  Book(std::string name = ""s,
       Author author = { ""s, ""s, UNSPECIFIED, },
       double price = 0.0, int qtyInStock = 0);
  virtual ~Book() = default;

  Book(Book const & that) noexcept;
  Book(Book && that) noexcept;

  Book & operator=(Book const & that) noexcept;
  Book & operator=(Book && that) noexcept;
 
  virtual std::string getName(void)       const { return name_; }
  virtual Author      getAuthor(void)     const { return author_; }
  virtual double      getPrice(void)      const { return price_; }
  virtual int         getQtyInStock(void) const { return qtyInStock_; }

  virtual void setPrice(double price)        { price_ = price; }
  virtual void setQtyInStock(int qtyInStock) { qtyInStock_ = qtyInStock; }

  virtual std::string getAuthorName(void) const { return author_.name; }

  virtual void print(bool raw = false) const;
  virtual std::string toString(bool raw = false) const;
  virtual std::string json(void) const;

private:
  std::string name_;
  Author      author_;
  double      price_;
  int         qtyInStock_;
};

} /* namespace bkrp */

//  main.cpp
/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "CF.BookReport00"s << std::endl;

  std::cout << "Vector"s << std::endl;

  auto books = std::vector<bkrp::Book> {
   bkrp::Book("Lord of the Rings"s,
    { "J.R.R. Tolkien", "jrrt@middleearth.ac.uk"s, bkrp::MALE }, 45.0, 5),
    bkrp::Book("A Brief History of Time"s,
    { "Stephen Hawking", "hawking@thirdblackholeontheleft.ac.uc"s, bkrp::MALE }),
  };

  books[1].setPrice(30.0);
  books[1].setQtyInStock(15);

  for (auto const & bk : books) {
    bk.print();
  }
  std::cout << std::endl;

  auto bkmp = std::map<std::string const, bkrp::Book> {
    { "lotr"s,
      bkrp::Book("Lord of the Rings"s,
           { "J.R.R. Tolkien", "jrrt@middleearth.ac.uk"s, bkrp::MALE, },
           45.0, 5), },
    { "bhot"s,
      bkrp::Book("A Brief History of Time"s,
           { "Stephen Hawking", "hawking@thirdblackholeontheleft.ac.uc"s, bkrp::MALE, }), },
    { "con"s,
      bkrp::Book("The Chronicles of Narnia"s,
           { "C.S. Lewis"s, "CliveStaples@narnia.ac.uk", bkrp::MALE, }), },
    { "aiw"s,
      bkrp::Book("Alice in Wonderland"s,
           { "Lewis Carroll"s, "CharlesLutwidgeDodgson@wonderland.ac.uc", bkrp::MALE, },
           29.99, 40), },
    { "attlg"s,
      bkrp::Book("Through the Looking-Glass, and What Alice Found There"s,
           { "Lewis Carroll"s, "CharlesLutwidgeDodgson@wonderland.ac.uc", bkrp::MALE, },
           29.99, 35), },
    { "hpps"s,
      bkrp::Book("Harry Potter and the Philosopher's Stone"s,
           {"J.K. Rowling"s, "jk@hogwarts.ac.uk"s, bkrp::FEMALE, },
           15.49, 19), },
  };

  std::cout << "Map"s << std::endl;

  bkmp["bhot"s].setPrice(30.0);
  bkmp["bhot"s].setQtyInStock(15);

  bkmp["con"s].setPrice(15.0);
  bkmp["con"s].setQtyInStock(12);

  for (auto const & [key, val] : bkmp) {
    std::cout << key << ": "s << val.toString() << std::endl;
  }
  std::cout << std::endl;

  for (auto const & [key, val] : bkmp) {
    std::cout << key << ": "s << val.toString(true) << std::endl;
  }
  std::cout << std::endl;

  auto first(true);
  std::cout << "[\n";
  std::for_each(bkmp.cbegin(), bkmp.cend(), [&first](auto const & it) {
    auto const key = it.first;
    auto const val = it.second;
    auto scd = first ? ""s : ", ";
    first = false;
    std::cout << scd << '\n';
    std::cout << " \"id\" : \""s << key << "\" , \"book\" : "s << '\n';
    std::cout << val.json() << '\n';
  });
  std::cout << " ]\n"s;
  std::cout << std::endl;

  return 0;
}

//  Book.cpp

namespace bkrp {

/*
 *  MARK: Book::Book() - default c'tor
 */
Book::Book(std::string name, Author author, double price, int qtyInStock)
: name_(name), author_(author), price_(price), qtyInStock_(qtyInStock) {}

/*
 *  MARK: Book::Book() - copy c'tor
 */
Book::Book(Book const & that) noexcept
: name_(that.name_), author_(that.author_), price_(that.price_), qtyInStock_(that.qtyInStock_) {}

/*
 *  MARK: Book::Book() - move c'tor
 */
Book::Book(Book && that) noexcept {
  if (this != &that) {
    name_       = std::move(that.name_);
    author_     = std::move(that.author_);
    price_      = std::move(that.price_);
    qtyInStock_ = std::move(that.qtyInStock_);
  }
}

/*
 *  MARK: Book::operator=() - copy assignment
 */
Book & Book::operator=(Book const & that) noexcept {
  if (this != &that) {
    name_       = that.name_;
    author_     = that.author_;
    price_      = that.price_;
    qtyInStock_ = that.qtyInStock_;
  }

  return *this;
}

/*
 *  MARK: Book::operator=() - move assignment
 */
Book & Book::operator=(Book && that) noexcept {
  if (this != &that) {
    name_       = std::move(that.name_);
    author_     = std::move(that.author_);
    price_      = std::move(that.price_);
    qtyInStock_ = std::move(that.qtyInStock_);
  }

  return *this;
}

/*
 *  MARK: Book::print()
 */
void Book::print(bool raw) const {
  std::cout << toString(raw) << std::endl;
}

/*
 *  MARK: Book::toString()
 */
std::string Book::toString(bool raw) const {
  std::ostringstream ss;
  std::string book;

  char gn = author_.gender == MALE ? 'M' : (author_.gender == FEMALE ? 'F' : 'U');

  if (raw) {
    ss << "\""s << getName() << "\","s
       << "\""s << std::fixed << std::setprecision(2) << getPrice() << "\","s
       << "\""s << getQtyInStock() << "\","s
       << "\""s << getAuthorName() << "\","s
       << "\""s << author_.email << "\""s
       << "\""s << gn << "\""s;
  }
  else {
    ss << "Name: \""     << getName()
       << "\", price: "  << std::fixed << std::setprecision(2) << getPrice()
       << ", in stock: " << getQtyInStock()
       << " [Author: "   << getAuthorName()
       << ", email: "    << author_.email
       << ", gender: "   << gn
       << "]";
  }

  book = ss.str();
  
  return book;
}

/*
 *  MARK: Book::json()
 */
std::string Book::json(void) const {
  std::ostringstream jss;
  std::string json;

  char gn = author_.gender == MALE ? 'M' : (author_.gender == FEMALE ? 'F' : 'U');

  jss << "{ "s
      << "\"name\" : \""s     << getName() << "\", "s
      << "\"price\" : "       << std::fixed << std::setprecision(2) << getPrice() << ", "s
      << "\"qtyInStock\" : "s << getQtyInStock()   << ", "s
      << "\"author\" : { "s
      << "\"name\" : \""s     << getAuthorName()   << "\", "s
      << "\"email\" : \""s    << getAuthor().email << "\", "s
      << "\"gender\" : \""s   << gn << "\""s
      << " }"s
      << " }"s;

  json = jss.str();
  return json;
}

} /* namespace bkrp */
