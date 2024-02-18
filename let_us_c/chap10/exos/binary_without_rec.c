#include <stdio.h>

#define MAX_BITS 32

int main() {
    int num, i;
    int binary[MAX_BITS];

    // init all elements to 0
    for (i = 0; i < MAX_BITS; i++) {
        binary[i] = 0;
    }

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    i = 0;
    while (num > 0) {
        binary[i] = num % 2; // store the remainder
        num = num / 2; // right shift
        i++; // move the next position in the array
    } 

    // print in reverse order
    printf("The binary equivalent is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);

    return 0;
}
