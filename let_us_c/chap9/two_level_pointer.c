/* Two-level indirection, allowing access of 'i's value,
 * through two layers of pointers */
#include <stdio.h>
int main() {
    int i = 3;
    int *j;
    int **k;

    j = &i;
    k = &j;

    printf("Value of i: %d\n", i);
    printf("Value of i via j: %d\n", *j); /* indirect */
    printf("Value of i via k: %d\n", **k); /* double-indirect */

    return 0;
}
