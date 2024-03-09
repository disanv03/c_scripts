/* Check whether a file has been opened succesfully before
 * trying to read or write to the file */

#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    fp = fopen("PR1.c", "r");
    if (fp == NULL) {
        puts("cannot open file");
        exit(1);
    }
    return 0;
}

