/* Memory locations in which the elements of
 * this array are stored
 * */
#include <stdio.h>
int main() {
    int num[] = { 24, 34, 12, 44, 56, 17};
    int i;
    for (i = 0; i <= 5; i++) {
        printf("element no. %d ", i);
        printf("address = %u\n", &num[i]);
    }
    return 0;
}

/* In an array each element occupying 2 bytes, since it is an interger array*/
