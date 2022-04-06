
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

inline
static
void showerror(int errnum) {
#ifdef _GNU_SOURCE
  fprintf(stderr, "ERROR [%03d]: %s - %s\n", errnum, strerrorname_np(errnum), strerrordesc_np(errnum));
#else
  fprintf(stderr, "ERROR [%03d]: %s\n", errnum, strerror(errnum));
#endif
}

void fit_the_first(void);
void fit_the_second(void);

int main() {
  fit_the_first();
  fit_the_second();

  return 0;
}

void fit_the_first(void) {
  printf("In function %s()\n\n", __func__);

  int inputFd, outputFd;
  ssize_t numRead, numWrite;
  size_t count;
  char dbuf[256] = { 0, };
  char * buf = dbuf;
  if ((inputFd = open("necho.c", O_RDONLY)) == -1) {
    fprintf(stderr, "error opening input file\n");
    showerror(errno);
    exit(EXIT_FAILURE);
  }

  if ((outputFd = open("copy1.txt", O_WRONLY /*| O_APPEND*/)) == -1) {
    fprintf(stderr, "error opening output file\n");
    showerror(errno);
    exit(EXIT_FAILURE);
  }

  count = 10;
  size_t reads = 0;
  while ((numRead = read(inputFd, buf, count)) != -1 && numRead != 0) {
    printf("read nr: %zu, bytes read: %ld\n", ++reads, numRead);
    if ((numWrite = write(outputFd, buf, numRead)) == -1) {
      fprintf(stderr, "error writing data\n");
      showerror(errno);
      exit(EXIT_FAILURE);
    }
    // if (reads == 20) { break; }
  }
  putchar('\n');

  return;
}

void fit_the_second(void) {
  printf("In function %s()\n\n", __func__);

  FILE * fpi;
  FILE * fpo;
  int fcf;
  char buff[256];

  fpi = fopen("necho.c", "r");
  if (fpi == NULL) {
    fprintf(stderr, "error opening input file\n");
    showerror(errno);
    exit(EXIT_FAILURE);
  }

  fpo = fopen("copy2.txt", "w");
  if (fpo == NULL) {
    fprintf(stderr, "error opening output file\n");
    showerror(errno);
    exit(EXIT_FAILURE);
  }

  size_t numRead;
  size_t numWrite;
  size_t count = 10;
  size_t reads = 0;
  while (!feof(fpi)) {
    numRead = fread(buff, 1, count, fpi);
    printf("read nr: %zu, bytes read: %ld\n", ++reads, numRead);
    if (ferror(fpi)) {
      fprintf(stderr, "error reading data\n");
      showerror(errno);
      exit(EXIT_FAILURE);
    }

    numWrite = fwrite(buff, 1, numRead, fpo);
    if (ferror(fpo)) {
      fprintf(stderr, "error reading data\n");
      showerror(errno);
      exit(EXIT_FAILURE);
    }
  }

  fcf = fclose(fpo);
  if (fcf != 0) {
    fprintf(stderr, "error closing input file\n");
    showerror(errno);
  }
  fcf = fclose(fpi);
  if (fcf != 0) {
    fprintf(stderr, "error closing output file\n");
    showerror(errno);
  }
  putchar('\n');

  return;
}
