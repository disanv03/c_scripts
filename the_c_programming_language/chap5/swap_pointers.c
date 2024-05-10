/* Swaps value of variable given in the calling function */

void swap(int *px, int *py) {     /* interchange *px and *py */
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
} 


