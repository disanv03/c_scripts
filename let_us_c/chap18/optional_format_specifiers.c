/* Illustration of optional format specifiers */

#include <stdio.h>
int main() {
    int weight = 63;
    printf("weight is %d kg\n", weight);
    printf("weight is %2d kg\n", weight);
    printf("weight is %4d kg\n", weight);
    printf("weight is %6d kg\n", weight);
    printf("weight is %-6d kg\n", weight);
    printf("weight is %1d kg\n", weight);
    return 0;
}
