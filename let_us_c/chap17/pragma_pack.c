/* The #pragma pack directive offers a way to arrange byte
 * of the structure elements
 */
#include <stdio.h>
#pragma pack(1)

struct emp {
    int a;
    char ch;
    float s;
};

#pragma pack()

int main() {
    struct emp e;
    printf("%u %u %u\n", &e.a, &e.ch, &e.s);
    return 0;
}

/* Here #pragma pack(1) lets each structure element to begin
 * on 1-byte boundary as justified by the output
 */
