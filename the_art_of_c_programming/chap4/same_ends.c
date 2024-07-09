/* write a function same_end(p) that returns 1 if a byte p starts
 * and ends with the same bit, and 0 if not.
 *
 * check if the first and last bits of p are the same
 */

int same_ends(p) {
    return ((p & 129 == 0) || (p & 129 == 129));
}
