// @see: https://onlinegdb.com/rkEMPqaEU
//
#include <stdio.h>
#include <math.h>

void floaties(float const X);
void doublies(double const X);
void bigdoublies(long double const X);

int main(int argc, char const * argv[]) {

  double const dX = 2.55;
  float  const fX = 2.55;
  long double const lX = 2.55;

  doublies(dX);
  puts("");
  floaties(fX);
  puts("");
  bigdoublies(lX);
  puts("");

  return 0;
}

/*
 * z = 3X^3 - 5X^2 + 6
 */
void doublies(double const X) {

  printf("Function: %s\n", __func__);

  double z1, z2;

  z1 = 3 * X * X * X - 5 * X * X + 6;
  z2 = 3 * pow(X, 3) - 5 * pow(X, 2) + 6;
  printf("z1 = %15.9lf\n", z1);
  printf("z2 = %15.9lf (pow)\n", z2);

  z1 = 3. * X * X * X - 5. * X * X + 6.;
  z2 = 3. * pow(X, 3.) - 5. * pow(X, 2.) + 6.;
  printf("z1 = %15.9lf\n", z1);
  printf("z2 = %15.9lf (pow)\n", z2);

  z1 = (3. * (X * X * X)) - (5. * (X * X)) + (6.);
  z2 = (3. * pow(X, 3.)) - (5. * pow(X, 2.)) + (6.);
  printf("z1 = %15.9lf\n", z1);
  printf("z2 = %15.9lf (pow)\n", z2);

  return;
}

/*
 * z = 3X^3 - 5X^2 + 6
 */
void floaties(float const X) {

  printf("Function: %s\n", __func__);

  float z1, z2;

  z1 = 3 * X * X * X - 5 * X * X + 6;
  z2 = 3 * pow(X, 3) - 5 * pow(X, 2) + 6;
  printf("z1 = %15.9f\n", z1);
  printf("z2 = %15.9f (pow)\n", z2);

  z1 = 3. * X * X * X - 5. * X * X + 6.;
  z2 = 3. * pow(X, 3.) - 5. * pow(X, 2.) + 6.;
  printf("z1 = %15.9f\n", z1);
  printf("z2 = %15.9f (pow)\n", z2);

  z1 = (3. * (X * X * X)) - (5. * (X * X)) + (6.);
  z2 = (3. * pow(X, 3.)) - (5. * pow(X, 2.)) + (6.);
  printf("z1 = %15.9f\n", z1);
  printf("z2 = %15.9f (pow)\n", z2);

  z1 = (3. * (X * X * X)) - (5. * (X * X)) + (6.);
  z2 = (3. * powf(X, 3.)) - (5. * powf(X, 2.)) + (6.);
  printf("z1 = %15.9f\n", z1);
  printf("z2 = %15.9f (powf)\n", z2);

  return;
}

void bigdoublies(long double const X) {

  printf("Function: %s\n", __func__);

  long double z1, z2;

  z1 = 3 * X * X * X - 5 * X * X + 6;
  z2 = 3 * pow(X, 3) - 5 * pow(X, 2) + 6;
  printf("z1 = %15.9Lf\n", z1);
  printf("z2 = %15.9Lf (pow)\n", z2);

  z1 = 3. * X * X * X - 5. * X * X + 6.;
  z2 = 3. * pow(X, 3.) - 5. * pow(X, 2.) + 6.;
  printf("z1 = %15.9Lf\n", z1);
  printf("z2 = %15.9Lf (pow)\n", z2);

  z1 = (3. * (X * X * X)) - (5. * (X * X)) + (6.);
  z2 = (3. * pow(X, 3.)) - (5. * pow(X, 2.)) + (6.);
  printf("z1 = %15.9Lf\n", z1);
  printf("z2 = %15.9Lf (pow)\n", z2);

  return;
}


