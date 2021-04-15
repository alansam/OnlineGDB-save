
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
  enum Pass_Fail { PASS, FAIL, };
  enum Sex { M, F, };
  std::string givenname;
  std::string lastname;
  Sex sex;
  double writtenw;
  double peformancetsk;
  double quartassys;
  double finalgrades;
  Pass_Fail remarks;
};

void student_grades(std::vector<student> & students);
void display_table(std::vector<student> const & students);
void order_by_name(std::vector<student> & students);
void order_by_gender(std::vector<student> & students);
void rank_high(std::vector<student> & students);
void rank_low(std::vector<student> & students);

int main() {
  std::vector<student>
  students {
    { "Jake Jeric",        "Tan",         student::M,  75.,  85., 85., },
    { "Rico James",        "Abella",      student::M,  80.,  83., 80., },
    { "Trishia Valerie",   "Acas",        student::F,  82.,  84., 87,  },
    { "Jenny Mae",         "Adventurado", student::F,  90.,  70., 89., },
    { "Shan Forrest",      "Almia",       student::M,  80.,  72., 75., },
    { "Maebelle Marie",    "Aniscal",     student::F,  88.,  77., 66., },
    { "Amanda Jan Alexis", "Babao",       student::F,  65.,  74., 80., },
    { "Hans Marius",       "Baranquil",   student::M,  70.,  56., 44., },
    { "Zairrah Shynne",    "Bayawa",      student::F,  80.,  80., 80., },
    { "Jonathan Carl",     "Catipay",     student::M,  80.,  80., 70., },
    { "Aeisha Jewel",      "Ceniza",      student::F,  90.,  90., 90., },
    { "Carmelle",          "Centino",     student::F,  81.,  71., 91., },
    { "Carmelo Anthony",   "Clar",        student::M,  70.,  80., 77., },
    { "Arabella",          "Constantino", student::F,  75.,  75., 75., },
    { "Bianca Andreah",    "Cubar",       student::F,  75.,  75., 75., },
    { "Magen",             "Delgado",     student::M,  75.,  75., 75., },
    { "Bernard",           "Dicdican",    student::M,  75.,  75., 75., },
    { "Mary Claire",       "Enriquez",    student::F,  75.,  75., 75., },
    { "Maxene",            "Espina",      student::F,  75.,  75., 75., },
    { "Kierth Jerland",    "Figues",      student::M,  75.,  75., 75., },
    { "Althea Aubrey",     "Herrera",     student::F,  70.,  70., 70., },
    { "Justine Kylie",     "Itol",        student::F,  70.,  70., 70., },
    { "Kheilah Marie",     "Ligtas",      student::F,  70.,  70., 70., },
    { "Marea Noelle",      "Magnanao",    student::F,  81.,  71., 91., },
    { "Alyssa Kaithlyn",   "Makiling",    student::F,  81.,  71., 91., },
    { "Karlos Daniel",     "Masecampo",   student::M,  99.,  99., 99., },
    { "Jieuel",            "Migabon",     student::F,  98.,  99., 98., },
    { "James Edward",      "Nepangue",    student::M,  98.,  99., 99., },
    { "Jule Daniel",       "Ocariza",     student::M,  92.,  82., 72., },
    { "Fiona Elaiza Dela", "Parazo",      student::F,  62.,  72., 82., },
    { "Ethan Daryl",       "Quijada",     student::M,  55.,  98., 77., },
    { "Cris Paolo",        "Rafols",      student::M,  75.,  74., 75., },
    { "Aiah Michelley",    "Rizarri",     student::M,  75.,  75., 75., },
    { "Lear Lorenz",       "Roma",        student::M,  74.,  77., 74., },
    { "Kirsten",           "Saavedra",    student::F,  74.,  76., 74., },
    { "Clare Marie",       "Salazar",     student::F,  74.,  76., 73., },
    { "Michael Louie",     "Secapuri",    student::M,  73.,  76., 73., },
    { "Maria Sofia",       "Sevilla",     student::F, 73.2, 76.1, 73.5, },
    { "Kammerdeiner",      "Solon",       student::M, 73.2,  76., 73., },
    { "Chielsea",          "Tahanlangit", student::F, 73.2,  76., 73., },
  };

  student_grades(students);

  bool looping(true);
  while (looping) {
    char choice;
    std::cout << "   Menu of Choices\n"
              << "a. Display Table\n"
              << "b. Names in alphabetical Order\n"
              << "c. According to Gender\n"
              << "d. Rank from Highest to Lowest\n"
              << "e. Rank from Lowest to Highest\n"
              << "f. Quit/End\n"
              << std::endl;

    std::cout << "Select: ";
    std::cin >> choice;

    switch (choice) {
    case 'a':
    case 'A':
      display_table(students);
      break;

    case 'b':
    case 'B':
      order_by_name(students);
      display_table(students);
      break;

    case 'c':
    case 'C':
      order_by_gender(students);
      display_table(students);
      break;

    case 'd':
    case 'D':
      rank_high(students);
      display_table(students);
      break;

    case 'e':
    case 'E':
      rank_low(students);
      display_table(students);
      break;

    case 'f':
    case 'F':
      looping = false;
      std::cout << "---------------------------\n";
      std::cout << "Thank you for your time... \n";
      std::cout << "---------------------------\n";
      std::cout << std::endl;
      break;

    default:
      break;
    }
  }

  return 0;
}

