/* The enumerated data type gives you an opportunity to invent your own
 * data type and define what values the varibles of this data type can take.
 */

#include <stdio.h>

enum mar_status {
    /* those values are called 'enumerators' */
    single, married, divorced, widowed
};

enum mar_status person1, person2;

person1 = married;
person2 = divorced;

/* internally, the compiler treats the enumerators as integers.
 * Each value on the list of permissible values correspond to an integer,
 * starting with 0. Thus, in our above example, single is stored as 0,
 * married is stored as 1, divorced as 2 and widowed as 3.
 */

/* This way of assigning numbers can be overriden */

enum mar_status {
    single = 100, married = 200, divorced = 300, widowed = 400
};

enum mar_status person1, person2;


