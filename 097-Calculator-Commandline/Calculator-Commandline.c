
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct pair pair;
struct pair {
  int lhs;
  int rhs;
};

typedef struct results results;
struct results {
  long    lresult;
  int     rem;
  double  dresult;
};

/*
 *  MARK: menu()
 */
static
inline
int menu() {
  printf("Simple integer arithmetic calculator\n\n");
  printf("Menu:\n");
  printf("  1: + (add)\n");
  printf("  2: - (subtract)\n");
  printf("  3: x (multiply)\n");
  printf("  4: ÷ (divide)\n");
  printf("  5: Exit\n\n");

  int choice = 0;
  while (choice < 1 || choice > 5) {
    printf("  Choice: ");
    fflush(stdout);
    scanf("%d", &choice);
  }

  return choice;
}

/*
 *  MARK: getvalues()
 */
static
inline
pair * getvalues(pair * vals) {
  printf("  (NOTE: to enter octal value, prefix with '0', for hex, prefix with '0x')\n");
  printf("  Enter 2 values: ");
  fflush(stdout);
  scanf("%i %i", &vals->lhs, &vals->rhs);

  return vals;
}

/*
 *  MARK: show()
 */
static
inline
void show(char opt, pair values, results result) {
  putchar('\n');
  switch (opt) {
    case '/':
      printf("  %11d %c %11d = %22ld, remainder %11d, real[%%f] = %24.6lf\n",
             values.lhs, opt, values.rhs, result.lresult, result.rem, result.dresult);
      printf("  %011o %c %011o = %022lo, remainder %011o,  exp[%%e] = %24e\n",
             values.lhs, opt, values.rhs, result.lresult, result.rem, result.dresult);
      printf("     %08x %c    %08x =       %016lx, remainder    %08x,  hex[%%a] = %24a\n",
             values.lhs, opt, values.rhs, result.lresult, result.rem, result.dresult);
      break;
  
    case '+':
    case '-':
    case '*':
    default:
      printf("  %11d %c %11d = %22ld\n",
             values.lhs, opt, values.rhs, result.lresult);
      printf("  %011o %c %011o = %022lo\n",
             values.lhs, opt, values.rhs, result.lresult);
      printf("     %08x %c    %08x =       %016lx\n",
             values.lhs, opt, values.rhs, result.lresult);
      break;
  }
  putchar('\n');
}

/*
 *  MARK: main()
 */
int main() {
  bool control = true;

  while (control) {
    int choice = 0;
    pair values = { .lhs = 0, .rhs = 0, };
    div_t divided = { .quot = 0, .rem = 0, };
    results result = {
      .lresult = 0, .rem = 0, .dresult = NAN,
    };

    choice = menu();
    if (choice != 5) {
      getvalues(&values);
    }

    switch (choice) {
      case 1:
        //  Add
        result.lresult = values.lhs + values.rhs;
        show('+', values, result);
        break;

      case 2:
        //  Subtract
        result.lresult = values.lhs - values.rhs;
        show('-', values, result);
        break;

      case 3:
        //  Multiiply
        result.lresult = values.lhs * values.rhs;
        show('*', values, result);
        break;

      case 4:
        //  Divide
        if (values.rhs == 0) {
          fprintf(stderr, "\nERROR: divide by zero\n\n");
          break;
        }
        divided = div(values.lhs, values.rhs);
        result.lresult = divided.quot;
        result.rem = divided.rem;
        result.dresult = (double) values.lhs / (double) values.rhs;
        show('/', values, result);
        break;

      case 5:
      default:
        printf("All done ...\n");
        control = false;
        break;
    }
  }

  return 0;
}
