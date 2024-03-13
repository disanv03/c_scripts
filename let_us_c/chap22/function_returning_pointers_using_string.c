/* Copies one string into another and returns the pointer to the target string */

char *copy(char *, char *);
int main() {
    char *str;
    char source[] = "Jadded";
    char target[10];

    str = copy(target, source);
    printf("%s\n", str);
    return 0;
}

char *copy(char *t, char *s) {
    char *r;
    r = t;

    while (*s != '\0') {
        *t = *s;
        t++;
        s++;
    }

    *t = '\0';
    return (r);
}

