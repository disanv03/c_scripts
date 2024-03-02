/* Our example program asks you to type your name.
 * When you do so, it checks your name against a master list to
 * see if you are worthy of entry to the palace.
 */

#include <stdio.h>
#include <string.h>
#define FOUND 1
#define NOTFOUND 0

int main() {
    char masterlist[6][10] = {
                                "aksahy",
                                "parag",
                                "raman",
                                "srinivas",
                                "gopal",
                                "rajesh"
    };
    int i, flag, a;
    char yourname[10];

    printf("Enter your name ");
    scanf("%s", yourname);

    flag = NOTFOUND;
    for (i = 0; i <= 5; i++) {
        a = strcmp(&masterlist[i][0], yourname);
        if (a == 0) {
            printf("Welcome, you can enter the palace\n");
            flag = FOUND;
            break;
        }
    }
    if (flag == NOTFOUND)
        printf("Sorry, you are a trespasser\n");
    return 0;
}
