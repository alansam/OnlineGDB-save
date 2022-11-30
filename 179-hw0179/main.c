
#include <stdio.h>

#define SZ_STUDENT_NAME 50
#define N 5
#define SZ_K 10

struct student {
  char studentName[SZ_STUDENT_NAME];
  int scoreDepression;
  int scoreAnxiety;
  int scoreStress;
};

int main() {
  int i;//, n = 5;
  int highestDepression, highestAnxiety, highestStress;
  struct student s[N] = { 0, };

  for (i = 0; i < N; i++) {
    printf("\nEnter student name %d: ", i + 1);
    scanf("%s", s[i].studentName);
    printf(" '%s'", s[i].studentName);

    printf("\nStudent %d Depression level: ", i + 1);
    scanf("%d", &(s[i].scoreDepression));
    printf(" '%d'", s[i].scoreDepression);

    printf("\nStudent %d Anxiety level: ", i + 1);
    scanf("%d", &(s[i].scoreAnxiety));
    printf(" '%d'", s[i].scoreAnxiety);

    printf("\nStudent %d Stress level: ", i + 1);
    scanf("%d", &(s[i].scoreStress));
    printf(" '%d'", s[i].scoreStress);

    putchar('\n');
    printf ("------------------------------------\n");
  }
  putchar('\n');

  printf("StudentName Depression Anxiety    Stress\n");
  printf("----------- ---------- ---------- ----------");
  for (i = 0; i < N; i++) {
    printf("\n%-12s",s[i].studentName);

    if (s[i].scoreDepression <= 9) {
      printf("%-11s", "Normal"); // printing outputs
    }
    else if (s[i].scoreDepression <= 13) { // Note the space between else & if
      printf("%-11s", "Mild");
    }
    else if (s[i].scoreDepression <= 20) {
      printf("%-11s", "Moderate");
    }
    else if (s[i].scoreDepression <= 27) {
      printf("%-11s", "Severe");
    }
    else if (s[i].scoreDepression >= 28) {
      printf("%-11s", "Extreme");
    }

    if (s[i].scoreAnxiety <= 7) {
      printf("%-11s", "Normal"); // printing outputs
    }
    else if (s[i].scoreAnxiety <= 9) { // Note the space between else & if
      printf("%-11s", "Mild");
    }
    else if (s[i].scoreAnxiety <= 14) {
      printf("%-11s", "Moderate");
    }
    else if (s[i].scoreAnxiety <= 19) {
      printf("%-11s", "Severe");
    }
    else if (s[i].scoreAnxiety >= 20) {
      printf("%-11s", "Extreme");
    }

    if (s[i].scoreStress <= 14) {
      printf("%-11s", "Normal"); // printing outputs
    }
    else if (s[i].scoreStress <= 18) { // Note the space between else & if
      printf("%-11s", "Mild");
    }
    else if (s[i].scoreStress <= 25) {
      printf("%-11s", "Moderate");
    }
    else if (s[i].scoreStress <= 33) {
      printf("%-11s", "Severe");
    }
    else if (s[i].scoreStress >= 34) {
      printf("%-11s", "Extreme");
    }
  }

  printf("\n\n======================================================\n");
  int k[SZ_K] = { 0, };
  //TODO: not needed -> struct student;
  highestDepression = k[0];
  highestAnxiety = k[0];
  highestStress = k[0];

  for (i = 0; i < N; i++) {
    if (s[i].scoreDepression > highestDepression) {
      highestDepression = s[i].scoreDepression;
    }

    if (s[i].scoreAnxiety > highestAnxiety) {
      highestAnxiety = s[i].scoreAnxiety;
    }

    if (s[i].scoreStress > highestStress) {
      highestStress = s[i].scoreStress;
    }
  }

  printf("Highest score : Depression = %d, Anxiety = %d, Stress = %d\n", highestDepression, highestAnxiety, highestStress);

  return 0;
}
