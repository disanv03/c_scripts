/* This function concatenates the source string at the end of the
 * target string.
 */
#include <stdio.h>
#include <string.h>

void xstrcat(char *target, const char *source);

int main() {
    char source[] = "Folks!";
    char target[30] = "Hello";
    xstrcat(target, source);
    printf("source string = %s\n", source);
    printf("target string = %s\n", target);
    return 0;
}

void xstrcat(char *target, const char *source) {
    while (*target)
        target++;

    while (*source) {
        *target = *source;
        target++;
        source++;
    }

    *target = '\0';
}
