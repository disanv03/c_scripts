/* The next program counts input lines.
 * Input text stream appears as a sequence of lines, each terminated
 * by a newline.
 */

#include <stdio.h>
main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
            if (c == '\n')
                ++nl;
    printf("%d\n", nl);
}
