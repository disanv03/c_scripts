/* first version of echo treats argv as an array of character pointer */
#include <stdio.h>

/* echo command-line arguments; 1st version */
main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");
    return 0;
}

/* echo command-line arguments; 2nd version */
main(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}

/* alternatively, we could write the printf statement as */
printf((argc > 1) ? "%s " : "%s", *++argv);
/* this shows that the format argument of printf can be an expression too */


