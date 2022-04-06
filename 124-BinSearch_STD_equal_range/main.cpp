#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
// #include <compare>
#include <functional>
#include <iterator>

struct person {
  std::string given_name;
  std::string family_name;
};

int main() {
  std::vector<person> folks {
    { "Norma",  "Snockers",  },
    { "Irma",   "Nalias",    },
    { "Justin", "Ottre",     },
    { "Wanda",  "Nother",    },
    { "Harry",  "Sanaleis",  },
    { "Ernie",  "Nalias",    },
    { "Omo",    "Zapien",    },
    { "Ivana",  "Dropskik",  },
    { "Ivan",   "Tarealnom", },
    { "Petra",  "Glyph",     },
  };
  std::vector<std::string> fn;

  std::sort(folks.begin(), folks.end(), [](auto & lhs, auto & rhs) {
    auto rv = (lhs.family_name < rhs.family_name)
    || (lhs.family_name == rhs.family_name && lhs.given_name < rhs.given_name);
    return rv;
  });

  std::transform(folks.cbegin(), folks.cend(), std::back_inserter(fn), [](auto const & fk) -> std::string {
    return fk.family_name;
  });

  std::for_each(folks.begin(), folks.end(), [](auto & c1) {
    std::cout << c1.family_name << '|' << c1.given_name << '\n';
  });
  std::cout << std::string(60, '~') << '\n';

  std::for_each(fn.begin(), fn.end(), [](auto & c1) {
    std::cout << c1 << '\n';
  });
  std::cout << std::string(60, '~') << '\n';

  auto folksp = std::equal_range(folks.cbegin(), folks.cend(), person { "", "Nalias", }, [](person const & p1, person const & p2) {
    return p1.family_name < p2.family_name;
  });
  std::for_each(folksp.first, folksp.second, [](auto & ps) {
    std::cout << ps.family_name << '|' << ps.given_name << '\n';
  });
  std::cout << std::string(60, '~') << '\n';

  auto fnp = std::equal_range(fn.cbegin(), fn.cend(), "Nalias");
  std::for_each(fnp.first, fnp.second, [](auto const & ps) {
    std::cout << ps << '\n';
  });
  std::cout << std::string(60, '~') << '\n';

  return 0;
}

