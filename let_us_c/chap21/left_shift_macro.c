/* left shift to create a number with a particular
 * bit in it set to 1 are required quite often while writing programs
 * that interact with hardware. Hence it is often done using 
 * a macro
 */

#define _BV(x) (1 << x)
#include <stdio.h>

int main() {
    unsigned char a;

    /* create a value (bit value) */
    a = _BV(3);
    printf("a = %02x", a);
    return 0;
}
