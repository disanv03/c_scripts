/* Invoking a function using a pointer to a function */
#include <stdio.h>
void display();
int main() {
    void (*func_ptr)();
    func_ptr = display; /* assign address of function */
    printf("Address of function display is %u", func_ptr);
    (*func_ptr)(); /* invoke the function display() */
    /* equivalent of func_ptr(); */
    return 0;
}

void display() {
    puts("\nLong live the king!!");
}
