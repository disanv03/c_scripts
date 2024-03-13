/* Renaming data types with typedef */
/* There is one more technique, which, in some situations, can
 * help to clarify the source code of a C program.
 * This technique is to make use of the typedef declaration.
 * Its purpose is to redefine the name of an existing variable type.
 */

typedef unsigned long int TWOWORDS;
TWOWORDS var1, var2;
/* instead of */
unsigned long int var1, var2;

/* thus, typedef provides a short and meaninful way to call a data type. 
 * Usually, uppercase letters are used to make it clear that we are dealing
 * with a renamed data type.
 */

struct employee {
    char name[30];
    int age;
    float bs;
};
typedef struct employee EMP;
EMP e1, e2;

/* Thus, by reducing the length and apparent complexity of data types,
 * typedef can help to clarify source listing and save time and energy
 * spent in understanding a program
 * */

typedef struct employee {
    char name[30];
    int age;
    float bs;
} EMP;
EMP e1, e2;

/* typedef can also be used to rename pointer data types */
struct employee {
    char name[30];
    int age;
    float bs;
}
typedef struct employee *PEMP;
PEMP p;
p -> age = 32;



