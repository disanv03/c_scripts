/* The core of the OS assigns each process running in memory
 * a unqie ID, often known as PID.
 */

#include <stdio.h>
#include <unistd.h>
int main() {
    printf("Process ID = %d", getpid());
    return 0;
}

/* would print the running instance PID of the program itself */
