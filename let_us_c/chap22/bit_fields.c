/* If a variable is to take only two values 1 and 0,
 * why waste an entire integer ?
 */

/* Well, for one thing, there aren't any 1 bit or 2 bit or 3 bit data
 * types available in C. However, when there are several variables whose
 * maximum values are small enough to pack into a single memory location,
 * we can use "bit fields" to store several values in a single integer.
 */

/* Using bit fields */

struct employee {
    unsigned gender :1;
    unsigned mar_stat :2;
    unsigned hobby :3;
    unsigned scheme :4;
}
