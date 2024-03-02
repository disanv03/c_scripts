/* scanf() is not capable of receiving multi-word strings.
 * The way to get around this limitation is by using the function get().
 * The usage of functions gets() and its counterpart puts() is shown below
 */

#include <stdio.h>
int main() {
    char name[25];
    printf("Enter your full name:");
    gets(name);
    puts("Hello!"); /* only one string at a time */
    puts(name);
    return 0;
}

/* Making scanf() accept multi-word strings envolve
 * char name[25];
 * printf("Enter your full name");
 * scanf("%[^\n]s", name);
 */

/* [^\n] indicate that scanf() will keep receiving characters into
 * name[] until \n is encountered.
 */
