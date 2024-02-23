/* Macro templates = PI
 * Macro expansions = 3.1415 */
#include <stdio.h>
#define PI 3.1415
int main() {
    float r = 6.25;
    float area;

    area = PI * r * r;
    printf("Area of circle = %f\n", area);
    return 0;
}

/* Why use #define in the above programs ? What have we gained by
 * substituing PI for 3.1415 in our program ?
 *
 * It is nice to know that you would be able to change values of a
 * constant at all the places in the progam by just making a change
 * in the #define directive.
 * */
