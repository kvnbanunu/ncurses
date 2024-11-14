#ifndef EXTERNAL_H
#define EXTERNAL_H

#include <ncurses.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Entity{
    int color;
    char c;
    int16_t x;
    int16_t y;
}entity_t;

void e_print(const entity_t entity);

// colored char print
void e_print_cc(char c, int x, int y, int color);

// colored string print
void e_print_cs(char *s, int x, int y, int color);

char *itoa(int val, int base);

#endif // EXTERNAL_H
