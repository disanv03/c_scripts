/* is there a way to achieve what was achieved (use_of_enum.c)
 * using Enums ? 
 * Yes, using macros
 */

#include <string.h>
#define ASSEMBLY 0
#define MANUFACTURING 1
#define ACCOUNTS 2
#define STORES 3

int main() {
    struct employee {
        char name[30];
        int age;
        float bs;
        int department;
    };

    struct employee e;
    strcpy(e.name, "Lothar Mattheus");
    e.age = 28;
    e.bs = 5575.50;
    e.department = MANUFACTURING;
    return 0;
}

/* If the same effect -convenience and readability can be achieved using macros then why should we prefer enum ? Because, macros have a global scope, whereas, scope of enum can either be global or local
 */

