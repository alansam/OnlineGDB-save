//  @see: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * trimwhitespace(char * str);

#define STRLN 32

static
inline
void showthings(size_t nr, char things[nr][STRLN]) {
  for (size_t t_ = 0; t_ < nr; ++t_) {
    printf("\"%s\"\n", things[t_]);
  }
  putchar('\n');
}

int main (void) {
  char string[] = { "      the quick brown fox jumps over a lazy dog        " };
  char work[256] = { '\0' };
  char * pwork = work;
  strcpy(pwork, string);
  printf("\"%s\"\n", string);
  pwork = trimwhitespace(pwork);
  strcpy(string, pwork);
  printf("\"%s\"\n", string);
  putchar('\n');

  char things[][STRLN] = {
    "   anc ir ",
    "",
    "   ",
    "ave meo",
    " jutr",
    "didlle derp    ",
  };
  size_t things_l = sizeof(things) / sizeof(things[0]);

  showthings(things_l, things);

  for (size_t t_ = 0; t_ < things_l; ++t_) {
    char tmp[STRLN] = { '\0' };
    strcpy(tmp, things[t_]);
    strcpy(things[t_], trimwhitespace(tmp));
  }

  showthings(things_l, things);

  return 0;
}

// Note: This function returns a pointer to a substring of the original string.
// If the given string was allocated dynamically, the caller must not overwrite
// that pointer with the returned value, since the original pointer must be
// deallocated using the same allocator with which it was allocated.  The return
// value must NOT be deallocated using free() etc.
char * trimwhitespace(char * str) {
  char * end;

  // Trim leading space
  while (isspace((unsigned char) *str)) { str++; }

  if(*str == 0) { // All spaces?
    return str;
  }

  // Trim trailing space
  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char) *end)) { --end; }

  // Write new null terminator character
  end[1] = '\0';

  return str;
}
