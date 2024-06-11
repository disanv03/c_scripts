/* Pointers to structures 
 * To illustrate some of the considerations involved with pointers
 * to array of structures, let us write the keyword-counting program
 * again.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100 /* max length of a word */

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

struct key {
    char *word; /* keyword */
    int count;
};

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"while", 0}
};

#define NKEYS (sizeof(keytab) / sizeof(keytab[0])) /* number of keywords */

/* count C keywords; pointer version */
int main() {
    char word[MAXWORD]; /* buffer to hold the current word */
    struct key *p; 

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            /* perform binsearch for the word in the keytab array */
            if ((p=binsearch(word, keytab, NKEYS)) != NULL)
                p->count++; /* increment the count if the word is found */

    /* print the counts for each keyword */
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n) {
    int cond; /* result of strcmp */
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high-low) / 2; /* compute the middle element */
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid; /* search the lower half */
        else if (cond > 0)
            low = mid + 1; /* search the upper half */
        else
            return mid; /* word found */
    }
    return NULL; /* word not found */
}

/* binsearch finds the word, it returns a pointer to it */



