#ifndef PROJECT_H_
#define PROJECT_H_

typedef struct Character Character;
struct Character {
  int experience;
  int hit_points;
  int damage;
  char * name;
  char * weapname;
};

#endif /* PROJECT_H_ */
