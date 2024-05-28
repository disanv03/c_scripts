#include "defs.h"

#define ENUF 3
#define EOS '\0'
#define NEXT(i) input[i++]
#define FALSE 0
#define TRUE 1

char input[] = "PI=3.14159, approximalety";

int main() {
    char c;
    int done, high, i, in, low;

    i=low=in=high=0;
    while (c= NEXT(i) != EOS)
        if (c < '0') low++;
        else if (c > '9') high++;
        else in++;
    PRINT3(d,low,in,high);

    i=low=in=high=0; done = FALSE;
    while ((c = NEXT(i)) != EOS && !done)
        if (c < '0') low++;
        else if (c > '9') high++;
        else in++;
        if (low >= ENUF || high >= ENUF || in >= ENUF)
                done = TRUE;
    PRINT3(d,low,in,high);

    i=low=in=high=0; done = FALSE;
    while ((c = NEXT(i)) != EOS && !done)
        if (c < '0') done = (++low==ENUF);
        else if (c > '9') done = (++high==ENUF);
        else done = (++in == ENUF);
    PRINT3(d,low,in,high);

    return 0;
}

/*
 * while ((c = NEXT(i)) != EOS && !done)
 * As long as the current character is not EOF and done is FALSE,
 * the loop will continue (!done making done = 1 which pass the loop)
 */
