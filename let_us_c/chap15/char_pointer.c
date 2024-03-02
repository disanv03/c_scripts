/* We can assign a char pointer to another char pointer */
#include <stdio.h>
int main () {
    char str1[] = "Hello";
    char str2[10];

    char *s = "Good Morning";
    char *q;

    str2 = str1; /*error*/
    q = s; /*works*/
    return 0; 
}

/* Also, once a string has been defined, it cannot be initialized
 * to another set of characters. Unlike strings, such an operation is
 * perfectly valid with char pointers.
 */

int main() {
    char str1[] = "Hello";
    char *p = "Hello";
    str1 = "Bye"; /*error*/
    p = "Bye"; /*works*/
}
