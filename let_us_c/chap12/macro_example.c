/*Write macro definitions for the following:
1. To find arithmetic mean of two numbers.
2. To find absolute value of a number.
3. To convert an uppercase alphabet to lowercase.
4. To obtain the bigger of two numbers.
*/

#include <stdio.h>
#define MEAN(x,y) ((x + y) / 2)
#define ABS(x) (x < 0 ? x * - 1 : x)
#define TOLOWER(x) (x + 32)
#define BIG(x,y,z) (x > y && x > z ? x : y > x && y > z ? y : z)

int main() {
    char ch;
    int d, a, b, c;
    printf("\n Enter any two numbers: ");
    scanf("%d %d", &a, &b);
    d = MEAN(a, b); 
    printf("Mean is %d\n", d);
    printf("Enter any number: ");
    scanf("%d", &a);
    d = ABS(a);
    printf("Absolute  value is %d\n", d);
    fflush(stdin);
    printf("\nEnter any upper case character:");
    scanf("%c", &ch);
    ch = TOLOWER(ch);
    printf("Lower case character is %c\n", ch);
    printf("\nEnter any three numbers:");
    scanf("%d %d %d", &a, &b, &c);
    d = BIG(a, b, c);
    printf("Big number is: %d\n", d);
    return 0;
}
