
#include <stdio.h>

typedef union Uu Uu;
union Uu {
  double dd;
  long ll;
  void * pp;
  unsigned char cc[sizeof(double)];
};

inline
static
void le(unsigned char * cc, size_t sz) {
  for(size_t d_ = 0; d_ < sz; ++d_) {
    printf("%02x ", cc[d_]);
  }
}

inline
static
void be(unsigned char * cc, size_t sz) {
  for (size_t c_ = sz; c_ != 0; --c_) {
    printf("%02x ", cc[c_ - 1]);
  }
}

inline
static
void pshow(double * pdd, long * pll, size_t sz, unsigned char * pcc) {
  printf("%12.6f %22ld, %22a %#018lx\n", *pdd, *pll, *pdd, *pll);
  printf("%15s", "Little-endian: ");
  le(pcc, sz);
  putchar('\n');
  printf("%15s", "Big-endian: ");
  be(pcc, sz);
  putchar('\n');
}

inline
static
void show(double dd, long ll, Uu uu) {
  // printf("%f %ld\n", dd, ll);
  // printf("%f %ld\n", uu.dd, uu.ll);

  puts("Casts:");
  printf("%f %ld, %a %#018lx\n", dd, ll, dd, ll);
  unsigned char * cc = (unsigned char *) &dd;
  le(cc, sizeof(double));
  putchar(':');
  putchar(' ');
  be(cc, sizeof(double));
  putchar('\n');
  cc = (unsigned char *) &ll;
  le(cc, sizeof(long));
  putchar(':');
  putchar(' ');
  be(cc, sizeof(long));
  putchar('\n');

  puts("Union:");
  printf("%f %ld, %a %#018lx\n", uu.dd, uu.ll, uu.dd, uu.ll);
  //  little-endian
  le(uu.cc, sizeof(Uu));
  putchar(':');
  putchar(' ');
  //  big-endian
  be(uu.cc, sizeof(Uu));
}

int main() {
  double dd = 1024.0;
  long ll = (long) dd;

  Uu uu = { .dd = 1024.0 };

  // show(dd, ll, uu);

  // putchar('\n');
  // putchar('\n');

  pshow(&dd, (long *) &dd, sizeof(dd), (unsigned char *) &dd);
  pshow((double *) &ll, &ll, sizeof(ll), (unsigned char *) &ll);
  pshow(&uu.dd, &uu.ll, sizeof(uu.dd), uu.cc);
  uu.ll = 1024l;
  pshow(&uu.dd, &uu.ll, sizeof(uu.dd), uu.cc);
  putchar('\n');

  ll = 2048l;
  dd = (double) ll;
  uu.ll = 2048l;

  // show(dd, ll, uu);
  // putchar('\n');
  // putchar('\n');

  pshow(&dd, (long *) &dd, sizeof(dd), (unsigned char *) &dd);
  pshow((double *) &ll, &ll, sizeof(ll), (unsigned char *) &ll);
  pshow(&uu.dd, &uu.ll, sizeof(uu.dd), uu.cc);
  uu.dd = 1024.0;
  pshow(&uu.dd, &uu.ll, sizeof(uu.dd), uu.cc);
  putchar('\n');

  return 0;
}
