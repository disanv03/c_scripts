/* Implement the insertion sort algorithms */

/* Insertion sort */
#include <stdio.h>
int main() {
    int a[25], i, j, k, t;
    printf("\nEnter 25 numbers:\n");
    for (i = 0; i <=24; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= 24; i++) {
        t = a[i];
        for (j = 0; j < i; j++) {
            if (t < a[j]) {
                for (k = i; k >= j; k--)
                    a[k] = a[k - 1]; /*shift elements to left */
                a[j] = t;
                break;
            }
        }
    }
    printf("\nSorted Numbers are:\n");
    for (i = 0; i <= 24; i++)
        printf("%d\n", a[i]);
    return 0;
}
