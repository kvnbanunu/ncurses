#include "include/game.h"
#include <ncurses.h>
#include <stdio.h>

int main(void)
{
    initscr();
    curs_set(0);

    if(has_colors() == FALSE)
    {
        endwin();
        fprintf(stderr, "Your terminal does not support color\n");
        getch();
        return 0;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    keypad(stdscr, true);
    noecho();
    cbreak();

    refresh();

    setup(50, 20);
    play();

    getch();

    endwin();
    return 0;
}
