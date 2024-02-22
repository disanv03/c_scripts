/* Statci Storage class:
 * Storage: Memory
 * Default value: Zero
 * Scope: Local to the block
 * Life: Value of the variable persists between different function calls.
 */

#include <stdio.h>
void increment();
int main() {
    increment();
    increment();
    increment();
    return 0;
}
void increment() {
    //auto int i = 1; => 1 1 1
    static int i = 1; // => 1 2 3
    printf("%d\n", i);
    i = i + 1;
}


