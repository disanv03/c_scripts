/* bitcount: count 1 bits in x - faster version */
/* count the number of 1 in a unsigned integer, from
 * least significant bit.
 * The operation x &= x - 1 efficiently clears the least significant set bit of x in each iteration
 */

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= x - 1)
        ++b;
    return b;
}
