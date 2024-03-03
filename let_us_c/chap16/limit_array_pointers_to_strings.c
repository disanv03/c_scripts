/* When using an array of pointers to strings, we can initialize
 * the strings at the place where we are declaring the array,
 * but we cannot receive the strings from keyboard using scanf().
 */

/* Slightly roundabout manner to store addresses in an array of pointers
 * to strings, while receiving strings from keyboard using scanf().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *names[6];
    char n[50];
    int len, i;
    char *p;
    for (i = 0; i <= 5; i++) {
        printf("Enter name ");
        scanf("%s", n);
        len = strlen(n);
        p = (char *) malloc(len+1); /* +1 for accommodating \0 */
        strcpy(p, n);
        names[i] = p;
    }

    for (i = 0; i <= 5; i++)
        printf("%s\n", names[i]);
    return 0;
}

/* -> malloc()
 * This function requires the number of bytes to be allocated and 
 * returns the base address of the chunk of memory that it allocates.
 * The address retruned by this function is always of the type void *.
 * Void * means a pointer which is a legal address but is not address of
 * any datatype, hence the convertion with (char *) called typecasting.
 * The prototype of this function has been declared in the header file
 * 'stdlib.h'.
 *
 * But why did we not use array to allocate memory ? This is because,
 * with arrays, we have to commit to the size of the array at the time
 * of writing the program. Moreover, there is no way to increase or decrease
 * the array size during execution of the program.
 * In other words, when we use arrays, static memory allocation takes place.
 * Unlike this, using malloc(), we can allocate memory dynamically, during
 * execution. 
 *
 * Once we have allocated the memory using malloc(), we have copied the 
 * name received through the keyboard into this allocated space and 
 * finally stored the address of the allocated chunk in the appropriate
 * element of names[], the array of pointers to strings.
 */


