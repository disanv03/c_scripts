/* what would be the ouptut ? */
#include <stdio.h>
int main() {
    float a = 13.5;
    float *b, *c;
    b = &a; /* suppose address of a is 1006 */
    c = b;
    printf("%u %u %u\n", &a, b, c);
    printf("%f %f %f %f %f\n", a, *(&a), *&a, *b, *c);
    return 0;
}
