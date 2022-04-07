//  @author: Alan Sampson
//  @author: Martynas Puga

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std::literals::string_literals;

//  file name constants
auto const FileIn  { "./hw107_failas2.txt"s };
auto const FileOut { "./hw107_rezultatai25.txt"s };

/*
 *  MARK: Class Zaidimas
 */
class Zaidimas {
private:
  std::string Valdovas;
  int PirmasKauliukas;
  int AntrasKauliukas;
  int TreciaKauliukas;

public:
  //  default ctor.
  Zaidimas(std::string valdovas = ""s, int pirmaskauliukas = 0, int antraskauliukas = 0, int treciakauliukas = 0)
  : Valdovas { valdovas },
    PirmasKauliukas { pirmaskauliukas },
    AntrasKauliukas { antraskauliukas },
    TreciaKauliukas { treciakauliukas }
  {}

  //  getters
  std::string valdovas(void) const { return Valdovas; }
  int pirmasKauliukas(void)  const { return PirmasKauliukas; }
  int antrasKauliukas(void)  const { return AntrasKauliukas; }
  int treciaKauliukas(void)  const { return TreciaKauliukas; }

  //  setters
  std::string valdovas(std::string valdovas) {
    valdovas = Valdovas;
    return Valdovas;
  }
  int pirmasKauliukas(int pirmasKauliukas){
    pirmasKauliukas = PirmasKauliukas;
    return PirmasKauliukas;
  }
  int antrasKauliukas(int antrasKauliukas) {
    antrasKauliukas = AntrasKauliukas;
    return AntrasKauliukas;
  }
  int treciaKauliukas(int treciaKauliukas)  {
    treciaKauliukas = TreciaKauliukas;
    return TreciaKauliukas;
  }
};

/*
 *  MARK: Nuskaitymas()
 */
std::vector<Zaidimas> & Nuskaitymas(std::vector<Zaidimas> & masyvas) {
  std::string Valdovas;
  int PirmasKauliukas;
  int AntrasKauliukas;
  int TreciaKauliukas;

  std::ifstream fin(FileIn);
  if (fin.is_open()) {
    while (fin.good()) {
      fin >> Valdovas
          >> PirmasKauliukas
          >> AntrasKauliukas
          >> TreciaKauliukas;
      fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //  clear out to EOL

      Zaidimas laikinas(Valdovas, PirmasKauliukas, AntrasKauliukas, TreciaKauliukas);

      masyvas.push_back(laikinas);
    }

    fin.close();
  }

  return masyvas;
}

/*
 *  MARK: Isvedimas()
 */
void Isvedimas(std::vector<Zaidimas> masyvai) {
  std::ofstream fout(FileOut);

  if (fout.is_open()) {
    for (auto masyva : masyvai) {
      fout << std::setw(20) << std::left << masyva.valdovas() << std::right
           << std::setw( 4) << masyva.pirmasKauliukas()
           << std::setw( 4) << masyva.antrasKauliukas()
           << std::setw( 4) << masyva.treciaKauliukas()
           << std::endl;
    }

    fout.close();
  }
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::vector<Zaidimas> zaidimai;

  Nuskaitymas(zaidimai);

  Isvedimas(zaidimai);

  return 0;
}
