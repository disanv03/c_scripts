/* print multiplication tables from 1 to 12 */

#include <stdio.h>

int main() {
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}
