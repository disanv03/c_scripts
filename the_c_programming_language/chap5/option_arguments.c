/* Optional arguments */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

/* find: print lines that match pattern form 1st arg */
main(int argc, char *argv[]) {
    char line[MAXLINE];         /* buffer to store each line    */
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    /* Process command-line arguments   */
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])  /* Process each character in the flag   */
            switch (c) {
                case 'x':
                    excpet = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    if (argc != 1)      /* check if exactly one pattern arguemnt is provided*/
        printf("Usage: find -x -n pattern\n");
    else
        while (getline(line, MAXLINE) > 0) {
            lineno++;
            /* strstr: return ->
             * a pointer to the first occurence of the substring within the string if the substring is found
             * NULL if the substring is not found
             *
             * Evaluate to 1 (true) if the substring is found
             * Evaluate to 0 (false) if the substring is not found
             *
             * except = 0 : we want lines that contain the substring
             * except = 1 : we want lines that do not contains the substring
             *
             */
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found; /* Return the number of matching lines found  */
}


int getline(char *line, int max) {
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);    /* return the length of the line */
}
