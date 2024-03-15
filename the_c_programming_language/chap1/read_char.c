/* copy input to output; 1st version */

#include <stdio.h>

main() {
    int c;
    
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

/* int c, to make c variable able to read EOF (-1, for example,
 * the specific numeric value doesn't matter as long as it is not the
 * same as any char value. By using the symbolic constant, we are assured
 * that nothing in the program depends on the specific numeric value.)
 *  */
