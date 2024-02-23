#include <stdio.h>
#define AND &&
#define ARANGE (a > 25 AND a < 50)

int main() {
    int a = 30;
    if (ARANGE)
        printf("within range\n");
    else
        printf("out of range\n");
    return 0;
}

