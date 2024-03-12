/* The left shift operator is often used to create a number with a particular
 * bit in it set to 1.
 */
#include <stdio.h>
int main() {
    unsigned char a;
    a = 1 << 3;
    printf("a = %02x", a);
    return 0;
}
