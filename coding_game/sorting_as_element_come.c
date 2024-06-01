/* Find the position to insert X (a number) in a sorted way
 * in an array called sorted_array.
 * Insertion sort algorithm.
 *
 * input =>
 * 5
 * 34
 * 23
 * 45
 * 12
 * 30
 * 
 * output =>
 * sorted_array: [45, 34, 30, 23, 12]
 */

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int sorted_array[N];

    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);

        /* find the position to insert X in sorted_array (desc order),
         * and shifting element at the same time.
         */
        int j = i;
        while (j > 0 && sorted_array[j - 1] < X) {
            sorted_array[j] = sorted_array[j - 1];
            j--;
        }
        sorted_array[j] = X;
    }

    /* printing all elements of sorted_array */
    for (int i = 0; i < N; i++) {
        if (i < N - 1) {
            printf("%d ", sorted_array[i]);
        } else {
            printf("%d", sorted_array[i]);
        }
    }

    return 0;
}


