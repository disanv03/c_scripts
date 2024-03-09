/* Copying text as well as binary files as shown below */
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fs, *ft;
    int ch;

    fs = fopen("pr1.exe", "rb");
    if (fs == NULL)
        exit(1);
    ft = fopen("newpr1.exe", "wb");

    if (ft == NULL)
        exit(2);

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
