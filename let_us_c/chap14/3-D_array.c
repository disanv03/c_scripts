/* In pratice, one rarely uses 3-D array
 * However, an example of initializing a three-dimensional array 
 * will consolidate your understanding of subscript
 */

#include <stdio.h>
int main() {
    int arr[3][4][2] = {
                        {
                            {2, 4},
                            {7, 8},
                            {3, 4},
                            {5, 6}
                        },
                        {
                            {7, 6},
                            {3, 4},
                            {5, 3},
                            {2, 3}
                        },
                        {
                            {8, 9},
                            {7, 2},
                            {3, 4},
                            {5, 1}
                        }
    };

    /* arr[2][3][1] */

    printf("%d", *(*(*(arr + 2) + 3) + 1));

    return 0;

}

                     
