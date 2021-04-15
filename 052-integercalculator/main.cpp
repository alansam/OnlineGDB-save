
#include <iostream>
#include <string>
#include <cstdlib>

#define BETTER_MOUSETRAP_

//using namespace std;  /* there's never a good reason to do this */

struct input {  /* Manage user input, Collect it into a single sharable structure */
  int choice;
  int num1;
  int num2;
};

void Mycalculator(input const & in, std::string const & opt); /* pass variables by reference, result is local to the function */

input menu(void) {  /* DRY - don't repeat yourself! -- Don't repeat the same code in multiple places, they quickly become different */
  input in;
  std::cout << " M~E~N~U\n";
  std::cout << '\n';
  std::cout << "1. Add\n"
            << "2. Subtract\n"
            << "3. Multiply\n"
            << "4. Divide\n"
            << "5. Modulus\n\n";

  std::cout << "Enter your choice: ";
  std::cin >> in.choice;
  std::cout << '\n';
  std::cout << "Enter first number: ";
  std::cin >> in.num1;
  std::cout << '\n';
  std::cout << "Enter second number: ";
  std::cin >> in.num2;
  std::cout << '\n';

  return in;
}

int main() {
//  int num1, num2, choice;
  std::string opt;

  input in;

  in = menu();

  Mycalculator(in, opt);

  do {
    std::cout << "Would you like to continue (Y/Yes) or (N/No): ";
    std::cin >> opt;
    if (opt == "n" || opt == "N" || opt == "no" || opt == "No") {
      break;
    }
    in = menu();

    Mycalculator(in, opt);
  } while (opt =="Yes" || opt == "yes" || opt == "y" || opt == "Y");

  return 0;
}

void Mycalculator(input const & in, std::string const & opt) {
  long result;  //  make room for large multiplications
  
  if (in.choice == 1) {
    result = in.num1 + in.num2;
    std::cout <<'\n';
    std::cout << "Result = " << result << '\n';
  }
  else if (in.choice == 2) {
    result = in.num1 - in.num2;
    std::cout << "Result: " << result << '\n';
  }
  else if (in.choice == 3) {
    result = in.num1 * in.num2;
    std::cout << "Result = " << result << '\n';
  }
  else if (in.choice == 4) {
    if (in.num2 == 0) {
      std::cerr << "this will cause a divide by zero exception.\n";
    }
    else {
#ifndef BETTER_MOUSETRAP_
      result = in.num1 / in.num2;
      std::cout << "Result = " << result << '\n';
#else
      std::div_t dres = std::div(in.num1, in.num2);
      std::cout << "Result, quotient = " << dres.quot << ", remainder = " << dres.rem << '\n';
#endif
      std::cout << '\n';
    }
  }
  else if (in.choice == 5) {
    if (in.num2 == 0) {
      std::cerr << "this will cause a divide by zero exception.\n";
    }
    else {
      result = in.num1 % in.num2;
      std::cout << "Result: " << result <<'\n';
      std::cout << '\n';
    }
  }
}
