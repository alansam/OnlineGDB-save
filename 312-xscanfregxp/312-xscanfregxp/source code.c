//  @see: https://stackoverflow.com/questions/24483075/input-using-sscanf-with-regular-expression
//  Compiler flags: -Wall -Wpedantic -Werror=vla -std=gnu2x

#include <stdio.h>

void so_example(char const * instr);
void xmlstr(char const * xml);

/*
 *  MARK: main()
 */
int main() {
  printf("In file %s\n", __FILE__);

  so_example("First (helloWorld): last");
  xmlstr("<x>136</n>");
  xmlstr("<x> 136</n>");

  return 0;
}

/*
 *  %*[^(]   read and discard everything up to opening paren
 *  (        read and discard the opening paren
 *  %[^)]    read and store up up to (but not including) the closing paren
 *  %*[^\n]  read and discard up to (but not including) the newline
 */
void so_example(char const * instr) {
  printf("In function %s()\n", __func__);

  char str[256];
  printf("Input : %s\n", instr);
  sscanf(instr, "%*[^(](%[^)]%*[^\n]", str);
  printf("Result: %s\n", str);
  putchar('\n');

  return;
}

/*
 *  MARK: xmlstr()
 */
void xmlstr(char const * xml) {
  printf("In function %s()\n", __func__);

  char xval[256];
  int ival;
  printf("Input : %s\n", xml);
  sscanf(xml, "%*[^>]>%[^<]%*[^\n]", xval);
  ival = atoi(xval);
  printf("Result: %d\n", ival);
  putchar('\n');

  return;
}
