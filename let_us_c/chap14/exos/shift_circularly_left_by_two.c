/* Given an array p[5], write a function to shift it circularly left
 * by two positions. Thus, if the original array is {15, 30, 28, 19, 61}
 * then after shifting it will be {28, 19, 61, 15, 30}
 * Call this function for a 4 x 5 matrix and get its rows left shifted
 */

/* Circular rotation of array elements and its use in matrix */
#include <stdio.h>

void swap(int *);
int main() {
    int p[4][5];
    int i, j;
    /* Enter data for a matrix */
    for (i = 0; i <= 3; i++) {
        printf("\nEnter the %d row elements:\n", i);
        for (j = 0; j <= 4; j++)
            scanf("%d", &p[i][j]);
    }
    /*Print the matrix as entered */
    printf("\nMatrix elements as entered:");
    for (i = 0; i <= 3; i++) {
        printf("\nThe %d row elements: ", i);
        for (j = 0; j <= 4; j++)
            printf("\t%d", p[i][j]);
    }
    printf("\n");

    swap(p); /* base address of array passed to function */

    /* Print the new matrix after left shifting */
    printf("\nMatrix after left shifting the row elements:");
    for (i = 0; i <= 3; i++) {
        printf("\nThe %d row elements: ", i);
        for (j = 0; j <= 4; j++)
            printf("\t%d", p[i][j]);
    }
    return 0;
}

/* Function for left shifting of the rows */
void swap(int *p) {
    int k, i, tt, t, j;
    for (k = 0; k <= 3; k++) { /* 4 rows to be shifted */
        for (i = 0; i <= 1; i++) { /* shifting donce twice */
            t = *(p + k * 5 + 0);
            for (j = 0; j <= 3; j++) {
                tt = *(p + k * 5 + j);
                *(p + k * 5 + j) = *(p + k * 5 + j + 1);
                *(p + k * 5 + j + 1) = tt;
            }
            *(p + k * 5 + j) = t;
        }
    }
}


