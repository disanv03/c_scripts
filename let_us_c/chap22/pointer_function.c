/* Pointers can also point to C functions */

#include <stdio.h>
void display();
int main() {
    printf("Address of function display is %d\n", display);
    display(); /* usual way of invoking a function */
    return 0;
} 

void display() {
    puts("Long live the king!!\n");
}
