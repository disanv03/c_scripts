#include <stdio.h>
#define ISDIGIT(y) (y >= 48 && y <= 57)
/* Note, the entire marco expansion is enclosed within parentheses. */

int main() {
    char ch;

    printf("Enter any digit");
    scanf("%c", &ch);
    if (ISDIGIT(ch))
        printf("You entered a digit\n");
    else
        printf("Illegal input\n");
    return 0;
}
