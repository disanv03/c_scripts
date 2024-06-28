/* Find the prime factors of an integer 
 * Prime factor: is a factor of a given number that is a prime number itself */

#include <stdio.h>

/* find_prime_factors: print prime factors of a given number */
void find_prime_factors(int n) {
    /* handle smallest prime factor (2) */
    while (n % 2 == 0) {
        printf("%d ", 2);
        n = n / 2;
    }

    /* handle odd prime factors from 3 onwards */
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    /* case when n is a prime number > than 2 */
    if (n > 2)
        printf("%d ", n);

    printf("\n");
}

int main() {
    int n;

    printf("enter an integer: ");
    scanf("%d", &n);

    /* valid input ? */
    if (n <= 1) {
        printf("enter a number greater than 1\n");
        return 1;
    }

    printf("prime factors of %d are: ", n);
    find_prime_factors(n);

    return 0;
}
            

