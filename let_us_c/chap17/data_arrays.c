/* Construct individual arrays, one for storing names, another for
 * storing prices and another for storing number of pages. */

#include <stdio.h>
int main() {
    char name[3];
    float price[3];
    int pages[3], i;

    printf("Enter names, prices and no. of pages of 3 books\n");

    for (i = 0; i <= 2; i++)
        scanf("%c %f %d", &name[i], &price[i], &pages[i]);

    printf("\nAnd this is what you entered\n");
    for (i = 0; i <= 2; i++)
        printf("%c %f %d\n", name[i], price[i], pages[i]);

    return 0;
}

/* Use a structure variable */

#include <stdio.h>
int main() {
    struct book { // new data type called struct book
        char name;
        float price;
        int pages;
    };
    struct book b1, b2, b3; // variables declared to be of type struct book
    /* This statement sets aside space in memory
     * It makes available space to hold all elements in the structure
     * One byte for name
     * Four for price
     * Four for pages
     *
     * We can combine the declaration of the structure type and
     * the structure variables in one statement:
     * struct book {
     *  char name;
     *  float price;
     *  int pages;
     *  } b1, b2, b3;
     */

    printf("Enter names, prices & no. of pages of 3 books\n");
    scanf("%c %f %d", &b1.name, &b1.price, &b1.pages);
    scanf("%c %f %d", &b2.name, &b2.price, &b2.pages);
    scanf("%c %f %d", &b3.name, &b3.price, &b3.pages);
    printf("And this is what you entered\n");
    printf("%c %f %d\n", b1.name, b1.price, b1.pages);
    printf("%c %f %d\n", b2.name, b2.price, b2.pages);
    printf("%c %f %d\n", b3.name, b3.price, b3.pages);
    return 0;
}

/* This demonstrates two fundamental aspects of structures:
 * (a) Declaration of a structure
 * (b) Accessing of structure elements
 */

