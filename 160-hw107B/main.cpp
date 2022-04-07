
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

std::string const FnInput("dievai23.txt");
std::string const FnResults("rezultatai223.txt");

struct Dievas {
  int ValdovuSkaicius;
  int KauliukuSkaicius;
  std::string Valdovas;
  int Kauliukai[20];
};

void Nuskaitymas(Dievas masyvopavadinimas[], int & kiekisvaldovu, int & kiekiskauliuku) {
  std::ifstream fin(FnInput);

  fin >> kiekisvaldovu >> kiekiskauliuku;

  for (int i = 0; i < kiekisvaldovu; i++) {
    fin >> masyvopavadinimas[i].Valdovas;
    for (int j = 0; j < kiekiskauliuku; j++) {
      fin >> masyvopavadinimas[i].Kauliukai[j];
    }
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //  clear out to EOL
  }

  fin.close();
}

void Isvedimas(Dievas masyvopavadinimas[], int & kiekisvaldovu, int & kiekiskauliuku) {
  std::ofstream fout(FnResults);

  for (int i = 0; i < kiekisvaldovu; i++) {   //  <<< BUGFIX:  Was kiekiskauliuku
    fout << std::left << std::setw(20) << masyvopavadinimas[i].Valdovas << std::right;
    for (int j = 0; j < kiekiskauliuku; j++) {
      fout << std::setw(4) << masyvopavadinimas[i].Kauliukai[j];
    }
    fout.put('\n');
  }

  fout.close();
}

void ShowFile(std::string const & fn) {
  std::ifstream fin(fn);
  std::string line;
  while (std::getline(fin, line)) {
    std::cout << line << '\n';
  }
  std::cout << std::endl;
}



int main() {
  Dievas dievai[10];
  int kiekisvaldovu = 0;
  int kiekiskauliuku = 0;
  Nuskaitymas(dievai, kiekisvaldovu, kiekiskauliuku);

  Isvedimas(dievai, kiekisvaldovu, kiekiskauliuku);
  // system("start rezultatai223.txt");

  ShowFile(FnInput);
  ShowFile(FnResults);

  return 0;
}
