/* Determine character case using conditional operators */
#include <stdio.h>
int main(){
    char ch;
    printf("Enter character");
    scanf("%c", &ch);
    ch >= 97 && ch <= 122 ? printf("character is lower case\n")
        : printf("character is not lower case\n");
    return 0;
}
