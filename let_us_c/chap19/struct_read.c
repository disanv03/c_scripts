/* Read records form a file using structure */
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    struct emp {
        char name[50];
        int age;
        float bs;
    };

    struct emp e;

    fp = fopen("EMPLOYEE.DAT", "r");
    if (fp == NULL) {
        puts("cannot open file");
        exit(1);
    }

    while(fscanf(fp, "%s %d %f", e.name, &e.age, &e.bs) != EOF)
        printf("%s %d %f\n", e.name, e.age, e.bs);
    fclose(fp);
    return 0;
}




