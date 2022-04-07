//  @author: Martynas Puga
//  @author: Alan Sampson

#include <iostream>
#include <fstream>
#include <string>

struct Zaidimas {
  std::string Valdovas;
  int PirmasKauliukas;
  int AntrasKauliukas;
  int TreciaKauliukas;

  Zaidimas(std::string valdovas, int pirmaskauliukas, int antraskauliukas, int treciakauliukas) {
    Valdovas = valdovas;
    PirmasKauliukas = pirmaskauliukas;
    AntrasKauliukas = antraskauliukas;
    TreciaKauliukas = treciakauliukas;
  }

  Zaidimas() {}
};

// void Nuskaitymas(Zaidimas masyvas[], int valdovuskaicius, int kauliukuskaicius) {
int Nuskaitymas(Zaidimas masyvas[]) {
  std::string Valdovas;
  int PirmasKauliukas;
  int AntrasKauliukas;
  int TreciaKauliukas;
  [[maybe_unused]]
  int valdovuskaicius;
  [[maybe_unused]]
  int kauliukuskaicius;

  int records { 0 };
  std::ifstream fin("hw107_failas1.txt");
  if (fin.is_open()) {
    fin >> valdovuskaicius >> kauliukuskaicius;
    while(fin.good()) {
      int i = records++;
    // for (int i = 0; i < valdovuskaicius; i++) {
      // for (int j = 0; j < kauliukuskaicius; j++) {

        fin >> Valdovas >> PirmasKauliukas >> AntrasKauliukas >> TreciaKauliukas; // >> std::ws;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //  clear out to EOL
        Zaidimas laikinas(Valdovas, PirmasKauliukas, AntrasKauliukas, TreciaKauliukas);
        masyvas[i] = laikinas;
      // }
    }
    fin.close();
  }

  return records;
}

void Isvedimas(Zaidimas masyva[], int kiek) {
  std::ofstream fout("hw107_rezultatai24.txt");

  if (fout.is_open()) {
    for (int i = 0; i < kiek; i++) {
      fout << masyva[i].Valdovas << " "
           << masyva[i].PirmasKauliukas << " "
           << masyva[i].AntrasKauliukas << " "
           << masyva[i].TreciaKauliukas
           << std::endl;
    }
    fout.close();
  }
}

int main() {
  Zaidimas zaidimai[50];
  int kauliukuskaicius = 2;
  // int valdovuskaicius = 2;
  // Nuskaitymas(zaidimai, valdovuskaicius, kauliukuskaicius);
  kauliukuskaicius = Nuskaitymas(zaidimai);

  Isvedimas(zaidimai, kauliukuskaicius);

  return 0;
}
