/* XOR operator is used to toggle (change) a bit ON or OFF. */

#include <stdio.h>
int main() {
    unsigned char b = 0x32; /* binary 00110010 */
    b = b ^ 0x0C; /* 0x0C -> binary 00001100 */
    printf("\n%02x", b); /* this will print 0x3E -> 00111110 */
    b = b ^ 0x0C;
    printf("\n%02x", b); /* this will print 0x32 */

    return 0;
}
