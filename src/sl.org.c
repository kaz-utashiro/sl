#include	<curses.h>
#include	<signal.h>

#define		NCOLS	(COLS-1)
#define		NLINES	(LINES)
#define		NL	'\012'
#define		MLINE	24
#define		MCOL	300

char *ban[] = {
	"      o    ",
	"     o     ",
	"    o  ____",
	"   --  |OO|",
	"  _||__|  |",
	" |        |",
	"/-O=O O=O--"
};

main (argc, argv) 
int	argc;
char	*argv[];
{
	reg char	c;
	int		die ();
	reg int		i, j;
	reg int		ceil;
	reg int		width = 11;

	initscr();
	signal(SIGINT,die);
	noecho();
	nonl();
	leaveok(stdscr,TRUE);
	scrollok(stdscr,FALSE);

	ceil = (LINES-7)/2;
	for (i=0; i <= width; i++) {
		for (j=0; j < 7; j++) {
			move(j + ceil, 0);
			delch();
			move(j + ceil, NCOLS-2);
			addch(*(ban[j]+i));
		}
		refresh();
	}
	for (i=NCOLS; i ; i--) {
		for (j=0; j < 7; j++) {
			move(j + ceil, 0);
			delch();
		}
		refresh();
	}
	die();
}


die()
{
	signal(SIGINT,SIG_IGN);
	mvcur(0,COLS-1,LINES-1,0);
	endwin();
	exit(0);
}
