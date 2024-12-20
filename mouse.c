#include <ncurses.h>

int main() {
    initscr();               // Initialize ncurses
    keypad(stdscr, TRUE);    // Enable keyboard input
    mousemask(ALL_MOUSE_EVENTS, NULL); // Enable all mouse events
    start_color();           // Enable color support
    noecho();                // Don't echo input
    cbreak();                // Disable line buffering

    // Define colors
    init_pair(1, COLOR_WHITE, COLOR_BLUE); // Highlight color
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // Normal color

    int rows = 5, cols = 5;  // Grid size
    int cell_width = 10;     // Cell width
    int cell_height = 3;     // Cell height
    MEVENT event;

    // Draw the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mvprintw(i * cell_height, j * cell_width, "+----------");
            for (int k = 1; k < cell_height; k++) {
                mvprintw(i * cell_height + k, j * cell_width, "|          ");
            }
        }
    }
    refresh();

    int ch;
    while ((ch = getch()) != 'q') { // Press 'q' to exit
        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) { // Left mouse button clicked
                    int row = event.y / cell_height;
                    int col = event.x / cell_width;

                    if (row < rows && col < cols) { // Ensure click is inside grid
                        // Highlight the selected cell
                        for (int k = 0; k < cell_height; k++) {
                            mvchgat(row * cell_height + k, col * cell_width, cell_width, A_NORMAL, 1, NULL);
                        }
                        refresh();
                    }
                }
            }
        }
    }

    endwin(); // End ncurses mode
    return 0;
}

