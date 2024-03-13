/* sometimes we are required to force the compiler to explicitly
 * convert the value of an expression to a particular data type. */
#include <stdio.h>
int main() {
    float a;
    int x = 6, y = 4;
    a = x / y;
    printf("value of a = %f\n", a);
    return 0;
}

/* => the answer turns out to be 1.0000 and not 1.5.
 * This is because 6 and 4 are both integers hence 6 / 4 yields and
 * integer, 1. This 1 when stored in a is converted to 1.00000.
 * But what if we don't want the quotient ot be truncated ?
 * One solution is to make x or y as float.
 * Or,
 * typecasting.
 */

#include <stdio.h>
int main() {
    float a;
    int x = 6, y = 4;
    a = (float) x / y;
    printf("Value of a = %f\n", a);
    return 0;
}

/* The expression (float) causes the variable x to be converted form type
 * int to type float before being used in the division operation. */

#include <stdio.h>
int main() {
    float a = 6.35;
    printf("Value of a on type casting = %d\n", (int) a);
    printf("Value of a = %f\n", a);
    return 0;
}


