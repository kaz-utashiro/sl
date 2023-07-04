#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <term.h>
void mvprintw(int y, int x, const char* fmt, const char* str) {
    tputs(tparm(tgoto(cursor_address, x, y)), 1, putchar);
    printf(fmt, str);
}
char *sl[] = {
    "      o o o o",
    "     o       ",
    "    o  ┯━━┯  ",
    "   ╒╕  │OO│  ",
    " ┌─┘└──┘  │  ",
    "┌┘        │  ",
    "┴─O=O O=O─┴ з\n"
};
int main() {
    setupterm(NULL, STDOUT_FILENO, NULL);
    int COLS = tigetnum("cols"), LINES = tigetnum("lines");
    int len = strlen(sl[0]), height = sizeof(sl)/sizeof(sl[0]);
    int start_x = COLS - len, start_y = LINES - height - 1;
    char dch2[20] = "", *dch2p = tparm(tigetstr("dch"), 2);
    if (dch2p != NULL)
        strcpy(dch2, dch2p);
    char smoke[1024]; strcpy(smoke, sl[0]); sl[0] = smoke;
    for (int x = start_x/2*2; x >= 0; x -= 2) {
        for (int y = 0; y < height; y++) {
            mvprintw(start_y + y, 0, "%s", dch2);
            mvprintw(start_y + y, x, "%s", sl[y]);
        }
        fflush(stdout);
        strcat(smoke, " o");
        usleep(100000);
    }
}
