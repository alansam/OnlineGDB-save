
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Write a program that will ask for an integer input (1 - 9999). */

void ugly(int num);
void less_ugly(int num);

// int main tells the compiler where your program should start
/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {  // start of the program.
  int num;
  printf("Enter the digits (1 to 9999): "); // printf is output while scanf is input.
  scanf("%d", &num);
  if ( num < 1 || num > 9999) {
    printf("Invalid Number,");
  }
  else {  // the formula.
    printf("%d\n", num);

    puts("....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|");
    ugly(num);

    puts("....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|");
    less_ugly(num);

    int ts[] = {
         0,    1,    5,    9,   10,   11,   15,   19,   20,   21,
        30,   35,   39,   40,   41,   44,   49,   50,   60,   70,
        29,   99,  100,  101,  110,  111,  159,  999, 1000, 1001,
      1002, 1010, 1011, 1019, 1100, 1101, 1109, 1110, 1111, 3020,
      3022, 4102, 4011, 4124,
      11, 12, 111, 112, 1111, 9911,
    };
    size_t ts_sz = sizeof ts / sizeof *ts;

    for (size_t n_ = 0; n_ < ts_sz; ++n_) {
      less_ugly(ts[n_]);
    }
  }

  return 0;
} //End of the program.

/*
 *  MARK: ugly()
 */
void ugly(int num) {
  int thou = 0, hun = 0, tens = 0, ones = 0;

  thou = num / 1000;
  hun  = num % 1000 / 100;
  tens = num % 1000 % 100 / 10;
  ones = num % 1000 % 100 % 10/1;
  printf("%d %d %d %d\n", thou, hun, tens, ones);

  // thousands
  if (thou == 1) { printf("one thousand "); }
  if (thou == 2) { printf("two thousand "); }
  if (thou == 3) { printf("three thousand "); }
  if (thou == 4) { printf("four thousand "); }
  if (thou == 5) { printf("five thousand "); }
  if (thou == 6) { printf("six thousand "); }
  if (thou == 7) { printf("seven thousand "); }
  if (thou == 8) { printf("eight thousand "); }
  if (thou == 9) { printf("nine thousand "); }
  // hundreds
  if (hun == 1) { printf("one hundred "); }
  if (hun == 2) { printf("two hundred "); }
  if (hun == 3) { printf("three hundred "); }
  if (hun == 4) { printf("four hundred "); }
  if (hun == 5) { printf("five hundred "); }
  if (hun == 6) { printf("six hundred "); }
  if (hun == 7) { printf("seven hundred "); }
  if (hun == 8) { printf("eight hundred "); }
  if (hun == 9) { printf("nine hundred "); }
  // tens
  if (tens == 9) { printf("ninety "); }
  if (tens == 8) { printf("eighty "); }
  if (tens == 7) { printf("sevety "); }
  if (tens == 6) { printf("sixty "); }
  if (tens == 5) { printf("fifty "); }
  if (tens == 4) { printf("forty "); }
  if (tens == 3) { printf("thirty "); }
  if (tens == 2) { printf("twenty "); }
  if (tens == 1) {
    // ones
    if (ones == 9) { printf("nineteen"); }
    if (ones == 8) { printf("eighteen"); }
    if (ones == 7) { printf("seventeen"); }
    if (ones == 6) { printf("sixteen"); }
    if (ones == 5) { printf("fifteen"); }
    if (ones == 4) { printf("fourteen"); }
    if (ones == 3) { printf("thirteen"); }
    if (ones == 2) { printf("twelve"); }
    if (ones == 1) { printf("eleven"); }
    if (ones == 0) { printf("ten"); }
  }
  else {
    //ones
    if (ones == 1) { printf("one"); }
    if (ones == 2) { printf("two"); }
    if (ones == 3) { printf("three"); }
    if (ones == 4) { printf("four"); }
    if (ones == 5) { printf("five"); }
    if (ones == 6) { printf("six"); }
    if (ones == 7) { printf("seven"); }
    if (ones == 8) { printf("eight"); }
    if (ones == 9) { printf("nine"); }
  }
  putchar('\n');

  return;
}

/*
 *  MARK: enum name_type
 */
typedef enum name_type name_type;
enum name_type { UNITS, TEENS, TENS, };

