#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ft_revstr(char*);
int ft_strlen(char*);

#define SIZE 256

int main(int argc, char* argv[]) {
  //commented code works fine. when i pass argument in main
  
  if (argc >= 2) {
    char reverse[SIZE] = { '\0', };
    strncpy(reverse, argv[1], SIZE - 1);
    // printf("Reverse String is: %s", ft_revstr(argv[1]));
    printf("Original string is: %s\n", reverse);
    printf(" Reverse string is: %s\n", ft_revstr(reverse));
  }
  else {
    printf("Invaild Argument");
  }
  
  // this code create seg fault why ???
  // printf(" Reverse string is: %s\n", ft_revstr("Hello"));

  putchar('\n');

  char hello[] = "Hello";  
  printf("Original string is: %s\n", hello);
  printf(" Reverse string is: %s\n", ft_revstr(hello));

  return EXIT_SUCCESS;
}

// char* ft_revstr(char* str)
// {
//     char* string = str;
//     int i = 0;
//     int j = ft_strlen(string);
//     printf("Reverse String is: ");
//     for(i = j; i >= 0; i--)
//     {
//         printf("%c",string[i]);
//     }
//     return string;
// }

char* ft_revstr(char* str) {
  char* string = str;
  char tmp;
  int i = 0;
  int j = ft_strlen(string) - 1;

  while (i <= j) {
    tmp = string[i];
    string[i] = string[j];
    string[j] = tmp;
    //printf("I: %c\n\tJ: %c\n",string[i],string[j]);

    i++;
    j--;
  }

  return string;
}

int ft_strlen(char* str) {
  char* string = str;
  int i = 0;

  while (string[i] != '\0') {
    i++;
  }

  printf("String Length: %d\n", i);

  return i;
}
