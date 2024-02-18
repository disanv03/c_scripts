/* Binary equivalent of a decimal number */
#include <stdio.h>
int binary(int );
int main() {
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &num);
    binary(num);
    return 0;
}

int binary(int n) {
    int r;
    r = n % 2; /* determine the lest significant bit */
    n = n / 2; /* shift to the right */

    if (n == 0) {
        printf("\nThe binary equivalent is %d", r);
        return r;
    } 
    else 
        binary(n); /* recursive call */
    printf("%d", r);
}


