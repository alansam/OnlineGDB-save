
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

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
 */

static
auto const data = std::string {
  "8\n"
  "8 3 4\n"
  "1 1 1 6\n"
  "1 1 2 2\n"
  "1 2 1 3\n"
  "2 1 2 2\n"
  "2 2 3 1\n"
  "3 4 1 2\n"
  "3 2 1 4\n"
  "3 3 2 1\n"
};

struct row {
  uint32_t tsn;
  uint32_t csn;
  uint32_t dow;
  uint32_t hour;
};

int main() {
  // std::cout << data << '\n';
  auto iss = std::istringstream(data);
  uint32_t entries;
  uint32_t hours;
  uint32_t teachers;
  uint32_t subjects;

  iss >> entries;
  iss >> hours >> teachers >> subjects;
  std::cout << "hours: " << hours << ", teachers: " << teachers << ", subjects: " << subjects << '\n' << std::endl;

  auto classes = std::vector<row>();
  for (size_t l_ = 0; l_ < entries; ++l_) {
    row tr;
    iss >> tr.tsn >> tr.csn >> tr.dow >> tr.hour;
    classes.push_back(tr);
  }

  std::cout << std::setw(9) << "teacher"
            << std::setw(7) << "course"
            << std::setw(4) << "day"
            << std::setw(5) << "hour"
            << '\n';

  for (auto const & clas : classes) {
    std::cout << std::setw(9) << clas.tsn
              << std::setw(7) << clas.csn
              << std::setw(4) << clas.dow
              << std::setw(5) << clas.hour
              << '\n';
  }
  std::cout << std::endl;

  int nums[] { 1234, 01234 };
  for (auto num : nums) {
    std::cout << std::setw(5) << std::setfill('0') << std::showbase << std::dec << num << ' '
              << std::setw(5) << std::setfill('0') << std::showbase << std::oct << num << ' '
              << std::setw(5) << std::setfill('0') << std::showbase << std::hex << num << '\n';
  }

  return 0;
}

