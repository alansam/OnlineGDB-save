//  @see: https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
//  @see: https://www.programiz.com/dsa/quick-sort
//  @see: https://en.wikipedia.org/wiki/Quicksort
//  @see: https://www.cs.princeton.edu/~rs/talks/QuicksortIsOptimal.pdf

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void quicksort(size_t, int *);
void Quicksort(int *, size_t, size_t);
void quickSort(int array[], size_t low, size_t high);

void quicksort_Lomuto(int * AA, size_t lo, size_t hi);
void quicksort_Hoare(int * AA, ssize_t lo, ssize_t hi);

void quicksort_Sedgwick(int ary[], ssize_t lo, ssize_t hi);
void quicksort_Sedgwick_3way(int ary[], ssize_t lo, ssize_t hi);

static
inline
void show(size_t sz, int Aa[]) {
  for (size_t i_ = 0; i_ < sz; ++i_) {
    printf("%4d", Aa[i_]);
  }
  putchar('\n');
}

static
inline
void swap(int * lhs, int * rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void t1(void);
void t2(void);
void t3(void);
void t4(void);
void t5(void);
void t6(void);
void t7(void);

#ifdef DEBUG_
static int * remember_array = NULL;
static size_t remember_array_sz = 0UL;
#endif

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
int main() {
  t1();
  t2();
  t3();
  t4();
  t5();
  t6();
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t1(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

  show(aa_sz, aa);
  quicksort(aa_sz, aa);
  show(aa_sz, aa);
  putchar('\n');

  show(vv_sz, vv);
  quicksort(vv_sz, vv);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t2(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

  show(aa_sz, aa);
  Quicksort(aa, 0, aa_sz - 1);
  show(aa_sz, aa);
  putchar('\n');

  show(vv_sz, vv);
  Quicksort(vv, 0, vv_sz - 1);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t3(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

  show(aa_sz, aa);
  quickSort(aa, 0, aa_sz - 1);
  show(aa_sz, aa);
  putchar('\n');

  show(vv_sz, vv);
  quickSort(vv, 0, vv_sz - 1);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t4(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

  show(aa_sz, aa);
  quicksort_Lomuto(aa, 0, aa_sz - 1);
  show(aa_sz, aa);
  putchar('\n');

  show(vv_sz, vv);
  quicksort_Lomuto(vv, 0, vv_sz - 1);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t5(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

#ifdef DEBUG_
  remember_array = aa;
  remember_array_sz = aa_sz;
#endif
  show(aa_sz, aa);
  quicksort_Hoare(aa, 0, aa_sz - 1);
  show(aa_sz, aa);
  putchar('\n');

#ifdef DEBUG_
  remember_array = vv;
  remember_array_sz = vv_sz;
#endif
  show(vv_sz, vv);
  quicksort_Hoare(vv, 0, vv_sz - 1);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t6(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

  show(aa_sz, aa);
  quicksort_Sedgwick(aa, 0, aa_sz - 1);
  show(aa_sz, aa);
  putchar('\n');

  show(vv_sz, vv);
  quicksort_Sedgwick(vv, 0, vv_sz - 1);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void t7(void) {
  printf("In %s()\n", __func__);

  int aa[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t aa_sz = sizeof(aa) / sizeof(*aa);
  int vv[] = { 1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92, };
  size_t vv_sz = sizeof(vv) / sizeof(*vv);

  show(aa_sz, aa);
  quicksort_Sedgwick_3way(aa, 0, aa_sz - 1);
  show(aa_sz, aa);
  putchar('\n');

  show(vv_sz, vv);
  quicksort_Sedgwick_3way(vv, 0, vv_sz - 1);
  show(vv_sz, vv);
  putchar('\n');
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
void quicksort(size_t len, int * Ary) {
  if (len < 2) { return; }

  int pivot = Ary[len / 2];

  size_t i_, j_;
  for (i_ = 0, j_ = len - 1; ; i_++, j_--) {
    while (Ary[i_] < pivot) { i_++; }
    while (Ary[j_] > pivot) { j_--; }

    if (i_ >= j_) { break; }

    swap(&Ary[i_], &Ary[j_]);
  }

  quicksort(i_, Ary);
  quicksort(len - i_, Ary + i_);
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
size_t Partition(int * Ary, size_t p_, size_t q_) {
  // swap(&Ary[p_ + (rand() % (q_ - p_ + 1))], &Ary[q_]);   // PIVOT = Ary[q_] --- doesn't work

  size_t i_ = p_ - 1;
  for (size_t j_ = p_; j_ <= q_; j_++) {
    if (Ary[j_] <= Ary[q_]) {
      swap(&Ary[++i_], &Ary[j_]);
    }
  }

  return i_;
}

void Quicksort(int * Ary, size_t p_, size_t q_) {
  if(p_ < q_) {
    size_t pivotIndx = Partition(Ary, p_, q_);
 
    Quicksort(Ary, p_, pivotIndx - 1);
    Quicksort(Ary, pivotIndx + 1, q_);
  }
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
// function to find the partition position
size_t partitioN(int array[], size_t low, size_t high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  size_t i_ = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (size_t j_ = low; j_ < high; j_++) {
    if (array[j_] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i_++;

      // swap element at i with element at j
      swap(&array[i_], &array[j_]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i_ + 1], &array[high]);

  // return the partition point
  return (i_ + 1);
}

void quickSort(int array[], size_t low, size_t high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    size_t pi = partitioN(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
/*
 *  Lomuto partition scheme
 *
 *  This scheme is attributed to Nico Lomuto and popularized by Bentley in his book
 *  Programming Pearls and Cormen et al. in their book Introduction to Algorithms.
 *  This scheme chooses a pivot that is typically the last element in the array
 *  The algorithm maintains index i as it scans the array using another index j such
 *  that the elements at lo through i-1 (inclusive) are less than the pivot, and the
 *  elements at i through j (inclusive) are equal to or greater than the pivot.
 *  As this scheme is more compact and easy to understand, it is frequently used in
 *  introductory material, although it is less efficient than Hoare's original scheme
 *  e.g., when all elements are equal. This scheme degrades to O(n2) when the array
 *  is already in order. There have been various variants proposed to boost performance
 *  including various ways to select pivot, deal with equal elements, use other sorting
 *  algorithms such as Insertion sort for small arrays and so on. In pseudocode, a
 *  quicksort that sorts elements at lo through hi (inclusive) of an array A can be
 *  expressed as:
 *
 *  // Sorts a (portion of an) array, divides it into partitions, then sorts those
 *  algorithm quicksort(A, lo, hi) is 
 *    // If indices are in correct order
 *    if lo >= hi || lo < 0 then 
 *      return
 *
 *    // Partition array and get the pivot index
 *    p := partition(A, lo, hi) 
 *  
 *    // Sort the two partitions
 *    quicksort(A, lo, p - 1) // Left side of pivot
 *    quicksort(A, p + 1, hi) // Right side of pivot
 *
 *  // Divides array into two partitions
 *  algorithm partition(A, lo, hi) is 
 *    pivot := A[hi] // Choose the last element as the pivot
 *
 *    // Temporary pivot index
 *    i := lo - 1
 *
 *    for j := lo to hi do 
 *      // If the current element is less than or equal to the pivot
 *      if A[j] <= pivot then 
 *      // Move the temporary pivot index forward
 *        i := i + 1
 *
 *        // Swap the current element with the element at the temporary pivot index
 *        swap A[i] with A[j] 
 *    // Move the pivot element to the correct pivot position (between the smaller and larger elements)
 *    i := i + 1
 *    swap A[i] with A[hi]
 *    return i // the pivot index
 *
 *  Sorting the entire array is accomplished by quicksort(A, 0, length(A) - 1).
 */

/*
 *  Divides array into two partitions
 */
size_t partition_Lomuto(int * AA, size_t lo, size_t hi) {
  int pivot = AA[hi]; // Choose the last element as the pivot

  // Temporary pivot index
  size_t i_ = lo - 1;
  for (size_t j_ = lo; j_ < hi; ++j_) {
    // If the current element is less than or equal to the pivot
    if (AA[j_] <= pivot) {
      // Move the temporary pivot index forward
      i_++;

      // Swap the current element with the element at the temporary pivot index
      swap(&AA[i_], &AA[j_]);
    }
  }

  // Move the pivot element to the correct pivot position (between the smaller and larger elements)
  i_++;
  swap(&AA[i_], &AA[hi]);
  return i_;  // the pivot index
}

/*
 *  Sorts a (portion of an) array, divides it into partitions, then sorts those
 */
void quicksort_Lomuto(int * AA, size_t lo, size_t hi) {
  // If indices are in correct order
  if (lo >= hi || lo < 0) {
    return;
  }

  // Partition array and get the pivot index
  size_t pi = partition_Lomuto(AA, lo, hi);

  // Sort the two partitions
  quicksort_Lomuto(AA, lo, pi - 1);
  quicksort_Lomuto(AA, pi + 1, hi);
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
/*
 *  Hoare partition scheme
 *
 *  The original partition scheme described by Tony Hoare uses two pointers (indices
 *  into the range) that start at both ends of the array being partitioned, then move
 *  toward each other, until they detect an inversion: a pair of elements, one greater
 *  than the bound (Hoare's terms for the pivot value) at the first pointer, and one
 *  less than the bound at the second pointer; if at this point the first pointer is
 *  still before the second, these elements are in the wrong order relative to each
 *  other, and they are then exchanged.[18] After this the pointers are moved inwards,
 *  and the search for an inversion is repeated; when eventually the pointers cross
 *  (the first points after the second), no exchange is performed; a valid partition
 *  is found, with the point of division between the crossed pointers (any entries
 *  that might be strictly between the crossed pointers are equal to the pivot and
 *  can be excluded from both sub-ranges formed). With this formulation it is possible
 *  that one sub-range turns out to be the whole original range, which would prevent
 *  the algorithm from advancing. Hoare therefore stipulates that at the end, the
 *  sub-range containing the pivot element (which still is at its original position)
 *  can be decreased in size by excluding that pivot, after (if necessary) exchanging
 *  it with the sub-range element closest to the separation; thus, termination of
 *  quicksort is ensured.
 *
 *  With respect to this original description, implementations often make minor but
 *  important variations. Notably, the scheme as presented below includes elements
 *  equal to the pivot among the candidates for an inversion (so "greater than or
 *  equal" and "less than or equal" tests are used instead of "greater than" and
 *  "less than" respectively; since the formulation uses do...while rather than
 *  repeat...until which is actually reflected by the use of strict comparison
 *  operators). While there is no reason to exchange elements equal to the bound,
 *  this change allows tests on the pointers themselves to be omitted, which are
 *  otherwise needed to ensure they do not run out of range. Indeed, since at least
 *  one instance of the pivot value is present in the range, the first advancement
 *  of either pointer cannot pass across this instance if an inclusive test is used;
 *  once an exchange is performed, these exchanged elements are now both strictly
 *  ahead of the pointer that found them, preventing that pointer from running off.
 *  (The latter is true independently of the test used, so it would be possible to
 *  use the inclusive test only when looking for the first inversion. However, using
 *  an inclusive test throughout also ensures that a division near the middle is found
 *  when all elements in the range are equal, which gives an important efficiency gain
 *  for sorting arrays with many equal elements.) The risk of producing a non-advancing
 *  separation is avoided in a different manner than described by Hoare. Such a
 *  separation can only result when no inversions are found, with both pointers advancing
 *  to the pivot element at the first iteration (they are then considered to have crossed,
 *  and no exchange takes place). The division returned is after the final position of the
 *  second pointer, so the case to avoid is where the pivot is the final element of the
 *  range and all others are smaller than it. Therefore the pivot choice must avoid the
 *  final element (in Hoare's description it could be any element in the range); this is
 *  done here by rounding down the middle position, using the floor function.[19] This
 *  illustrates that the argument for correctness of an implementation of the Hoare
 *  partition scheme can be subtle, and it is easy to get it wrong.
 *
 *  // Sorts a (portion of an) array, divides it into partitions, then sorts those
 *  algorithm quicksort(A, lo, hi) is 
 *    if lo >= 0 && hi >= 0 && lo < hi then
 *      p := partition(A, lo, hi) 
 *      quicksort(A, lo, p) // Note: the pivot is now included
 *      quicksort(A, p + 1, hi) 
 *  
 *  // Divides array into two partitions
 *  algorithm partition(A, lo, hi) is 
 *    // Pivot value
 *    pivot := A[ floor((hi + lo) / 2) ] // The value in the middle of the array
 *  
 *    // Left index
 *    i := lo - 1 
 *  
 *    // Right index
 *    j := hi + 1
 *  
 *    loop forever 
 *      // Move the left index to the right at least once and while the element at
 *      // the left index is less than the pivot
 *      do i := i + 1 while A[i] < pivot
 *      
 *      // Move the right index to the left at least once and while the element at
 *      // the right index is greater than the pivot
 *      do j := j - 1 while A[j] > pivot
 *  
 *      // If the indices crossed, return
 *      if i ≥ j then return j
 *      
 *      // Swap the elements at the left and right indices
 *      swap A[i] with A[j]
 *
 *  The entire array is sorted by quicksort(A, 0, length(A) - 1).
 */

#ifdef DEBUG_
static
inline
void show_range(int * AA, size_t lo, size_t hi) {
  printf("lo:%4zu, hi:%4zu, AA: ", lo, hi);
  for (size_t i_ = lo; i_ <= hi; ++i_) {
    printf("%4d", AA[i_]);
  }
  putchar('\n');
}
#endif

/*
 *  Divides array into two partitions
 */
ssize_t partition_Hoare(int * AA, ssize_t lo, ssize_t hi) {
#ifdef DEBUG_
  printf("\nbefore: ");
  show(remember_array_sz, remember_array);
#endif
  // Pivot value
  int pivot = AA[ ((hi + lo) / 2) ]; // The value in the middle of the array
  // printf("pivot: %4d\n", pivot);

  // Left index
  ssize_t i_ = lo - 1;

  // Right index
  ssize_t j_ = hi + 1;

  while (true) {
    // Move the left index to the right at least once and while the element at
    // the left index is less than the pivot
    do { i_++; } while (AA[i_] < pivot);

    // Move the right index to the left at least once and while the element at
    // the right index is greater than the pivot
    do { j_--; } while (AA[j_] > pivot);

    // If the indices crossed, return
    if (i_ >= j_) {
#ifdef DEBUG_
      printf("index: %4zu\n", j_);
      printf("after : ");
      show(remember_array_sz, remember_array);
#endif
      return j_;
    }

    // Swap the elements at the left and right indices
    swap(&AA[i_], &AA[j_]);
  }
}

/*
 *  Sorts a (portion of an) array, divides it into partitions, then sorts those
 */
void quicksort_Hoare(int * AA, ssize_t lo, ssize_t hi) {
  if (/*lo >= 0 && hi >= 0 &&*/ lo < hi) {
    ssize_t pi = partition_Hoare(AA, lo, hi);
    quicksort_Hoare(AA, lo, pi); // Note: the pivot is now included
    quicksort_Hoare(AA, pi + 1, hi);
  }
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
/*
 *                          QUICKSORT IS OPTIMAL
 *                            Robert Sedgewick
 *                            Jon Bentley
 *
 *  Quicksort
 *
 * void quicksort(Item a[], int l, int r)
 * { int i = l-1, j = r; Item v = a[r];
 *   if (r <= l) return;
 *   for (;;)
 *   {
 *     while (a[++i] < v) ;
 *     while (v < a[--j]) if (j == l) break;
 *     if (i >= j) break;
 *     exch(a[i], a[j]);
 *   }
 *   exch(a[i], a[r]);
 *   quicksort(a, l, i-1);
 *   quicksort(a, i+1, r);
 * }
 */
void quicksort_Sedgwick(int ary[], ssize_t lo, ssize_t hi) {
  ssize_t i_ = lo - 1, j_ = hi;

  int pivot = ary[hi];
  if (hi <= lo) { return; }

  for (;;) {
    while (ary[++i_] < pivot) ;
    while (pivot < ary[--j_]) {
      if (j_ == lo) { break; }
    }
    if (i_ >= j_) { break; }

    swap(&ary[i_], &ary[j_]);
  }
  swap(&ary[i_], &ary[hi]);

  quicksort_Sedgwick(ary, lo, i_ - 1);
  quicksort_Sedgwick(ary, i_ + 1, hi);
}

// ----+----!----+----!----+----!----+----!----+----!----+----!----+----!----+----!
/*
 *                          QUICKSORT IS OPTIMAL
 *                            Robert Sedgewick
 *                            Jon Bentley
 *
 *  Quicksort with 3-way partitioning
 *
 * void quicksort(Item a[], int l, int r)
 * { int i = l-1, j = r, p = l-1, q = r; Item v = a[r];
 *   if (r <= l) return;
 *   for (;;)
 *   {
 *     while (a[++i] < v) ;
 *     while (v < a[--j]) if (j == l) break;
 *     if (i >= j) break;
 *     exch(a[i], a[j]);
 *     if (a[i] == v) { p++; exch(a[p], a[i]); }
 *     if (v == a[j]) { q--; exch(a[j], a[q]); }
 *   }
 *   exch(a[i], a[r]); j = i-1; i = i+1;
 *   for (k = l; k < p; k++, j--) exch(a[k], a[j]);
 *   for (k = r-1; k > q; k--, i++) exch(a[i], a[k]);
 *   quicksort(a, l, j);
 *   quicksort(a, i, r);
 * }
 */
void quicksort_Sedgwick_3way(int ary[], ssize_t lo, ssize_t hi) {
  ssize_t i_ = lo - 1;
  ssize_t j_ = hi;
  ssize_t p_ = lo - 1;
  ssize_t q_ = hi;

  int pivot = ary[hi];

  if (hi <= lo) { return; }

  for (;;) {
    while (ary[++i_] < pivot);
    while (pivot < ary[--j_]) {
      if (j_ == lo) { break; }
    }

    if (i_ >= j_) { break; }

    swap(&ary[i_], &ary[j_]);

    if (ary[i_] == pivot) {
      p_++;
      swap(&ary[p_], &ary[i_]);
    }

    if (pivot == ary[j_]) {
      q_--;
      swap(&ary[j_], &ary[q_]);
    }
  }

  swap(&ary[i_], &ary[hi]);
  j_ = i_ - 1;
  i_ = i_ + 1;

  for (ssize_t k_ = lo; k_ < p_; k_++, j_--) {
    swap(&ary[k_], &ary[j_]);
  }

  for (ssize_t k_ = hi - 1; k_ > q_; k_--, i_++) {
    swap(&ary[i_], &ary[k_]);
  }

  quicksort_Sedgwick_3way(ary, lo, j_);
  quicksort_Sedgwick_3way(ary, i_, hi);
}

