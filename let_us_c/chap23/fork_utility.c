/* Creating a child process,
 * parent process coping file while child display animated load picture */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid;
    /* control come back from fork() twice, even though
     * it is actually called only once.
     * When control return from fork() of the parent process, it returns the PID of
     * the child, whereas control retrun form the child always returns 0 PID */
    pid = fork();
    if (pid == 0) {
        printf("in child process\n");
        /* code to play animated load picture */
    } else {
        printf("in parent process\n");
        /* code to copy file */
    }
    return 0;
}
