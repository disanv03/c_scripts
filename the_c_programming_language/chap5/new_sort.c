/* Sorts lines of text either numerically or lexicographically (alphabetically */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max #lines to be sorted      */
char *lineptr[MAXLINES]; /* pointers to text lines      */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        /* calls the quicksort function.
         * It casts lineptr to void** and choose the comparison function:
         * numcmp: for numeric sorting
         * strcmp: for lexicographic sorting
         */
        qsort((void**) lineptr, 0, nlines-1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* The use of void * provides flexibility, enabling the function
 * to sort any type of data.
 * int (*comp) (void *, void *) :
 * pointer to a comparison function either numcmp or strcmp
 * To pass these functions to qsort, we need to cast them to match the
 * expected prototype.
 * The cast ensures that both numcmp and strcmp are treated as functions
 * that take two void* arguments and return an int.
 */
