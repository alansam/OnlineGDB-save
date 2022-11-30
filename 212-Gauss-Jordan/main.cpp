// Gauss Jordan Elimination
// @see: https://www.tutorialspoint.com/cplusplus-program-to-implement-gauss-jordan-elimination

/*
 *  This is a C++ Program to Implement Gauss Jordan Elimination.
 *  It is used to analyze linear system of simultaneous equations.
 *  It is mainly focused on reducing the system of equations to a
 *  diagonal matrix form by row operations such that the solution is obtained directly.
 *
 *  Algorithm
 *  Begin
 *    n = size of the input matrix
 *    To find the elements of the diagonal matrix:
 *    Make nested for loops j = 0 to n and i = 0 to n
 *      The element in the first row and the first column is made 1
 *      and then the remaining elements in the first column are made 0.
 *      Similarly, the elements in the second row and the second
 *      column is made 1, and then the other elements in the second
 *      column are reduced to 0 and so on.
 *    Print all calculated solution values.
 *  End
 *
 *  Output
 *  Enter the size of matrix: 3
 *  Enter the elements of augmented matrix row-wise:
 *  A[1, 1 ]=1
 *  A[1, 2 ]=2
 *  A[1, 3 ]=-4
 *  A[1, 4 ]=2
 *  A[2, 1 ]=7
 *  A[2, 2 ]=6
 *  A[2, 3 ]=-2
 *  A[2, 4 ]=-5
 *  A[3, 1 ]=0
 *  A[3, 2 ]=-3
 *  A[3, 3 ]=-5
 *  A[3, 4 ]=-8
 *  The solution is:
 *  x1=-2.89831 x2=2.5678 x3=0.059322
 */

#include <iostream>
#include <iomanip>

size_t constexpr MXSZ(10ul);

auto sm = [](auto const trix[][MXSZ], auto const n_) {
  std::cout << "\nmatrix:\n";
  for (auto i_ { 1ul }; i_ <= n_; ++i_) {
    for (auto j_ { 1ul }; j_ <= n_ + 1ul; ++j_) {
      std::cout << std::setw(10) << trix[i_][j_];
    }
    std::cout.put('\n');
  }
  std::cout.put('\n');
  std::cout.put('\n');
};

int main(int argc, char const * argv[]) {
  size_t n; // declare variables and matrixes as input
  double a[MXSZ][MXSZ] = { 0, };

  printf("\nEnter the size of matrix: ");
  scanf("%lu", &n);
  printf("\nEnter the elements of augmented matrix (row-wise):\n");
  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= (n + 1); j++) {
      std::cout << "A[" << i << ", " << j << " ]=";
      std::cin >> a[i][j];
      std::cout << std::setw(5) << a[i][j] << '\n';
    }
  }

  std::cout << std::fixed << std::setprecision(5);

  sm(a, n);

  std::cout << "...\n";

  //to find the elements of diagonal matrix
  for (size_t j = 1; j <= n; j++) {
    for (size_t i = 1; i <= n; i++) {
     if (i != j) {
        float b = a[i][j] / a[j][j];
        for (size_t k = 1; k <= n + 1; k++) { 
          a[i][k] = a[i][k] - b * a[j][k];
        }
      }
    }
  }

  sm(a, n);

  double x[MXSZ] = { 0, };
  std::cout << "\nThe solution is:\n";
  for (size_t i = 1; i <= n; i++) {
    x[i] = a[i][n + 1] / a[i][i];
    std::cout << "x" << i << " =" << std::setw(10) << x[i] << " ";
  }

  return(0);
}
