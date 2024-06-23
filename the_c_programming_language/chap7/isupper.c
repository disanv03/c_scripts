/* functions isupper */

/* isupper: return 1 (true) of c is an upper case letter */

int isupper(char c) {
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

/* isupper using macro */

#define isupper(c)      ((c) >= 'A' && (c) <= 'Z') ? 1 : 0

/* for example */
char *p = "This is a string";
if (isupper(*p++))
    ...
/* the macro expands into */
((*p++) >= 'A' && (*p++) <= 'Z') ? 1 : 0
/* which, will increment the pointer p twice. */

/* one solution is: */
if (isupper(*p))
    ...
p++;
/* you have to be aware of macros that may evaluate the argument more
 * than once. */
