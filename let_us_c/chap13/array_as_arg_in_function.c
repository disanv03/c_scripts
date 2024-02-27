/* Passing an entire array to a function */
/* How to pass an entire array to a function rather than
 * its individual elements
 * */

#include <stdio.h>
void display(int *, int);
int main() {
    int num[] = {24, 34, 12, 44, 56, 17};
    display(&num[0], 6);
    return 0;
}

void display(int *j, int n) {
    int i;
    for (i = 0; i <= n - 1; i++) {
        printf("element = %d\n", *j);
        j++; /* increment pointer to point to next element */
    }
}

/* The addresss of the zeroth element (called base address) can also 
 * be passed by just passing the name of the array.
 * Thus the following are the same:
 * display(&num[0], 6);
 * display(num, 6);
 * */
