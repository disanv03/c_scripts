/* Specifiying field width for creating tables of numeric values */
#include <stdio.h>
int main() {
    /* no lined up */
    printf("%f %f %f\n", 5.0, 13.5, 133.9);
    printf("%f %f %f\n", 305.0, 1200.9, 3005.3);

    /* lined up */
    printf("%10.1f %10.1f %10.1f\n", 5.0, 13.5, 133.9);
    printf("%10.1f %10.1f %10.f\n", 305.0, 1200.9, 3005.3);

    return 0;
}
