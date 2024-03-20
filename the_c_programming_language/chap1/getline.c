/* Write a function getline to fetch the next line of input 
 * When we find a line that is longer than the previous longest line,
 * it must be saved somewhere, we will write a second function, copy, for that.
 */

/* Here the program to control getline and copy */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%d\n", len);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }   
    if (max > 0) /* there was a line */
        printf("Longest line: %s", longest);

    return 0;
}

/* getline: read a line into s, return length */
/* 'i' track the total number of characters read, including beyound the buffer limit
 * 'j' track the number of character actually stored in the buffer s[]
 */
int get_line(char s[], int lim) {
    int c, i, j;
    j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim-2) {
        s[j] = c; /* line still in boundaries */
        ++j;
        }
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


