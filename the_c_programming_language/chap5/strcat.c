/* write a pointer version of the function strcat that
 * copies the string t to the end of s. */

#include <stdio.h>

/* strcat: concatenate t to the end of s; pointer version */
void strcat(char *s, char *t) {
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
    /* the above statement assigns to *s whatever is in *t,
     * increments both pointers, and continues as long as t does
     * not point to the end of string marker('\0') */
}
