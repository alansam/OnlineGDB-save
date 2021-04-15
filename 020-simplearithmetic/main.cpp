
#include <iostream>
#include <string>

int
main (int argc, char const *argv[]) {

  if (argc < 4) {
    printf("Usage: a op b - where a & b are numbers and op is +, -, *, /\n");
  }
  else {
    char const * valA = argv[1];
    char const * valB = argv[3];
    char const * op   = argv[2];

    printf("%s %s %s\n", valA, op, valB);
    double arith_v1, arith_v2, arith_result;
    char arith_op;
    sscanf(valA, "%lf", &arith_v1);
    sscanf(valB, "%lf", &arith_v2);
    sscanf(op, "%c", &arith_op);

    switch (arith_op) {
      case '+':
        arith_result = arith_v1 + arith_v2;
        printf("%10.3f + %10.3f = %10.3f\n", arith_v1, arith_v2, arith_result);
        break;

      case '-':
        arith_result = arith_v1 - arith_v2;
        printf("%10.3f - %10.3f = %10.3f\n", arith_v1, arith_v2, arith_result);
        break;

      case '*':
        arith_result = arith_v1 * arith_v2;
        printf("%10.3f * %10.3f = %10.3f\n", arith_v1, arith_v2, arith_result);
        break;

      case '/':
        if (arith_v2 != 0) {
          arith_result = arith_v1 / arith_v2;
          printf("%10.3f / %10.3f = %10.3f\n", arith_v1, arith_v2, arith_result);
        }
        else {
          printf("Illegal operation: divide by zero!\n");
        }
        break;

      default:
        printf("Unexpected operator: %c\n", arith_op);
        break;
    }
  }

  return 0;
}

