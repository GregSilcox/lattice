#include <iostream>
#include <curses.h>
using namespace std;

#include "virtex.h"

int main() {
  int tmp;
  int number = 1;
  int offset = 0;

  string str[14];
  str[0]  = ".wTTwggggwBgggwwh";
  str[1]  = "hwBlBgggTTBgglgwg";
  str[2]  = ".wgBmgwwTgggBTgTh";
  str[3]  = "h.ggBgwwglgBwTggT";
  str[4]  = ".wglgBwBgBTTwwwgh";
  str[5]  = "hwgTglwwmgBggBwgg";
  str[6]  = "TgggBwwTggBggwBgh";
  str[7]  = "hgBwggBggTwwBgggT";
  str[8]  = "ggwBggBgmwwlgTgwh";
  str[9]  = "hgwwwTTBgBwBgmgw.";
  str[10] = "TggTwBglgwwgBgg.h";
  str[11] = "hTgTBgggTwwgmBgw.";
  str[12] = "gwglggBTTgggBlBwh";
  str[13] = "hwwgggBwggggwTTw.";

  initscr();
  cbreak();
  noecho();

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_CYAN);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  init_pair(4, COLOR_BLACK, COLOR_BLUE);
  init_pair(5, COLOR_BLACK, COLOR_YELLOW);
  init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(8, COLOR_WHITE, COLOR_GREEN);

  for (int r = 0; r < 14; r++) {
    for (int x = 0; x < str[r].length(); x++) {
      switch(str[r][x]) {
	case '.':
	  number = 1;
	  break;
	case 'h':
	  number = 1;
	  break;
	case 'w':
	  number = 2;
	  break;
	case 'T':
	  number = 3;
	  break;
	case 'm':
	  number = 4;
	  break;
	case 'S':
	  number = 5;
	  break;
	case 'B':
	  number = 6;
	  break;
	case 'l':
	  number = 7;
	  break;
	case 'g':
	  number = 8;
	  break;
      }

      attron(COLOR_PAIR(number));

      if (str[r][0] == 'h') { 
	if (x > 0) {
          mvwprintw(stdscr, r, 2*x-1, "%c", str[r][x]);
	}

        mvwprintw(stdscr, r, 2*x, "%c", str[r][x]);
      } else {
        mvwprintw(stdscr, r, 2*x, "%c", str[r][x]);

	if (str[r][x] != 'h') {
	  mvwprintw(stdscr, r, 2*x+1, "%c", str[r][x]);
	}
      }

      attroff(COLOR_PAIR(number));
    }
  }

  refresh();
  cin >> tmp;
  endwin();

  Virtex v;

  return 0;
}
