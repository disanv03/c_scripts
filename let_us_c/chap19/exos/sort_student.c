/* Suppose a file contains student records with each record
 * containing name and age of a student.
 * Write a program to read these records and display them in a sorted
 * order by name. */

#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp;
    struct stud {
        char name[40];
        int age;
    };

    struct stud s, stud[10], temp;
    int n, j, k, ii;
    fp = fopen("student.dat", "rb");

    n = 0;

    /* fread()
     * &s -> where the data would be stored
     * sizeof(s) -> size in bytes of each element to be read
     * 1 -> number of element, each with the size above, that we read
     * fp -> stream where we read from
     *
     * returns the number of items of data successfully read.
     * less that number of element if an error occurs
     */
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        stud[n] = s;
        n++;
    }
    for (j = 0; j < n - 1; j++) {
        for (k = j + 1; k < n; k++) {
            if (strcmp(stud[j].name, stud[k].name) > 0) {
                temp = stud[j];
                stud[j] = stud[k];
                stud[k] = temp;
            }
        }
    }
    fclose(fp);
    for (j = 0; j < n; j++)
        printf("Name: %s age: %d\n", stud[j].name, stud[j].age);
    return 0;
}

        
