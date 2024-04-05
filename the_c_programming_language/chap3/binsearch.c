#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int v[] = {1, 3, 4, 6, 8, 9, 10};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 4; /* element to look for */

    int result = binsearch(x, v, n);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

/* binsearch: find x in v[0] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
           high = mid - 1;
        else if (x > v[mid])
           low = mid + 1;
        else /* found match */
           return mid;
    }
   return -1; /* no match */
} 

/* if 'low' and 'high' are equal, 'mid' will be equal to both, effectively pointing to that single element. */
