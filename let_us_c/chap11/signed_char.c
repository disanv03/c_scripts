/* Illustrates signed char range from -128 to +127 */
#include <stdio.h>

int main() {
    char ch = 291; /* Exceed the max value 127 */
    printf("\n%d %c\n", ch, ch);
    /* => 35 and '#'
     * 291 = 100100011 in 9 bits
     * becoming 00100011 in 8 bits => 35
     * ASCII character for 35 is '#'
     * */
    return 0;
}
