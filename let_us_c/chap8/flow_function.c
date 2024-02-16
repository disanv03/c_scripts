#include <stdio.h>
void italy();
void brazil();
void argentina();

int main() {
    printf("I am in main\n");
    italy();
    printf("I am finally back in main\n");
    return 0;
}

void italy() {
    printf("I am in italy\n");
    brazil();
    printf("I am back in italy\n");
}

void brazil() {
    printf("I am in brazil\n");
    argentina();
}

void argentina() {
    printf("I am in argentina\n");
}

/* output:
 *I am in main
 *I am in italy
 *I am in brazil
 *I am in argentina
 *I am back in italy
 *I am finally back in main
 */
