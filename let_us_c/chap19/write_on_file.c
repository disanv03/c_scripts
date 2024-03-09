/* This program takes the contents of a file and copies them
 * into another file, character-by-character. */

#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fs, *ft;
    char ch;

    fs = fopen("PR1.c", "r");
    if (fs == NULL) {
        puts ("cannot open source file");
        exit(1);
    }

    ft = fopen("PR2.c", "w");
    if (ft == NULL) {
        puts("cannot open target file");
        fclose(fs);
        exit(2);
    }

    while (1) {
        ch = fgetc(fs);
        if (ch == EOF)
            break;
        else
            fputc(ch, ft);
    }
    fclose(fs);
    fclose(ft);
    return 0;
}
