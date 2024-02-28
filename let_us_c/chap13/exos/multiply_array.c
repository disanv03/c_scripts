/* Program to pass the entire array & multiply each element by 3 */
#include <stdio.h>
void modify(int *arr, int n);
int main() {
    int i;
    static int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("\nOriginal Array is:\n");
    for (i = 0; i < 10; i++)
        printf("%d", array[i]);
    modify(array, 10);
    printf("\n\nModified Array is:\n");
    for (i = 0; i < 10; i++)
        printf("%d", array[i]);
    return 0;
}

void modify(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        *arr = *arr * 3;
        arr++;
    }
}

