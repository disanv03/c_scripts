/* Read strings from the file and display them on screen */
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char s[80];
    fp = fopen("POEM.txt", "r");
    if (fp == NULL)
        exit(1);
    while (fgets(s, 79, fp) != NULL)
        printf("%s", s);

    printf("\n");
    fclose(fp);
    return 0;
}
