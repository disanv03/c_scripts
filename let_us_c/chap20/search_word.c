/* Write a program using command-line arguments
 * to search for a word in a file and replace it with specified word.
 * usage:
 * change <old word> <new word> <filename>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fs, *ft;
int newstr(char *, char *, char *);

int main(int argc, char *argv[]) {
    char str[80];
    int newstr(char *s, char *t, char *n);
    if (argc != 4) {
        puts("improper number of arguments\n");
        exit(1);
    }
    fs = fopen(argv[3], "r");
    printf("%s \n %s \n %s \n %s", argv[0], argv[1], argv[2], argv[3]);

    if (fs == NULL) {
        puts("unable to open source file \n");
        exit(2);
    }

    ft = fopen("temp.txt", "w");
    if (ft == NULL) {
        fclose(fs);
        exit(3);
    }

    while (fgets(str, 79, fs) != NULL)
        newstr(str, argv[1], argv[2]);
    fclose(fs);
    fclose(ft);
    remove(argv[3]);
    rename("temp.txt", argv[3]);
    return 0;
}

int newstr(char *line, char *search, char *replace) {
    char *p;
    int offset;
    char pre[80], post[80], final[80];
    p = strstr(line, search);
    if (p == NULL)
        return;

    offset = p - line;
    strncpy(pre, line, offset);
    pre[offset] = "\0";
    strcpy(post, p + strlen(search));
    strcpy(final, pre);
    strcat(final, replace);
    strcat(final, post);
    fputs(final, ft);
}

