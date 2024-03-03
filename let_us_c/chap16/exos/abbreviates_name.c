/* Write a program that stores a set of names of individuals
 * and abbreviates the first, middle and other names except the last
 * name by their first letter
 */

/* Convert a full name into initials & last name */
#include <stdio.h>
#include <string.h>
int main() {
    char str1[30], str2[30], target[30];
    char lastname[20];
    char *p, *token;
    int count, i, j;
    
    printf("\nEnter name, middle name and surname:\n");
    gets(str1);
    strcpy(str2, str1);
    count = 0;
    token = strtok(str1, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    j = 0;
    i = 0;
    p = strtok(str2, " ");
    while (p != NULL) {
        if (i == count - 1) {
            strcpy(lastname, p);
            target[j] = '\0';
        }
        else {
            target[j] = *p;
            j++;
            target[j] = '.';
            j++;
        }
        i++;
        p = strtok(NULL, " ");
    }
    strcat(target, lastname);
    printf("%s\n", targer);

    return 0;
}

        
/* The 'strtok' function is a standard library function in C that is
 * used to tokenize a string, which means it breaks a string into a
 * series of tokens based on a set of delimiters specified by the user.
 * [ChatGPT]
 */
 *
