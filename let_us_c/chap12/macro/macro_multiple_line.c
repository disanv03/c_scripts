#include <stdio.h>

#define HLINE for (i = 0; i < 79; i++)\
                       printf("-");
#define VLINE(X, Y) {\
    printf("|");\
}

int main() {
    int i, y;
    HLINE
    for (y = 1; y < 25; y++)
        VLINE(39, y);
    return 0;
}

