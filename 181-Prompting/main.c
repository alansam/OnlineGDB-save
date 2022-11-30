
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SZ 40

typedef struct busManager busManager;
struct busManager {
  char drvrName[STR_SZ];
  int drvrLicNumb;
  int busNumb;
  char fullRoute[STR_SZ];
  char route[2][STR_SZ];
  int kms;
};

void show(busManager * bm) {
  putchar('\n');
  printf(": %s\n", bm->drvrName);
  printf(": %d\n", bm->drvrLicNumb);
  printf(": %d\n", bm->busNumb);
  printf(": %s\n", bm->fullRoute);
  printf(": %s\n", bm->route[0]);
  printf(": %s\n", bm->route[1]);
  putchar('\n');

  return;
}

int main(int argc, char const * argv[]) {

  int busNo = 0;
  int cc = 0;

  printf("Enter no. of buses: ");
  scanf("%d", &busNo);
  putchar('\n');
  while ((cc = getchar()) != '\n');

  // busManager agraAgency[busNo];
  busManager * agraAgency = malloc(busNo * sizeof(busManager));

  for (int i = 0; i < busNo; i++) {
    char * s_ = NULL;
    printf("Enter the name of driver: ");
    s_ = fgets(agraAgency[i].drvrName, STR_SZ, stdin);
    putchar('\n');
    agraAgency[i].drvrName[strcspn(agraAgency[i].drvrName, "\n")] = 0;
    printf("??? %p %p \"%s\"\n", agraAgency[i].drvrName, (void *) s_, s_);

    printf("Enter the license number of driver '%s': ", agraAgency[i].drvrName);
    scanf("%d\n", &agraAgency[i].drvrLicNumb);
    // while ((cc = getchar()) != '\n');
    printf("??? %p %d", &agraAgency[i].drvrLicNumb, agraAgency[i].drvrLicNumb);
    putchar('\n');

    printf("Enter bus number alloting to driver '%s': ", agraAgency[i].drvrName); 
    scanf("%d\n", &agraAgency[i].busNumb);
    // while ((cc = getchar()) != '\n');
    printf("??? %p %d", &agraAgency[i].busNumb, agraAgency[i].busNumb);
    putchar('\n');

    printf("Enter the route of bus no. %d\n", agraAgency[i].busNumb);
    s_ = fgets(agraAgency[i].fullRoute, STR_SZ, stdin);
    putchar('\n');
    agraAgency[i].fullRoute[strcspn(agraAgency[i].fullRoute, "\n")] = 0;
    printf("??? %p %p \"%s\"\n", agraAgency[i].fullRoute, (void *) s_, s_);

    printf("Enter the starting point of bus number %d: \n", agraAgency[i].busNumb);
    s_ = fgets(agraAgency[i].route[0], STR_SZ, stdin);
    putchar('\n');
    agraAgency[i].route[0][strcspn(agraAgency[i].route[0], "\n")] = 0;
    printf("??? %p %p \"%s\"\n", agraAgency[i].route[0], (void *) s_, s_);

    printf("Enter the destination of bus number %d: \n", agraAgency[i].busNumb);
    s_ = fgets(agraAgency[i].route[1], STR_SZ, stdin);
    putchar('\n');
    agraAgency[i].route[1][strcspn(agraAgency[i].route[1], "\n")] = 0;
    printf("??? %p %p \"%s\"\n", agraAgency[i].route[1], (void *) s_, s_);

    show(&agraAgency[i]);
  }

  free(agraAgency);

  return 0;
}
