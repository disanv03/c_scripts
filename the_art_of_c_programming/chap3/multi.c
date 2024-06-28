/* write a program to print-out a complete set
 * of multiplication tables for numbers from 1 to 12
 * (a) using for loops
 * (b) using while loops
 * (c) using do/while loops
 */

#include <stdio.h>

/* multi_for: print multiplication table using for loop */
int multi_for(const int n) {
    int i;
    const int upplim = 12;      /* upper limit */

    for (i = 1; i <= upplim; i++)
        printf("%d x %d = %d\n", n, i, i*n);
}

/* multi_while: print multi table using while loop */
int multi_while(const int n) {
    int i = 1;
    const int upplim = 12;

    while (i <= upplim) {
        printf("%d x %d = %d\n", n, i, i*n);
        i++;
    }
}

/* multi_do: print multi table using do loop */
int multi_do(const int n) {
    int i = 1;
    const int upplim = 12;

    do {
        printf("%d x %d = %d\n", n, i, i*n);
        i++;
    } while (i <= upplim);
}

int main() {
    /* testing every loop once */
    multi_for(5);
    printf("\n");
    multi_while(6);
    printf("\n");
    multi_do(7);

    /* printing complete set of multiplication */
    for (int i = 1; i <= 10; i++) {
        multi_for(i);
        printf("\n");
    }
    return 0;
}
    

/* NOTE:
 * May be quicker to use a nested loop:
 */

/*
int main() {
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++)
            printf("%4d", i * j);
        printf("\n");
    }
    return 0;
}

int main() {
    int i = 1;
    while (i <= 12) {
        int j = 1;
        while (j <= 12) {
            printf("%4d", i * j);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}

int main() {
    int i = 1;
    do {
        int j = 1;
        do {
            printf("%4d", i * j);
            j++;
        } while (j <= 12);
        printf("\n");
        i++;
    } while (i <= 12);

    return 0;
}
*/
