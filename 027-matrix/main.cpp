#include <iostream>

using namespace std;

int main() {
  int x, y;
  cout << "Enter the number of the rows \n";
  cin >> x;
  cout << "Enter the bumber of the colums \n";
  cin >> y;
  int matrice_1[x][y], matrice_2[x][y], addition[x][y];

  // varaibles for the loops is as below
  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << "Enter the elements of the matrice 1 \n";
      cin >> matrice_1[x][y];
    }
  }

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << "Enter the elements of the matrice 2 \n";
      cin >> matrice_2[x][y];
    }
  }

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      addition[x][y] = matrice_1[x][y] + matrice_2[x][y];
    }
  }

  cout << "MATRICE 1 \n";
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << matrice_1[x][y] << "\t";
    }
    cout << endl;
  }

  cout << "MATRICE 2 \n";
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << matrice_2[x][y] << "\t";
    }
    cout << endl;
  }

  cout << "Addition of the two matrices \n";
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << addition[x][y] << "\t";
    }
    cout << endl;
  }

  return 0;
}
