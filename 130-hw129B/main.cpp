/*
Hello, Can anybody help me how can I make a 3 dimensional array in this exercise?

Input : In the first line of the standard input are the number of hours, the number of teachers,
the number of subjects.
Each of the following lines contains 4 integers, one space at a time separated:
serial number of the teacher, serial number of the taught subject, the day and the hour.
For example 3 7 2 0 it means that the third teacher takes the seventh subject on the second day 
of the week he teaches in the zero hour. I would like to make the Teachers' timetables which are
three-dimensional stored in an array. The first index is the teacher, the second is the day, and
the third is the number of the lesson. The value of the array element specifies the subject
(represented by numbers). If not hour to the teacher on that day and time, it is indicated by 0.

Input:
8 3 4 
1 1 1 6
1 1 2 2
1 2 1 3
2 1 2 2
2 2 3 1
3 4 1 2
3 2 1 4
3 3 2 1

 */

#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  size_t Ox;
  size_t Nx;
  size_t Mx;
  cin >> Ox >> Nx >> Mx;
  auto * teachernumber = new uint32_t[Ox];
  auto * subject = new uint32_t[Ox];
  auto * day = new uint32_t[Ox];
  auto * lesson = new uint32_t[Ox];

  for (size_t i_ = 0; i_ < Ox; i_++) {
    cin >> teachernumber[i_] >> subject[i_] >> day[i_] >> lesson[i_];
  }
  auto show = [](size_t const Ix, auto const & ary) {
    for (size_t tt = 0; tt < Ix; ++tt) {
      std::cout << std::setw(3) << ary[tt];
    }
    std::cout << std::endl;
  };
  std::cout << "teachernumber" << '\n';
  show(Ox, teachernumber);
  std::cout << "subject" << '\n';
  show(Ox, subject);
  std::cout << "day" << '\n';
  show(Ox, day);
  std::cout << "lesson" << '\n';
  show(Ox, lesson);

  auto * DBhole = new uint32_t[Nx];  // = { 0, };
  set<uint32_t> lessons;

  for (size_t i_ = 1; i_ < Nx; i_++) {
    //Teacher
    for (size_t k_ = 1; k_ < 6; k_++) {
      // day
      // lessons.clear();
      for (size_t j_ = 0; j_ < 9; j_++) {
        // lesson
        std::cout << i_ /*<< ' ' << k_*/ << ' '
                  << teachernumber[i_] << " : "
                  << j_ + 1 << ' '
                  << day[j_] << '\n';
        if (i_ == teachernumber[i_] && j_ + 1 == day[j_]) {
          lessons.insert(lesson[j_]);
        }
      }

      if (lessons.size() > 1) {
        DBhole[i_] += (*std::prev(lessons.end()) - *lessons.begin() + 1 - lessons.size());
      }
    }
  }
  std::cout << "set lessons, size: " << lessons.size() << '\n';
  for_each(lessons.cbegin(), lessons.cend(), [](auto const ls) { std::cout << std::setw(3) << ls; });
  std::cout << std::endl;
  std::cout << "DBhole" << '\n';
  show(Nx, DBhole);

  uint32_t minimum = 0;

  for (size_t i_ = 0; i_ < Nx; i_++) {
    if (DBhole[i_] < minimum) {
      minimum = i_;
    }
  }

  cout << "\nminimum: " << minimum;

  delete [] teachernumber;
  delete [] subject;
  delete [] day;
  delete [] lesson;
  delete [] DBhole;

  return 0;
}

