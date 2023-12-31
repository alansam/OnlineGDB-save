/******************************************************************************

I don't know how to use binary mode , I need help

write a program by C++ below:
1) Write information of 10 employees to file( binary mode).
   the information of 1 employee includes :

    Employee ID
    full name
    salary coefficient
    basic salary
    allowance

2) Read employee information from file (binary mode).
   Output the employee's total salary on the screen according to the formula:
    total salary = salary coefficient * basic salary + allowance

I would like to thank everyone for reading this post

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>

#include "snap.h"

#define SVC51_

using namespace std::literals::string_literals;

static
auto filename = "salary.dat"s;

struct employee {
  uint32_t eye0;
  uint16_t emp_ID;
  std::string emp_name;
  int64_t salary_coefficient;
  int64_t salary_basic;
  int64_t allowance;
  uint32_t eye1;

  int64_t salary_total(void) const {
    int64_t salary = (salary_coefficient * salary_basic / 100) + allowance;
    return salary;
  }

  static
  std::string money(int64_t val) {
    std::ostringstream os;
    int64_t units = val / 100;
    int64_t dec = val % 100;
    os << units << '.' << std::setw(2) << std::setfill('0') << dec;
    return os.str();
  }
};

struct alignas(alignof(uint64_t)) employee_bin {
  uint32_t eye0;
  uint16_t emp_ID;
  char emp_name[64];
  int64_t salary_coefficient;
  int64_t salary_basic;
  int64_t allowance;
  int32_t filler; // force alignment to last 4 bytes of struct
  uint32_t eye1;
};

bool to_file(std::vector<employee> const & emps);
bool from_file(std::vector<employee> & emps);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  union eyecatcher {
    uint32_t eye;
    uint8_t eyecatcher[4];
  };
  eyecatcher e0 { .eyecatcher = { 0xca, 0xfe, 0xfa, 0xce, } };  //  CAFEFACE
  eyecatcher e1 { .eyecatcher = { 0xfa, 0xce, 0xca, 0xfe, } };  //  FACECAFE
  auto emps = std::vector<employee> {
    { e0.eye, 0u, "Irma N\u00e4lias"s, 1'20, 120'000'00, 1'000'00, e1.eye, },
    { e0.eye, 1u, "Ivan Idea"s,        3'33, 100'000'00, 0'000'00, e1.eye, },
    { e0.eye, 2u, "Justin Other"s,     1'00, 220'000'00, 1'000'00, e1.eye, },
    { e0.eye, 3u, "Andy Identity"s,    1'01, 320'000'00, 1'500'00, e1.eye, },
  };

  auto report = [](auto const & emps) {
    for (auto const & thing : emps) {
      auto ename = "«"s + thing.emp_name + "»"s;
      std::cout << std::hex << thing.eye0 << std::dec << ' '
                <<        std::setw(7) << thing.emp_ID << ' '
                << std::setw(30) << ename << ' '
                <<        std::setw(4) << employee::money(thing.salary_coefficient) << ' '
                << '$' << std::setw(9) << employee::money(thing.salary_basic) << ' '
                << '$' << std::setw(7) << employee::money(thing.allowance) << ' '
                << '$' << std::setw(9) << employee::money(thing.salary_total()) << ' '
                << std::hex << thing.eye1 << std::dec
                << '\n';
    }
    std::cout << std::endl;
  };

  report(emps);
  std::cout << "Data written to file:\n"s;
  for (auto const & record : emps) {
    snap(stdout, &record, sizeof record);
  }

  std::cout << std::string(80, '-') << '\n';
  auto outs = std::vector<employee>();
  auto io_ok { false };

  io_ok = to_file(emps);
  io_ok = from_file(outs);

  report(outs);

  std::cout << std::string(80, '-') << '\n';
  std::cout << "Data read from file:\n"s;
  for (auto const & record : outs) {
    snap(stdout, &record, sizeof record);
  }

  return io_ok ? 0 : 1;
}

/*
 *  MARK: to_file()
 */
bool to_file(std::vector<employee> const & emps) {
  auto all_ok { false };

  std::ofstream f_sal(filename, std::ios::binary);
  if (f_sal.is_open()) {
    for (auto const & emp : emps) {
      employee_bin emp_record {
        .eye0 = emp.eye0,
        .emp_ID = emp.emp_ID,
        .emp_name = { '\0', },
        .salary_coefficient = emp.salary_coefficient,
        .salary_basic = emp.salary_basic,
        .allowance = emp.allowance,
        .eye1 = emp.eye1,
      };
      auto namsz = sizeof(emp_record.emp_name) / sizeof(*emp_record.emp_name);
      std::strncpy(emp_record.emp_name, emp.emp_name.data(), namsz - 1);

#ifdef SVC51_
      std::cout << "Output record:\n"s;
      snap(stdout, &emp_record, sizeof emp_record);
#endif
      f_sal.write(reinterpret_cast<char const *>(&emp_record), sizeof emp_record);
    }

    f_sal.close();
    all_ok = true;
  }

  return all_ok;
}

/*
 *  MARK: from_file()
 */
bool from_file(std::vector<employee> & outs) {
  auto all_ok { false };

  std::ifstream f_sal(filename, std::ios::binary);
  if (f_sal.is_open()) {
    do {
      employee_bin emp_record { 0 };
      f_sal.read(reinterpret_cast<char *>(&emp_record), sizeof(emp_record));
      if (f_sal.good()) {
#ifdef SVC51_
        std::cout << "Input record:\n"s;
        snap(stdout, &emp_record, sizeof emp_record);
#endif
        employee emp {
          .eye0 = emp_record.eye0,
          .emp_ID = emp_record.emp_ID,
          .salary_coefficient = emp_record.salary_coefficient,
          .salary_basic = emp_record.salary_basic,
          .allowance = emp_record.allowance,
          .eye1 = emp_record.eye1,
        };
        emp.emp_name = std::string(emp_record.emp_name);

        outs.push_back(emp);
      }
    } while (!f_sal.eof());

    f_sal.close();
    all_ok = true;
  }

  return all_ok;
}
