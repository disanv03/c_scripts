/* If we assign a value of key.i, it gets automatically assigned to key.ch[0]
 * and key.ch[1] and vice versa, if we assign a value to key.ch[0] or key.ch[1], it
 * is bound to get assigned to key.i
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

    key.ch[0] = 50; /* assign a new value to key.ch[0] */
    printf("key.i = %d\n", key.i);
    printf("key.ch[0] = %d\n", key.ch[0]);
    printf("key.ch[1] = %d\n", key.ch[1]);
    return 0;
}

