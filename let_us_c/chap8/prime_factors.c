/* Obtain prime factors of a number */
#include <stdio.h>
void prime(int );
int main() {
    int num;
    printf("Enter number:");
    scanf("%d", &num);
    prime(num);
    return 0;
}

void prime(int num) {
    int i = 2;
    printf("Prime factors of %d are ", num);
    while (num != 1) {
        if (num % i == 0)
            printf("%d", i);
        else {
            i++;
            continue;
        }
        num = num / i;
    }
}

            
