/*
 *  Provide the correct input to have the program print the sentence:
 *        "Exactly! Good job."
 *
 *  Here we have 3 methods each method eather fails or succeeds, if it fails it prints Nope
 *  We need to make sure that nope is not printed, for that purpose they let us decide if which values for (f,k,z) as input for linkin_park 
 *  So the condition needs to evaluate to 0
 *  I choosed values of (f, k, z) such as the expression inside the if equals to 0
 *  I used: (f,k,z)= (0,0,0)
 *  ...
 *  But when i execute it prints: Nope...
 *  The values should satisfy the 3 methods,
 *  ------------------------------------------------------------------
 *  Brute force solution:
 *  -247 1573 1274
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

static
int64_t ac_dc[] = {
  10143, 54893, 47109, 24350, 17669, 82062,
};
static
size_t const N = sizeof(ac_dc) / sizeof(*ac_dc);

static
void fail() {
  puts("Nope!");
  exit(EXIT_FAILURE);
}

static
void chow(size_t const sz, int64_t const ac_dc[]) {
  printf("In function %s()\n", __func__);

  for (size_t i_ = 0ul, cc = 1ul; i_ < sz; ++i_) {
    printf("%6" PRId64 "%s", ac_dc[i_], (cc++ % 6 == 0 ? "\n" : ""));
  }
  putchar('\n');
}

static
void linkin_park(int64_t t, int64_t v, int64_t s) {
  printf("In function %s()\n", __func__);
  printf("t = %6" PRId64 ", v = %6" PRId64 ", s = %6" PRId64 "\n", t, v, s);

  printf(">>> %6" PRId64 ", %6" PRId64 ", %6" PRId64 ", %6" PRId64 ", %6" PRId64 "\n",
        (s / 7), (3 * v / 11), (s / 7) + (3 * v / 11), (t - s / 7), (t - s / 7 + 3 * v / 11));
  if (t - s / 7 + 3 * v / 11) {
    fail();
  }
}

static
void metalica(size_t o, int64_t j) {
  printf("In function %s()\n", __func__);

  chow(N, ac_dc);
  int64_t g = j;
  for (; o < N; ++o) {
    if ((o % 2) == 0) {
      continue;
    }
    printf("Index o = %" PRIdPTR "\n", o);
    printf("g = %6" PRId64 "\n", g);
    g += ac_dc[o];
    printf("g = %6" PRId64 "\n", g);
  }
  if (g != 94857) {
    fail();
  }
}

static
void aerosmith(size_t d, int64_t n) {
  printf("In function %s()\n", __func__);
  printf("d = %" PRIdPTR ", n = %" PRId64 "\n", d, n);
  static size_t depth = 0;
  printf("depth: %" PRIdPTR "\n", depth++);

  if (d < N) {
    if (d % 2) {
      puts("..odd");
      aerosmith(++d, n);
    }
    else {
      puts("..even");
      aerosmith(d + 1, n * ac_dc[d]);
    }
  }
  else if (n != 540151794) {
    printf("n = %" PRId64 "\n", n);
    fail();
  }
  --depth;
  printf("depth: %" PRIdPTR "\n", depth);
}

int main() {
  int64_t f, k, z;
  
  printf("Please enter the right three numbers: ");
  fflush(stdout);
  if (scanf("%" SCNd64 " %" SCNd64 " %" SCNd64, &f, &k, &z) != 3) {
    fail();
  }
  else {
    printf("%6" PRId64 " %6" PRId64 " %6" PRId64 "\n", f, k, z);
  }
  chow(N, ac_dc);

  ac_dc[0] = f;
  ac_dc[5] = k;
  ac_dc[4] = z;
  chow(N, ac_dc);

  metalica(0, 14041);
  aerosmith(1, 9);
  linkin_park(f, k, z);
  puts("Exactly! Good job.");

  return EXIT_SUCCESS;
}
