/*
 * Hint, use jot or seq to generate input:
 * E.G:
 * MacOS:
 * ( jot -r 100 ; jot 1 -1 ) | ../bin/Odds_n_Evens 2>/dev/null
 * Linux:
 * seq 101 -1 | ../bin/Odds_n_Evens 2>/dev/null
 */

#include <stdio.h>

#define ARY_MAX 100

static
inline
void show_array(size_t const mx, int const even_odd[ARY_MAX]) {
  size_t const cc_max = 10;
  for (size_t eo = 0, cc = 0; eo < mx; ++eo) {
    printf(" %11d%s", even_odd[eo], (++cc % cc_max == 0 ? "\n" : ""));
  }
  putchar('\n');
}

int main() {
  int evens[ARY_MAX] = { 0, };
  size_t evens_mx = 0;
  int odds[ARY_MAX] = { 0, };
  size_t odds_mx = 0;

  printf("enter list of integers (limit %d): ", ARY_MAX);
  fflush(stdout);
  int nr;
  do {
    scanf("%i", &nr);
    if (nr != -1) { //  depends if -1 should be included in list or not
      if (nr % 2 == 0) {
        evens[evens_mx++] = nr;
      }
      else {
        odds[odds_mx++] = nr;
      }
    }
    // catch condition where max odd or max even nrs is exceeded
    if (evens_mx + odds_mx == ARY_MAX) {
      fprintf(stderr, "\ntoo many numbers\n");
      break;
    }
  } while (nr != -1);

  printf("\nthere are %zu even and %zu odd numbers\n", evens_mx, odds_mx);
  if (evens_mx > 0) {
    printf("Even numbers:\n");
    show_array(evens_mx, evens);
    putchar('\n');
  }
  if (odds_mx > 0) {
    printf("Odd numbers:\n");
    show_array(odds_mx, odds);
    putchar('\n');
  }

  /*
  int a[10] = { 0, }, i, even=0, odd=0;
  printf("Enter 10 integer numbers");
  for (i=0; i<10;i++)
  {
    scanf("%d",&a[i]); 
  }

  printf("\n Even numbers in arrays are....\n");
  for (i=0; i<10; i++)
  {
    if (a[i] % 2 == 0)
    {
      printf("%d\n",a[i]);
      even++;
    }
  }

  printf("\n Odd numbers in the arrays are...\n");
  for (i=0; i<10; i++)
  {
    if (a[i] % 2 != 0)
    {
      printf("%d\n",a[i]);
      odd++;
    }
  }
  printf("\n\n Total even numbers: %d",even);
  printf("\n\n Total odd numbers: %d",odd);
  */
}