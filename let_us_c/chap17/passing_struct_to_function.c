/* Passing individual structure elements */
#include <stdio.h>
void display(char *, char *, int);
int main() {
    struct book {
        char name[25];
        char author[25];
        int callno;
    };
    struct book b1 = {"Let us C", "YPK", 101};

    /* Passing the base addresses of the array name and author,
     * but the value stored in callno. Thus, this is a mixed call
     * -a call by reference as well as a call by value.
     */
    display(b1.name, b1.author, b1.callno);

    return 0;
}

void display(char *s, char *t, int n) {
    printf("%s %s %d\n", s, t, n);
}
