/* --- Part Two ---
 * Find the top three Elves carrying the most calories.
 * How many calories are those Elves carrying in total ?
 */

/* solution by antirez */
#include <stdio.h>
#include <stdlib.h>

/* take a list of the 'n' top scores observed. */
void updateNMax(long *max, int n, long sum) {
    for (int j = 0; j < n; j++) {
        if (sum <= max[j]) continue;
        /* move all the lower-rank scores one position down and update */
        for (int k = n - 1; k > j; k--) max[k] = max[k-1];
        max[j] = sum;
        break;
    }
}

int main(void) {
    char buf[64];
    long max[3] = {0}, sum = 0;
    while(fgets(buf,sizeof(buf),stdin) != NULL) {
        if (buf[0] == '\n' || buf[0] == '\r') {
            /* we are done with this elf. update the top three scores. */
            updateNMax(max, 3, sum);
            sum = 0;
            continue;
        }

        /* sum this meal calories to the current elf total calories. */
        sum += strtol(buf,NULL,10);
    }
    printf("Top three elfs with more cals have %ld cals.\n", max[0]+max[1]+max[2]);
    return 0;
}


