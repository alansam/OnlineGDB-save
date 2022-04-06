//  @see: https://medium.com/programming-in-c/an-introduction-to-ncurses-in-c-d977efd706f8

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ncurses.h"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void printing();
void moving_and_sleeping();
void colouring();
void banner();

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main() {

  /*  WINDOW * mywindow;
  mywindow =*/
  initscr();

  // printw("Hello World\n");
  // refresh();

  banner();

  bool loop = true;
  while (loop) {
    addstr("\nChoice:\n1. Printing.\n2. Moving & Sleeping.\n3. Colouring\nX. Exit\n> ");
    int choice = getch();
    switch (choice) {
      case '1':
        clear();
        banner();
        printing();
        break;

      case '2':
        clear();
        banner();
        moving_and_sleeping();
        break;

      case '3':
        clear();
        banner();
        colouring();
        break;

      case 'X':
      case 'Q':
      case 'x':
      case 'q':
        loop = false;
        break;

      default:
        //  nop;
        break;
    }
  }

  addstr("\n\npress any key to exit...");
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}

//--------------------------------------------------------
// FUNCTION banner
//--------------------------------------------------------
void banner(void) {
  addstr("-----------------\n| codedrome.com |\n| ncurses Demo  |\n-----------------\n\n");
  refresh();
}

//--------------------------------------------------------
// FUNCTION printing
//--------------------------------------------------------
void printing() {
  addstr("This was printed using addstr\n\n");
  refresh();

  addstr("The following letter was printed using addch:- ");
  addch('a');
  refresh();

  printw("\n\nThese numbers were printed using printw\n%d\n%f\n", 123, 456.789);
  refresh();
}

//--------------------------------------------------------
// FUNCTION moving_and_sleeping
//--------------------------------------------------------
void moving_and_sleeping() {
  int row = 5;
  int col = 0;

  curs_set(0);

  for (char c = 65; c <= 90; c++) {
    move(row++, col++);
    addch(c);
    refresh();
    napms(100);
  }

  row = 5;
  col = 3;

  for (char c = 97; c <= 122; c++) {
    mvaddch(row++, col++, c);
    refresh();
    napms(100);
  }

  curs_set(1);

  addch('\n');
}

//--------------------------------------------------------
// FUNCTION colouring
//--------------------------------------------------------
void colouring() {
  if (has_colors()) {
    use_default_colors();
    if (start_color() == OK) {
      init_pair(1, COLOR_YELLOW, COLOR_RED);
      init_pair(2, COLOR_GREEN, COLOR_GREEN);
      init_pair(3, COLOR_MAGENTA, COLOR_CYAN);

      attrset(COLOR_PAIR(1));
      addstr("Yellow and red\n\n");
      refresh();
      attroff(COLOR_PAIR(1));

      attrset(COLOR_PAIR(2) | A_BOLD);
      addstr("Green and green A_BOLD\n\n");
      refresh();
      attroff(COLOR_PAIR(2));
      attroff(A_BOLD);

      attrset(COLOR_PAIR(3));
      addstr("Magenta and cyan\n");
      refresh();
      attroff(COLOR_PAIR(3));
    }
    else {
      addstr("Cannot start colours\n");
      refresh();
    }
  }
  else {
    addstr("Not colour capable\n");
    refresh();
  }
}

