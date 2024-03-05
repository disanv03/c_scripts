/* Pass the entire structure variable at a time */
#include <stdio.h>
struct book {
    char name[25];
    char author[25];
    int callno;
};
void display(struct book);

int main() {
    struct book b1 = {"Let us C", "YPK", 101};
    display(b1);
    return 0;
}

void display(struct book b) {
    printf("%s %s %d\n", b.name, b.author, b.callno);
}

/* having collected what is being passed to the dipslay() function
 * the question comes, how do we define the formal arguments in the
 * function. We cannot say struct book b because the data type struct book
 * is not known to the function display(). Therefore, it becomes necessary
 * to declare the structure type struct book outside main(), so that it 
 * becomes known to all functions in the program.
 */
