/* Function which compares two strings to find out whether they
 * are same or different. The two string are compared character-by-character
 * until there is a mismatch or end of one of the string is reached,
 * whichever occurs first.
 * If the two strings are identical, strcmp() returns a value zero.
 * If they're not, it returns the numeric difference between the ASCII values
 * of the first non-matching pair of characters.
 */

#include <stdio.h>
#include <string.h>
int main() {
    char string1[] = "Jerry";
    char string2[] = "Ferry";
    int i, j, k;
    i = strcmp(string1, "Jerry");
    j = strcmp(string1, string2);
    k = strcmp(string1, "Jerry boy");
    printf("%d %d %d\n", i, j, k);
    return 0;
}
