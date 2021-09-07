
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

struct student {
  int id;
  std::string name;
  double mark;

  enum struct comparator { ID, NAME, MARK, };
};

void bubbly(size_t const size, student bubbles[], student::comparator sot = student::comparator::ID);

/*
 *  MARK: main()
 */
int main() {
  std::cout << "BubblyStudent\n";
  std::cout << "C++ Version: " << __cplusplus << std::endl;

  student roster[] {
    { 105, "Ann Onymouse", 90.5, },
    { 102, "Ann Other",    98.7, },
    {  13, "Jusin Ames",   70.3, },
    {  42, "Irma Alias",   89.7, },
  };

  auto print_student = [](auto & stud) {
    std::cout << std::setw(5) << stud.id 
              << std::fixed << std::setw(12) << stud.mark << ' '
              << stud.name << '\n';
  };

  //  original contents of array
  std::cout << "original contents of array\n";
#if (__cplusplus > 201300)
  std::for_each(std::cbegin(roster), std::cend(roster), print_student);
#else
  std::for_each(std::begin(roster), std::end(roster), print_student);
#endif
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "sort by name\n";
  std::sort(std::begin(roster), std::end(roster), [](auto & lhs, auto & rhs) { return lhs.name < rhs.name; });

#if (__cplusplus > 201300)
  std::for_each(std::cbegin(roster), std::cend(roster), print_student);
#else
  std::for_each(std::begin(roster), std::end(roster), print_student);
#endif
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "sort by mark\n";
  std::sort(std::begin(roster), std::end(roster), [](auto & lhs, auto & rhs) { return lhs.mark < rhs.mark; });

#if (__cplusplus > 201300)
  std::for_each(std::cbegin(roster), std::cend(roster), print_student);
#else
  std::for_each(std::begin(roster), std::end(roster), print_student);
#endif
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "sort by id\n";
  std::sort(std::begin(roster), std::end(roster), [](auto & lhs, auto & rhs) { return lhs.id < rhs.id; });

#if (__cplusplus > 201300)
  std::for_each(std::cbegin(roster), std::cend(roster), print_student);
#else
  std::for_each(std::begin(roster), std::end(roster), print_student);
#endif
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "show contents with range-based for loop\n";
  for (auto & stud : roster) {
    print_student(stud);
  }
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "bubble sorted - mark\n";

  bubbly(sizeof(roster) / sizeof(*roster), roster, student::comparator::MARK);

  for (auto & stud : roster) {
    print_student(stud);
  }
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "bubble sorted - name\n";

  bubbly(sizeof(roster) / sizeof(*roster), roster, student::comparator::NAME);

  for (auto & stud : roster) {
    print_student(stud);
  }
  std::cout << std::string(80, '-') << '\n';

  // --------------------------------------------------------------------------------
  std::cout << "bubble sorted - id\n";

  bubbly(sizeof(roster) / sizeof(*roster), roster, student::comparator::ID);

  for (auto & stud : roster) {
    print_student(stud);
  }
  std::cout << std::string(80, '-') << '\n';

  return 0;
}

// ----------------------------------------------------------------------------------
/*
 *  MARK: bubbly()
 */
void bubbly(size_t const size, student bubbles[], student::comparator sot) {
  std::cout << "In: " << __func__ << '\n' << std::endl;

  for (size_t s_(0); s_ < size - 1; ++s_) {
    for (size_t r_(s_ + 1); r_ < size; ++r_) {
      auto comp = false;
      switch (sot) {
      default:
      case student::comparator::ID:
        comp = bubbles[s_].id > bubbles[r_].id;
        break;

      case student::comparator::NAME:
        comp = bubbles[s_].name > bubbles[r_].name;
        break;

      case student::comparator::MARK:
        comp = bubbles[s_].mark > bubbles[r_].mark;
        break;
      }
      if (comp) {
        std::swap(bubbles[s_], bubbles[r_]);
      }
    }
  }
}
