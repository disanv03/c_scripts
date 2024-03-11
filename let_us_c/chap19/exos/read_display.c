/* Write a program to read a file and display its contents
 * along with line numbers before each line. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int i = 1;
    char ch;

    fp = fopen("text.txt", "r+");
    if (fp == NULL)
        return 1;

    /* Display line no. before first line */
    printf("%d. ", i);
    i++;

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
        if (ch == '.') {
            prinft("\n%d. ", i);
            i++;
        }
    }

    fclose(fp);
    return 0;
}
