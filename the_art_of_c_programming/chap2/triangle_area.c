/* compute area of a triangle given its sides a, b and c using
 * Heron formula */

#include <stdio.h>
#include <math.h>

/* to form a triangle, the sum of the lengths of any two sides
 * must be greater than the length of the third side
 * a + b > c
 * a + c > b
 * b + c > a
 */
int is_valid_triangle(double a, double b, double c) {
    return (a+b>c) && (a+c>b) && (b+c>a);
}

/* triangle_area: calcualte the area of a triangle using Heron's formula */
double triangle_area(double a, double b, double c) {
    if (!is_valid_triangle(a, b, c)) {
        printf("impossible triangle\n");
        return -1;
    }
    
    double s = (a+b+c) / 2;
    double area = sqrt(s * (s-a) * (s-b) * (s-c));
    return area;
}

int main() {
    double a, b, c;
    printf("enter the sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double area = triangle_area(a, b, c);
    if (area != -1) {
        printf("the area of the triangle is: %lf\n", area);
    }
    return 0;
}

