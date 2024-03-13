/* Functions with variable number of arguments
 * There macros in stdarg.h
 * va_start, va_arg and va_list
 * The fixed number of arguments are accessed in the normal way, whereas
 * the optional arguments are accessed using the marcros va_start and va_arg.
 *
 * Let us put these concepts into action */

#include <stdio.h>
#include <stdarg.h>
int findmax(int, ...);
int main() {
    int max;
    max = findmax(5, 23, 15, 1, 92, 50);
    printf("maximum = %d\n", max);

    max = findmax(3, 100, 300, 29);
    printf("maximum = %d\n", max);
    return 0;
}

int findmax(int tot_num, ...) {
    int max, count, num;
    /* va -> variable arguments */
    va_list ptr; /* ptr of type va_list */
    va_start(ptr, tot_num); /* points to the first variable in arg list */
    max = va_arg(ptr, int); /* 23 is assigned to max */

    for (count = 1; count < tot_num; count++) {
        num = va_arg(ptr, int);
        if (num > max)
            max = num;
    }
    return 0;
}

/* Note that for each call of findmax() the first argument is
 * the count of arguments that follow the first argument.
 *
 * Each call to va_arg(ptr, int) retrieves the next integer argument from the list
 * and increments the internal pointer maintained by va_list ptr to point to the 
 * subsequent argument.
 */
