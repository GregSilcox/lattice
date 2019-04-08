#include <iostream>
#include <curses.h>
using namespace std;

#include "virtex.h"

int main() {
  int tmp;

  initscr();
  cbreak();
  noecho();
  printw("lattice");
  move(6,12);
  printw("dude");
  refresh();
  cin >> tmp;
  endwin();

  Virtex v;

  return 0;
}
