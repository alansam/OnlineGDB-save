
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <limits.h>

bool AlmostEqualRelative(float A, float B, float maxRelDiff) {
  maxRelDiff = maxRelDiff != 0 ? maxRelDiff : FLT_EPSILON;
  // Calculate the difference.
  float diff = fabs(A - B);
  A = fabs(A);
  B = fabs(B);
  // Find the largest
  float largest = (B > A) ? B : A;
  
  if (diff <= largest * maxRelDiff) {
    return true;
  }
  return false;
}

bool AlmostEqualRelativeD(double A, double B, double maxRelDiff) {
  maxRelDiff = maxRelDiff != 0 ? maxRelDiff : DBL_EPSILON;
  // Calculate the difference.
  double diff = fabs(A - B);
  A = fabs(A);
  B = fabs(B);
  // Find the largest
  double largest = (B > A) ? B : A;
  
  if (diff <= largest * maxRelDiff) {
    return true;
  }
  return false;
}

void f1(void) {
  printf("In %s()\n", __func__);

  double r;
  for (r = 1.0; r < 10.0; r = r + 1.0) {
    printf("r = %.*lf %0.*e %0*a\n",
           DBL_DECIMAL_DIG, r, DBL_DECIMAL_DIG, r, DBL_DECIMAL_DIG, r);
  }
  putchar('\n');

  return;
}

void f2(void) {
  printf("In %s()\n", __func__);

  double r;
  for (r = 0.50; r < 1.00; r = r + 0.10) {
    printf("r = %.*lf %0.*e %0*a\n",
           DBL_DECIMAL_DIG, r,
           DBL_DECIMAL_DIG, r,
           DBL_DECIMAL_DIG, r);
  }
  putchar('\n');

  return;
}

void f3(void) {
  printf("In %s()\n", __func__);

  double x = 10.0;
  double y = 10.0 / 7.0 * 7.0;

  printf("x = %.*f y = %.*f na- = %33.*f\n",
         DBL_DECIMAL_DIG, x,
         DBL_DECIMAL_DIG, y,
         DBL_DECIMAL_DIG, nextafter(x, -INFINITY));
  printf("x = %.*f y = %.*f na+ = %33.*f\n",
         DBL_DECIMAL_DIG, x,
         DBL_DECIMAL_DIG, y,
         DBL_DECIMAL_DIG, nextafter(x, +INFINITY));

  printf("%c\n", (nextafter(x, -INFINITY) <= y) ? 'T' : 'F');
  printf("%c\n", (y >= nextafter(x, +INFINITY)) ? 'T' : 'F');

  if ((nextafter(x, -INFINITY) <= y) && (y >= nextafter(x, +INFINITY))) {
    puts("\nT");
  }
  else {
    puts("\nF");
  }

  float f = 0.1f;
  float sum;
  sum = 0;

  for (int i = 0; i < 10; ++i) {
    sum += f;
  }
  float product = f * 10.f;
  printf("sum = %1.*f, mul = %1.*f, mul2 = %1.*f\n",
         DBL_DECIMAL_DIG, sum,
         DBL_DECIMAL_DIG, product,
         DBL_DECIMAL_DIG, f * 10.);

  return;
}

int main(int argc, char const * argv[]) {
  f1();
  f2();
  f3();

  printf("DBL_MAX = %.*f\n", DBL_DECIMAL_DIG, DBL_MAX);
  printf("FLT_MAX = %.*f\n", FLT_DECIMAL_DIG, FLT_MAX);

  return 0;
}
