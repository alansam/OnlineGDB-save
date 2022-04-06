
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

bool is_prime(int number) {
  // calculate prime number
  bool prime = true;
  for (int i_ = 2; i_ <= sqrt(number); ++i_) {
    if (number % i_ == 0) {
      prime = false;
      break;
    }
  }
  return prime;
}

int main() {
  bool reiterate = true;
  char * line = NULL;
  ssize_t line_sz = 0;

  do {
    char choice;
    int number;
    printf("Enter a number [or 'E' to exit.]\n");
    ssize_t glx = getline(&line, &line_sz, stdin);
    if (glx == -1) {
      puts("I/O error in getline()");
      exit(EXIT_FAILURE);
    }

    printf("%zu: %s\n--\n", glx, line);
    sscanf(line, "%c", &choice);
    printf("%c\n..\n", choice);

    if (isalnum(choice)) {
      if (isalpha(choice)) {
        if (toupper(choice) == 'E' || toupper(choice) == 'Q') {
          puts("stopping...");
          reiterate = false;
        }
      }
      else {
        sscanf(line, "%d", &number);
        printf("%d\n..\n", number);
        if (is_prime(number)) {
          printf("%d is prime.\n\n", number);
        }
      }
    }
  } while (reiterate);

  free(line);

  return 0;
}

