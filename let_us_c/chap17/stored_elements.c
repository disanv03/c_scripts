/* How structure elements are stored ?
 * Whatever the elements of a structure, they are always
 * stored in contiguous memory locations.
 */

/* Memory map of structure elements */
#include <stdio.h>
int main() {
    struct book {
        char name;
        float price;
        int pages;
    };
    struct book b1 = {'B', 130.00, 550};

    printf("Address of name = %u\n", &b1.name);
    printf("Address of price = %u\n", &b1.price);
    printf("Address of pages = %u\n", &b1.pages);
   
    return 0;
}

/* This show how structure types are created, 
 * how structure variables are declared and how individual elements
 * of a structure variable are referenced.
 */

/* Usage of an array of structures */
#include <stdio.h>
void linkfloat();
int main() {
    struct book {
        char name;
        float price;
        int pages;
    };
    struct book b[100];
    int i;

    for (i = 0; i <= 99; i++) {
        printf("enter name, price and pages");
        fflush(stdin);
        scanf("%c %f %d", &b[i].name, &b[i].price, &b[i].pages);
    }

    for (i = 0; i <= 99; i++)
        printf("%c %f %d\n", b[i].name, b[i].price, b[i].pages);

    return 0;
}

void linkfloat() {
    float a = 0, *b;
    b = &a; /* cause emulator to be linked */
    a = *b; /* suppress the warning - variable not used */
}

/*
 * It should be appreciated what careful thought Dennis Ritchie has
 * put into C language. He first defined array as a collection of similar
 * elements; then realized that dissimilar data types that are often found
 * in real life cannot be handled using arrays, therefore created a new
 * data type called structure.
 * But even using structures, programming convenience could not be achieved,
 * because a lot of variables (b1 to b100 for storing data about hundred books)
 * needed to be handled. Therefore, he allowed us to create an array of structures; an array of similar data types which themselves are a collection of
 * dissimilar data types. Hats off to the genius!
 */
    
