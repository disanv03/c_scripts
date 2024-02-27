/* If an array "arr" contains n elements, then write a program to check
 * if arr[0] = arr[n-1], arr[1] = arr[n-2] and do on.
 */

/* Program to check if arr[0] = arr[n-1] and so on */
#include <stdio.h>
int main() {
    int arr[10], i, j;
    printf("\nEnter 10 elements of array:\n");
    for (i = 0; i <= 9; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i <= 4; i++) {
        printf("arr[%d] and arr[%d] are", i, 10 - (i + 1));
        if (arr[i] == arr[10 - (i + 1)])
            printf("equal\n");
        else 
            printf("unequal\n");
    }
    return 0;
}
