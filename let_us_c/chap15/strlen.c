#include <stdio.h>
#include <string.h>

int xstrlen(char *);

int main() {
    char arr[] = "Bamboozled";
    int len1, len2;

    len1 = strlen(arr);
    len2 = strlen("Humpty Dumpty");
    
    printf("String = %s length = %d\n", arr, len1);
    printf("String = %s length = %d\n", "Humpty Dumppty", len2);
    
    return 0;
}

/* A look alike of the function strlen() */
int xstrlen(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return (length);
}
