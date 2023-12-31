// IS this code okay for insertions sort? it gives correct awnser

#include <iostream>
#include <iomanip>
#include <vector>

void insert(int array[], int size) { 
  for (int j = 0; j < size; j++) {
    for (int i = 1; i < size; i++) {
      if (array[i] < array[i - 1]) {
        std::swap(array[i], array[i - 1]);
      }
    }
  }
}

/*
 *  pseudocode 
 *  @see: https://en.wikipedia.org/wiki/Insertion_sort
 *
 *  i ← 1
 *  while i < length(A)
 *    j ← i
 *    while j > 0 and A[j-1] > A[j]
 *      swap A[j] and A[j-1]
 *      j ← j - 1
 *    end while
 *    i ← i + 1
 *  end while
 *
 *  RosettaCode
 *  @see: https://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort#top-page
 *
 *  function insertionSort(array A)
 *    for i from 1 to length[A]-1 do
 *      value := A[i] 
 *      j := i-1
 *      while j >= 0 and A[j] > value do
 *        A[j+1] := A[j]
 *        j := j-1
 *      done
 *      A[j+1] = value
 *    done
 */
void insert(std::vector<int> & vect) {
  for (auto i_ { 1ul }; i_ < vect.size() - 1ul; ++i_) {
    int value = vect[i_];
    auto j_ = i_ - 1ul;
    while (j_ > 0ul && vect[j_] > value) {
      vect[j_ + 1] = vect[j_];
      j_--;
    }
    vect[j_ + 1] = value;
  }
}

int main() {
  auto show = [](auto const & ary) {
    for (auto val : ary) {
      std::cout << std::setw(4) << val;
    }
    std::cout << std::endl;
  };

  int array[] = { 12, 71, 22, 67, 45, };
  size_t constexpr size = sizeof array / sizeof *array;

  show(array);
  insert(array, size);
  show(array);

  std::vector<int> vect { 102, 701, 202, 607, 405, };

  show(vect);
  insert(vect);
  show(vect);

  return 0;
}
