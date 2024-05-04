/* Day 1:
 * Find the elf carrying the most calories.
 * How many total calories is that elf carrying?
 */

/* solution by antirez */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buf[64];
    long max = 0, sum = 0;
    while(fgets(buf,sizeof(buf),stdin) != NULL) {
        if (buf[0] == '\n' || buf[0] == '\r') {
            /* we are done with this elf. Check if it is the winner */
            if (sum > max)
                max = sum;
            sum = 0;
            continue;
        }

        /* sum this mean calories to the current elf total calories. */
        sum += strtol(buf,NULL,10);
    }
    printf("Elf with more cals has %ld cals.\n", max);
    return 0;
}
