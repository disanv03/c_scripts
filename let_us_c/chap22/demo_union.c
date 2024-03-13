/* Demo of union at work */
/* A union offers a way for a section of memory to be treated
 * as a variable of one type on one occasion, and as a different variable
 * of different type on another occasion.
 */

#include <stdio.h>
int main() {
    union a {
        short int i;
        char ch[2];
    };
    union a key;

    key.i = 512;
    printf("key.i = %d\n", key.i);
    printf("key.ch[0] = %d\n", key.ch[0]);
    printf("key.ch[1] = %d\n", key.ch[1]);
    return 0.
}

/* same memory locations that are used for key.i are also
 * being used by key.ch[0] and key.ch[1].
 * Now we can access the 2 bytes simultaneously (by using key.i) or the same
 * 2 bytes individually (using key.ch[0] and key.ch[1]).
 *
 * This is a frequent requirement while interacting with the hardware.
 */
