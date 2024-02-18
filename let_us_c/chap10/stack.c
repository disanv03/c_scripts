/* How does the stack works ? */
#include <stdio.h>
int add(int, int);
int main() {
    int a = 5, b = 2, c;
    c = add(a, b);
    printf("sum = %d\n", c);
    return 0;
}

int add(int i, int j) {
    int sum;
    sum = i + j;
    return sum;
}

/* In this program, before transferring the execution control to
 * the function add(), the values of parameters a and b are pushed on
 * the stack.
 * Following this, the address of the statement printf() is pushed on the
 * stack and the control is transferred to add().
 *
 * How the values are being pushed and popped even though we didn't write
 * any code to do so ? Simple - the compiler, on encountering the function
 * call, would generate code to push the parameteres and the address. 
 * Similary, it would generate code to clear the stack when the control
 * returns back from add().
