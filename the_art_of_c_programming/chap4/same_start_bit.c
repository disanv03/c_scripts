/* write a function same_start(p,q) which returns 1 if bytes p,q
 * start with the same bit, and zero if they start with different bits
 */

int same_start(p, q) {
    char mask;
    mask = 128;
    return (p & mask == q & mask);
}
    

