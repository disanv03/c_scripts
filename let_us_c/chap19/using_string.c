/* Receives strings from keyboard and writes them to file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    FILE *fp;
    char s[80];
    fp = fopen("POEM.txt", "w");
    if (fp == NULL) {
        puts("cannot open file");
        exit(1);
    }
    printf("\nEnter a few lines of text:\n");
    while (fgets(s, sizeof(s), stdin) != NULL && s[0] != '\n') {
        fputs(s, fp);
    }
    fclose(fp);
    return 0;
}
