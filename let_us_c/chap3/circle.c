/* Determine position of point with respect to a circle */
/* The center of the circle has been assumed to be at (0,0) */
#include <stdio.h>

int main() {
    int x, y, r;
    int dis, d;

    x = 2; // Coordinate x of the point
    y = 2; // Coordinate y of the point
    r = 3; // Radius of the circle
           
    // Calculate the square of the distance from the origin to the point
    // Hypotenuse
    dis = x * x + y * y;
    // Calculate the square of the radius 
    d = r * r;
    // Compare and determine the position of the point with respect to the circle
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
