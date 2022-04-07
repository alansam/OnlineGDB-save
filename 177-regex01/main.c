
#include <stdio.h>
#include <regex.h>
#include <stdbool.h>

bool match(char const * string, char const * pattern) {
  regex_t re;
  if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
    fprintf(stderr, "pattern %s failed to compile\n", pattern);
    return false;
  }

  int status = regexec(&re, string, 0, NULL, 0);
  regfree(&re);

  return (status == 0) ? true : false;
}

int main() {
  char const * s1 = "abc";
  char const * s2 = "123";
  char const * strs[] = { s1, s2, };
  size_t const strs_l = sizeof(strs) / sizeof(*strs);

  char const * re = "[1-9]+";

  for (size_t s_ = 0; s_ < strs_l; ++ s_) {
    printf("'%s' Given string matches '%s'? %s\n", strs[s_], re, match(strs[s_], re) ? "true" : "false");
  }

  return 0;
}

