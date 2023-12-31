
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char const * const textfile[] = {
  "words.txt",
  "empty.txt",
  "daffies.txt",
};

void do_words(char const * fname);
void do_bytes(char const * fname);
void do_advance(char const * fname);
FILE * discard_line(FILE * fp);
FILE * advance_one_word(FILE * fp, size_t wl, char * last_word);

/*
 *  MARK: main()
 */
int main() {
  printf("fgetc+fgets\n");

  for (size_t f_ = 0ul; f_ < sizeof textfile / sizeof *textfile; ++f_) {
    do_words(textfile[f_]);
  }

  for (size_t f_ = 0ul; f_ < sizeof textfile / sizeof *textfile; ++f_) {
    do_bytes(textfile[f_]);
  }

  for (size_t f_ = 0ul; f_ < sizeof textfile / sizeof *textfile; ++f_) {
    do_advance(textfile[f_]);
  }

  return 0;
}

/*
 *  MARK: discard_line()
 */
FILE * discard_line(FILE * fp) {
  printf("In function %s()\n", __func__);

  if (fp != NULL) {
    //  discard first line.
    int gc = '\n';
    while ((gc = fgetc(fp)) != '\n' && gc != EOF);
    printf("read up to a %#04x\n", gc);
    // gc = fgetc(tf);
  }

  return fp;
}

/*
 *  MARK: advance_one_word()
 */
FILE * advance_one_word(FILE * fp, size_t wl, char * last_word) {
  printf("In function %s()\n", __func__);

  if (fp != NULL) {
    int gc = '\0';
    size_t cc = 0ul;
    char * buff_p = last_word;
    while ((gc = fgetc(fp)) != EOF) {
      cc++;
      if (cc >= wl) {
        printf("GRONK!: word is too big for buffer\n");
        *buff_p = '\0';
      }
      else if (isspace(gc)) {
        *buff_p++ = '\0';
        break;
      }
      else {
        *buff_p++ = gc;
      }
    }
  }

  return fp;
}

/*
 *  MARK: do_words()
 */
void do_words(char const * textfile) {
  printf("In function %s()\n", __func__);

  FILE * tf = NULL;
  tf = fopen(textfile, "r");
  if (tf != NULL) {
    //  file is open, here we go ...
    printf("Using file \"%s\"\n", textfile);

    //  discard first line.
    discard_line(tf);

    //  read the rest of the file, string by string.
    char str[256];
    char * pstr = NULL;
    while ((pstr = fgets(str, sizeof str, tf)) != NULL) {
      str[strcspn(pstr, "\n")] = '\0';  //  strip any newlines off the end of the string
      printf("%s ", str);
    }
    putchar('\n');

    if (feof(tf)) {
      //  check that really we did get to EOF.
      printf("Reached end-of-file for \"%s\"\n", textfile);
    }
    else {
      printf("Not at end-of-file for \"%s\" yet\n", textfile);
    }

    if (fclose(tf) == 0) {
      printf("Successful close of \"%s\"\n", textfile);
    }
    else {
      printf("Unable to close \"%s\"\n", textfile);
    }
  }
  else {
    //  fopen() failed. issue error message.
    printf("GRONK!: unable to open \"%s\"\n", textfile);
  }
  putchar('\n');

  return;
}

/*
 *  MARK: do_bytes()
 */
void do_bytes(char const * textfile) {
  printf("In function %s()\n", __func__);

  FILE * tf = NULL;
  tf = fopen(textfile, "r");
  if (tf != NULL) {
    //  file is open, here we go ...
    printf("Using file \"%s\"\n", textfile);

    //  discard first line.
    discard_line(tf);

    //  read the rest of the file, byte by byte.
    int gc = EOF;
    while ((gc = fgetc(tf)) != EOF) {
      if (isspace(gc)) {
        putchar(' ');
      }
      else if (iscntrl(gc)) {
        putchar('.');
      }
      else {
        putchar(gc);
      }
    }
    putchar('\n');

    if (feof(tf)) {
      //  check that really we did get to EOF.
      printf("Reached end-of-file for \"%s\"\n", textfile);
    }
    else {
      printf("Not at end-of-file for \"%s\" yet\n", textfile);
    }

    if (fclose(tf) == 0) {
      printf("Successful close of \"%s\"\n", textfile);
    }
    else {
      printf("Unable to close \"%s\"\n", textfile);
    }
  }
  else {
    //  fopen() failed. issue error message.
    printf("GRONK!: unable to open \"%s\"\n", textfile);
  }
  putchar('\n');

  return;
}

/*
 *  MARK: do_advance()
 */
void do_advance(char const * textfile) {
  printf("In function %s()\n", __func__);

  FILE * tf = fopen(textfile, "r");
  if (tf != NULL) {
    char word[256] = { '\0', };
    size_t word_sz = sizeof word / sizeof *word;
    for (size_t wi = 0ul; wi < 4; ++wi) {
      word[0] = '\0';
      advance_one_word(tf, word_sz, word);
      printf("word %2zu: %s\n", wi + 1ul, word);
      if (feof(tf)) {
        break;
      }
    }

    if (feof(tf)) {
      //  check that really we did get to EOF.
      printf("Reached end-of-file for \"%s\"\n", textfile);
    }
    else {
      printf("Not at end-of-file for \"%s\" yet\n", textfile);
    }

    if (fclose(tf) == 0) {
      printf("Successful close of \"%s\"\n", textfile);
    }
    else {
      printf("Unable to close \"%s\"\n", textfile);
    }
  }
  else {
    //  fopen() failed. issue error message.
    printf("GRONK!: unable to open \"%s\"\n", textfile);
  }
  putchar('\n');

  return;
}
