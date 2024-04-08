/* Write a function escape(s, t) that converts characters like newline and
 * tab into visible escape sequences like \n and \t as it copies the string
 * t to s. Usa a switch.
 * Write a function for the other direction as well, converting escape sequences into the real characters.
 */

/* escape: expand newline and tab into visible sequences */
/* while copying the string t to s */

void escape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    s[j] = '\0';
}


/* unescape: convert escape sequences into real characters */
/* while copying the string t to s */
void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
        if (t[i] != '\\')
            s[j++] = t[i];
        else
            switch(t[++i]) {
                case 'n':
                    s[j++] = '\n'; /* real newline --one character */
                    break;
                case 't':
                    s[j++] = '\t'; /* real tab                     */
                    break;
                default:
                    s[j++] = '\\'; /* all other chars              */
                    s[j++] = t[i];
                    break;
            }
    s[j] = '\0';
}

