/* An array of pointers can even contain the addresses of
 * other arrays */
#include <stdio.h>

int main() {
    static int a[] = {9, 1, 2, 3, 4};
    int *p[] = {a, a + 1, a + 2, a + 3, a + 4};
    printf("%u %u %d\n", p, *p, *(*p));
    return 0;
}
