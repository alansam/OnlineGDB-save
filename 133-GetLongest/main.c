
#include <stdio.h>
#include <string.h>

#define MAX_STR 100

typedef struct longest_result longest_result;
struct longest_result {
  size_t longest;
  char const * longest_s;
};

longest_result get_longest(size_t ln, char str[ln][MAX_STR]) {
  longest_result res = { 0, NULL, };

  for (size_t s_ = 0; s_ < ln; ++s_) {
    size_t sl = strlen(str[s_]);
    if (sl > res.longest) {
      res.longest = sl;
      res.longest_s = str[s_];
    }
  }

  return res;
}

size_t locate_longest(size_t ln, char str[ln][MAX_STR]) {
  size_t longest = 0;
  size_t current = 0;
  for (size_t s_ = 0; s_ < ln; ++s_) {
    size_t sl = strlen(str[s_]);
    if (sl > current) {
      current = sl;
      longest = s_;
    }
  }
  return longest;
}

int main() {
  char str[][MAX_STR] = {
    "ones", "twoses", "threezies", "fourzies", "fivezies",
  };
  size_t str_l = sizeof(str) / sizeof(*str);

  for (size_t s_ = 0; s_ < str_l; ++s_) {
    printf("%s\n", str[s_]);
  }

  longest_result lr = get_longest(str_l, str);
  printf("\nlongest string is \"%s\", length: %2zu.\n", lr.longest_s, lr.longest);

  size_t pos = locate_longest(str_l, str);
  printf("\nlongest string is \"%s\", length: %2zu.\n", str[pos], strlen(str[pos]));

  return 0;
}


