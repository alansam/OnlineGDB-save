
#include <stdio.h>
#include <stdlib.h>
#include <bsd/stdlib.h>

#define SIDES  6
#define ROLLS 20
#define LOOPS  5

typedef long (*dice)(void);

typedef struct rgen rgen;
struct rgen {
  char * name;
  dice rng;
  long results[ROLLS * LOOPS];
};

long dice00(void) { return rand() % SIDES; }
long dice01(void) { return random() % SIDES; }
long dice02(void) { return arc4random() % SIDES; }
void freq_analysis(rgen * gen);

static
char const * const dlm = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

int main() {
  rgen roll[] = {
    { "rand",       dice00, },
    { "random",     dice01, },
    { "arc4random", dice02, },
  };
  size_t roll_sz = sizeof(roll) / sizeof(*roll); 

  for (size_t i_ = 0; i_ < LOOPS; ++i_) {
    for (size_t fn = 0; fn < roll_sz; ++fn) {
      printf("%s\nUsing RNG %s\n", dlm, roll[fn].name);
      dice die = roll[fn].rng;
      for (size_t rl = 0; rl < ROLLS; ++rl) {
        long rolled = die() + 1;
        roll[fn].results[i_ * ROLLS + rl] = rolled;
        printf("Roll # %4zu: %ld\n", rl + 1, rolled);
      }
      putchar('\n');
    }
  }

  for (size_t fn = 0; fn < roll_sz; ++fn) {
    printf("%s\nResults for RNG %s\n", dlm, roll[fn].name);
    for (size_t i_ = 0, pc = 1; i_ < ROLLS * LOOPS; ++i_) {
      printf("%2ld%s", roll[fn].results[i_], (pc++ % 20 == 0 ? "\n" : " "));
    }
    putchar('\n');
  }

  for (size_t fn = 0; fn < roll_sz; ++fn) {
    freq_analysis(&roll[fn]);
  }

  return 0;
}

int cmp_long(void const * lhs, void const * rhs) {
  int cv;
  cv = (*(long *) lhs == *(long *) rhs) ? 0 : ((*(long *) lhs > *(long *) rhs) ? 1 : -1);
  return cv;
}

void freq_analysis(rgen * gen) {
  long work[ROLLS * LOOPS] = { 0L, };

  for (size_t i_ = 0; i_ < ROLLS * LOOPS; ++i_) {
    work[i_] = gen->results[i_];
  }

  printf("%s\nAnalysis of RNG %s\n", dlm, gen->name);

  int dots[SIDES] = { 0, };
  qsort(work, ROLLS * LOOPS, sizeof(long), cmp_long);
  for (size_t i_ = 0, pc = 1; i_ < ROLLS * LOOPS; ++i_) {
    dots[work[i_] - 1] += 1;
    printf("%3ld%s", work[i_], (pc++ % 20 == 0 ? "\n" : " "));
  }
  putchar('\n');

  puts("Frequencies:");
  for (size_t d_ = 0; d_ < SIDES; ++d_) {
    printf("%3zu occurs %3d times\n", d_ + 1, dots[d_]);
  }
  putchar('\n');

  return;
}

