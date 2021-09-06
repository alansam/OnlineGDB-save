
#include <stdio.h>
#include <stdint.h>

typedef struct IArray IArray;
struct IArray {
  size_t const size;
  int const * data;
};

IArray longest_seq(size_t nr, int const sample[nr]);

/*
 *  MARK: show()
 */
static
inline
void show(size_t nr, int const ary[nr]) {
  for (size_t x_ = 0; x_ < nr; ++x_) {
    printf("%4d", ary[x_]);
  }
  putchar('\n');
}

/*
 *  MARK: main()
 */
int main() {

  int32_t const s0[] = { 23, 65, 15, 43, 10, 25, 35, 42, 18, };
  size_t const s0_e = sizeof(s0) / sizeof(*s0);
  int32_t const s1[] = { 0, };
  size_t const s1_e = sizeof(s1) / sizeof(*s1);
  int32_t const s2[] = { 0, 0, 0, 0, };
  size_t const s2_e = sizeof(s2) / sizeof(*s2);
  int32_t const s3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
  size_t const s3_e = sizeof(s3) / sizeof(*s3);
  int32_t const s4[] = { 0, 1, 2, 3, 4, 3, 2, 1, 0, };
  size_t const s4_e = sizeof(s4) / sizeof(*s4);
  int32_t const s5[] = { 1, 2, 3, 0, 1, 2, 3, 4, };
  size_t const s5_e = sizeof(s5) / sizeof(*s5);
  int32_t const s6[] = { 5, 4, 3, 2, 1, 0, };
  size_t const s6_e = sizeof(s6) / sizeof(*s6);
  int32_t const s7[] = { 5, 6, };
  size_t const s7_e = sizeof(s7) / sizeof(*s7);

  IArray const samples[] = {
    { .size = s0_e, .data = s0, },
    { .size = s1_e, .data = s1, },
    { .size = s2_e, .data = s2, },
    { .size = s3_e, .data = s3, },
    { .size = s4_e, .data = s4, },
    { .size = s5_e, .data = s5, },
    { .size = s6_e, .data = s6, },
    { .size = s7_e, .data = s7, },
  };
  size_t const samples_e = sizeof(samples) / sizeof(*samples);

  for (size_t s_ = 0; s_ < samples_e; ++s_) {
    show(samples[s_].size, samples[s_].data);

    IArray rslt = longest_seq(samples[s_].size, samples[s_].data);

    show(rslt.size, rslt.data);

    putchar('\n');
  }

  return 0;
}

/*
 *  MARK: longest_seq()
 */
IArray longest_seq(size_t nr, int const sample[nr]) {
  uint32_t count = 1U;
  uint32_t maxcount = 1U;
  int32_t const * seq = sample;
  int32_t const * longseq = sample;

  if (nr > 1) {
    for (size_t s_ = 1ULL; s_ < nr; ++s_) {
      if (sample[s_ - 1] < sample[s_]) {
        count++;
      }
      else if (count > maxcount) {
        maxcount = count;
        longseq = seq;
        count = 1u;
        seq = &sample[s_];
      }
      else {
        count = 1u;
        seq = &sample[s_];
      }
    }

    if (count > maxcount) {
      maxcount = count;
      longseq = seq;
    }
  }
  else {
    maxcount = nr;
    longseq = sample;
  }

  IArray rslt = { .size = maxcount, .data = longseq, };
  return rslt;
}
