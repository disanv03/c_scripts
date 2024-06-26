/* write a function expand(s1, s2) that expands shorthand notations like
 * a-z in the string s1 into the equilent complete list abc...xyz in s2.
 * Allow for letters of either case and digits and be prepared to handle
 * cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing
 * - is taken literally.
 */

#include <stdio.h>

/* expand: expand shorthand notation in s1 into string s2 */
void expand(char s1[], char s2[]) {
    char  c;
    int i, j;

    i = j = 0;
    while ((c = s1[i++]) != '\0') /* fetch a char from s1[] */
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++;
            while (c < s1[i]) /* expand shorthand */
                s2[j++] = c++;
        } else 
            s2[j++] = c; /* copy the character */
    s2[j] = '\0';
}

int main() {
    char s1[] = "a-d1-3";
    char s2[100];
    expand(s1, s2);
    printf("s2: %s\n", s2); /* s2: abcd123 */
}
