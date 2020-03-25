#include <stdio.h>

char * digits_reverse(unsigned long numr, char * out, size_t out_l);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {

  unsigned long numr = 9876543210;
  size_t const bl = 21;
  char buffer[bl];
  char * out = buffer;
  out = digits_reverse(numr, buffer, bl);
  printf("%lu\n%s\n", numr, out);

  return 0;
}

/*
 *  MARK: digits_reverse()
 */
char * digits_reverse(unsigned long numr, char * out, size_t out_l) {

  char const * nc = "0123456789";
  size_t xx;
  size_t ix = 0;
  if (numr != 0) {
    while (numr != 0) {
      xx = numr % 10;
      numr /= 10;
      out[ix++] = nc[xx];
    }
  }
  else {
    out[ix++] = nc[numr];
  }
  out[ix] = '\0';
  
  return out;
}

