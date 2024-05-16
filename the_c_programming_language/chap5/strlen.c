/* When an array name is passed to a function, what is passed is the location of the initial element.
 * Within the called function, this argument is a local variable, and so an
 * array name parameter is a pointer, that is, a variable containing an address.
 * We can use this fact to write another version of strlen, which computes the length of a string
 */

#include <stdio.h>

/*strlen: return length of string s */
int strlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/* since s is a pointer, incrementing it is prefectly legal; */
