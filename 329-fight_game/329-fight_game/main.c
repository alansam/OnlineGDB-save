// I am new to C, and I try to create a project. The programme work,
// but there is a lot of valgrind error about dynamic memory in addPlayer
// and qsort. Can someone give any advice how to fix those?

#include "project.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/*
 *  MARK: cmpexp()
 */
int cmpexp(const void * a, const void * b) {
  const struct Character * const * characterA = (const struct Character * const *) a;
  const struct Character * const * characterB = (const struct Character * const *) b;
  if ((*characterA)->experience > (*characterB)->experience) {
    return -1;
  } 
  else if ((*characterA)->experience < (*characterB)->experience) {
    return 1;
  }
  else {
    return 0;
  }
}

/*
 *  MARK: checkplayer()
 */
int checkplayer(struct Character ** collection, const char * name2, int size) {
  for (int i = 0; i < size; i++) {
    if (!strcmp(collection[i]->name, name2)) {
      return 1; // Player found
    }
  }

  return 0; // Player not found
}

/*
 *  MARK: addplayer()
 */
struct Character ** addplayer(struct Character ** collection_ptr, int size, const char * name, int hitpoint, int experience, const char * wpname, int wpdmg) {
  // First, allocate memory for the new Character* array
  struct Character ** new_collection_ptr = /*(struct Character **)*/ realloc(collection_ptr, (size + 1) * sizeof(struct Character *));
  if (new_collection_ptr == NULL) {
    // Memory allocation failed
    return NULL;
  }

  // Now, allocate memory for the new Character
  new_collection_ptr[size] = /*(struct Character *)*/ malloc(sizeof(struct Character));
  if (new_collection_ptr[size] == NULL) {
    // Memory allocation failed
    free(new_collection_ptr);
    return NULL;
  }

  // Allocate memory for the name and copy it
  new_collection_ptr[size]->name = calloc((strlen(name) + 1), sizeof(char));
  if (new_collection_ptr[size]->name == NULL) {
    free(new_collection_ptr[size]);
    free(new_collection_ptr);
    return NULL;
  }
  strcat(new_collection_ptr[size]->name, name);

  // Allocate memory for the weapon name and copy it
  new_collection_ptr[size]->weapname = calloc((strlen(wpname) + 1), sizeof(char));
  if (new_collection_ptr[size]->weapname == NULL) {
    // Memory allocation failed
    free(new_collection_ptr[size]->name);
    free(new_collection_ptr[size]);
    free(new_collection_ptr);
    return NULL;
  }
  strcat((new_collection_ptr)[size]->weapname, wpname);

  // Assign other attributes
  new_collection_ptr[size]->hit_points = hitpoint;
  new_collection_ptr[size]->damage = wpdmg;
  new_collection_ptr[size]->experience = experience;

  return new_collection_ptr;
}
/*
 *  MARK: attack()
 */
int attack(struct Character ** collection, int size, const char * name1, const char * name2) {
  int attacker = -1;
  int target = -1;
  for (int i = 0; i < size; i++) {
    if (!strcmp(collection[i]->name, name1)) {
      attacker = i;
    }
    if (!strcmp(collection[i]->name, name2)) {
      target = i;
    }
  }

  if (attacker == -1) {
    return -1;
  }
  if (target == -1) {
    return 0;
  }
  if (collection[attacker]->hit_points == 0) {
    return 2;
  }
    
  collection[attacker]->experience += collection[attacker]->damage;
  collection[target]->hit_points -= collection[attacker]->damage;
  printf("%s attacked %s with %s by %d damage.\n",
         collection[attacker]->name,
         collection[target]->name,
         collection[attacker]->weapname,
         collection[attacker]->damage);
  printf("%s has %d hit points remaining.\n",
         collection[target]->name,
         collection[target]->hit_points);
  printf("%s gained %d experience points.\n",
         collection[attacker]->name,
        collection[attacker]->experience);
        // collection[attacker]->damage);

  return 1;
}

/*
 *  MARK: main()
 */
