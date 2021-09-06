
#include <stdio.h>
#include <math.h>

#define ITERATIONS_ 3
/*
 * The fastest algorithm of the square root is found in the Quake III Arena codes
 * (all time classic) [1/sqrt(x) to be more accurate]:
 * [the original author's comments are included]
 */
float Q_rsqrt( float number )
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the fuck!
  y  = * ( float * ) &i;
#ifndef ITERATIONS_
  y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
#elif (ITERATIONS_ < 3)
  // manually unrolled loop
  y  = y * ( threehalfs - ( x2 * y * y ) );
  y  = y * ( threehalfs - ( x2 * y * y ) );
  y  = y * ( threehalfs - ( x2 * y * y ) );
#else
  for (size_t p = 0; p < ITERATIONS_; ++p) {
    y  = y * ( threehalfs - ( x2 * y * y ) );
  }
#endif

  return y;
}

int main() {
  for (int ti = 100; ti > 0; --ti) {
    float tf = (float) ti;
    printf("%16.12f, %16.12f %16.12f\n", tf, sqrtf(tf), 1.0F / Q_rsqrt(tf));
  }

  return 0;
}
