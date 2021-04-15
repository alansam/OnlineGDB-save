
#include <stdio.h>
#include <math.h>

#define CUBE(x) (x * x * x)

inline
static
double cube(double val) { return val * val * val; }

int main()
{
  {
    double cu;
    double a = 5;
    cu = pow(a - (double) 1/2, 3);
    printf("cu=%lf\n", cu);
  }
  {
    double cu;
    double a = 5;
    cu = a - (double) 1/2 * a - (double) 1/2 * a - (double) 1/2;
    printf("cu=%lf\n", cu);
  }
  {
    double cu;
    double a = 5;
    cu = CUBE(a - (double) 1/2);
    printf("cu=%lf\n", cu);
  }
  {
    double cu;
    double a = 5;
    cu = (a - 1./2.) * (a - (double) 1/2) * (a - (double) 1/2);
    printf("cu=%lf\n", cu);
  }
  {
    double cu;
    double a = 5;
    cu = cube(a - (double) 1/2);
    printf("cu=%lf\n", cu);
  }

  return 0;
}
