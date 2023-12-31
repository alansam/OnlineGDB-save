#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <tuple>
// #include <cstdint>

using namespace std::literals::string_literals;

//  MARK: - Definitions
using qs = std::string;

//  MARK:   struct tdata
struct tdata {
  static
  std::string const pang;
  static
  std::string const hamsol;
  
  tdata() = delete;
  tdata(tdata const &) = delete;
  tdata(tdata &&) = delete;
  ~tdata() = delete;
  tdata & operator=(tdata const &) = delete;
  tdata & operator=(tdata &&) = delete;
};

std::vector<std::string> & get_words(std::vector<std::string> & word_list, std::string const & words);

//  MARK: - Implimentation
//  MARK:   lambda show_words()
auto show_words = [](auto const & words) {
  std::istringstream iwords(words);
  std::cout << "\u00ab"s;
  std::copy(std::istream_iterator<std::string>(iwords),
            std::istream_iterator<std::string>(),
            std::ostream_iterator<std::string>(std::cout, "\u00bb\u00a0\u00ab"));
  std::cout << "\u00bb"s;
  std::cout << '\n' << std::endl;
};

//  MARK:   lambda show_word_list()
auto show_word_list = [](auto const & word_list) {
  auto wc = 1ul;
  std::for_each(word_list.cbegin(), word_list.cend(), [&wc](auto const & word) {
    std::cout << word << (wc++ % 10 == 0 ? "\n"s : " "s);
  });
  std::cout << '\n' << std::endl;
};

//  MARK:   lambda order_by_stanza()
auto order_by_stanza = [](auto const & stanzas, auto gc) {
  std::cout << "word groups with more than "s << gc << " matches\n"s;
  std::for_each(stanzas.cbegin(), stanzas.cend(), [&gc](auto const & kv) {
    auto const & [stanza, count] = kv;
    if (count > gc) {
      std::ostringstream tup;
      tup << "<"s
          << std::get<0>(stanza)
          << " "s
          << std::get<1>(stanza)
          << " "s
          << std::get<2>(stanza)
          << " "s
          << std::get<3>(stanza)
          << " "s
          << std::get<4>(stanza)
          << ">"s;

      std::cout << std::setw(40) << tup.str() << " : "s << std::setw(3) << count << '\n';
    }
  });
  std::cout << '\n' << std::endl;
};

//  MARK:   lambda order_by_matches()
auto order_by_matches = [](auto const & stanzas, auto gc) {
  std::cout << "word groups with more than "s << gc << " matches ordered by matches\n"s;
  auto ordered = std::multimap<uint64_t, std::tuple<qs, qs, qs, qs, qs>, std::greater<>>();
  for (auto const & [key, val] : stanzas) {
    if (val > gc) {
      ordered.insert(std::make_pair(val, key));
    }
  }
  std::for_each(ordered.cbegin(), ordered.cend(), [&gc](auto const & kv) {
    auto const & [count, stanza] = kv;
    // if (count > gc) {
      std::ostringstream tup;
      tup << "<"s
          << std::get<0>(stanza)
          << " "s
          << std::get<1>(stanza)
          << " "s
          << std::get<2>(stanza)
          << " "s
          << std::get<3>(stanza)
          << " "s
          << std::get<4>(stanza)
          << ">"s;

      std::cout << std::setw(40) << tup.str() << " : "s << std::setw(3) << count << '\n';
    // }
  });
};

//  MARK:   lambda build()
auto build = [](auto & stanzas, auto const & word_list) -> std::map<std::tuple<qs, qs, qs, qs, qs>, uint64_t> {
  for (auto ix { 0ul }; ix < word_list.size(); ++ix) {
    auto stanza = std::make_tuple(
      (ix     < word_list.size() ? word_list[ix    ] : ""s),
      (ix + 1 < word_list.size() ? word_list[ix + 1] : ""s),
      (ix + 2 < word_list.size() ? word_list[ix + 2] : ""s),
      (ix + 3 < word_list.size() ? word_list[ix + 3] : ""s),
      (ix + 4 < word_list.size() ? word_list[ix + 4] : ""s));
    stanzas[stanza] += 1;
  }
  return stanzas;
};

auto match_counts = [](auto const & stanzas) {
  std::map<uint64_t, uint64_t, std::greater<>> tots;
  for (auto const & [tup, tct] : stanzas) {
    tots[tct] += 1;
  }

  std::cout << '\n' << std::setw(5) << "match"s << std::setw(7) << "count\n"s;
  for (auto const & [tct, tot] : tots) {
    std::cout << std::setw(5) << tct << std::setw(7) << tot << '\n';
  }
};