int main(void) {
  struct Character ** players = /*(struct Character **)*/ malloc(1 * sizeof(struct Character *));
  int size = 0;
  int go_on = 1;
  char buffer[1000];
  while (go_on) {
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      continue;
    }

    buffer[strlen(buffer) - 1] = '\0';
printf(":::%s\n", buffer);

    if (strlen(buffer) > 0) {
      char * type = strtok(buffer, " \t");
printf(":::%s\n", type);
      if (!strcmp(type, "A")) {
        //  ....+....|....+....|....+....|....+....|....+....|....+....|....+....|
        //  ADD fighter
        char * name = strtok(NULL, " \t");
printf(":::%s\n", name);
        if (name == NULL || isdigit(*name)) {
          printf("A should be followed by exactly 4 arguments.\n");
          continue;
        }
        char * hp_string = strtok(NULL, " \t");
printf(":::%s\n", hp_string);
        char * wpname = strtok(NULL, " \t");
printf(":::%s\n", wpname);
        if (wpname == NULL || isdigit(*wpname)) {
          printf("Weapon name cannot be empty or space.\n");
          continue;
        }
        char * wpdmg_string = strtok(NULL, " \t");
printf(":::%s\n", wpdmg_string);
        if (hp_string == NULL || wpname == NULL || wpdmg_string == NULL) {
          printf("A should be followed by exactly 4 arguments.\n");
          continue;
        }

        int hp = atoi(hp_string);
        int wpdmg = atoi(wpdmg_string);
printf("%d %d\n", hp, wpdmg);
        if (wpdmg < 1) {
          printf("Max damage cannot be lower than 1\n");
          continue;
        }
        if (hp < 1) {
          printf("HP cannot be lower than 1\n");
          continue;
        }
        if (checkplayer(players, name, size) == 1) {
          printf("Fighter '%s' is already in the database.\n", name);
          continue;
        }
        players = addplayer(players, size, name, hp, 0, wpname, wpdmg);
        if (players != NULL) {
          size++;
          printf("SUCCESS\n\n");
        }
      }
      else if (!strcmp(type, "L")) {
        //  ....+....|....+....|....+....|....+....|....+....|....+....|....+....|
        //  LIST data
        qsort(players, size, sizeof(struct Character *), cmpexp);
        for (int n = 0; n < size; n++) {
          printf("%s %d %d %s %d\n",
                 players[n]->name,
                 players[n]->hit_points,
                 players[n]->experience,
                 players[n]->weapname,
                 players[n]->damage);
        }
        printf("SUCCESS\n\n");
      }
      else if (!strcmp(type, "H")) {
        //  ....+....|....+....|....+....|....+....|....+....|....+....|....+....|
        //  ATTACK (HIT) opponent
        char * name1 = strtok(NULL, " \t");
        char * name2 = strtok(NULL, " \t");
        if (name1 == NULL || name2 == NULL) {
          printf("H should be followed by exactly 2 arguments.\n");
          continue;
        }
        if (!strcmp(name1, name2)) {
          printf("Attacker '%s' cannot attack to itself.\n", name1);
          continue;
        }

        int value = attack(players, size, name1, name2);
        if (value == -1) {
          printf("Attacker '%s' is not in the database.\n", name1);
        }
        else if (value == 0) {
          printf("Target '%s' is not in the database.\n", name2);
        }
        else if (value == 1) {
          printf("SUCCESS\n\n");
        }
        else if (value == 2) {
          printf("Attacker %s is already dead.\n", name1);
          continue;
        }
      }
      else if (!strcmp(type, "W")) {
        //  ....+....|....+....|....+....|....+....|....+....|....+....|....+....|
        //  SAVE (WRITE) to file
        const char * name = strtok(NULL, "\t");
        FILE * f;
        f = fopen(name, "w");
        if (f == NULL) {
          printf("Error!");   
          continue;             
        }
        for (int n = 0; n < size; n++) {
          fprintf(f,
                  "%s %d %d %s %d\n",
                  players[n]->name,
                  players[n]->hit_points,
                  players[n]->experience,
                  players[n]->weapname,
                  players[n]->damage);
        }
        fclose(f);
        printf("SUCCESS\n\n");
      }
      else if (!strcmp(type, "O")) {
        //  ....+....|....+....|....+....|....+....|....+....|....+....|....+....|
        // READ (OPEN) save file
        int size2 = 0;
        const char * name = strtok(NULL, " \t");
        FILE * f;
        f = fopen(name, "r");
        if (f == NULL) {
          printf("Cannot open file %s for reading.\n", name);   
          continue;             
        }
        for (int i = 0; i < size; i++) {
          free(players[i]->weapname);
          free(players[i]->name);
          free(players[i]);
        }
        free(players);
        struct Character ** players = /*(struct Character **)*/ malloc(1 * sizeof(struct Character *));
        char * buffer3 = /*(char *)*/ malloc(1000 * sizeof(char) + 1);
        if (buffer3 == NULL) {
          return 0;  // Check for memory allocation failure
        }
        char * ret;
        while ((ret = fgets(buffer3, 1000, f)) != NULL) {
          // Remove the newline character
          char * player = strtok(ret, " \t");
          if (player == NULL) {
            printf("Invalid line format: %s\n", ret);
            continue;
          }
          char * hit_point_str = strtok(NULL, " \t");
          if (hit_point_str == NULL) {
            printf("Invalid line format: %s\n", ret);
            continue; // Skip lines with missing values
          }
          char * experience_str = strtok(NULL, " \t");
          if (experience_str == NULL) {
            printf("Invalid line format: %s\n", ret);
            continue; // Skip lines with missing values
          }
          char *weapon_name = strtok(NULL, " \t");
          if (weapon_name == NULL) {
            printf("Invalid line format: %s\n", ret);
            continue; // Skip lines with missing values
          }
          char *weapon_damage_str = strtok(NULL, " \t");
          if (weapon_damage_str == NULL) {
            printf("Invalid line format: %s\n", ret);
            continue; // Skip lines with missing values
          }
          int hit_point = atoi(hit_point_str);
          int experience = atoi(experience_str);
          
          ret[strcspn(ret, "\n")] = '\0';
          
          if (weapon_damage_str == NULL) {
            continue;
          }
          int weapon_damage = atoi(weapon_damage_str);  
          players = addplayer(players, size2, player, hit_point, experience, weapon_name, weapon_damage);
          size2++;
        }
        size = size2;
        free(buffer3);
        fclose(f);
        printf("SUCCESS\n\n");
      }
      else if (!strcmp(type, "Q")) {
        //  ....+....|....+....|....+....|....+....|....+....|....+....|....+....|
        //  QUIT
        for (int i = 0; i < size; i++) {
          free(players[i]->weapname);
          free(players[i]->name);
          free(players[i]);
        }
        free(players);
        printf("SUCCESS\n\n");
        go_on = 0;
      }
      else {
        printf("Invalid command %s\n", type);
      }
    }
  }

  return 0;
}
