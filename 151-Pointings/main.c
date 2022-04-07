
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct group group;
struct group {
  char      A1;
  uint32_t  I1;
  int64_t   L1;
  char      S1[48];
};

typedef struct group_ptr group_ptr;
struct group_ptr {
  char *      PA1;
  uint32_t *  PI1;
  int64_t *   PL1;
  char *      PS1;
};

inline
static
void snap(size_t sz, void * group) {
  size_t const cc_mx = 8UL;
  unsigned char * gc = (unsigned char *) group;
  printf("\nSnap:\n");
  printf("\nBlock starts at address: %" PRIxPTR " - Size: %" PRIdPTR " [hex digits]\n", (uintptr_t) group, sz);
  size_t offset = 0ul;
  printf("%04" PRIxPTR ": ", offset);
  char formatter[80] = { 0, };
  for (size_t c_ = 0, cc = 1; c_ < sz; ++c_) {
    sprintf(formatter, " %02" PRIx8 "%s", gc[c_], (cc++ % cc_mx == 0 ? "\n%04" PRIxPTR ": " : ""));
    printf(formatter, ++offset);
  }
  putchar('\n');

  printf("\nBlock starts at address: %" PRIxPTR " - Size: %" PRIdPTR " [printable characters]\n", (uintptr_t) group, sz);
  offset = 0ul;
  printf("%04" PRIxPTR ": ", offset);
  for (size_t c_ = 0, cc = 1; c_ < sz; ++c_) {
    char cp = isprint(gc[c_]) ? gc[c_] : '.';
    sprintf(formatter, " %2c%s", cp, (cc++ % cc_mx == 0 ? "\n%04" PRIxPTR ": " : ""));
    printf(formatter, ++offset);
  }
  putchar('\n');
}

int main(int argc, char const * argv[]) {
  putchar('\n');

  group gg1 = { .A1 = 'A', .I1 = 0xdecaf, .L1 = 0xcafebabe, .S1 = "A quick brown fox jumps over the lazy dog!", };
  size_t gg1_sz = sizeof gg1;
  group_ptr gg1_p = { .PA1 = &gg1.A1, .PI1 = &gg1.I1, .PL1 = &gg1.L1, .PS1 = (char *) &gg1.S1, };
  size_t gg1_p_sz = sizeof gg1_p;

  char xL1[17];
  char xI1[ 9];
  sprintf(xI1, "%08"  PRIx32, gg1.I1);
  sprintf(xL1, "%016" PRIx64, gg1.L1);
  printf("|%p<|>%-48c|\n",  gg1_p.PA1, gg1.A1);
  printf("|%p<|>%-48s|\n", (void *) gg1_p.PI1, xI1);
  printf("|%p<|>%-48s|\n", (void *) gg1_p.PL1, xL1);
  printf("|%p<|>%-48s|\n",  gg1_p.PS1, gg1.S1);
  snap(gg1_sz, (void *) &gg1);
  snap(gg1_p_sz, (void *) &gg1_p);

  return 0;
}

