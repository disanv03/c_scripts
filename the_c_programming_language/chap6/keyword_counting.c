/* Keyword counting program */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 1000

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */

int main() {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1]    */
int binsearch(char *word, struct keytab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

/* NOTES:
 * NKEYS: is the number of keywords in keytab.
 */

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF) /* handle Non-EOF character */
        *w++ = c;
    if (!isalpha(c)) { /* handle non-alphabetic character */
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

/* From <ctype.h> standard header
 * isspace: to skip whitespace
 * isalpha: to identify letters
 * isalnum: to identify letters and digits
 */
