/* 'magic numbers' like 300 and 20 in the previous program convey
 * little information to someone who might have to read the program later,
 * and they are hard to change in a systematic way
 *
 * One way to deal with magic numbers is to give them meaningful names.
 * A #define line defines a symbolic name or symbolic constant to be a
 * particular string of characters, thereafter, any occurence of name will 
 * replaced by the corresponding replacement text.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

}

/* The quantities LOWER, UPPER, and STEP are symbolic constants, not variables, so they do not appear in declarations. */

