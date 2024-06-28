/* write abs function */
#include <stdio.h>

int my_abs(int x) {
    if (x < 0)
        return -x;      /* -(-5) = 5 */
    else
        return x;
}

int main() {
    int num;
    num = -5;

    printf("the absolute value of %d is %d\n", num, my_abs(num));

    return 0;
}
