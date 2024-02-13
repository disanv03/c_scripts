/* Calculation of simple interest */
/* Author: gekay Date: 25/06/2016 */
#include<stdio.h>

int main() {
    int p, n; /* declaration */
    float r, si; /* "" */

    p = 1000;
    n = 3;
    r = 8.5;

    /* formula for simple interest */
    si = p * n * r / 100; /* usage */

    printf("%f\n", si); /* readymade library functions */
    /* %f for real values
     * %d for integer values
     * %c for character values
     */
    return 0; /* 0 indicates success */
}

