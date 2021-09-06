
#include <stdio.h>
#include <ctype.h>

void sol00(void);
void sol01(void);
void sol02(void);

int main() {
  puts("\012Begin\n=====");

  sol00();
  sol01();
  sol02();

  puts("\012All done\x0a========");

  return 0;
}

void sol01(void) {
  printf("Input:\n");
  int i;
  while ((i = getchar()) != EOF) {
    if (i == '\t') {
      putchar('\\');
      putchar('t');
    }
    if (i == '\b') {
      putchar('\\');
      putchar('b');
    }
    if (i == '\\') {
      putchar('\\');
      putchar('\\');
    }
    if (i != '\t') {
      putchar(i);
    }
  }
  puts(i == EOF ? "\nEOF" : "\n");
}

void sol02(void) {
  printf("Input:\n");
  int i;
  while ((i = getchar()) != EOF) {
    if (i == '\t') {
      putchar('\\');
      putchar('t');
    }
    if (i == '\b') {
      putchar('\\');
      putchar('b');
    }
    if (i == '\\') {
      putchar('\\');
      putchar('\\');
    }
    putchar(i);
  }
  puts(i == EOF ? "\nEOF" : "\n");
}

void sol00(void) {
  printf("Input reader\n");
  int ch;
  while ((ch = getchar()) != EOF) {
    if (isprint(ch)) {
      putchar(ch);
    }
    else if (isspace(ch)) {
      // NOTE: space, 0x20 (SP) is caught by isprint()
      putchar('\\');
      int sp;
      switch (ch) {
        case '\t':
          sp = 't';
          break;
        case '\n':
          sp = 'n';
          break;
        case '\v':
          sp = 'v';
          break;
        case '\f':
          sp = 'f';
          break;
        case '\r':
          sp = 'r';
          break;
        default:
          break;
      }
      putchar(sp);
    }
    else if (iscntrl(ch)) {
      printf("\\%03o", ch);
    }
    else {
      printf("%#04x", ch);
    }
  }
  puts(ch == EOF ? "\nEOF" : "\n");

  return;
}
