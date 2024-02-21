/* Recursive function to calculate sum of digits
 * of 5-digit number */

#include <stdio.h>

int sum_recursive(int n);
int sum_non_recursive(int n);

int main() {
    int number;
    scanf("%d", &number);
    printf("Sum of 5-digit: %d\n", sum_recursive(number));
    printf("Sum of 5-digit: %d", sum_non_recursive(number));
    return 0;
}

int sum_recursive(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sum_recursive(n / 10);
}

int sum_non_recursive(int n) {
    int sum = 0;
    while (n > 0) { /* base case */
        sum += n % 10; /* accumulate */
        n /= 10; /* reducing */
    }
    return sum;
}