char const * t01_09(int num);
char const * t11_19(int num);
char const * t10_90(int num);
char const * unit_name(enum name_type nt, int num);

/*
 *  MARK: less_ugly()
 */
void less_ugly(int num) {
  int thou = 0, hun = 0, tens = 0, ones = 0;
  bool pad = false;

  thou = num / 1000;
  hun  = num % 1000 / 100;
  tens = num % 1000 % 100 / 10;
  ones = num % 1000 % 100 % 10 / 1;
  printf("%d %d %d %d\n", thou, hun, tens, ones);

  char message[1024];
  size_t message_sz = sizeof message / sizeof *message;
  int chpt = 0;

  // 1,000s
  if (thou > 0) {
    chpt += snprintf(message + chpt, message_sz, "%s thousand", t01_09(thou));
    pad = true;
  }

  //  100s
  if (pad) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%c", ' ');
    pad = false;
  }
  if (hun > 0) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%s hundred", t01_09(hun));
    pad = true;
  }

  //   10s
  if (pad) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%c", ' ');
    pad = false;
  }
  if (tens > 1) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%s", t10_90(tens));
    pad = true;
  }

  //    1s
  if (pad) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%c", ' ');
    pad = false;
  }
  if (tens == 1 && ones != 0) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%s", t11_19(ones + 1));
    pad = true;
  }
  else if (tens == 1 && ones == 0) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%s", t10_90(tens));
    pad = true;
  }
  else if (ones > 0) {
    chpt += snprintf(message + chpt, message_sz - chpt, "%s", t01_09(ones));
    pad = true;
  }

  //    0
  if (num == 0) {
    snprintf(message, message_sz, "%s", "zero");
  }

  printf("%s\n", message);

  return;
}

/*
 *  MARK: t01_09()
 */
char const * t01_09(int num) {
  char const * dgt;

#ifndef SWITCHY_
  dgt = unit_name(UNITS, num);
#else
  switch (num) {
    case 1:
      dgt = "one";
      break;
    case 2:
      dgt = "two";
      break;
    case 3:
      dgt = "three";
      break;
    case 4:
      dgt = "four";
      break;
    case 5:
      dgt = "five";
      break;
    case 6:
      dgt = "six";
      break;
    case 7:
      dgt = "seven";
      break;
    case 8:
      dgt = "eight";
      break;
    case 9:
      dgt = "nine";
      break;
  }
#endif

  return dgt;
}

/*
 *  MARK: t11_19()
 */
char const * t11_19(int num) {
  char const * dgt;

#ifndef SWITCHY_
  dgt = unit_name(TEENS, num);
#else
  switch (num) {
    case 1:
      dgt = "eleven";
      break;
    case 2:
      dgt = "twelve";
      break;
    case 3:
      dgt = "thirteen";
      break;
    case 4:
      dgt = "fourteen";
      break;
    case 5:
      dgt = "fifteen";
      break;
    case 6:
      dgt = "sixteen";
      break;
    case 7:
      dgt = "seventeen";
      break;
    case 8:
      dgt = "eighteen";
      break;
    case 9:
      dgt = "nineteen";
      break;
  }
#endif

  return dgt;
}

/*
 *  MARK: t10_90()
 */
char const * t10_90(int num) {
  char const * dgt;

#ifndef SWITCHY_
  dgt = unit_name(TENS, num);
#else
  switch (num) {
    case 1:
      dgt = "ten";
      break;
    case 2:
      dgt = "twenty";
      break;
    case 3:
      dgt = "thirty";
      break;
    case 4:
      dgt = "forty";
      break;
    case 5:
      dgt = "fifty";
      break;
    case 6:
      dgt = "sixty";
      break;
    case 7:
      dgt = "seventy";
      break;
    case 8:
      dgt = "eighty";
      break;
    case 9:
      dgt = "ninety";
      break;
  }
#endif

  return dgt;
}

/*
 *  MARK: unit_name()
 */
char const * unit_name(enum name_type nt, int num) {
  char const * units[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  };
  char const * teens[] = {
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
  };
  char const * tens[] = {
    "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
  };

  char const * uname;
  switch (nt) {
    case UNITS:
      uname = units[num - 1];
      break;

    case TEENS:
      uname = teens[num - 1];
      break;

    case TENS:
      uname = tens[num - 1];
      break;
  }

  return uname;
}
