/* Subtraction of one pointer from another */
#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 45, 67, 56, 74};
    int *h, *i, *j, *k;

    i = &arr[1];
    j = &arr[5];

    printf("%d %d\n", i, j);

    printf("%d %d\n", j - i, *j - *i);
    return 0;
}
