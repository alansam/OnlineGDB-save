
#include <stdio.h>

int main() {
  int inbuf[256] = { 0, };
  size_t ix = 0;
  int ic;
  ic = getc(stdin);
  inbuf[ix] = ic;
  while (ic != EOF && ic != '2') {
    fputc(inbuf[ix], stdout);
    ic = getc(stdin);
    inbuf[++ix] = ic;
  }
  putchar('\n');
  int cc = 0;
  int const cc_max = 16;
  for (size_t i_ = 0; i_ <= ix; ++i_) {
    printf("%#04x%s", inbuf[i_], (++cc % cc_max == 0 ? "\n" : " "));
  }
  putchar('\n');

  return 0;
}
