
#include <stdio.h>

int main() {
  char operation;
  float calcius, farenhite;
  int radius = 10;
  float pi = 3.14;
  float length, breadth;
  char ch;
  float age;
  float  principle, year, rate;

  printf("1=[Calculator]:\n");
  printf("2=[ceclcius to farenhite converter]:\n");
  printf("3=[Circle area finder]:\n");
  printf("4=[Rectangle area finder]:\n");
  printf("5=[Tax counter]:\n");
  printf("6=[Lower case finder]:\n");
  printf("7=[Years converter]:\n");
  printf("8=[Interest finder]:\n");
  printf("----------------------------------------------------\n");
  printf("Enter operation:\n"/*, operation*/);
  scanf("%c", &operation);
  printf("----------------------------------------------------\n");

  switch (operation)
  {
  case '1':
    printf("This program will help you in calcultions:\n");
    printf("____________________________________________________\n");
    printf(":Operations:\n");
    printf("-----------------|\n");
    printf("1=[sum]:\n");
    printf("2=[difference]:\n");
    printf("3=[multiplication]:\n");
    printf("4=[division]:\n");
    float a, b, c, d;
    char calcop;
    printf("-----------------|\n");
    printf("Enter the value of [a]:\n");
    scanf("%f", &a);
    printf("Enter the value of [b]:\n");
    scanf("%f", &b);
    printf("enter operation\n"/*, operation*/);
    int cc;
    while ((cc = getchar()) != '\n' && cc != EOF);
    scanf("%c", &calcop);
    printf("... %c, %02x\n", calcop, calcop);

    switch (calcop) {
    case '1':
      printf("the sum is %f\n", a + b);
      break;

    case '2':
      printf("the difference is %f\n", (a - b));
      break;

    case '3':
      printf("the multiply is %f\n", (a * b));
      break;

    case '4':
      printf("the division is %f\n", (a) / (c));
      break;

    default:
      printf("invalid operation\n\n");
    }
    break;

  case '2':
    farenhite = (calcius * 9 / 5) + 32;
    printf("Enter temparature in celcius:\n");
    scanf("%f", &calcius);
    printf("Temprature in farenhite is:  %ff\n", (calcius * 9 / 5) + 32);
    break;

  case '3':
    printf("ENTER RADIUS:\n");
    scanf("%d", &radius);
    printf("AREA OF THE CIRCLE IS  :%f meter square\n", pi * radius * radius);
    printf("THANKS\n");
    break;

  case '4':
    printf("What is the length of rectangle:  \n");
    scanf("%f", &length);
    printf("What is the breadth of rectangel:\n ");
    scanf("%f", &breadth);
    printf("The area of rectangel is: %f meter square", length * breadth);
    printf("    :THANKS:     \n");
    break;

  case '5':
    printf("THIS PROGRAM IS USED TO CALCULATE YOUR TAX:\n");
    printf(":\t-- income<250000 NO TAX--\t:\n");
    printf("if income >250000 than tax is 5%%\n");
    printf("if income >500000 than tax is 8%%\n");
    printf("if income >1000000 than tax is 18.9%%\n");
    float tax, income;
    printf("Enter your income\n");
    scanf("%f", &income);

    if (income <= 250000) {
      tax = 0;
      printf(" your tax is %f\n",tax);
    }

    if (income > 250000 && income <= 500000) {
      tax = 0.05 * (income - 250000);
      printf(" your tax id %f\n", tax);
    }

    if (income > 500000 && income <= 1000000) {
      tax = 0.08 * (income);
      printf("your tax is %f\n", tax);
    }

    if (income > 1000000) {
      tax = 0.189 * income;
      printf("your tax is %f\n", tax);
    }
    break;

  case '6':
    printf("Enter character:\n");
    scanf("%c", &ch);
    if (ch <= 127 && ch >= 97) {
      printf("%c is Lower case:\n", ch);
    }
    else {
      printf("%c is not lower case:\n", ch);
    }
    break;

  case '7':
    printf("1=[Years to seconds]:\n");
    printf("1=[Years to minutes]:\n");
    printf("1=[Years to hours]:\n");
    printf("Chose operation:\n");
    scanf("%c", &operation);
    printf("Enter your age:\n");
    scanf("%f", &age);

    switch (operation) {
    case '1':
      printf("Your age in seconds is: %f seconds\n", age * 60 * 60 * 24 * 365);
      break;

    case '2':
      printf("Your age in minutes is: %f minutes\n", age * 60 * 60 * 24 * 365 / 60);
      break;

    case '3':
      printf("Your age in hours is: %f hours\n", age * 60 * 60 * 24 * 365 / 3600);
    }
    break;

  case '8':
    printf("enter your amount: \n");
    scanf("%f", &principle);
    printf("enter rate: \n");
    scanf("%f", &rate);
    printf("enter year: \n");
    scanf("%f", &year);
    printf("your interest is %f", principle * rate * year / 100);
    break;

  default:
    printf("Invalid input\n");
  }
  printf("Programmed by:JOE ADAM ");

  return 0;
}

