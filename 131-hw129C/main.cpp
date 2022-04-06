/*
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
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

struct schedule {
  uint32_t teacher;
  uint32_t subject;
  uint32_t day;
  uint32_t lesson;
};

static
std::string const dlm(64, '=');

int main() {
  size_t Ox;
  size_t Nx;
  size_t Mx;
  std::cin >> Ox >> Nx >> Mx;

  auto lesson_plan = std::vector<schedule>();
  for (size_t r_ = 0; r_ < Ox; ++r_) {
    auto sch = schedule();
    std::cin >> sch.teacher >> sch.subject >> sch.day >> sch.lesson;
    lesson_plan.push_back(sch);
  }

  std::cout << dlm << '\n';
  std::cout << "Input:\n";
  std::for_each(lesson_plan.cbegin(), lesson_plan.cend(), [](auto const & sch) {
    std::cout << std::setw(3) << sch.teacher
              << std::setw(3) << sch.subject
              << std::setw(3) << sch.day
              << std::setw(3) << sch.lesson
              << '\n';
  });
  std::cout << std::endl;

  auto classes = std::map<uint32_t, uint32_t>();
  for (auto const & lp : lesson_plan) {
    classes[lp.teacher]++;
  }

  std::cout << dlm << '\n';
  std::for_each(classes.cbegin(), classes.cend(), [](auto const & rp) {
    std::cout << std::setw(3) << rp.first << ": " << std::setw(5) << rp.second << '\n';
  });
  std::cout << std::endl;

  auto mteacher = std::map<uint32_t, std::vector<schedule>>();
  std::for_each(lesson_plan.begin(), lesson_plan.end(), [&mteacher](auto & sch) {
    if (mteacher.count(sch.teacher == 0)) {
      auto ss = std::vector<schedule>();
      ss.push_back(sch);
      mteacher[sch.teacher] = ss;
    }
    else {
      auto & val = mteacher[sch.teacher];
      val.push_back(sch);
      mteacher[sch.teacher] = val;
    }
  });

  std::cout << dlm << '\n';
  for (auto const & mp : mteacher) {
    auto const & key = mp.first;
    auto const & val = mp.second;
    std::cout << "Teacher" << std::setw(3) << key << " has" << std::setw(4) << val.size() << " classes.\n";
  }
  std::cout << std::endl;

  std::cout << dlm << '\n';
  std::cout << "Data by teacher.\n";
  std::for_each(mteacher.cbegin(), mteacher.cend(), [](auto const & mp) {
    auto const & tchr = mp.first;
    auto const & vsch = mp.second;
    std::cout << std::setw(3) << "Teacher" << std::setw(3) << tchr << ':' << '\n';
    for (auto const & sch : vsch) {
      std::cout << std::setw(6) << sch.subject
                << std::setw(3) << sch.day
                << std::setw(3) << sch.lesson
                << '\n';
    }
  });
  std::cout << std::endl;

  return 0;
}


