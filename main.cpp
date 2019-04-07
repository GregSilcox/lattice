#include <iostream>
#include <curses.h>
using namespace std;

int main() {
  initscr();
  printw("lattice");
  refresh();
  return 0;
}
