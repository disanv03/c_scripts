/* In canonical(cooked) mode the input is processed in lines.
 * In now-canonical mode (raw mode) the terminal input is made available
 * immediately to the program.
 * Curses for cursor optimization.
 * ncruses open source implementation of the curses lib (BSD)
 * ncurses.h, library for handling i/o.
 * ncurses, handles the screen and input requiring initialization and
 * cleanup routines.
 */

#include <stdio.h>
#include <ncurses.h>

int main() {
    char ch;

    initscr(); /* init ncruses */
    cbreak(); /* disable line buffering, half-cooked */
    noecho(); /* disable automatic echoing of ch read by getch */

    printw("Press any key to continue"); /* w for window */
    ch = getch(); /* read ch without echoing */
    refresh(); /* transfers contents of vitual to physical screen */

    printw("\nType any character: ");
    echo(); /* enable echoing */
    ch = getch(); /* read and echo it */
    noecho();
    refresh();

    printw("\nType any character");
    ch = getch(); /* ch immediately available */
    refresh();

    printw("\nContinue Y/N");
    ch = getch(); /* still in cbreak mode, getch reads without waiting for
                     enter */
    refresh();

    endwin(); /* end ncurses mode */

    return 0;
}


/* NOTE:
 * The buffering mechanism allows for more efficient screen updates
 * because it minimizes the number of changes that need to be made
 * to the physical screen.
 * refresh() apply changes simultaneously for better physical screen performance
 */
