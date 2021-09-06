
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define INTS 16
#define INT_SZ (sizeof(int32_t) * 2 + 1)

#define SHRTS 32
#define SHRT_SZ (sizeof(int16_t) * 2 + 1)

size_t resolve_int(char const * xstr, size_t nr, int32_t * result);
size_t resolve_short(char const * xstr, size_t nr, int16_t * result);

int alt001(void);
int alt002(void);
int alt003(void);

/*
 *  MARK: main()
 */
int main() {
  char * xstr[] = {
    "00EF56F542AD684400000078DFAD20B480CF88",
    "00EF56F542AD684400000078DFAD20B480CF8",
    "00EF56F542AD684400000078DFAD20B480CF",
    "00EF56F542AD684400000078DFAD20B480C",
    "00EF56F542AD684400000078DFAD20B480",
    "00EF56F542AD684400000078DFAD20B48",
    "00EF56F542AD684400000078DFAD20B4",

    "80000000ffffffff0000000000007fff0000ffff000100007fffffff",
    "8000ffff0000007f008000ff01007fff",
  };
  size_t xstr_el = sizeof xstr / sizeof(*xstr);

  {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("32-bit integers\n\n");

    int32_t vals[INTS];
    size_t vals_sz = sizeof vals / sizeof(*vals);

    for (size_t xz = 0; xz < xstr_el; ++xz) {
      printf("%s\n\n", xstr[xz]);
      size_t ct = resolve_int(xstr[xz], vals_sz, vals);
      printf("\nElements: %zu\n\n", ct);
      for (size_t i_ = 0; i_ < ct; ++ i_) {
        printf("%2zu: %08x %12d %12u\n", i_, vals[i_], vals[i_], (uint32_t) vals[i_]);
      }
      putchar('\n');
    }
  }

  {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("16-bit integers\n\n");

    int16_t vals[SHRTS];
    size_t vals_sz = sizeof vals / sizeof(*vals);

    for (size_t xz = 0; xz < xstr_el; ++xz) {
      printf("%s\n\n", xstr[xz]);
      size_t ct = resolve_short(xstr[xz], vals_sz, vals);
      printf("\nElements: %zu\n\n", ct);
      for (size_t i_ = 0; i_ < ct; ++ i_) {
        printf("%2zu: %04hx %12hd %12hu\n", i_, vals[i_], vals[i_], (uint16_t) vals[i_]);
      }
      putchar('\n');
    }
  }

  {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("First alternate\n");
    alt001();
  }

  {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Second alternate\n");
    alt002();
  }

  {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("third alternate\n");
    alt003();
  }

  return EXIT_SUCCESS;
}

/*
 *  MARK: resolve_int()
 */
size_t resolve_int(char const * xstr, size_t nr, int32_t * result) {
  size_t xstr_l = strlen(xstr);
  char wk[INT_SZ];
  char const * pch = xstr;
  uint32_t * val = (uint32_t *) result;

  div_t  szz  = div(xstr_l, (sizeof(int32_t) * 2));
  size_t elmt = szz.quot;
  size_t rem  = szz.rem;
  elmt += (rem == 0) ? 0 : 1;

  if (elmt > nr) {
    fprintf(stderr, "Not enough space for %zu conversions", elmt);
    exit(EXIT_FAILURE);
  }

  for (size_t wd = 0; wd < elmt; ++wd) {
    memset(wk, 0, sizeof wk);
    for (size_t cc = 0; cc < 8 || isspace(wk[cc]); ++cc) {
      wk[cc] = *pch++;
    }
    sscanf(wk, "%X", val++);
    printf("%s\n", wk);
  }

  return elmt;
}

/*
 *  MARK: resolve_short()
 */
size_t resolve_short(char const * xstr, size_t nr, int16_t * result) {
  size_t xstr_l = strlen(xstr);
  char wk[SHRT_SZ];
  char const * pch = xstr;
  uint16_t * val = (uint16_t *) result;

  div_t  szz  = div(xstr_l, (sizeof(int16_t) * 2));
  size_t elmt = szz.quot;
  size_t rem  = szz.rem;
  elmt += (rem == 0) ? 0 : 1;

  if (elmt > nr) {
    fprintf(stderr, "Not enough space for %zu conversions", elmt);
    exit(EXIT_FAILURE);
  }

  for (size_t wd = 0; wd < elmt; ++wd) {
    memset(wk, 0, sizeof wk);
    for (size_t cc = 0; cc < 4 || isspace(wk[cc]); ++cc) {
      wk[cc] = *pch++;
    }
    sscanf(wk, "%hX", val++);
    printf("%s\n", wk);
  }

  return elmt;
}

//  Alan Sampson
int alt001(void) {
  char hexstring[] = "00EF56F542AD684400000078DFAD20B480CF88",
     * position = hexstring;
  unsigned char val[19];
  char const * pch = hexstring;
  size_t i = 0;
  for (i = 0; i < 19; i++) {
    sscanf(position, "%2hhx", &val[i]);
    position += 2 * sizeof(char);
  }

  char scratch[9] = { 0 };
  int ival;
  for (size_t cc = 0; cc < 8; ++cc) {
    scratch[cc] = *pch++;
  }

  sscanf(scratch, "%X", (unsigned *) &ival);
  printf("%08x %11d\n", ival, ival);

  return 0;
}

//  Yasir Naeem
int alt002(void) {
  __attribute__((unused))
  int first_value;
  char hexstring[] = { "00EF56F542AD684400000078DFAD20B480CF88BA" };
  char *position = hexstring;
  unsigned char val[5][9];
  int i;
  int row = 0 ;
  int col = 0;
  for (i = 0; i < 40; i++) {
    val[row][col] = position[i];
    if (col == 7) {
      val[row][col+1]='\0';
      row++;
      col=0;
    }
    else {
      col++;
    }
  }

  unsigned long x;
  for (i = 0; i < 5; i++) {
    x = strtoul((char *) val[i], 0, 16);
    printf("The value represented by the string \"%s\" is\n"
           "%lu (decimal)\n" "%#lo (octal)\n" "%#lx (hex)\n",
           val[i], x, x, x);
  }

  return 0;
}

//  Pavlo Slavynskyy
#ifndef USE_STDIN_PIPE
#define BUFFER_SIZE 100
#define HEX_CHUNK 8

#define HEXFILE "hexdata.txt"
#define HEXFILE_mode "r"
#endif

int alt003(void) {
	char buffer[BUFFER_SIZE];

#ifdef USE_STDIN_PIPE
  {
  	fgets(buffer, 100, stdin);
#else
  FILE * hhex;
  hhex = fopen(HEXFILE, HEXFILE_mode);
  if (hhex == NULL) {
    fprintf(stderr, "unable to open file %s\n", HEXFILE);
    exit(EXIT_FAILURE);
  }
  else {
  	fgets(buffer, 100, hhex);
#endif
  	char *buffer_end = buffer + strlen(buffer);
  	putchar('\n');
  	for (char * str = buffer;str < buffer_end;str += HEX_CHUNK) {
  		unsigned int hex_value = 0;
  		sscanf(str, "%8x", &hex_value);
  		printf("  %.8s hex string is %11d dec signed, %10u dec unsigned, %08X hex, %12o octal.\n",
  		       str, (int) hex_value, hex_value, hex_value, hex_value);
  	}
  }

  return EXIT_SUCCESS;
}
