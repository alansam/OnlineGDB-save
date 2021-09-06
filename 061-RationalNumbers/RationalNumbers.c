//
//  rationalnrs.c
//  CF.RationalNrs00
//
//  Created by Alan Sampson on 4/19/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

int driver(void);

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  printf("CF.RationalNrs00\n");
  printf("C Version: %ld\n", __STDC_VERSION__);

  int RC = EXIT_SUCCESS;
  
  RC = driver();

  return RC;
}

/*
 *  MARK: struct RationalsPair
 */
typedef struct RationalsPair RationalsPair;
struct RationalsPair {
  int64_t num1;
  int64_t denom1;
  int64_t num2;
  int64_t denom2;
  char oper;
};

/*
 *  MARK: gcd()
 */
int64_t gcd(int64_t denominator1, int64_t denominator2) {
  int64_t GCD;
  if (denominator1 == 0) {
    GCD = denominator2;
  }
  else if (denominator2 == 0) {
    GCD = denominator1;
  }
  else if (denominator1 >= denominator2) {
    GCD = gcd(denominator1 - denominator2, denominator2);
  }
  else if (denominator2 >= denominator1) {
    GCD = gcd(denominator2 - denominator1, denominator1);
  }
  else {
    GCD = 0;  //  should never be reached
    assert(GCD != 0);
  }

  return GCD;
}

/*
 *  MARK: lcm()
 */
int64_t lcm(int64_t denominator1, int64_t denominator2) {
  int64_t LCM;
  LCM = (denominator1 * denominator2) / gcd(denominator1, denominator2);
  return LCM;
}

/*
 *  MARK: numerator()
 */
int64_t numerator(RationalsPair myRP) { //  TODO: pass by value?
  int64_t num;
  int64_t LCM = lcm(myRP.denom1, myRP.denom2);

  if (myRP.oper == '+') {
    num = myRP.num1 * LCM / myRP.denom1 + myRP.num2 * LCM / myRP.denom2;
  }
  else if (myRP.oper == '-') {
    num = myRP.num1 * LCM / myRP.denom1 - myRP.num2 * LCM / myRP.denom2;
  }
  else {
    num = 0;  //  should never be reached
    assert(num != 0);
  }

  return num;
}

/*
 *  MARK: Final()
 */
void Final(RationalsPair myRP) {  //  TODO: pass by value?
  int64_t Numerator = numerator(myRP);
  int64_t Denominator = lcm(myRP.denom1, myRP.denom2);
  printf("%ld/%ld\n", Numerator, Denominator);
}

/*
 *  MARK: collect()
 */
int collect(RationalsPair * myRP) { //  TODO: pass by address
  int sr;
  int64_t num1, denom1, num2, denom2;
  char oper;
  printf("input:\n");
  sr = scanf("%ld/%ld %c %ld/%ld", &num1, &denom1, &oper, &num2, &denom2);

  if (sr == 5) {
    myRP->num1 = num1;
    myRP->denom1 = denom1;
    myRP->oper = oper;
    myRP->num2 = num2;
    myRP->denom2 = denom2;

    printf("%ld/%ld %c %ld/%ld = ",
           myRP->num1, myRP->denom1,
           myRP->oper,
           myRP->num2, myRP->denom2);

    if (myRP->oper != '+' && myRP->oper != '-') {
      fprintf(stderr, "invalid oparation code %c\n", myRP->oper);
      sr = 0;
    }
    else if (myRP->denom1 == 0 || myRP->denom2 == 0) {
      fprintf(stderr, "Cannot divide by zero!\n");
      sr = 0;
    }
  }

  return sr;
}

/*
 *  MARK: driver()
 */
int driver(void) {
  int RC = EXIT_SUCCESS;

#undef INTERACTIVE
#ifdef INTERACTIVE
  RationalsPair myRP;

  // sr = scanf("%lld/%lld %c %lld/%lld", &myS.a, &myS.b, &myS.o, &myS.c, &myS.d);
  while (collect(&myRP) == 5) {
    Final(myRP);
  }

  if (myRP.oper != '+' && myRP.oper != '-') {
    RC = EXIT_FAILURE;
  }
  else if (myRP.denom1 == 0 || myRP.denom2 == 0) {
    RC = EXIT_FAILURE;
  }
  else {
    RC = EXIT_SUCCESS;
  }
#else
  RationalsPair pairs[] = {
    { 1, 2, 3, 4, '+', },
    { 4, 5, 7, 3, '-', },
    { 3, 2, 5, 6, '+', },
    { 7, 6, 1, 6, '-', },
    { 3, 2, 3, 2, '-', },
  };
  size_t pairs_e = sizeof(pairs) / sizeof(*pairs);

  for (size_t i_ = 0; i_ < pairs_e; ++i_) {
    RationalsPair r_pair = pairs[i_];
    printf("%ld/%ld %c %ld/%ld = ",
           r_pair.num1, r_pair.denom1, r_pair.oper, r_pair.num2, r_pair.denom2);
    Final(r_pair);
  }
#endif  /* INTERACTIVE */

  return RC;
}

