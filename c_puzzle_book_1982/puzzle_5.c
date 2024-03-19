/* Operators 5: Relational and Conditional Operators */

#include <stdio.h>
#define PRINT(int) printf("int = %d\n", int)

int main() {
    int x = 1, y = 1, z = 1;

    x += y += z;
    PRINT(x < y ? y : x);

    PRINT(x < y ? x++ : y++);
    PRINT(x); PRINT(y);

    PRINT(z += x < y ? x++ : y++);
    PRINT(y); PRINT(z);

    x = 3; y = z = 4;
    PRINT((z >= y >= x) ? 1 : 0); /* frist evaluates (x >= y) which is implicitly converted in "true" which is 1 */
    PRINT(z >= y && y >= x);

    return 0;
}

