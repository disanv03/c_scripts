/* Using a function, determine whether a year is leap year or not */
#include <stdio.h>
void leapyear(int);
int main() {
    int year;
    printf("\nEnter year:");
    scanf("%d", &year);
    leapyear(year);
    return 0;
}

void leapyear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        printf("%d is leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
}
