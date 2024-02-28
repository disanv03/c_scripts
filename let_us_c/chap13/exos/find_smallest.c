/* Write a program using pointers to find the smallest number in
 * an array of 25 integers
 * */

/* Program to find the smallest element using pointer */
#include <stdio.h>
int main() {
    int arr[25], i, n;
    printf("\nEnter 25 elements of array:\n");
    for (i = 0; i <= 24; i++)
        scanf("%d", &arr[i]);
    n = *arr;
    for (i = 0; i <= 24; i++) {
        if (*(arr + i) < n) /* equivalent of arr[i] < n */
            n = *(arr + i);
    }
    printf("Smallest number in array is %d\n", n);
    return 0;
}
