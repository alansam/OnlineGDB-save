
// I am using codeblock ide...

// Header file a.h contains deceleration 
// extern int num;
// another source file contain definition
// int num = 100;
// main file main.c contains 
// printf("%d", num);

/*
But it generate error undefined referance to num.

While sharing function no error occured but while
sharing variable it generate errorr. In stackoverflow
it was done in the same way but when i did its error...
*/

#include <stdio.h>

#include "a.h"

/*
 *  MARK: main()
 */
int main() {
  printf("%d\n", num);
  printf("%d\n", get_num());
  printf("%d\n", update_num(150));
  printf("%d\n", num);
  num += 50;
  printf("%d\n", get_num());

  return 0;
}
