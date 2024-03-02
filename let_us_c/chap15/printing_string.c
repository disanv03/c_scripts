/* Program to demonstrate printing of a string */

/*
#include <stdio.h>
int main() {
    char name[] = "Klinsman";
    int i = 0;

    while (i <= 7) {
        printf("%c", name[i]);
        i++;
    }
    printf("\n");
    return 0;
} 
*/

#include <stdio.h>
int main() {
    char name[] = "Klinsman";
    int i = 0;
    while (name[i] != '\0') {
        printf("%c", name[i]);
        i++;
    }
    printf("\n");
    return 0;
}

int main() {
    char name[] = "Klinsman";
    char *ptr;
    ptr = name; /* store base address of string */
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++; /* array elements are stored in contiguous memory */
    }
    printf("\n");
    return 0;
}

/* %s used in printf() is a format specification for printing out a string.
 * Note that printf() doesn't print the '\0'.
 */
int main() {
    char name[] = "Klinsman";
    printf("%s", name);
}

/* Same specification can be used to receive a string from the keyboard */
int main() {
    char name[25];
    printf("Enter your name");
    scanf("%s", name);
    printf("Hello %s!\n", name);
    return 0;
}

/* Note that the declaration char name[25] set aside 25 bytes under the
 * array name[], whereas the scanf() function fills in the characters
 * typed at keyboard into this array until the Enter key is hit.
 * Once enter is hit, scanf() places a '\0' in the array.
 * Naturally, we should pass the base address of the array to the scanf()
 * function.
 */
