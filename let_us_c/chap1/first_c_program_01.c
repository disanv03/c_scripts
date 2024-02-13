/* Calculation of simple interest */
/* Author: gekay Date: 25/06/2016 */
#include<stdio.h>

int main() {
    int p, n; 
    float r, si; 

    printf("Enter values of p, n,r");
    scanf("%d %d %f", &p, &n, &r);
    /* blank, tab or a new line must separate the values supplied to scanf() */

    /* formula for simple interest */
    si = p * n * r / 100; 
    printf("%f\n", si); 
    return 0; 
}

