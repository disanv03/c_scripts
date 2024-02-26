/* Checking bounds of array
 * Exceeding size
 * */
#include <stdio.h>
int main() {
    int num[40], i;
    for (i = 0; i <= 100; i++) {
        num[i] = i;
        printf("%d", num[i]);
    }
    return 0;
}