/*
 *  Calculate Grades
 */
void student_grades(std::vector<student> & students) {
  for (auto & sid : students) {
    sid.finalgrades = .2 * sid.writtenw
                    + .6 * sid.peformancetsk
                    + .2 * sid.quartassys;

    if (sid.finalgrades >= 75.) {
      sid.remarks = student::PASS;
    }
    else {
      sid.remarks = student::FAIL;
    }
  }
}

/*
 *  Produce the Report
 */
void display_table(std::vector<student> const & students) {
  std::cout << std::setw(40) << "COMPUTER PROJECT\n"
            << std::setw(43) << "ACADEMIC YEAR 2020- 2021\n\n"
            << std::setw(43) << "UNIVERSITY OF SAN CARLOS\n"
            << std::setw(51) << "BASIC EDUCATION DEPARTMENT- SOUTH CAMPUS\n"
            << std::setw(44) << "J. Alcantara St., Cebu City\n\n"
            << "Section: Grade 10 BMHS"
            << std::setw(29) << "Subject:TLE\n"
            << "Adviser: Daegie Montermoso"
            << std::setw(45) << "Teacher: Engr. Dang B. Guanzon\n\n"
            << "..: g "
            << std::left << std::setw(30) << "Student Names" << std::right
            << std::setw(5) << "WW"
            << std::setw(5) << "PT"
            << std::setw(5) << "QA"
            << std::setw(12) << "FINAL GRADE"
            << std::setw(9) << "REMARKS"
            << std::endl;

  auto zc(0);
  for (auto & sid : students) {
    std::string stdnt_name = sid.givenname + ' ' + sid.lastname;
    std::cout << std::setw(2) << ++zc << ": "
              << (sid.sex == student::M ? "M " : "F ")
              << std::setprecision(1) << std::fixed
              << std::left << std::setw(30) << stdnt_name << std::right
              << std::setw(5) << sid.writtenw
              << std::setw(5) << sid.peformancetsk
              << std::setw(5) << sid.quartassys
              << std::setprecision(2)
              << std::setw(12) << sid.finalgrades
              << std::setw(9)
              << (sid.remarks == student::PASS ? "Pass" : "Fail")
              << '\n';
  }
  auto sum(0.0);
  auto pass(0);
  auto fail(0);
  for (auto & sid : students) {
    sum += sid.finalgrades;
    if (sid.remarks == student::PASS) {
      pass++;
    }
    else {
      fail++;
    }
  }
  auto mean = sum / students.size();
  auto pct_pass = static_cast<double>(pass) / students.size() * 100.;
  auto pct_fail = static_cast<double>(fail) / students.size() * 100.;
  std::cout << "\n"
            << "Arithmetic Mean: "
            << std::setprecision(3) << std::fixed
            << std::setw(8) << mean << '\n'
            << "% Passing:       "
            << std::setw(8) << pct_pass << '\n'
            << "% Failing:       "
            << std::setw(8) << pct_fail << '\n'
            << "Student Name:    "
            << std::setw(50) << "|\n"
            << "Submitted by:    "
            << std::setw(50) << "Jake Jeric T. Tan |\n"
            << "Checked by:      "
            << std::setw(50) << "|\n"
            << "Computer Teacher "
            << std::setw(50) << "Engr. Dang B. Guanzon |\n"
            << std::endl;
}

/*
 *  Sort Table by Last Name
 */
void order_by_name(std::vector<student> & students) {
  std::sort(students.begin(), students.end(), [](auto a_, auto b_) {
    std::string ac = a_.lastname + " " + a_.givenname;
    std::string bc = b_.lastname + " " + b_.givenname;
    return ac < bc;
  });
}

/*
 *  Sort Table by Gender and Last Name
 */
void order_by_gender(std::vector<student> & students) {
  std::sort(students.begin(), students.end(), [](auto a_, auto b_) {
    std::string ac = 
    std::to_string(a_.sex) + a_.lastname + " " + a_.givenname;
    std::string bc =
    std::to_string(b_.sex) + b_.lastname + " " + b_.givenname;
    return ac < bc;
  });
}

/*
 *  Rank Table, Highest Grade Firts
 */
void rank_high(std::vector<student> & students) {
//  order_by_name(students);
  std::sort(students.begin(), students.end(), [](auto a_, auto b_) {
    return a_.finalgrades > b_.finalgrades;
  });
}

/*
 *  Rank Table, Lowest Grade Firts
 */
void rank_low(std::vector<student> & students) {
//  order_by_name(students);
  std::sort(students.begin(), students.end(), [](auto a_, auto b_) {
    return a_.finalgrades < b_.finalgrades;
  });
}
