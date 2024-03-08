/* Format specifiers can be used for displaying string of characters */
#include <stdio.h>
int main() {
    char firstname1[] = "Sandy";
    char surname1[] = "Malya";
    char firstname2[] = "ajay";
    char surname2[] = "Guru";
    printf("%20s%20s\n", firstname1, surname1);
    printf("%20s%20s\n", firstname2, surname2);

    return 0;
}
