#include <stdio.h>

#define PRINTX printf("%d\n", x)

int main() {
    int x = 2, y, z;

    x *= 3 + 2; PRINTX; /* 10 */
    x *= y = z = 4; PRINTX; /* 40 */
    x = y == z; PRINTX; /* 1 */
    x == (y = z); PRINTX; /* 1 */
}
