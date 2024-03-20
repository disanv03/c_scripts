/* write a program to remove trailing blanks and tabs from each line of input,
 * and delete entirely blank lines */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
int remove(char s[]);

int main() {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0)
        if (remove(line) > 0)
            printf("%s", line);
    return 0;
}

int remove(char s[]) {
    int i;
    i = 0;
    while (s[i] != '\n')
        i++;
    --i;

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}
