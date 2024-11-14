#include "include/external.h"
#include <ncurses.h>

void e_print(const entity_t entity)
{
    attron(COLOR_PAIR(entity.color));
    mvaddch(entity.y, entity.x, entity.c);
    attroff(COLOR_PAIR(entity.color));
}

// colored char print
void e_print_cc(char c, int x, int y, int color)
{
    attron(COLOR_PAIR(color));
    mvaddch(y, x, c);
    attroff(COLOR_PAIR(color));
}

// colored string print
void e_print_cs(char *s, int x, int y, int color)
{
    attron(COLOR_PAIR(color));
    mvaddstr(y, x, s);
    attroff(COLOR_PAIR(color));
}

char *itoa(int val, int base)
{
    static char buf[32] = {0};
    
    int i = 30; // init outside cuz you need it later

    for(; val && i; --i, val /= base)
    {
        buf[i] = "0123456789abcdef"[val % base];
    }

    return &buf[i + 1];
}
