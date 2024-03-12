/* The left shift << is similar to the right shift operator
 * the only difference being that the bits are shifted to the left,
 * and for each bit shifted, a 0 is added to the right of the number.
 */

#include <stdio.h>
void showbits(unsigned char);
int main() {
    unsigned char num = 225, j, k;
    printf("\nDecimal %d is the same as binary: ", num);
    showbits(num);

    for (j = 0; j <= 4; j++) {
        k = num << j;
        printf("\n%d left shift %d gives ", num, j);
        showbits(k);
    }
    return 0;
}

void showbits(unsigned char n) {
    int i;
    unsigned char j, k, andmask;
    for (i = 7; i >= 0; i--) {
        j = i;
        andmask = 1 << j;
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}
