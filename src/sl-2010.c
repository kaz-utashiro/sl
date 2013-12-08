#include <unistd.h>
#include <curses.h>

char *sl[] = {
	"      o o o",
	"     o  ",
	"    o  ____  ",
	"   --  |OO|  ",
	"  _||__|  |  ",
	" |        |  ",
	"/-O=O O=O--  "
};

int main() 
{
	int x, y;
	initscr();
	for (x = COLS - 13; x > 0; x -= 2) {
		for (y = 0; y < 7; y++)
			mvprintw(y + LINES - 7, x, "%s", sl[y]);
		refresh();
		usleep(100000);
	}
	/* endwin(); */
}
