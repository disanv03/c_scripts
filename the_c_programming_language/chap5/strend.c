/* write a function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise */

#include <stdio.h>

/* strend: return 1 if string t occurs at the end of s  */
int strend(char *s, char *t) {
    char *bs = s;       /* remember beginning of strs */
    char *bt = t;

    for ( ; *s; s++)    /* end of the string s    */
        ;
    for ( ; *t; t++)    /* end of the string t    */
        ;
    for ( ; *s == *t; s--, t--)
        if (t == bt || s == bs)
            break;      /* at the beginning of a str */
    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}
