/* Operators Precedence and Evaluation */

#define PRINT3(x, y,z) printf("x = %d\ty = %d\tz = %d\n", x, y, z)

int main() {
    int x, y, z;

    x = y = z = 1;
    ++x || ++y && ++z; PRINT3(x, y, z);

    x = y = z = 1;
    ++x && ++y || ++z; PRINT3(x, y, z);

    x = y = z = 1;
    ++x && ++y && ++z; PRINT3(x, y, z);

    x = y = z = -1;
    ++x && ++y || ++z; PRINT3(x, y, z);

    x = y = z = -1;
    ++x || ++y && ++z; PRINT3(x, y, z);

    x = y = z = -1;
    ++x && ++y && ++z; PRINT3(x, y, z);

    return 0;
}

/* `&&` parts are conceptually closer together than `||`
 * `&&` if the left operand is false, the right side is not evaluated
 * `||` if the left operand is true, the right side is not evaluated
 */
