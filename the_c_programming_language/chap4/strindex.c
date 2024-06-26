/* write a function strrindex(s,t), which returns the position of the 
 * rightmost occurence of t in s, or -1 if there is none.
 */

/* strrindex: returns rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}

/* Another possible solution is: */
int strrindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}



