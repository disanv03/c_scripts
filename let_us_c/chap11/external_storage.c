/* External Storage class
 * Storage: Memory
 * Default value: Zero
 * Scope: Global
 * Life: As long as the program's execution doesn't come to an end
 */

/* External variables differ from those we have already discussed in that
 * their scope is global, not local. External variables are declared outside
 * all functions, yet are available to all functions that care to use them. */

#include <stdio.h>

int i;
void increment();
void decrement();

int main() {
    printf("i = %d\n", i);
    increment();
    increment();
    decrement();
    decrement();
    return 0;
}

void increment() {
    i = i + 1;
    printf("on incrementing i = %d\n", i);
}

void decrement() {
    i = i - 1;
    printf("on decrementing i = %d\n", i);
}
