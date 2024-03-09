/* Writes records to a file using structure */
#include <stdio.h>
#include <stdlib.h>
#include <termios.h> /* terminal i/o settings */
#include <unistd.h> /* unix standard */

struct emp {
    char name[40];
    int age;
    float bs;
};

char linux_getche(void) {
    char ch;
    struct termios oldt, newt;

    /* terminal control set attributs
     * Essentially, this function configures the terminal's behavior
     * and modes according to the options specified in a termios structure.
     * tcsetattr is typically used in programs that need to modify the
     * terminal's default behavior.
     * STDIN_FILENO defined in <unistd.h>
     * it represents the file descriptor(reference an open file, or other
     * data stream) number for stdin
     */
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    /* disable canonical mode, and echo */
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); /* terminal control set attribut */

    /* read one character */
    read(STDIN_FILENO, &ch, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    /* echo char back */
    putchar(ch);
    return ch;
}

int main() {
    FILE *fp;
    char another = 'Y';
    struct emp e;

    fp = fopen("EMPLOYEE.DAT", "w");
    if (fp == NULL) {
        puts("cannot open file");
        exit(1);
    }

    while (another == 'Y') {
        printf("\nEnter name, age and basic salary: ");
        scanf("%s %d %f", e.name, &e.age, &e.bs);
        fprintf(fp, "%s %d %f\n", e.name, e.age, e.bs);
        //while (getchar() != '\n'); /* clear input buffer, including the newline */
        printf("Add another record (Y/N) ");
        fflush(stdout); /* flush the output buffer */
        another = linux_getche();
    }
    fclose(fp);
    return 0;
}

