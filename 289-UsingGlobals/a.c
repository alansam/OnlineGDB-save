
#include "a.h"

//  MARK: global, yuck!
int num = 100;

/*
 *  MARK: update_num()
 */
int update_num(int const new_num) {
  int old_num = num;
  num = new_num;
  return old_num;
}

/*
 *  MARK: get_num()
 */
int get_num(void) {
  return num;
}
