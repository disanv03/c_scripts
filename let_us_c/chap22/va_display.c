/* Call a function display() which is capable of printing any number
 * of arguments of any type */

#include <stdio.h>
#include <stdarg.h>

void display(int, int, ...);
int main() {
    display(1, 2, 5, 6);
    display(2, 4, 'A', 'a', 'b', 'c');
    display(3, 3, 2.5, 299.4, -1.0);
    return 0;
}

void display(int type, int num, ...) {
    int i, j;
    char c;
    float f;
    va_list ptr;

    va_start(ptr, num);

    switch(type) {
        case 1:
            for (j = 1; j <= num; j++) {
                i = va_arg(ptr, int);
                printf("%d", i);
            }
            break;
        case 2:
            for (j = 1; j <= num; j++) {
                c = va_arg(ptr, char);
                printf("%c", c);
            }
            break;
        case 3:
            for (j = 1; j <= num; j++) {
                f = (float) va_arg(ptr, double);
                printf("%f", f);
            }
    }
    printf("\n");
}
