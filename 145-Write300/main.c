
#include <stdio.h>
#include <stdlib.h>

char const * file_name = "./300-lines.txt";
char const * delim10 = "....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|....+....|";
char const * delim00 = "-";

int main() {
  int RC = EXIT_SUCCESS;

  printf("Begin\n");
  FILE * fp;
  fp = fopen(file_name, "w");
  if (fp == NULL) {
    RC = EXIT_FAILURE;
    perror("File opening failed");
    exit(RC);
  }

  printf("Begin write\n");
  size_t const cc_max = 10;
  for (size_t l_ = 0, cc = 1; l_ < 300; ++l_) {
    // fprintf(stdout, "Line No: %4zu: %s\n", l_ + 1, (cc++ % cc_max == 0 ? delim10 : delim00));
    fprintf(fp, "Line No: %4zu: %s\n", l_ + 1, (cc++ % cc_max == 0 ? delim10 : delim00));
  }
  printf("End write\n");
 
  if (ferror(fp)) {
    RC = EXIT_FAILURE;
    fprintf(stderr, "I/O error: RC=%d", RC);
    exit(RC);
  }

  int frc = fclose(fp);
    fprintf(stdout, "fclose result=%d\n", frc);
  if (frc != 0) {
    RC = EXIT_FAILURE;
    fprintf(stderr, "fclose failed: RC=%d\n", RC);
  }
  printf("End I/O\n");

  printf("End\n");

  return RC;
}
