
#if !defined(__APPLE__) && !defined(_GNU_SOURCE)
# define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATA 400
#define MAX_STR 9

//  MARK: Constants
static
size_t const max_data = MAX_DATA;
static
size_t const max_str = MAX_STR;

//  MARK: function prototypes
void do_qsort(void);
void do_qsort_r(void);
int * arrayinit(int data[max_data]);
void display(int data[max_data], size_t cols);
size_t setupstrings(char const * strings[max_str]);
void displaystrings(char const * strings[max_str], size_t cols);

//  MARK: sorting callback prototypes
int int_compare(void const * p1, void const * p2);

//  TODO: <<!!!>> Check MacOS/BSD vs. Linux/ISO implementations!
#ifdef __APPLE__
int int_compare_r(void * thunkIn, void const * aIn, void const * bIn);
#else
int int_compare_r(void const * aIn, void const * bIn, void * thunkIn);
#endif

/*
 *  MARK: main()
 */
int main() {
  printf("014-qsort_r test.\n");

  puts("Doing qsort");
  do_qsort();

  puts("Doing qsort_r");
  do_qsort_r();

  return 0;
}

/*
 *  MARK: do_qsort()
 */
void do_qsort(void) {
  printf("Fnuction: %s\n", __func__);

  int data[max_data];
  int * pdata;
  
  pdata = arrayinit(data);
  display(pdata, 10);
  qsort(&data, max_data, sizeof(data[0]), int_compare);
  display(pdata, 10);

  return;
}

/*
 *  MARK: do_qsort_r()
 */
void do_qsort_r(void) {
  printf("Fnuction: %s\n", __func__);
  
  int data[max_data];
  int * pdata;

  enum thnk { ASC = 0, DESC, };
  for (int thunk = ASC; thunk <= DESC; ++thunk) {
    switch (thunk) {
      default:
      case ASC:
        puts("Sort ascending");
        break;
        
      case DESC:
        puts("Sort descending");
        break;
    }

    pdata = arrayinit(data);
    display(pdata, 10);
    //  TODO: <<!!!>> Check MacOS/BSD vs. Linux/ISO implementations!
#ifdef __APPLE__
    qsort_r(&data, max_data, sizeof(data[0]), (void *) &thunk, int_compare_r);
#else
    qsort_r(&data, max_data, sizeof(data[0]), int_compare_r, (void *) &thunk);
#endif
    display(pdata, 10);
  }

  return;
}

//  MARK: - Helper functions

/*
 *  MARK: arrayinit()
 */
int * arrayinit(int data[max_data]) {

  int rupper = 200;
  int rlower = -200;
  for (size_t e_ = 0; e_ < max_data; ++e_) {
    long rn = (random() % (rupper - rlower - 1)) + rlower;
    data[e_] = (int) rn;
  }

  return data;
}

/*
 *  MARK: display()
 */
void display(int data[max_data], size_t cols) {

  for (size_t i_ = 0; i_ < max_data; ++i_) {
    printf("%6d%c",
       data[i_],
       (i_ % cols == cols - 1 || i_ == (size_t) max_data - 1) ? '\n' : ' ');
  }
  putchar('\n');

  return;
}

//  MARK: - Sort comparitor callbacks
/*
 *  Custom comparison function that  compares 'int' values through pointers
 *  passed by qsort(3).
 *  @see: https://www.freebsd.org/cgi/man.cgi?query=qsort&sektion=3&manpath=freebsd-release-ports
 */
int int_compare(void const * p1, void const * p2) {

  int left =  *(int const *) p1;
  int right = *(int const *) p2;

  return ((left > right) - (left < right));
}

// If you want to use a single compare function that changes behavior based on
// another argument, you can use qsort_r() and add an additional parameter to your
// comparison function (a void* variable called "thunk").
//
// Also, if your compare function changes a global variable and you could have
// multiple threads running qsort and touching that same global variable at the
// same time---there could be problems! qsort_r() would allow you to use one
// compare function, but to tell each thread what data it should be working with
// (besides the actual data that is getting sorted).
//
//  TODO: <<!!!>> Check MacOS/BSD vs. Linux/ISO implementations!
#ifdef __APPLE__
int int_compare_r(void * thunkIn, void const * aIn, void const * bIn) {
#else
int int_compare_r(void const * aIn, void const * bIn, void * thunkIn) {
#endif

  int a     = *((int *) aIn);
  int b     = *((int *) bIn);
  int thunk = *((int *) thunkIn);
  int returnVal;

  if (thunk == 0) {
    //  sort ascending
    if (a < b)      { returnVal = -1; }
    else if (a > b) { returnVal = 1; }
    else            { returnVal = 0;}
  }
  else {
    //  sort descending
    if(a > b)       { returnVal = -1; }
    else if(a < b)  { returnVal = 1; }
    else            { returnVal = 0; }
  }

  return returnVal;
}

