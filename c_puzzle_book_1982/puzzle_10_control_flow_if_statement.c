#include "defs.h"

int main() {
    int x, y = 1, z;

    if (y != 0) x = 3;
    PRINT1(d, x);

    if (y == 0) x = 3;
    else x = 5;
    PRINT1(d, x);

    x = 1;
    if (y < 0) if (y > 0) x = 3; /* nested if is never evaluated because the parent condition is false */
    else x = 5; /* the else statement is associated with the closest if */
    PRINT1(d, x);

    if (z = y < 0) x = 3;
    else if (y == 0) x = 5; /* since both if and else if conditions are 'false', the program executes the else block */
    else x = 7;
    PRINT2(d, x, z);

    if (z = (y == 0)) x = 5; x = 3; /* if block not executed, x = 3 is not part of the if block */
    PRINT2(d, x, z);

    if (x = z = y); x = 3;
    PRINT2(d, x, z);

    return 0;
}
