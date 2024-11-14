#include <ncurses.h>

int main()
{
    // initializes the screen
    // sets up memory and clears the screen
    initscr();

    // check if terminal supports color
    if(has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        getch();
        return 0;
    }

    start_color();
    // creates the color pair, (index, foreground, background)
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    // access the color
    // pass COLOR_PAIR(index);
    
    // clears terminal
    clear();

    // prints a string(const char *) to a window
    printw("Hello World!");

    // refreshes the screen to match whats in memory
    refresh();

    // waits for user input, returns int value of that key
    getch();

    // removes cursor highlighter
    curs_set(0);

    // allows special chars like arrow keys
    keypad(stdscr, true);

    // prevents printing from keyboard to terminal
    noecho();

    // allows exit with <C-c>
    cbreak();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}
