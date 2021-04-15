#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <valarray>

void the_old_way(void);
auto the_other_way(void) -> void; // C++11 trailing return type
auto something_else(void) -> void;

int main() {

//  the_old_way();
  the_other_way();
  something_else();

  return 0;
}

template <typename T>
auto by3(std::vector<T> & ov, std::vector<T> const & iv) -> std::vector<T> & {
  std::transform(iv.cbegin(), iv.cend(), ov.begin(), [](auto v_) {
    return v_ * 3;
  });
  return ov;
}

auto something_else(void) -> void {

  auto ipvec = std::vector<int> { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, };
  auto opvec = std::vector<int>(ipvec.size());

  opvec = by3(opvec, ipvec);

  std::copy(ipvec.cbegin(), ipvec.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  std::copy(opvec.cbegin(), opvec.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n' << std::endl;

  auto vry = std::valarray<int> { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, };
  std::copy(std::cbegin(vry), std::cend(vry), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  vry *= 3;

  std::copy(std::cbegin(vry), std::cend(vry), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n' << std::endl;

  return;
}

//  a solution that exploits the C++ STL
//  - C++11 trailing return type
auto the_other_way(void) -> void {
  auto sch(0.0);
  auto grades = std::map<std::string, decltype(sch)> {
                     { "A", 4.00, }, { "A-", 3.70, },
                     { "a", 4.00, }, { "a-", 3.70, },
    { "B+", 3.33, }, { "B", 3.00, }, { "B-", 2.70, },
    { "b+", 3.33, }, { "b", 3.00, }, { "b-", 2.70, },
    { "C+", 2.33, }, { "C", 2.00, }, { "C-", 1.70, },
    { "c+", 2.33, }, { "c", 2.00, }, { "c-", 1.70, },
    { "D+", 1.33, }, { "D", 1.00, }, { "D-", 0.70, },
    { "d+", 1.33, }, { "d", 1.00, }, { "d-", 0.70, },
                     { "F", 0.33, },
                     { "f", 0.33, },
  };

  size_t constexpr sct(4ULL);
  auto student = std::vector<decltype(sch)>(sct);

  auto select = [&grades, &sch](auto const g_) {
    std::string grade;
    auto ch(0.0);

    while (true) {
      std::cout << "Enter grade and credit hours: ";
      std::cin >> grade >> ch;
      if (grades.find(grade) != grades.end()) { break; }
      else { std::cout << grade << " is invalid.\n"; }
    }

    sch += ch;
    auto gp = grades[grade] * ch;

    return gp;
  };

#if defined(TX_AND_RD)
  std::transform(student.cbegin(), student.cend(), student.begin(), select);
  std::reduce(student.cbegin(), student.cend(), 0.0, std::plus<>());
#elif defined(TX_RD)
  std::transform_reduce(student.begin(), student.end(), 0.0, select, std::plus<>());
#else
  std::transform(student.cbegin(), student.cend(), student.begin(), select);
  auto total = std::accumulate(student.begin(), student.end(), 0.0, std::plus<>());
#endif
  auto gpa = total / sch;

  std::copy(student.cbegin(), student.cend(), std::ostream_iterator<decltype(sch)>(std::cout, " "));
  std::cout << '\n';
  std::cout << "\ngrade totals: " << total << ", total hours: " << sch << '\n';
  std::cout << "\nYour CGPA is = " << gpa << std::endl;

  return;
}

//  A more C like solution
void the_old_way(void) {
  int ch;
  double gpa;
  int sch(0); //sum of cradit hours.
  double total(0);  //  TODO: this needs to be a floating point type
  std::string grade;

  for (size_t i = 0; i <= 4; i++) {
    std::cout << "Enter your grade " << std::endl;
    std::cin >> grade;
    std::cout << "Enter the cradit hour of this subject " << std::endl;
    std::cin >> ch;
    sch = sch + ch;

    if      (grade == "F"  || grade == "f")  {
      total = total + 0.33 * ch;
    }
    else if (grade == "D-" || grade == "d-") {
      total = total + 0.7 * ch;
    }
    else if (grade == "D"  || grade == "d")  {
      total = total + 1 * ch;
    }
    else if (grade == "d+" || grade == "D+") {
      total = total + 1.33 * ch;
    }
    //  TODO: This block is a duplicate! Decide which one to use
    else if (grade == "d+" || grade == "D+") {
      total = total + 1.7 * ch;
    }
    else if (grade == "c-" || grade == "C-") {
      total = total + 2 * ch;
    }
    else if (grade == "c"  || grade == "C")  {
      total = total + 2.33 * ch;
    }
    else if (grade == "c+" || grade == "C+") {
      total = total + 2.33 * ch;
    }
    else if (grade == "b-" || grade == "B-") {
      total = total + 2.7 * ch;
    }
    else if (grade == "b"  || grade == "B")  {
      total = total + 3 * ch;
    }
    else if (grade == "b+" || grade == "B+") {
      total = total + 3.33 * ch;
    }
    else if (grade == "a-" || grade == "A-") {
      total = total + 3.7 * ch;
    }
    else if (grade == "a"  || grade == "A")  {
      total = total + 4 * ch;
    }
    else {
      i--;
      std::cout << "Enter a valid grade " << std::endl;
    }
  }
  /*std::cout<<"Enter the cradit hour of subjects respectively ";
  cin>>ch;
  for(int j=0; j<=4; j++){
  cin>>ch;
  sch=sch+ch
  }*/
  gpa = total / sch;
  std::cout << "Your CGPA is = " << gpa << std::endl;

  return;
}
