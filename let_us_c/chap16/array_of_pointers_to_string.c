/* Obtain greater ease in manipulation of the strings
 * with an array of pointers instead of a two-dimensional array
 * of characters.
 */

/* Exchange names using 2-D array of characters
 * We want to exchange the position of the names "raman" and "srinivas"
 */

/* Using 2-D */
#include <stdio.h>
int main() {
    char names[][10] = {
                        "akshay",
                        "parag",
                        "raman",
                        "srinivas",
                        "gopal",
                        "rajesh"
    };

    int i;
    char t;
    printf("Original:%s %s\n", &names[2][0], &names[3][0]);

    for (i = 0; i <= 9, i++) {
        t = names[2][i];
        names[2][i] = names[3][i];
        names[3][i] = t;
    }

    printf("New: %s %s\n", &names[2][0], &names[3][0]);
    return 0;
}

/* Using array of pointers to string */
#include <stdio.h>
int main() {
    char *names[] = {
                        "akshay",
                        "parag",
                        "raman",
                        "srinivas",
                        "gopal",
                        "rajest"
    };
    char *temp;
    printf("Original: %s %s\n", names[2], names[3]);
    temp = names[2];
    names[2] = names[3];
    names[3] = temp;
    printf("New: %s %s\n", names[2], names[3]);
    return 0;
}

/* Thus, from the point of view of efficient memory usage and ease of
 * programming, an array of pointers to strings definitely scores over
 * a two-dimensional character array. That is why, even though, in principle,
 * strings can be stored and handled through a two-dimensinal array of characters,
 * in actual pratice, it is the array of pointers to strings, which is more
 * commonly used.
 */

