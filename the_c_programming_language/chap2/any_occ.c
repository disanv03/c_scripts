/* write the function any(s1, s2), which returns the first location
 * in a string s1 where any character from the string s2 occurs, or -1
 * of s1 contains no characters from s2
 */

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    return -1;
}

