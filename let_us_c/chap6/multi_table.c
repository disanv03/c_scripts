/* Generate and print table of a given number */
#include <stdio.h>

int main() {
    int i, num;
    printf("\nEnter the number: ");
    scanf("%d", &num);
    for (i = 1; i <= 10; i++) 
        printf("%d * %d = %d\n", num, i, num * i);
    return 0;
}

