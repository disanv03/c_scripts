/* Convert a snake_case input into camelCase output */
#include <stdio.h>
#include <ctype.h>

char to_upper(char ch);

int main() {
    char input[] = "hello_world";
    char camelCase[20];

    int i, camelIndex = 0;

    /* '\0' null character, indicate the end of a string */
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '_') {
            /* skip the underscore, moving to the next character */
            i++;
            camelCase[camelIndex++] = to_upper(input[i]);
        } else {
            camelCase[camelIndex++] = input[i];
        }
    }
    camelCase[camelIndex] = '\0';
    printf("camelCase string: %s\n", camelCase);

    return 0;
}

char to_upper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');
    }
    /* if is not lowercase, return it unchanged */
    return ch;
}
