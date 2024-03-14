/* The reverse communication -from the OS to the program- is achieved
 * using a mechanism called 'signal'.
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void sighandler(int signum) {
    printf("SIGINT received. Inside sighandler\n");
    exit(0);
}

int main() {
    signal(SIGINT, sighandler);
    while (1)
        printf("program running\n");
    return 0;
}
