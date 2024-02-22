#include <stdio.h>

int x = 21;
int main() {
    extern int y; // declaration, since is used by the printf below
    printf("%d %d\n", x, y);
    return 0;
}

int y = 31; // definition

/* declaration: variable's type and its name without allocating memory
 * definition: allocate memory for the variable.
 * initialization: assigns an initial value to the var at the time of definition
 *
 * In C, context matters when distinguishing between a declaration and a definitio.
 * A definition is a specific type of declaration that allocates memory for variables.
 * When int x; is declared inside a function, it's both a declaration and a definiton.
 * Extern Keyword:
 * to declare a variable without defining it (allocating memory), you use 'extern'
 *
 * The first three are definitions, whereas the last one is a declaration:
 * auto int i;
 * static int j;
 * register int k;
 * extern int l;
 */
 */
