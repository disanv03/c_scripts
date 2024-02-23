/* #pragma startup and #pragma exit:
 * These directives allow us to specify functions that are called upon
 * program startup (before main()) or pragma exit (just before the program
 * terminates).
 * */

/*#pragma startup and pragma exit directive are specific to Turbo C/C++ */
/*
#include <stdio.h>
void fun1();
void fun2();

#pragma startup fun1
#pragma exit fun2

int main() {
    printf("Inside main\n");
    return 0;
}

void fun1() {
    printf("Inside fun1\n");
}

void fun2() {
    printf("Inside fun2\n");
}
*/

/* Equivalent for GCC */
#include <stdio.h>
void fun1() __attribute__ ((constructor));
void fun2() __attribute__ ((destructor));

void fun1() {
    printf("Inside fun1\n");
}

void fun2() {
    printf("Inside fun2\n");
}

int main() {
    printf("Inside main\n");
    return 0;
}

