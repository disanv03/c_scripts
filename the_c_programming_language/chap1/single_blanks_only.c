/* write a program to copy its input to its ouput, 
 * replacing each string of one or more blanks by a single blank
 */

#include <stdio.h>
#define NONBLANK 'a'

int main() {
    int c, lastc;
    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        if (c == ' ')
            if(lastc != ' ')
                putchar(c);
        lastc = c;
    }
}

/* with if-else statement */

int main() {
    int c, lastc;

    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        else if (lastc != ' ')
            putchar(c);
        lastc = c;
    }
}

/* with the logical OR (||) operator */

int main() {
    int c, lastc;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
