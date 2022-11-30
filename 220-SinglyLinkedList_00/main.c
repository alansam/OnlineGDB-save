#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
  Node * next;
  int data;
};

Node * add(Node ** parent, int data);
// TODO: Add method Node * del(Node ** parent, int data);
Node * show(Node ** parent);
Node * erase(Node ** parent);

//  Program EPA
int main(int argc, char const * argv[]) {
  if (argc >= 0) {
    printf("Running %s\n", argv[0]);
  }
  else {
    puts("Unknown program name");
  }

  Node * root = NULL;

  add(&root, 5);
  add(&root, 15);
  add(&root, 150);
  show(&root);
  erase(&root);

  return EXIT_SUCCESS;
}

Node * add(Node ** parent, int data) {
  printf("In %s\n", __func__);
  Node * next = NULL;
  Node * prev = *parent;

  if (*parent == NULL) {
    next = malloc(sizeof **parent);
    if (next == NULL) {
      fprintf(stderr, "Unable to allocate new Node\n");
      exit(EXIT_FAILURE);
    }
    printf("Adding node %p\n", (void *) next);
    *parent = next;
    next->next = NULL;
    next->data = data;
  }
  else {
    while (prev->next != NULL) {
      prev = prev->next;
    }
    next = malloc(sizeof *next);
    if (next == NULL) {
      fprintf(stderr, "Unable to allocate new Node\n");
      exit(EXIT_FAILURE);
    }
    printf("Adding node %p\n", (void *) next);
    prev->next = next;
    next->next = NULL;
    next->data = data;
  }

  return next;
}

Node * show(Node ** parent) {
  printf("In %s\n", __func__);
  Node * next = *parent;
  while (next != NULL) {
    printf("%p: %5d\n", (void *) next, next->data);
    next = next->next;
  }

  return next;
}

Node * erase(Node ** parent) {
  printf("In %s\n", __func__);
  Node * next = *parent;
  while (next != NULL) {
    Node * current = next;
    next = current->next;
    *parent = next;
    printf("Removing node %p\n", (void *) current);
    free(current);
  }

  return next;
}
