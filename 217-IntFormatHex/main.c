
#include <stdio.h>
#include <limits.h>

//  format an int as hex characters
static
inline
char const * showx(char * target, int val) {
  typedef union i2x i2x;
  union i2x {
    int ival;
    unsigned char xval[sizeof val];
  };

  char const * fnort = target;
  i2x vv;
  vv.ival = val;
  //  format each byte as printable hex
  for (size_t c_ = 0; c_ < sizeof val; ++c_) {
    sprintf(target, "%02x ", vv.xval[c_]);
    target += 3;  //  advance to next print position
  }
  *(--target) = '\0'; //  remove trailing space

  return fnort;
}

//  program driver
int main() {
  // int arr[] = { 299, 6, 0, 6, 9, 4, };
  int arr[] = {
    299, 666, 0, -6, 999, 4096,
    0x7fff, 0xffff, -1,
    INT_MAX, INT_MIN,
    0x2b010000, 0x0000012b,
  };

  int * ptr = arr;
  for (size_t c_ = 0; c_ < (sizeof arr / sizeof *arr); ++c_) {
    char tgt[20] = { 0, };
    printf("data @ %p:\n", ptr);
    printf("%12d == %#010x == %s\n", arr[c_], arr[c_], showx(tgt, arr[c_]));
  
    *((char *) ptr++) = 1;
  
    printf("%12d == %#010x == %s\n", arr[c_], arr[c_], showx(tgt, arr[c_]));
    
    printf("%12d\n", arr[c_]);
  }

  return 0;
}

