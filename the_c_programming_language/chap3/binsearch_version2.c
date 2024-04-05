/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int  v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}

/* we changed the expression in the while loop from
 * low <= high
 * to 
 * low <= high && x != v[mid]
 * so we can use only one if statement inside the loop.
 *
 * The original code reads better from top to bottom
 * else if statement improve readability in this case
 */
