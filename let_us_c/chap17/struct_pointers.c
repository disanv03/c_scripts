/* The way we can have a pointer pointing to an int,
 * or a pointer pointing to a char, similary we can have
 * a pointer pointing to a struct. */

/* Let us look at a program that demonstrates the usage of 
 * a structure pointer.
 */

#include <stdio.h>
int main() {
    struct book {
        char name[25];
        char author[25];
        int callno;
    };
    struct book b1 = {"Let us C", "YPK", 101};
    struct book *ptr;
    ptr = &b1;
    printf("%s %s %d\n", b1.name, b1.author, b1.callno);
    printf("%s %s %d\n", ptr->name, ptr->author, ptr->callno);
    return 0;
}

/* We can't use ptr.name or ptr.callno because ptr is not a
 * structure variable but a pointer to a structure, and the dot
 * operator requires a structure variable on its left.
 * In such cases C provides an operator ->, called an arrow operator
 * to refer to the structure elements.
 *
 * Remember that on the left hand side of the '.' structure operator,
 * there must always be a structure variable, whereas on the left hand
 * side of the '->' operator, there must always be a pointer to a structure.
 */
