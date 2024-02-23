#include <stdio.h>
#define FOUND printf("The Yankee Doodle Virus\n");

int main() {
    char signature;

    if (signature == 'Y')
        FOUND
    else
        printf("Safe.. as yet!\n");
    return 0;
}

