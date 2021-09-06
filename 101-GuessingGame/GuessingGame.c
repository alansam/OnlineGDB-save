
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int userInput(void);
void playGame(int joueurs);

int main(void) {
  int joueurs = userInput();
  printf("\n\n");
  if (joueurs == 1 || joueurs == 2) {
    printf("commencer\n");
    playGame(joueurs);
  }
  else {
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}

int userInput(void) {
  int choixDuMenu;
  printf("====Menu===\n");
  printf("1.un joueur\n");
  printf("2.deux joueux\n");
  scanf("%d", &choixDuMenu);
  printf("\n");

  switch (choixDuMenu) {
    case 1:
      printf("vous avez choisi un joueur\n");
      break;
    case 2:
      printf("vous avez choidi deux jouer\n");
      break;
    default:
      printf("vous n'avez pas faix de bon choix\n");
      break;
  }

  return choixDuMenu;
}

void playGame(int joueurs) {
  int nombreMystere = 0, nombreEntrer = 0;
  const int MAX = 100, MIN = 1;
  srand(time(NULL));
  nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

  do {
    printf("quel est le nombre?\n");
    scanf("%d", &nombreEntrer);
    if (nombreMystere > nombreEntrer) {
      printf("c'est moin\n");
    }
    else if(nombreMystere<nombreEntrer) {
      printf("c'est plus \n");
    }
    else {
      printf("bravo! vous avez trouver\n\n");
    }
  }
  while (nombreEntrer != nombreMystere);
}

