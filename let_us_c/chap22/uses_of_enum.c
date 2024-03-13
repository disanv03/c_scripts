/* Enumerated variables are usually used to clarify the operation
 * of a program.
 */

#include <stdio.h>
#include <string.h>
int main() {
    enum emp_dept {
        assembly, manufacturing, accounts, stores
    };

    struct employee {
        char name[30];
        int age;
        float bs;
        enum emp_dept departement;
    };

    struct employee e;

    strcpy(e.name, "Lothar Mattheus");
    e.age = 28;
    e.bs = 5575.50;
    e.department = manufactoring;

    printf("Name = %s\n", e.name);
    printf("Age = %d\n", e.age);
    printf("Basic salary = %f\n", e.bs);
    printf("Dept = %d\n", e.department);

    if (e.department == acounts)
        printf("%s is an accounant\n", e.name);
    else
        printf("%s is not an accounant\n", e.name);
    return 0;
}

/* e.department = manufacturing;
 * This is much more informative to anyone reading the program than
 * e.department = 1;
 */

/* The next part of the program shows an important weakness of using
 * enum varibles... there is no way to use the enumerated values directly
 * in input/output functions like scanf() and printf();
 */
