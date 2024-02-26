/*Access elements in an array */
#include <stdio.h>
int main() {
    int num[] = {24, 34, 12, 44, 56, 17};
    int i;
    int size;
    int *head, *tail;
    for (i = 0; i <= 5; i++) {
        printf("address = %u ", &num[i]);
        printf("element = %d\n", num[i]);
    }
    printf("Size of this array: \n");
    head = &num[0];
    tail = &num[5];
    printf("%d",(tail - head));
    return 0;
}

/* When you subtract one pointer from another in C, the operation internally calculates the difference in bytes between the two memory addresses and then divides that difference by the size of the data type the pointers are pointing to. This division adjusts the byte difference to a difference in terms of array elements. */
