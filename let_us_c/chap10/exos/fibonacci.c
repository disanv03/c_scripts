/* Recusive function to obtain the first 25 numbers of a Fibonacci sequence 
 * 1 1 2 3 5 8 13 21 34 55 89... 
 * */

#include <stdio.h>

unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int i;
    printf("First 25 numbers of the Fibonacci sequence: \n");
    for (i = 0; i < 25; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
