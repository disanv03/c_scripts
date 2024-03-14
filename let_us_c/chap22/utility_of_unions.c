/* Suppose we wish to store information, that way:
 * Name
 * Grade
 * Age
 * If Grade = HSK (Highly SKilled)
 *      hobbie name
 *      credit card no
 * If Grade = SSK (Semi SKilled)
 *      Vehicle no.
 *      Distance from Co.
 */

struct employee {
    char n[20];
    char grade[4];
    int age;
    char hobby[10];
    int crcardno;
    char vehno[10];
    int dist;
};
struct employee e;
/* Depending upon his/her grade, some fields would lead to a waste of memory*/
/* This cna be avoided by creating union between these sets of fields */

struct info1 {
    char hobby[10];
    int crcardno;
};

struct info2 {
    char vehno[10];
    int dist;
};

union info {
    struct info1 a;
    struct info2 b;
};

struct employee {
    char n[20];
    char grade[4];
    int age;
    union info f;
};

struct employee e;

