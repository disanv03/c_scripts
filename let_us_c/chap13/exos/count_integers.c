/* Twenty-five numbers are entered from the keyboard into an array.
 * Write a program to find out how many of them are positive, how
 * many are negative, how many are even and how many odd.
 */

/* Program to count positive, negative odds & evens in an array */
#include <stdio.h>
int main() {
    int num[25], i, neg = 0, pos = 0, odd = 0, even = 0;
    printf("Enter 25 elements of array: ");
    for (i = 0; i <= 24; i++)
        scanf("%d", &num[i]); /*array elements*/
    for (i = 0; i <= 24; i++) {
        num[i] < 0 ? neg++ : (pos++); 
        num[i] % 2 ? odd++ : (even++);
    }
    printf("Negative elements = %d\n", neg);
    printf("Positive elements = %d\n", pos);
    printf("Even elements = %d\n", even);
    printf("Odd elements = %d\n", odd);
    return 0;
}
