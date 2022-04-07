
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

//  Refactored to use string literals, std::vector, and "almost always 'auto'" for variable definitions
//  NOTE: Never use 'using namespace std;' - it's really bad practice and exposes code to name collisions.

using namespace std::literals::string_literals;

//  MARK: - Constants.
auto const FnInput    { "dievai24.txt"s };        //  std::string literal - use instead of std::string("dievai24.txt");
auto const FnResults  { "rezultatai224.txt"s };   //  std::string literal

//  MARK: - Definitions.
/*
 *  Structure Dievas
 */
struct Dievas {
  std::string Valdovas;
  std::vector<int> Kauliukai;
};

//  MARK: - Implementation.
/*
 *  MARK: Nuskaitymas()
 */
void Nuskaitymas(std::vector<Dievas> & masyvopavadinimas) {
  auto fin { std::ifstream(FnInput) };

  auto kiekisvaldovu { 0u };
  auto kiekiskauliuku { 0u };

  fin >> kiekisvaldovu >> kiekiskauliuku;

  for (auto i_ { 0u }; i_ < kiekisvaldovu; i_++) {
    Dievas dievas;
    fin >> dievas.Valdovas;
    for (auto j_ { 0u }; j_ < kiekiskauliuku; j_++) {
      auto val { 0 };
      fin >> val;
      dievas.Kauliukai.push_back(val);
    }
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //  clear out to EOL
    masyvopavadinimas.push_back(dievas);
  }

  fin.close();
}

/*
 *  MARK: Isvedimas()
 */
void Isvedimas(std::vector<Dievas> const & masyvopavadinimas, int const kiekisvaldovu, int const kiekiskauliuku) {
  auto fout { std::ofstream(FnResults) };

  for (auto i_ { 0u }; i_ < kiekisvaldovu; i_++) {   //  <<< BUGFIX:  Was kiekiskauliuku
    fout << std::left << std::setw(20) << masyvopavadinimas[i_].Valdovas << std::right;
    for (auto j_ { 0u }; j_ < kiekiskauliuku; j_++) {
      fout << std::setw(4) << masyvopavadinimas[i_].Kauliukai[j_];
    }
    fout.put('\n');
  }

  fout.close();
}

/*
 *  MARK: Isvedimas()
 *
 *  Overloaded Isvedimas() function - takes advantage of vectors to use range-based for loops
 */
void Isvedimas(std::vector<Dievas> const & masyvopavadinimas) {
  auto fout { std::ofstream(FnResults) };

  for (auto dievas : masyvopavadinimas) {
    fout << std::left << std::setw(20) << dievas.Valdovas << std::right;
    for (auto val : dievas.Kauliukai) {
      fout << std::setw(4) << val;
    }    
    fout.put('\n');
  }
  
  fout.close();
}

/*
 *  MARK: ShowFile()
 */
void ShowFile(std::string const & fn) {
  auto fin { std::ifstream(fn) };
  auto line { ""s };                  //  std::string literal

  while (std::getline(fin, line)) {
    std::cout << line << '\n';
  }
  std::cout << std::endl;
}

/*
 *  MARK: main()
 */
int main(int main, char const * argv[]) {
  auto dievai { std::vector<Dievas>() };

  Nuskaitymas(dievai);
  Isvedimas(dievai);

  ShowFile(FnInput);
  ShowFile(FnResults);

  return 0;
}
