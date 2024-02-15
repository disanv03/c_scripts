/* Insurance of driver - using logical operators */
#include <stdio.h>

int main() {
    char sex, ms;
    int age;

    printf("Enter age, sex, martial status");
    scanf("%d %c %c", &age, &sex, &ms);

    if ((ms == 'M') || (ms == 'U' && sex == 'M' && age > 30) ||
            (ms == 'U' && sex == 'F' && age > 25))
        printf("Driver should be insured\n");
    else
        printf("Driver should not be insured\n");

    return 0;
}

/* && and || are useful in the follwing programming situations:
 * (a) When it is to be checked in which range does a value fall
 * (b) When after testing several conditions, the outcome is only one of thetwo answers. (This problem is often called yes/no problem).

    
