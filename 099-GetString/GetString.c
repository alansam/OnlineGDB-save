
#include <stdio.h>
#include <ctype.h>

#define SSZ (256)

char * getstring(size_t const nr, char string[nr]);
void showstring(size_t const nr, char const string[nr]);

int main() {
  printf("Enter a string:\n");
  char string[SSZ] = { 0, };
  char * strung;
  strung = getstring(SSZ, string);

  puts(strung);
  showstring(SSZ, strung);
  putchar('\n');

  char more[SSZ] = { 0, };
  char * moreorless;
  fgets(more, SSZ, stdin);

  puts(more);
  showstring(SSZ, more);
  putchar('\n');

  return 0;
}

char * getstring(size_t const nr, char string[nr]) {
  string[nr - 1] = '\0';
  for (size_t ix = 0; ix < nr - 1; ++ix) {
    int ch = fgetc(stdin);
    if (ch == '\n' || ch == EOF) {
      string[ix] = '\0';
      break;
    }
    string[ix] = ch;
  }

  return string;
}

void showstring(size_t const nr, char const string[nr]) {
  for (size_t ix = 0; ix < SSZ - 1; ++ix) {
    int ch = string[ix];
    if (ch == '\0') {
      break;
    }
    else if (isprint(ch)) {
      putchar(ch);
    }
    else {
      printf("\\%03o", ch); // octal non-printable
    }
  }
}
