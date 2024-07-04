/* write a function same_end(p) that returns 1 if a byte p starts
 * and ends with the same bit, and 0 if not.
 */

int same_ends(p) {
    return ((p & 129 == 0) | (p & 129 == 129));
}
