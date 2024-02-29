/* The way there can be an array of ints or an array of floats,
 * similary, there can be an array of pointers.
 * Since a pointer variable always contains an address, an array of
 * pointers would be nothing but a collection of addresses.
 *
 * The addresses present in the array of pointers can be addresses of
 * isolated variables or addresses of array elements or any other addresses.
 * All rule that apply to an ordinary array apply to the array of pointers 
 * as well. I think a program would clarify the concept.
 */

#include <stdio.h>
int main() {
    int *arr[4]; /* array of integer pointers */
    int i = 31; j = 5; k = 19; l = 71, m;

    arr[0] = &i;
    arr[1] = &j;
    arr[2] = &k;
    arr[3] = &l;
    for (m = 0; m <= 3; m++)
        printf("%d\n", *(arr[m]));
    return 0;
}
