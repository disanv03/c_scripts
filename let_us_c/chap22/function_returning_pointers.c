/* to make function returning pointer, it has to be explicitly
 * mentioned in the calling function as well as in the function definition
 */

int *fun();
int main() {
    int *p;
    p = fun();
    return 0;
}

int *fun() {
    static int i = 20;
    return (&i);
}
