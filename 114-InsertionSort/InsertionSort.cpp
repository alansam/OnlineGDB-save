/*
 *  Sorting algorithms/Insertion sort
 *
 *  @see: https://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort#C
 *  @see: https://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort#C.2B.2B
 *  @see: https://en.cppreference.com/w/cpp/algorithm/rotate
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <memory>
#ifdef SHOW_TYPE_
#include <typeinfo>
#endif /* SHOW_TYPE_ */
#include <cstdio>

/*
 *  MARK: insertion_sort()
 */
void insertion_sort(int * ary, size_t nr) {
	for (size_t i_ = 1; i_ < nr; ++i_) {
		int tmp = ary[i_];
		size_t j_ = i_;
		while (j_ > 0 && tmp < ary[j_ - 1]) {
			ary[j_] = ary[j_ - 1];
			--j_;
		}
		ary[j_] = tmp;
	}
}

/*
 *  MARK: Template insertion_sort_plus()
 */
template <typename RandomAccessIterator, typename Predicate>
void insertion_sort_plus(RandomAccessIterator begin, RandomAccessIterator end, Predicate pdct) {
  for (auto i_ = begin; i_ != end; ++i_) {
    std::rotate(std::upper_bound(begin, i_, *i_, pdct), i_, i_ + 1);
  }
}

/*
 *  MARK: Template insertion_sort_plus()
 */
template <typename RandomAccessIterator>
void insertion_sort_plus(RandomAccessIterator begin, RandomAccessIterator end) {
  insertion_sort_plus(begin,
                      end,
                      std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

/*
 *  MARK: insertionSort_ix()
 *
 *  This function seems to be giving problems.
 */
int insertionSort_ix(const int * unsorted, const size_t elements, int *& sorted) {
  for (size_t i_ = 0; i_ < elements; i_++) {
    sorted[i_] = unsorted[i_];
  }
  size_t iterations = 0;

  for (size_t i_ = 1; i_ < elements; i_++) {
    int next_item = sorted[i_];
    size_t location = i_;

    while (location > 0 && sorted[location - 1] > next_item) {
      sorted[location] = sorted[location - 1];
      iterations++;
      location--;
    }
    sorted[location] = next_item;
  }
  return iterations;
}

/*
 *  MARK: insertionSort()
 *
 *  This function seems to be giving problems.
 */
int insertionSort(const int * unsorted, const size_t elements, int *& sorted) {
  for (size_t i_ = 0; i_ < elements; i_++) {
    *(sorted + i_) = *(unsorted + i_);
  }
  size_t iterations = 0;

  for (size_t i_ = 1; i_ < elements; i_++) {
    int next_item = *(sorted + i_);
    size_t location = i_;

    while ((location > 0) && (*(sorted + location - 1) > next_item)) {
      *(sorted + location) = *(sorted + location - 1);
      iterations++;
      location--;
    }
    *(sorted + location) = next_item;
  }
  return iterations;
}

/*
 *  MARK: show()
 */
inline
static
void show(int const * ary, size_t nr) {
  for (size_t i_ = 0; i_ < nr; i_++) {
    printf("%4d%c", ary[i_], i_ == nr - 1 ? '\n' : ',');
  }
}

/*
 *  MARK: copy()
 */
inline
static
void copy(size_t nr, int const * src, int * tgt) {
  for (size_t i_ = 0; i_ < nr; ++i_) {
    tgt[i_] = src[i_];
  }
}

/*
 *  MAEK: main()
 */
int main() {
  int const sample[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782, 1, };
  size_t nr = sizeof sample / sizeof sample[0];
  int ary[32] = { 0, };

  //  ==========================================================================
  std::cout << "rosettacode.org C\n";
  copy(nr, sample, ary);
  show(ary, nr);
  insertion_sort(ary, nr);
  show(ary, nr);
  std::cout << std::endl;

  //  ==========================================================================
  std::cout << "rosettacode.org C++\n";
  copy(nr, sample, ary);
  show(ary, nr);
  insertion_sort_plus(std::begin(ary), std::begin(ary) + nr);
  std::copy(std::begin(ary), std::begin(ary) + nr, std::begin(ary));
  show(ary, nr);
  std::cout << std::endl;

  //  ==========================================================================
  // auto ap = new int[nr];
  auto sap = std::make_unique<int[]>(nr);
  auto ap = sap.get();
#ifdef SHOW_TYPE_
  std::cout << typeid(nap).name() << std::endl;
  std::cout << typeid(sap).name() << std::endl;
  std::cout << typeid(sap.get()).name() << std::endl;
  std::cout << typeid(ap).name() << std::endl;
#endif /* SHOW_TYPE_ */

  std::cout << "Insertion Sort with index\n";
  show(sample, nr);
  insertionSort_ix(sample, nr, ap);
  show(ap, nr);
  std::cout << std::endl;

  //  ==========================================================================
  std::cout << "Insertion Sort with pointers\n";
  show(sample, nr);
  insertionSort(sample, nr, ap);
  show(ap, nr);
  std::cout << std::endl;

  // delete [] ap;

  return 0;
}
