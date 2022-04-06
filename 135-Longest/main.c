
#include <stdio.h>
#include <string.h>

int main() {
#ifdef JUST_SO_WRONG
  char str[100][100];
  int count = 0, max = 0, i = 0, longest; 
  for (i = 0; i < 5; i++) {
    printf("Enter 5 strings: ");
    fgets(str[i], 100, stdin);
  }
  max = strlen(str[0]);
  for (i = 0; str[i] != '\0'; i++) {
    if (strlen(str[i]) > max) {
      longest = strlen(str[i]);
    }
  }
  printf("The longest string is: %d\n", longest);
#endif

// #define USE_TYPEDEF
#define MAX_STR 100
#ifdef USE_TYPEDEF
  typedef char String[MAX_STR];
  String str[] =
#else
  char str[][MAX_STR] =
#endif
  {
    "ones", "twoses", "threezies", "fourzies", "fivezies",
  };
  size_t str_l = sizeof(str) / sizeof(*str);

  size_t longest = 0;
  char * longest_s = NULL;

  for (size_t s_ = 0; s_ < str_l; ++s_) {
    printf("%s\n", str[s_]);
    size_t sl = strlen(str[s_]);
#ifndef OH_LORDIE
    if (sl > longest) {
      longest = sl;
      longest_s = str[s_];
    }
#else
    longest = sl > longest ? longest_s = str[s_], sl : longest; //  this works but is it valid C?
#endif
  }

  printf("\nlongest string is \"%s\", length: %2zu.\n", longest_s, longest);

  return 0;
}

