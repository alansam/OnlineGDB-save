#include <stdio.h>
#include <regex.h>
#include <string.h>

int match(char *string, char *pattern) { //function to see if two string match
  regex_t re; //is a pointer to a memory location where expression is matched and stored; structure type regex_t w/ size_t, re_nsub, etc

  //&re- pointer to a memory loc. where the pattern to b matched is stored
  //pattern- a string type pointer to a pattern
  //REG_EXTENDED- maybe if we need to add additional metacharacters w/o "\" to interpret regex
  //^REG_NOSUB- when it compiles, it only reports if there's match success or failure, but not the positions of what was matched
  if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
    fprintf(stderr, "regexp pattern did not compiile: %s\n", pattern);
    return 0;
  }

  //&re- precompiled pattern
  //string- the string that needs to be searched for
  //0- info abt the location of matches
  //NULL- 
  //0- return value, 0 if theres a match, REG_NOMATCH: If there is no match. 
  int status = regexec(&re, string, 0, NULL, 0);

  regfree(&re); //to free the memory allocated for re

  return (status != 0) ? 0 : 1;
}

int main() {
    char *re = "[a-zA-Z0-9.-_]+@(gmail|yahoo|outlook)+\\.(com|edu)";
    char s1[50];
    char s2[50];
    printf("enter email 1: ");
    fgets(s1, 50, stdin);
    s1[strcspn(s1, "\n")] = 0;  // remove trailing \n
    printf("\n  echo: %s\n", s1);
    putchar('\n');
    printf("enter email 2: ");
    fgets(s2, 50, stdin);
    s2[strcspn(s2, "\n")] = 0;  // remove trailing \n
    printf("\n  echo: %s\n", s2);
    putchar('\n');

    printf("Does %s match the pattern: %s\n", s1, match(s1, re) ? "true" : "false");
    printf("Does %s match the pattern: %s\n", s1, match(s2, re) ? "true" : "false");
}

