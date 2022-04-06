
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

void run(void);
void again(void);
void againagain(void);
void notagain(void);
void notagainagain(void);

int main() {

  run();
  again();
  againagain();
  notagain();
  notagainagain();

  return 0;
}

void run(void) {
  std::cout << "\nIn function " << __func__ << "()\n" << std::endl;

  {
    size_t i, j;
    int temp, pass = 0;
    int a[] = { 10, 2, 0, 14, 43, 25, 18, 1, 5, 45, 3, 15, 16, 8, 9, };
    size_t constexpr a_sz = sizeof(a) / sizeof(*a);
    // std::cout << a_sz << '\n';
    std::cout << "Input list ...\n";
    for (i = 0; i < 15; i++) {
      std::cout << std::setw(3) << a[i];
    }
    std::cout << std::endl;
    for (i = 0; i < a_sz; i++) {
      for (j = i + 1; j < a_sz; j++) {
        if (a[j] < a[i]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
      pass++;
    }

    std::cout << "Sorted Element List ...\n";
    for (i = 0; i < 15; i++) {
      std::cout << std::setw(3) << a[i];
    }
    std::cout << std::endl;

    // int array[] = { a[i] };
    // int size = sizeof(array) / sizeof(array[0]);
    // std::cout << size << '\n';
    // std::cout << i << ' ' << a[i] << ' ' << array[0] << '\n';

    int reverse[a_sz];
    // std::cout << i << ' ' << k << '\n';
    // reverse[k--] = array[i--];
    // std::cout << i << ' ' << k << '\n';
    // reverse[i];
    // std::cout << reverse[i] << ", ";
    for (size_t k = 0, i = a_sz - 1; k < a_sz; ++k, --i) {
      reverse[k] = a[i];
    }

    std::cout << "Reversed Element List ...\n";
    for (size_t i = 0; i < a_sz; ++i) {
      std::cout << std::setw(3) << reverse[i];
    }
    std::cout << std::endl;
  }
}


auto constexpr show = [](auto const & sv) {
  for (auto const nr : sv) {
    std::cout << std::setw(3) << nr;
  }
  std::cout << std::endl;
};

void again(void) {
  std::cout << "\nIn function " << __func__ << "()\n" << std::endl;

  std::vector<int> array { 10, 2, 0, 14, 43, 25, 18, 1, 5, 45, 3, 15, 16, 8, 9, };
  show(array);
  std::sort(array.begin(), array.end());
  show(array);
  std::cout << std::endl;

  std::vector<int> reverse;
  std::copy(array.crbegin(), array.crend(), std::back_inserter(reverse));
  show(reverse);
}

void againagain(void) {
  std::cout << "\nIn function " << __func__ << "()\n" << std::endl;

  int array[] { 10, 2, 0, 14, 43, 25, 18, 1, 5, 45, 3, 15, 16, 8, 9, };
  size_t constexpr array_sz = sizeof(array) / sizeof(*array);
  show(array);
  std::sort(std::begin(array), std::end(array));
  show(array);
  std::cout << std::endl;

  int reverse[array_sz];
  std::copy(std::crbegin(array), std::crend(array), std::begin(reverse));
  show(reverse);
}

void notagain(void) {
  std::cout << "\nIn function " << __func__ << "()\n" << std::endl;

  std::vector<int> array { 10, 2, 0, 14, 43, 25, 18, 1, 5, 45, 3, 15, 16, 8, 9, };
  show(array);
  std::sort(array.begin(), array.end());
  show(array);
  std::cout << std::endl;

  std::reverse(array.begin(), array.end());
  show(array);
}

void notagainagain(void) {
  std::cout << "\nIn function " << __func__ << "()\n" << std::endl;

  std::vector<int> array { 10, 2, 0, 14, 43, 25, 18, 1, 5, 45, 3, 15, 16, 8, 9, };
  show(array);
  std::sort(array.begin(), array.end());
  show(array);
  std::cout << std::endl;

  std::reverse(std::begin(array), std::end(array));
  show(array);
}


