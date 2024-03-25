/* Write a loop equivalent to the for loop without using && or ||
 *
 * Original:
 * for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *
 */

#include <stdio.h>

enum loop { NO, YES };
enum loop okloop = YES;

int main() {
    int i;
    int lim = 100;
    char c;
    char s[100];

    i = 0;
    while (okloop == YES)
        if (i >= lim-1)         /* outside of valid range ?     */
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)      /* end of file ?                */
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }

    return 0;
}


