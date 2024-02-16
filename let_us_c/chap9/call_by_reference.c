/* sending the addresses of the arguments */
#include <stdio.h>
void swapr(int *, int *);
int main() {
    int a = 10, b = 20;
    swapr(&a, &b);
    printf("a = %d b = %d\n", a, b);
    return 0;
}

void swapr(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

/* Using a call by reference intelligently, we can make a function return
 * more than one value at a time, which is not possible ordinaly */
