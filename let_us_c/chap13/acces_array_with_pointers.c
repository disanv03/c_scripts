/*Accesses the array elements using pointers */
#include <stdio.h>
int main() {
    int num[] = {24, 34, 12, 44, 56, 17};
    int i, *j;

    j = &num[0]; /* assign address of zeroth element */
    for (i = 0; i <= 5; i++) {
        printf("address = %u ", j);
        printf("element = %d\n", *j);
        j++; /* increment pointer to point to next location */
    }
    return 0;
}

/* On incrementing j, it points to the next memory location of its type
 * But this location contains the second element of the array, therefore
 * printf print out the second element of the array, until the last element
 * of the array has been printed.
 * Accesing array elements by pointers is always faster than accesing them
 * by subscripts(or "array index").
 * */
