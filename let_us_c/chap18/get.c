/* gets() get a string from the keyboard. It is terminated when enter key
 * is hit. Thus, spaces and tabs are perfectly acceptable as part of the
 * input string. More exactly, gets() function gets a newline (\n) terminated
 * string of characters from the keyboard and replaces it with \0.
 */

#include <stdio.h>
int main() {
    char footballer[40];
    puts("Enter name");
    gets(footballer); /* sends base address of array */
    puts("Happy footballing!");
    puts(footballer);
    return 0;
}
