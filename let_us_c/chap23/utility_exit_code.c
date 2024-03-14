/* A good programming practice would be to get the exit 
 * code of the terminated process, and thereby ensure a proper cleanup.
 * Why is it important, because it is the exit code that would give the 
 * indication about whether the job assigned to the process was completed succesfully
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> /* for waitpid() and WIFEXITED */
int main() {
    unsigned int i = 0;
    int pid, status;
    pid = fork();

    if (pid == 0) {
        while (i < 4294967295u)
            i++;
        printf("the child is now termniating\n");
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            printf("Parent: child terminated normally\n");
        else
            printf("Parent: child terminted abnormally\n");
    }
    return 0;
}

