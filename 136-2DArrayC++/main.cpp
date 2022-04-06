
#include <iostream>
#include <iomanip>

using namespace std;

size_t constexpr ROW_1 { 3 };
size_t constexpr COL_1 { 3 };
size_t constexpr ROW_2 { 3 };
size_t constexpr COL_2 { 1 };

int m1[ROW_1][COL_1];
int m2[ROW_2][COL_2];

template <size_t row, size_t col>
void show(int const (&mtrx)[row][col]) {
  std::cout << "row" << std::setw(4) << row << " col" << std::setw(4) << col << '\n';
  for (size_t i_ = 0; i_ < row; ++i_) {
    for (size_t j_ = 0; j_ < col; ++j_) {
      std::cout << std::setw(4) << mtrx[i_][j_];
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}

template <size_t row, size_t col>
void load(int (&mtrx)[row][col]) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++){
      cout << "Masukkan angka matrik ke [" << i + 1 << "," << j + 1 << "] = ";
      cin >> mtrx[i][j];
    }
  }
}

void pshow(size_t row, size_t col, int * mtrx) {
  std::cout << "row" << std::setw(4) << row << " col" << std::setw(4) << col << '\n';
  for (size_t r_ = 0; r_ < row; ++r_) {
    for (size_t c_ = 0; c_ < col; ++c_) {
      std::cout << std::setw(4) << mtrx[r_ * col + c_];
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}

int main() {
  cout << "Perhitungan perkalian matrik ordo " << ROW_1 << "x" << COL_1 << " dengan ordo " << ROW_2 << "x" << COL_2 << endl;

  cout << "\nMasukkan data matrik ordo " << ROW_1 << "x" << COL_1 << endl;
  load(m1);

  cout << "\nMasukkan data matrik ordo " << ROW_2 << "x" << COL_2 << endl;
  load(m2);

  std::cout << std::endl;

  show(m1);
  show(m2);

  pshow(ROW_1, COL_1, reinterpret_cast<int *>(m1));
  pshow(ROW_2, COL_2, reinterpret_cast<int *>(m2));
  pshow(ROW_1, COL_1, (int *) m1);
  pshow(ROW_2, COL_2, (int *) m2);

  return 0;
}

