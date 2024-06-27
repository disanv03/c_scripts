/* calculate the power of a given number */
#include <stdio.h>

/* power: number power of n */
int power(int number, int n) {
    int count, result = 1;

    for (count = 1; count <= n; count++)
        result *= number;

    return result;
}
