
#include <stdio.h>

#define ABBA_MAX 9

// Agnetha Fältskog, Björn Ulvaeus, Benny Andersson, and Anni-Frid Lyngstad. 
int main() {
  char abba[ABBA_MAX] = { 'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd', '\0', };
  size_t abba_l = sizeof(abba) / sizeof(*abba);
  size_t abba_h = abba_l / 2;
  char abba_x[ABBA_MAX] = { '\0', };

  size_t j_ = 0;
  for (size_t k_ = 1; k_ < 2; k_--) {
    for (size_t i_ = k_ * abba_h; i_ < abba_h * k_ + abba_h; ++i_) {
      abba_x[j_++] = abba[i_];
    }
  }

  printf("Agnetha Fältskog, Björn Ulvaeus, Benny Andersson, and Anni-Frid Lyngstad.\n");
  printf("%s\n", abba);
  printf("%s\n", abba_x);

  return 0;
}
