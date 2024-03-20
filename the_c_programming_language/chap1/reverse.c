/* write a function reverse(s) that reverse the character string s */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

main() {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

void reverse(char s[]) {
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')
        ++i;
    --i;
    if (s[i] == '\n')
        --i;
    j = 0;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}

/* function get_line() is the same as other exercice */
