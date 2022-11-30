
#include <stdint.h>
#include <stdbool.h>

#ifndef dups_h_
#define dups_h_

typedef struct dups dups;
struct dups {
  dups * pbck;
  dups * pfwd;
  uint16_t id;
  bool flag;
  char name[80];
};

#endif
