/* One's complement operator ~
 * On taking one's complement of a number, all 1's present in the number
 * are changed to 0's and all 0's are changes to 1's.
 * One's complement of 1010 is 0101.
 */

#include <stdio.h>
int main() {
    unsigned char ch = 32;
    unsigned char dh;

    dh = ~ch;
    printf("~ch = %d\n", dh);
    printf("~ch = %x\n", dh); /* hex printed in smallcast */
    printf("~ch = %X\n", dh); /* hex printed in capital */

    return 0;
}
