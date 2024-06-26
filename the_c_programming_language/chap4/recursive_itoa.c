/* Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive routine
 */

#include <math.h>

/* itoa: convert n to characters in s; recursive */
void itoa(int n, char s[]) {
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

int main() {
    char str[20];

    itoa(1234, str);
    printf("Integer as string: %s\n", str);

    return 0;
}
