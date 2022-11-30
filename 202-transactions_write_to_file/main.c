// I have a following data structure I need to write in a .dat file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum change { INPUT, OUTPUT, } CHANGE;

typedef unsigned char byte;

typedef struct transaction {
  unsigned Id;
  CHANGE change;
  unsigned quantity;
} TRANSACTION;
size_t const TRANSACTION_sz = sizeof(TRANSACTION);

/*
 *  The output in a .dat file should be formatted like:
 *  ID  CHANGE  QUANTITY
 * "1   INPUT   25"
 * "2   OUTPUT  12"
 *  etc.
 *
 *  How do I manage to do this without modifying existing
 *  data structures and creating new ones to replace these?
 */

#ifdef DFNAM
static
char const * dfile_name = DFNAM;
#else
static
char const * dfile_name = "transactions.dat";
#endif

static
TRANSACTION txs[] = {
  { 1, INPUT,  25, },
  { 2, OUTPUT, 12, },
};
size_t const max_tx = sizeof(txs) / sizeof(TRANSACTION);

static
inline
char const * CHANGE_name(CHANGE ch) {
  char const * cv;
  switch (ch) {
  case INPUT:
    cv = "INPUT";
    break;
  case OUTPUT:
    cv = "OUTPUT";
    break;
  default:
    cv = "GRONK!";
    break;
  }

  return cv;
}

static
inline
void show_tx(size_t const sz, TRANSACTION const * tx) {
  printf("%-5s %-6s, %-5s\n", "ID", "CHANGE", "QUANTITY");
  for (size_t t_ = 0ul; t_ < sz; ++t_) {
    printf("%5u %-6s %5u\n", tx[t_].Id, CHANGE_name(tx[t_].change), tx[t_].quantity);
  }
  putchar('\n');
}

int write_dat(size_t const sz, TRANSACTION const * tx, char const * fn);
int read_dat(size_t * psz, TRANSACTION * ptx[], char const * fn);
int dump_dat(char const * fn);

int main() {
  puts("202-transactions_write_to_file\n");
  int RC = EXIT_SUCCESS;

  show_tx(max_tx, txs);

  RC = write_dat(max_tx, txs, dfile_name);
  if (RC == EXIT_SUCCESS) {
    RC = dump_dat(dfile_name);
  }
  if (RC == EXIT_SUCCESS) {
    TRANSACTION * ptx = NULL;
    size_t ptx_sz = 0ul;
    // read_dat(&ptx_sz, &ptx, dfile_name);
    show_tx(ptx_sz, ptx);
    free(ptx);
  }

  return RC;
}

int write_dat(size_t const sz, TRANSACTION const * tx, char const * fn) {
  int state = EXIT_SUCCESS;

  FILE * fdat;
  fdat = fopen(fn, "a");
  if (fdat != NULL) {
    size_t fw = 0ul;
    fw = fwrite(tx, TRANSACTION_sz, sz, fdat);
    printf("%5zu, %5zu byte items written to \"%s\"\n", fw, TRANSACTION_sz, fn);
    if (fw < sz) {
      printf("Ubable to write all items (%5zu of %5zu)\n", fw, sz);
    }

    int crc = fclose(fdat);
    if (crc != 0) {
      fprintf(stderr, "Unable to close file %s, err code %d. Terminating...", fn, crc);
      state = EXIT_FAILURE;
    }
  }
  else {
    fprintf(stderr, "Unable to open file %s. Terminating...", fn);
    state = EXIT_FAILURE;
  }

  return state;
}

int dump_dat(char const * fn) {
  int state = EXIT_SUCCESS;

  FILE * fdat;
  fdat = fopen(fn, "r");
  if (fdat != NULL) {
    TRANSACTION tx = { 0, };
    byte * ptx;
    size_t rd = 0ul;
    size_t rc = 0ul;
   do {
      int eof;
      ptx = (byte *) &tx;
      rd = fread(ptx, TRANSACTION_sz, 1ul, fdat);
      eof = feof(fdat);
      if (eof == 0) {
        printf("%5zu: ", 1ul + rc++);
        if (rd > 0) {
          for (size_t b_ = 0ul; b_ < TRANSACTION_sz; ++b_) {
            printf("%02x ", (unsigned) *ptx++);
          }
          putchar('\n');
        }
        else {
          eof = feof(fdat);
          if (eof != 0) {
            fprintf(stderr, "Error reading from file %s, err code %d. Terminating...", fn, eof);
            state = EXIT_FAILURE;
          }
          rd = EOF;
        }
      }
      else {
        rd = EOF;
      }
    } while (rd != EOF);
    putchar('\n');

    fclose(fdat);
  }
  else {
    fprintf(stderr, "Unable to open file %s. Terminating...", fn);
    state = EXIT_FAILURE;
  }
  putchar('\n');

  return state;
}

int read_dat(size_t * psz, TRANSACTION * ptx[], char const * fn) {
  int state = EXIT_SUCCESS;

  FILE * fdat;
  fdat = fopen(fn, "r");
  if (fdat != NULL) {
    TRANSACTION tx = { 0, };
    size_t rd = 0ul;
    size_t rc = 0ul;

    ptx = NULL;
    do {
      int eof;
      rd = fread(&tx, TRANSACTION_sz, 1ul, fdat);
      eof = feof(fdat);
      if (eof == 0) {
        if (rd > 0) {
          *ptx = realloc(*ptx, TRANSACTION_sz * (rc + 1));
          printf("%p\n", (void *) *ptx);
          if (ptx != NULL) {
            TRANSACTION * ctx = *ptx + (rc * TRANSACTION_sz);
            printf("%p\n", (void *) ctx);
            // memcpy(ctx, &tx, TRANSACTION_sz);
            rc++;
            exit(EXIT_FAILURE);
          }
          else {
            fprintf(stderr, "Unable to acquire %zu bytes of memory\n", TRANSACTION_sz);
            state = EXIT_FAILURE;
            rd = EOF;
          }
        }
        else {
          eof = feof(fdat);
          if (eof != 0) {
            fprintf(stderr, "Error reading from file %s, err code %d. Terminating...", fn, eof);
            state = EXIT_FAILURE;
          }
          rd = EOF;
        }
      }
      else {
        rd = EOF;
      }
    } while (rd != EOF);
    putchar('\n');

    fclose(fdat);
  }
  else {
    fprintf(stderr, "Unable to open file %s. Terminating...", fn);
    state = EXIT_FAILURE;
  }
  putchar('\n');

  return state;
}
