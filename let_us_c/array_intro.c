#include <stdio.h>

int main() {
    int avg, sum = 0;
    int i;
    int marks[30]; /* array declaration */

    for (i = 0; i <= 29; i++) {
        printf("Enter marks");
        scanf("%d", &marks[i]); /* store data in array */
    }

    for (i = 0; i <= 29; i++) 
        sum = sum + marks[i]; /* read data from an array */

    avg = sum / 30;
    printf("Average marks = %d\n", avg);
    return 0;
}

/*
 * (a) an array is a collection of similar elements
 * (b) the first element in the array is numbered 0,
 * so the last element is 1 less than the size of the array
 * (c) an array is also know as a subscripted variable
 * (d) before using an array, its type and dimension must be declared
 * (e) however big an array, its elements are always stored in contiguous
 * memory locations.
 * */
