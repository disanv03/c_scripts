/* Circular shifting of values */
#include <stdio.h>
void fun(int, int, int);
int main() {
    int x, y, z;
    printf("Enter the values x, y, z:\n");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nx = %d\ty = %d\t z = %d\n", x, y, z);
    fun(x, y, z);
    return 0;
}

/* Function to shift values of x, y & z */
void fun(int x, int y, int z) {
    int i, t;
    for (i = 0; i <= 2; i++) {
        t = z;
        z = y;
        y = x;
        x = t;
        printf("\nAfter right shifting %d time(s):\n", i + 1);
        printf("x = %d\ty = %d\tz = %d", x, y, z);
    }
}
