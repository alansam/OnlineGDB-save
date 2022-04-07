
#include <stdio.h>
#include <string.h>

#define __BEGIN_NAMESPACE_STD namespace std { \
extern "C" {
#define __END_NAMESPACE_STD } \
}
  
typedef enum { RED, BLACK } nodeColor;
typedef char T[80];

typedef struct rbt {
  struct rbt *left; /* left child */
  struct rbt *right; /* right child */
  struct rbt *parent; /* parent */
  nodeColor color; /* node color (BLACK, RED) */
  T data; /* data stored in node */
} rbt_t;

// <---- line 28    |     this is starting from line 29 ---->
#ifdef __cplusplus
__BEGIN_NAMESPACE_STD
#endif

extern void insertNode (rbt_t ** root, rbt_t *);
extern void deleteNode (rbt_t **, rbt_t *);
extern void initRoot (rbt_t **);
extern rbt_t *smallestNode (rbt_t **);

#ifdef __cplusplus
__END_NAMESPACE_STD
#endif

int main() {
  rbt_t RBT = { NULL, NULL, NULL, RED,  };
  strcpy(RBT.data, "Hello World");

  printf("%s\n", RBT.data);
  return 0;
}


