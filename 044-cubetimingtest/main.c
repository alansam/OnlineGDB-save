//
//  kerpow.c
//  CF.PowKerpow
//
//  Created by Alan Sampson on 2/3/21.
//
//  compiler command line settings: -Wall -Wextra -pedantic -O1
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LOOP 10000
#define SIZE 1000

__attribute__((always_inline))
inline
static
double kube(double val) { return val * val * val; }

__attribute__((always_inline))
inline
static
float kubef(float val) { return val * val * val; }

__attribute__((always_inline))
inline
static
double skuare(double val) { return val * val; }

__attribute__((always_inline))
inline
static
float skuaref(float val) { return val * val; }

__attribute__((always_inline))
inline
static
void use(double * results) {
  if (results[0] > results[1]) {
    double temp = results[0];
    results[0] = results[1];
    results[1] = temp;
  }
  else {
    double temp = results[0];
    results[0] = results[SIZE - 1];
    results[SIZE - 1] = temp;
  }
}

__attribute__((always_inline))
inline
static
void usef(float * results) {
  if (results[0] > results[1]) {
    float temp = results[0];
    results[0] = results[1];
    results[1] = temp;
  }
  else {
    float temp = results[0];
    results[0] = results[SIZE - 1];
    results[SIZE - 1] = temp;
  }
}

int fit_the_first(void);
int fit_the_second(void);
int fit_the_third(void);
int fit_the_fourth(void);

/*
 *  MARK: main()
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) const char * argv[]) {

  fit_the_first();
  fit_the_second();
  fit_the_third();
  fit_the_fourth();

  return EXIT_SUCCESS;
}

/*
 *  MARK: fit_the_first()
 */
int fit_the_first(void) {
  printf("Function: %s [cubes of floats]\n", __func__);

  float reals[SIZE];
  float results[SIZE];
  __attribute__((unused))
  float result = 0.0F;
  clock_t start, stop;

  //  random aray of floats
  for (size_t i_ = 0; i_ < SIZE; ++i_) {
    reals[i_] = (float) rand() / (float) rand();
  }

  //  test multiplication
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = f_ * f_ * f_;
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "f * f * f", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test kube()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = kube(f_);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "kube(f)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test kubef()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = kubef(f_);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "kubef(f)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test pow()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = pow(f_, 3);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "pow(f, 3)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test powf()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = powf(f_, 3);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "powf(f, 3)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  putchar('\n');

  return EXIT_SUCCESS;
}

/*
 *  MARK: fit_the_second()
 */
int fit_the_second(void) {
  printf("Function: %s [cubes of doubles]\n", __func__);

  double reals[SIZE];
  double results[SIZE];
  __attribute__((unused))
  double result = 0.0;
  clock_t start, stop;

  //  random aray of floats
  for (size_t i_ = 0; i_ < SIZE; ++i_) {
    reals[i_] = (double) rand() / (double) rand();
  }

  //  test multiplication
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      double f_ = reals[i_];
      result = f_ * f_ * f_;
      results[i_] = result;
    }
  }
  stop = clock();
  use(results);
  printf("%12s %10.6f\n", "f * f * f", (double) (stop - start) / (double) CLOCKS_PER_SEC);

  //  test kube()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      double f_ = reals[i_];
      result = kube(f_);
      results[i_] = result;
    }
  }
  stop = clock();
  use(results);
  printf("%12s %10.6f\n", "kube(f)", (double) (stop - start) / (double) CLOCKS_PER_SEC);

  //  test pow()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      double f_ = reals[i_];
      result = pow(f_, 3);
      results[i_] = result;
    }
  }
  stop = clock();
  use(results);
  printf("%12s %10.6f\n", "pow(f, 3)", (double) (stop - start) / (double) CLOCKS_PER_SEC);

  putchar('\n');

  return EXIT_SUCCESS;
}

/*
 *  MARK: fit_the_third()
 */
int fit_the_third(void) {
  printf("Function: %s [squares of floats]\n", __func__);

  float reals[SIZE];
  float results[SIZE];
  __attribute__((unused))
  float result = 0.0F;
  clock_t start, stop;

  //  random aray of floats
  for (size_t i_ = 0; i_ < SIZE; ++i_) {
    reals[i_] = (float) rand() / (float) rand();
  }

  //  test multiplication
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = f_ * f_;
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "f * f", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test kube()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = skuare(f_);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "skuare(f)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test kubef()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = skuaref(f_);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "skuaref(f)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test pow()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = pow(f_, 2);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "pow(f, 2)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  //  test powf()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      float f_ = reals[i_];
      result = powf(f_, 2);
      results[i_] = result;
    }
  }
  stop = clock();
  usef(results);
  printf("%12s %10.6f\n", "powf(f, 2)", (float) (stop - start) / (float) CLOCKS_PER_SEC);

  putchar('\n');

  return EXIT_SUCCESS;
}

/*
 *  MARK: fit_the_fourth()
 */
int fit_the_fourth(void) {
  printf("Function: %s [squares of doubles]\n", __func__);

  double reals[SIZE];
  double results[SIZE];
  __attribute__((unused))
  double result = 0.0;
  clock_t start, stop;

  //  random aray of floats
  for (size_t i_ = 0; i_ < SIZE; ++i_) {
    reals[i_] = (double) rand() / (double) rand();
  }

  //  test multiplication
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      double f_ = reals[i_];
      result = f_ * f_;
      results[i_] = result;
    }
  }
  stop = clock();
  use(results);
  printf("%12s %10.6f\n", "f * f", (double) (stop - start) / (double) CLOCKS_PER_SEC);

  //  test kube()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      double f_ = reals[i_];
      result = skuare(f_);
      results[i_] = result;
    }
  }
  stop = clock();
  use(results);
  printf("%12s %10.6f\n", "skuare(f)", (double) (stop - start) / (double) CLOCKS_PER_SEC);

  //  test pow()
  start = clock();
  for (size_t t_ = 0; t_ < LOOP; ++t_) {
    for (size_t i_ = 0; i_ < SIZE; ++i_) {
      double f_ = reals[i_];
      result = pow(f_, 2);
      results[i_] = result;
    }
  }
  stop = clock();
  use(results);
  printf("%12s %10.6f\n", "pow(f, 2)", (double) (stop - start) / (double) CLOCKS_PER_SEC);

  putchar('\n');

  return EXIT_SUCCESS;
}
