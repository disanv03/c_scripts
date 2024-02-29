/* The entity pointer to an array is immensely useful when we need
 * to pass a 2-D array to a function.
 */
/* Three ways of accessing a 2-D array */
#include <stdio.h>
void display(int *q, int, int);
void show(int (*q)[4], int, int);

void print(int q[][4], int, int);

int main() {
    int a[3][4] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 0, 1, 6
    };
    display(a, 3, 4);
    show(a, 3, 4);
    print(a, 3, 4);
    return 0;
}

void display(int *q, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%d", *(q + i * col + j));
            /* *(base address + row no. * no. of columns + column no.) 
             * for a[2][3]
             * *(65502 + 2 * 4 + 3)
             * *(65502 + 11)
             * */
        printf("\n");
    }
    printf("\n");
}

void show(int (*q)[4], int row, int col) {
    int i, j;
    int *p;

    for (i = 0; i < row; i++) {
        p = q + i;
        for (j = 0; j < col; j++)
            printf("%d", *(p + j));
        printf("\n");
    }
    printf("\n");
}

void print(int q[][4], int row, int col) {
    int i, j;
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%d", q[i][j]);
        printf("\n");
    }
    printf("\n");
}

/* int q[][4] is the same as int (*q)[4] 
 * where q is pointer to an array of 4 integers */

