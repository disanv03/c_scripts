/* Rudimentary storage allocator.
 *
 * Two routine:
 * alloc(n): returns a pointer to n consecutive character positions, which
 * can be used by the caller of alloc for storing characters.
 * afree(p): releases the storage thus acquired so it can be reused later.
 *
 * Storage managed by alloc and afree is a stack, last-in, first-out.
 */

#include <stdio.h>
#define ALLOCSIZE 10000                 /* size of available space */

static char allocbuf[ALLOCSIZE];        /* storage for alloc    */
static char *allocp = allocbuf;         /* next free position   */ 

char *alloc(int n) {                    /* return pointer to n characters */
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;              /* old p */
    } else                              /* not enough room */
        return 0;
}

void afree(char *p) {                     /* free storage pointed to by p */
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/* C guarantees that zero is never a valid address for data, so a return value of zero can be used to signal an abnormal event, in this case no space. */
