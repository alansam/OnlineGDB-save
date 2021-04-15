
#ifdef __cplusplus
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#endif

#define NAME_SIZE 24

#ifndef __cplusplus
typedef struct student student;
#endif
struct student {
  int id;
  char name[NAME_SIZE];
  double mark;
};
size_t const student_l = sizeof(student);

#ifndef __cplusplus
typedef enum student_comparator student_comparator;
#endif
enum student_comparator { ID, NAME, MARK, };

void bubbly(size_t const size, student bubbles[], student_comparator sot, bool asc);

#ifdef __cplusplus
extern "C" {
#endif
int qsort_comparator_ID(void const * lhs, void const * rhs);
int qsort_comparator_NAME(void const * lhs, void const * rhs);
int qsort_comparator_MARK(void const * lhs, void const * rhs);

//  MARK: Global. Used to provide context to qsort callbacks. (ascending/descending)
extern bool qs_ascending;
bool qs_ascending = true;
#ifdef __cplusplus
}
#endif

char const * dlm = "....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!";

/*
 *  MARK: print_roster()
 */
#ifdef __cplusplus
void print_roster(size_t count, student roster[]) {
#else
void print_roster(size_t count, student roster[count]) {
#endif
  for (size_t e_ = 0; e_ < count; ++ e_) {
    printf("%4d %-20s %10.6lf\n", roster[e_].id, roster[e_].name, roster[e_].mark);
  }
  putchar('\n');
}

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  printf("%s\n", "BubblyStudentQsort");
#ifdef __cplusplus
  std::cout << "C++ Version: " << __cplusplus << std::endl;
#endif

  student roster[] = {
    { 105, "Ann Onymouse", 90.5, },
    { 102, "Ann Other",    98.7, },
    {  13, "Jusin Ames",   70.3, },
    {  42, "Irma Alias",   89.7, },
  };
  size_t const roster_el = sizeof(roster) / student_l;

  // --------------------------------------------------------------------------------
  puts("original");

  print_roster(roster_el, roster);

  // --------------------------------------------------------------------------------
  printf("%s\n", dlm);
  puts("bubble sorted - mark");

  bubbly(roster_el, roster, MARK, true);
  print_roster(roster_el, roster);
  bubbly(roster_el, roster, MARK, false);
  print_roster(roster_el, roster);

  // --------------------------------------------------------------------------------
  printf("%s\n", dlm);
  puts("bubble sorted - id");

  bubbly(roster_el, roster, ID, true);
  print_roster(roster_el, roster);
  bubbly(roster_el, roster, ID, false);
  print_roster(roster_el, roster);

  // --------------------------------------------------------------------------------
  printf("%s\n", dlm);
  puts("bubble sorted - name");

  bubbly(roster_el, roster, NAME, true);
  print_roster(roster_el, roster);
  bubbly(roster_el, roster, NAME, false);
  print_roster(roster_el, roster);

  // --------------------------------------------------------------------------------
  printf("%s\n", dlm);
  puts("qsort - id");

  qs_ascending = true;
  qsort(roster, roster_el, student_l, qsort_comparator_ID);
  print_roster(roster_el, roster);
  qs_ascending = false;
  qsort(roster, roster_el, student_l, qsort_comparator_ID);
  print_roster(roster_el, roster);

  // --------------------------------------------------------------------------------
  printf("%s\n", dlm);
  puts("qsort - name");

  qs_ascending = true;
  qsort(roster, roster_el, student_l, qsort_comparator_NAME);
  print_roster(roster_el, roster);
  qs_ascending = false;
  qsort(roster, roster_el, student_l, qsort_comparator_NAME);
  print_roster(roster_el, roster);

  // --------------------------------------------------------------------------------
  printf("%s\n", dlm);
  puts("qsort - mark");

  qs_ascending = true;
  qsort(roster, roster_el, student_l, qsort_comparator_MARK);
  print_roster(roster_el, roster);
  qs_ascending = false;
  qsort(roster, roster_el, student_l, qsort_comparator_MARK);
  print_roster(roster_el, roster);

  return 0;
}

// ----------------------------------------------------------------------------------
/*
 *  MARK: bubbly()
 */
void bubbly(size_t const size, student bubbles[], student_comparator sot, bool asc) {
  printf("In: %s\n", __func__);

  for (size_t s_ = 0; s_ < size - 1; ++s_) {
    for (size_t r_ = s_ + 1; r_ < size; ++r_) {
      bool swap = false;
      switch (sot) {
      default:
      case ID:
        if ( (asc && (bubbles[s_].id > bubbles[r_].id)) || (!asc && (bubbles[s_].id < bubbles[r_].id)) ) {
          swap = true;
        }
        break;

      case NAME:
        
        if ( (asc && (strcmp(bubbles[s_].name, bubbles[r_].name) > 0)) || (!asc && (strcmp(bubbles[s_].name, bubbles[r_].name) < 0)) ) {
          swap = true;
        }
        break;

      case MARK:
        if ( (asc && (bubbles[s_].mark > bubbles[r_].mark)) || (!asc && (bubbles[s_].mark < bubbles[r_].mark)) ) {
          swap = true;
        }
        break;
      }

      if (swap) {
        student tmp;
        memcpy(&tmp, &bubbles[s_], student_l);
        memcpy(&bubbles[s_], &bubbles[r_], student_l);
        memcpy(&bubbles[r_], &tmp, student_l);
      }
    }
  }
}

#ifdef __cplusplus
extern "C" {
#endif
/*
 *  MARK: qsort_comparator_ID() - qsort callback
 *
 *  Uses global boolean qs_ascending to control sort direction
 */
int qsort_comparator_ID(void const * lhs, void const * rhs) {
  int comp;
  student const * lhstudent = (student const *) lhs;
  student const * rhstudent = (student const *) rhs;

  comp = lhstudent->id > rhstudent->id ?  1
       : lhstudent->id < rhstudent->id ? -1
       : 0;
  comp = comp == 0 ? comp : qs_ascending ? comp : -comp;

  return comp;

}

/*
 *  MARK: qsort_comparator_NAME() - qsort callback
 *
 *  Uses global boolean qs_ascending to control sort direction
 */
int qsort_comparator_NAME(void const * lhs, void const * rhs) {
  int comp;
  student const * lhstudent = (student const *) lhs;
  student const * rhstudent = (student const *) rhs;

  comp = strcmp(lhstudent->name, rhstudent->name);
  comp = comp == 0 ? comp : qs_ascending ? comp : -comp;

  return comp;
}

/*
 *  MARK: qsort_comparator_MARK() - qsort callback
 *
 *  Uses global boolean qs_ascending to control sort direction
 */
int qsort_comparator_MARK(void const * lhs, void const * rhs) {
  int comp;
  student const * lhstudent = (student const *) lhs;
  student const * rhstudent = (student const *) rhs;

  comp = lhstudent->mark > rhstudent->mark ?  1
       : lhstudent->mark < rhstudent->mark ? -1
       : 0;
  comp = comp == 0 ? comp : qs_ascending ? comp : -comp;

  return comp;
}
#ifdef __cplusplus
}   /*  extern "C" */
#endif
