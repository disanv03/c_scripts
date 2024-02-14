/* Determine position of point with respect to a circle */
/* The center of the circle has been assumed to be at (0,0) */
#include <stdio.h>

int main() {
    int x, y, r;
    int dis, d;

    x = 2; 
    y = 2; 
    r = 3; 
           
    /* Calculate the square of the distance (hypotenuse) from the origin (0,0) to (x, y) */
    dis = x * x + y * y;
    /* Square of the radius */
    d = r * r;
    
    if (dis == d)
        printf("Point is on the circle\n");
    else {
        if (dis > d)
            printf("Point is outside the circle\n");
        else
            printf("Point is inside the circle\n");
    }
    return 0;
}
