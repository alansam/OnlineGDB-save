/*
 * C Program To Sort array in ascending order using Shell Sort.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

static inline
void swap(int * a, int * b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void shell(int n, int array[n]);

int main(int argc, char const * argv[]) {
	int array[SIZE];

	printf("%s - %i\n", argv[0], SIZE);

	// create an array of random ints 
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
	  array[i] = rand();
	}

	// output array before
	for (int i = 0, cc = 0; i < SIZE; i++) {
	  printf("%12i%s", array[i], (++cc % 10 == 0 ? "\n" : ""));
	}
	putchar('\n');

	shell(SIZE, array);

	// output array after
	putchar('\n');
	for (int i = 0, cc = 0; i < SIZE; i++) {
	  printf("%12i%s", array[i], (++cc % 10 == 0 ? "\n" : ""));
	}
	putchar('\n');

	return 0;
}

void shell(int n, int array[n]) {
	for (int i = n / 2; i > 0; i /= 2) {
		for (int j = i; j < n; j++) {
			for (int k = j - i; k >= 0; k = k - i) {
				if (array[k + i] > array[k]) {
				  break;
				}
				else {
				  swap(&array[k], &array[k + i]);
				}
			}
		}
	}
}

