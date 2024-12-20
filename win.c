#include <ncurses.h>

int main()
{
    initscr();
    curs_set(0);
    cbreak();
    noecho();

    if(has_colors() == FALSE)
    {
        endwin();
        printw("Your terminal does not support color");
        getch();
        return 0;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    int mh;
    int mw;
    getmaxyx(stdscr, mh, mw);

    WINDOW *w1 = newwin(mh * 0.55, mw * 0.55, mh * 0.05, mw * 0.05);
    WINDOW *w2 = newwin(mh * 0.55, mw * 0.30, mh * 0.05, mw * 0.65);
    WINDOW *w3 = newwin(mh * 0.30, mw * 0.90, mh * 0.65, mw * 0.05);
    
    box(stdscr, 0, 0);
    box(w1, 0, 0);
    box(w2, 0, 0);
    box(w3, 0, 0);

    mvwaddch(w1, 5, 1, '@' | COLOR_PAIR(2));
    mvwaddch(w1, 4, 1, '@' | COLOR_PAIR(2));
    mvwaddch(w1, 3, 1, '@' | COLOR_PAIR(2));
    mvwaddch(w1, 2, 1, '@' | COLOR_PAIR(2));
    mvwaddch(w1, 1, 1, '@' | COLOR_PAIR(2));
    mvwaddstr(w2, 1, 1, "Level 1");
    mvwaddstr(w3, 1, 1, "Evin Died");

    refresh();
    wrefresh(w1);
    wrefresh(w2);
    wrefresh(w3);

    getch();

    wclear(w1);

    mvwaddch(w1, 1, 1, '@' | COLOR_PAIR(1));
    wrefresh(w1);




    getch();
    delwin(w1);
    delwin(w2);
    delwin(w3);
    endwin();
    return 0;
}
