/* Hello members, kindly help. Why am I getting invalid pointer in the output?  Thanks in advance... */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char * message;
} HELLO;

HELLO * newMessage(char * msg);
void deleteMessage(HELLO * hello_instance);
bool isAllocated(void * ptr);
void setMessage(HELLO * hello_instance, char * new_msg);
char * getMessage(HELLO * hello_instance);
void printMessage(HELLO * hello_instance);

int main() {
  HELLO * chitty;
  char * msg;
  chitty = newMessage("Hello World!");
  printf("HELLO and its message: %p, %p\n", (void *) chitty, (void *) chitty->message);
  msg = getMessage(chitty);
  printf("Outer Message: %s\n\n", msg);
  printMessage(chitty);
  deleteMessage(chitty);
  // printf("Outer Message: %s\n\n", msg);
  return 0;
}

HELLO * newMessage(char * msg) {
  fprintf(stderr, "In %s()\n", __func__);
  HELLO * hello_instance;
  hello_instance = malloc(sizeof(HELLO));
  if (isAllocated(hello_instance)) {
    if (isAllocated(msg)) {
      setMessage(hello_instance, msg);
      return hello_instance;
    }
    else {
      return NULL;
    }
  }
  else {
    printf("Error: Memory allocation failed.\n");
    return NULL;
  }
}

bool isAllocated(void * ptr) {
  fprintf(stderr, "In %s()\n", __func__);
  // if (ptr) {
  //   return true;
  // }
  // return false;
  return (ptr != NULL) ? true : false;
}

void deleteMessage(HELLO * hello_instance) {
  fprintf(stderr, "In %s()\n", __func__);
  if (isAllocated(hello_instance)) {
    if (isAllocated(hello_instance->message)) {
      printf("Deleting message instance.\n");
      free(hello_instance->message);
      hello_instance->message = NULL;
    }
    printf("Deleting main instance.\n\n");
    free(hello_instance);
    hello_instance = NULL;
  }
  else {
    printf("Failed to delete instance.\n");
  }
}

void setMessage(HELLO * hello_instance, char * new_msg) {
  fprintf(stderr, "In %s()\n", __func__);
  int size = strlen(new_msg);
  hello_instance->message = /*(char *)*/ malloc(sizeof(char) * size + 1);
  if (isAllocated(hello_instance->message)) {
    printf("Message is set successfully!\n");
    printf("Characters: %d\n", size);
    // hello_instance->message = new_msg;
    strcpy(hello_instance->message, new_msg);
  }
  else {
    printf("Error: Failed to set message.\n");
    hello_instance->message = NULL;
  }
}

char * getMessage(HELLO * hello_instance) {
  fprintf(stderr, "In %s()\n", __func__);
  if (isAllocated(hello_instance)) {
    if (isAllocated(hello_instance->message)) {
      return hello_instance->message;
    }
    else {
      return NULL;
    }
  }
  return NULL;
}

void printMessage(HELLO * hello_instance) {
  fprintf(stderr, "In %s()\n", __func__);
  if (isAllocated(hello_instance->message)) {
    printf("Message: %s\n", hello_instance->message);
  }
  else {
    printf("Error: No message to display.\n");
  }
}
  
/*
 *  OUTPUT
 *    Message is set successfuly!
 *    Characters: 12
 *    Message: Hello World!
 *    Deleting message instance.
 *    free(): invalid pointer
 */

