//
//  movies.cpp
//  CF.ClassyMovies
//
//  Created by Alan Sampson on 7/22/21.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std::literals::string_literals;

//  MARK: - Class Movie Definition
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
class Movie {
public:
  Movie() = delete;
  Movie(std::string const title) : title_ { title } {};
  virtual
  ~Movie();
  std::string const title(void) const;

private:
  std::string const title_;
};

//  MARK: - Class Movies Definition
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
class Movies {
public:
  Movies() = default;
  virtual
  ~Movies();
  void add_movie(std::string const title);
  std::vector<Movie *> const & get_movies(void) const;
  size_t size(void) const;

private:
  std::vector<Movie *> movies_;
};

//  MARK: - Class MoviesU Definition
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
class MoviesU {
public:
  MoviesU() = default;
  virtual
  ~MoviesU();
  void add_movie(std::string const title);
  std::vector<std::unique_ptr<Movie>> const & get_movies(void) const;
  size_t size(void) const;

private:
  std::vector<std::unique_ptr<Movie>> movies_;
};

//  MARK: - Implementation
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "C++ Version: " << __cplusplus << "\n\n";

  std::cout << std::string(80, '~') << std::endl;
  {
    auto movies = Movies();
    movies.add_movie("The Magnificent Seven"s);
    movies.add_movie("Jaws"s);

    std::cout << "total movies " << movies.size() << '\n';
    auto const & movie_vec = movies.get_movies();
    for (auto const & mp : movie_vec) {
      std::cout << mp->title() << '\n';
    }
    std::cout << std::endl;
  }

  std::cout << std::string(80, '~') << std::endl;
  {
    auto up_movies = MoviesU();
    up_movies.add_movie("Starwars"s);
    up_movies.add_movie("The Hobbit"s);
    up_movies.add_movie("The Lord of the Rings"s);

    std::cout << "total movies " << up_movies.size() << '\n';
    auto const & movieu_vec = up_movies.get_movies();
    std::for_each(movieu_vec.cbegin(), movieu_vec.cend(), [](auto const & up) {
      std::cout << up->title() << '\n';
    });
    std::cout << std::endl;
  }

  std::cout << std::string(80, '~') << std::endl;
  {
    std::vector<std::unique_ptr<Movie>> ptrs;
    ptrs.push_back(std::make_unique<Movie>(Movie("Jaws"s)));
    ptrs.push_back(std::make_unique<Movie>(Movie("Jaws II"s)));
    for (auto & ptr : ptrs) {
      auto ttl = (*ptr).title();
      std::cout << ttl << '\n';
    }
    std::cout << std::endl;
  }

  return 0;
}

//  MARK: - Class Movie Implementation
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: Movie::~Movie()
 */
Movie::~Movie() {
  std::cout << "I am become Teeth, Destroyer of Worms!\n"
            << "  [Movie    @" << this << " " << std::quoted(title()) << "]\n";
}

/*
 *  MARK: Movie::title()
 */
inline
std::string const Movie::title(void) const {
  return title_;
}

//  MARK: - Class Movies Implementation
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: Movies::~Movies()
 */
Movies::~Movies() {
  std::cout << "I am become Daisy Eraser, Destroyer of Words!\n"
            << "  [Movies   @" << this << "]\n";
  for (auto m_ : movies_) {
    delete m_;
  }
}

/*
 *  MARK: Movies::add_movie()
 */
void Movies::add_movie(std::string const title) {
  Movie * pmovie = new Movie(title);
  movies_.push_back(pmovie);
}

/*
 *  MARK: Movies::get_movies()
 */
inline
std::vector<Movie *> const & Movies::get_movies(void) const {
  return movies_;
}

/*
 *  MARK: Movies::size()
 */
inline
size_t Movies::size(void) const {
  return movies_.size();
}

//  MARK: - Class MoviesU Implementation
// .+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|
/*
 *  MARK: MoviesU::~MoviesU()
 */
MoviesU::~MoviesU() {
  std::cout << "I am Daisy Johnson, Destroyer of Worlds!\n"
            << "  [MoviesU  @" << this << "]\n";
}

/*
 *  MARK: MoviesU::add_movie()
 */
inline
void MoviesU::add_movie(std::string const title) {
  auto up_movie = std::make_unique<Movie>(Movie(title));
  movies_.push_back(std::move(up_movie));
}

/*
 *  MARK: MoviesU::get_movies
 */
inline
std::vector<std::unique_ptr<Movie>> const & MoviesU::get_movies(void) const {
  return movies_;
}

/*
 *  MARK: MoviesU::size
 */
inline
size_t MoviesU::size(void) const {
  return movies_.size();
}
