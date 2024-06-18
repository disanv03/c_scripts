/* lower program, converts its input to lower case */

#include <stdio.h>
#include <ctype.h>

/* lower: convert input to lower case */
int main() {
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}

/* NOTE:
 * functions like getchar, putchar in stdio.h and tolower in ctype.h
 * are often macros, thus avoiding the overhead of a function call
 * per character.
 */

