/* fork splits the running process into two processes */
#include <stdio.h>
#include <unistd.h> /* for prototype of fork() */

int main() {
    printf("before forking\n");
    fork();
    printf("after forking\n");
    return 0;
}
