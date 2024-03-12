/* The & operator operates on two operands.
 * While operating upon these two operands they are compared on
 * a bit-by-bit basis.
 * Both operands must be of the same type.
 * The second operand is often called an AND mask.
 */

/* Following program illustrate:
 * (a) check whether a particular bit is ON or OFF
 * (b) turn OFF a particular bit
 */
#include <stdio.h>
void showbits(unsigned char);
int main() {
    unsigned char num = 0xAD, j;
    printf("\nValue of num = ");
    showbits(num);

    j = num & 0x20;

    if (j == 0)
        printf("\nIts fifth bit is off");
    else
        printf("\nIts fifth bit is on");
    
    j = num & 0x08;
    if (j == 0)
        printf("\nIts third bit is off");
    else {
        printf("\nIts third bit is on");

        /* turn OFF partuclar bit(third) */
        num = num & 0xF7;
        printf("\nNew value of num = ");
        showbits(num);
        j = num & 0x08;

        if (j == 0)
            printf("\nNow its third bit is turned off");
    }
    return 0;
}

void showbits(unsigned char n) {
    int i;
    unsigned char j, k, andmask;

    /* 0xAD -> 10101011 */
    /* AND to check if a particular bit is ON or OFF
     * and print the correspond representation */
    for (i = 7; i >= 0; i--) {
        j = i;
        andmask = 1 << j;
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}

    
/* A quick glance at these statements does not indicate what 
 * operations is being carried out through them.
 * Hence a better idea is to use the macro _BV as shown below.
 * #define _BV(x) (1 << x)
 * j = num & _BV(5);
 * j = num & _BV(3);
 * num = num & ~ _BV(3);
 */