/*
 *  MARK:   main()
 */
int main(int argc, char const * argv[]) {
  show_words(tdata::pang);

  std::vector<std::string> word_list;
  word_list = get_words(word_list, tdata::pang);

  auto stanzas = std::map<std::tuple<qs, qs, qs, qs, qs>, uint64_t>();
  stanzas = build(stanzas, word_list);

  auto gc = 1ul;
  order_by_stanza(stanzas, gc);
  order_by_matches(stanzas, gc);
  match_counts(stanzas);
  
  return 0;
}

/*
 *  MARK:   get_words()
 */
std::vector<std::string> & get_words(std::vector<std::string> & word_list, std::string const & words) {
  std::istringstream iwords(words);
  std::copy(std::istream_iterator<std::string>(iwords),
            std::istream_iterator<std::string>(),
            std::back_inserter(word_list));

  return word_list;
}

//  MARK: - struct tdata static definitions

std::string const tdata::pang =
  "A quick brown fox jumps over the lazy dog\n"s
  "My girl wove six dozen plaid jackets before she quit\n"s
  "Sixty zippers were quickly picked from the woven jute bag\n"s
  "Sphinx of black quartz, judge my vow\n"s
  "A wizard's job is to vex chumps quickly in fog\n"s
  "Brown jars prevented the mixture from freezing too quickly\n"s
  "How vexingly quick daft zebras jump\n"s
  "Jackdaws love my big sphinx of quartz\n"s
  "We promptly judged antique ivory buckles for the next prize\n"s
  "Glib jocks quiz nymph to vex dwarf\n"s
  "When zombies arrive, quickly fax Judge Pat\n"s
  "Waxy and quivering, jocks fumble the pizza\n"s
  "Pack my box with five dozen liquor jugs\n"s
  "The five boxing wizards jump quickly\n"s
  "Farmer jack realized that big yellow quilts were expensive\n"s
  "A quick brown fox jumps over the lazy dog\n"s
  "A wizard's job is to vex chumps quickly in fog\n"s
  "A wizard's job is to vex chumps quickly in fog\n"s
  ;

std::string const tdata::hamsol =
  "To be or not to be that is the question\n"s
  "Whether tis nobler in the mind to suffer\n"s
  "The slings and arrows of outrageous fortune\n"s
  "Or to take arms against a sea of troubles\n"s
  "And by opposing end them To die to sleep\n"s
  "No more and by a sleep to say we end\n"s
  "The heartache and the thousand natural shocks\n"s
  "That flesh is heir to: tis a consummation\n"s
  "Devoutly to be wish'd To die, to sleep\n"s
  "To sleep, perchance to dream ay, there's the rub\n"s
  "For in that sleep of death what dreams may come\n"s
  "When we have shuffled off this mortal coil\n"s
  "Must give us pause there's the respect\n"s
  "That makes calamity of so long life\n"s
  "For who would bear the whips and scorns of time\n"s
  "Th' oppressor's wrong, the proud man's contumely\n"s
  "The pangs of dispriz'd love, the law's delay\n"s
  "The insolence of office and the spurns\n"s
  "That patient merit of th' unworthy takes\n"s
  "When he himself might his quietus make\n"s
  "With a bare bodkin? Who would fardels bear\n"s
  "To grunt and sweat under a weary life\n"s
  "But that the dread of something after death\n"s
  "The undiscovere'd country from whose bourn\n"s
  "No traveller returns puzzles the will\n"s
  "And makes us rather bear those ills we have\n"s
  "Than fly to others that we know not of\n"s
  "Thus conscience doth make cowards of us all\n"s
  "And thus the native hue of resolution\n"s
  "Is sicklied o'er with the pale cast of thought\n"s
  "And enterprises of great pith and moment\n"s
  "With this regard their currents turn awry\n"s
  "And lose the name of action\n"s
  ;

/*
I want to iterate over a large vector of strings(words).
I want to get 5 at a time. I also want to use for each for learning purposes.
I also need to concatenate them. Is there a better way then this?
Maybe more human readable?

auto make_groups = [&](string& a) 
    {
        auto b = *(& a + 1);
        auto c = *(&a + 2);
        auto d = *(&a + 3);
        auto e = *(&a + 4);
        string current{a};
        current += b += c += d += e;
        if (word_pairs.find(current) != word_pairs.end()) { word_pairs[current]++; }
        else { word_pairs.insert(make_pair(current, 1)); }
    };
for_each(data.begin(), data.end()-4, make_groups);

Thank You
 */

