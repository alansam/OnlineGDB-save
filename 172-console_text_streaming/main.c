#include <stdio.h>
#include <unistd.h> //usleep

int main() {
  char const startup[] =  { "Sweet text animation streaming to the console" };
  char const nexttext[] = { "but wait, there's more... " };
  size_t const size = sizeof(startup);
  for (int a = 0; a < size; a++) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("%c", startup[a]);
    usleep(50000);
  }

  for (int a = 0; a < size; a++) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("%c\b", 0);
    usleep(50000);
  }

  size_t const newsize = sizeof(nexttext);
  for (int b = 0; b < newsize; b++) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("%c", nexttext[b]);
    usleep(50000);
  }

  return 0;
}

