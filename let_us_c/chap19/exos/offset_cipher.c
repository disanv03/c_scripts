/* Write a program to encrypt/decrypt a file */
/* Offset cipher */

#include <stdio.h>
#include <stdlib.h>
FILE *fs, *ft;
void code();
void decode();

/* argc -> argument count
 * *argv -> argument vector, each element in this array is a C string
 * representing one of the command-line arguments.
 * argv[0] -> name of the program
 * argv[argc] -> NULL
 */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        puts("Improper usage. Correct usage is:\n");
        puts("command <source file> <target file> <C/D>\n"); /* C/D code or decode */
        exit(1);
    }

    fs = fopen(argv[1], "r");
    if (fs == NULL) {
        printf("cannot open source file\n");
        puts(argv[1]);
        exit(2);
    }
    ft = fopen(argv[2], "w");
    if (ft == NULL) {
        puts("cannot open target file\n");
        puts(argv[2]);
        fclose(fs);
        exit(3);
    }

    if (*argv[3] == 'c' || *argv[3] == 'C')
        code();
    else
        decode();
    fclose(fs);
    fclose(ft);
    printf("Mission accomplished\n");
    return 0;
}

void code() {
    int ch;
    while ((ch = getc(fs)) != EOF) {
        ch = ch + 128; /* encrypt */
        putc(ch, ft);
    }
}

void decode() {
    int ch;
    while ((ch = getc(fs)) != EOF) {
        ch = ch - 128; /* decrypt */
        putc(ch, ft);
    }
}
