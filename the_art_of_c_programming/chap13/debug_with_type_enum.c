/* Improving "debug" function so that it can handle variables
 * of different types.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VARS 10

int _count[MAX_VARS] = {0};

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} VarType;

void debug(const char *message, void *value, VarType type, int refno) {
    _count[refno]++;
    printf(">>Ref n° %d: %s = ", refno, message);
    switch(type) {
        case TYPE_INT:
            printf("%d", *(int *)value);
            break;
        case TYPE_FLOAT:
            printf("%f", *(float *)value);
            break;
        case TYPE_STRING:
            printf("%s", *(char *)value);
            break;
        default:
            printf("unknown type");
            break;
    }
    printf(": count = %d\n", _count[refno]);
}

int main() {
    int x = 99;
    float y = 50.5;
    char z[] = "hello";

    debug("x", &x, TYPE_INT, 2);
    x = 1001;
    debug("x", &x, TYPE_INT, 2);
    debug("y", &y, TYPE_FLOAT, 1);
    debug("z", z, TYPE_STRING, 0);
            
    return 0;
}
