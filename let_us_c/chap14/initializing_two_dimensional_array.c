/* Initializing a two dimensional Array */
#include <stdio.h>
int main() {
    int stud[4][2] = {
                        {1234, 56},
                        {1212, 33},
                        {1434, 80},
                        {1312, 78}
    };

    /* this work also... */
    int stud[4][2] = {1234, 56, 1212, 33, 1434, 80, 1312, 78};

    /* It is important to remember that, while initializing the 2-D array,
     * it is necessary to mention the second (column) dimension, whereas
     * the first dimension (row) is optional.
     */

    int arr[2][3] = {12, 34, 23, 45, 56, 45};
    int arr[][3] = {12, 34, 23, 45, 56, 45};

    /* We can easily refer to the marks obtained by the third student
     * using the subscript notation as shown below.
     */

    printf("Marks of third student = %d", stud[2][1]);

    /* and with pointer notation ? */
    /* The C language embodies an unusual but powerful capability
     * -it can treat parts of arrays as arrays. More specifically, each
     *  row of a two-dimensional array can be thought of as a one-dimensional array.
     *  This is a very important fact if we wish to access array elements
     *  of a two-dimensional array using pointers.
     */
}
