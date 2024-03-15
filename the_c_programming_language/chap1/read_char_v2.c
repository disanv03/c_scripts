/* copy input to output; 2nd version */

#include <stdio.h>

main() {
    int c;

    printf("EOF is %d\n", EOF);

    while ((c = getchar()) != EOF)
        printf("%c\n", c);
}

