/* Program that sort a set of text lines into alphabetic order,
 * a stripped-down version of the UNIX program 'sort'.
 */

/* input -> collect and save the charaters of each line, and build an
 * array of pointers to the lines.
 *
 * output -> print the lines in the order in which they appear in the array 
 * of pointers.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000           /* max #lines to be sorted      */

char *lineptr[MAXLINES];        /* pointers to text lines       */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines     */
int main() {
    int nlines;                 /* number of input lines read   */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000             /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p = alloc(len) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline       */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write ouput lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
