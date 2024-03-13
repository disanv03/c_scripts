/* Union provides a way to look at the same data in several different ways. */

union b {
    double d; /* 8 bytes */
    float f[2]; /* 4 bytes for each f[0], f[1] */
    short int i[4]; /* 2 bytes for each [0], [1], [2], [3] */
    char ch[8]; /* individual bytes */
};

union b data;
