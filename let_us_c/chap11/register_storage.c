/* Register storage:
 * Storage: CPU registers
 * Default value: Garbage value
 * Scope: Local to the block
 * Life: Till the control remains within the block
 */

#include <stdio.h>
int main() {
    register int i;
    for (i = 1; i <= 10; i++)
        printf("%d\n", i);
    return 0;
}
