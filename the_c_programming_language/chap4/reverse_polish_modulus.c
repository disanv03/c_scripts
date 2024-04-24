/* Add the modulus (%) operator and provisions for negative numbers */

#include <stdio.h>
#include <math.h>       /* for atof()           */

#define MAXOP   100     /* max size of operand or operator      */ 
#define NUMBER '0'      /* signal that a number was found       */   

int getop(char []);
void push(double);
double pop(void);

/* revers polish calculator     */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* getop: get next operator or numeric operand          */
int getop(char s[]) {
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;       /* not a number                 */
    if (c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c; /* negative number              */
        else {
            if (c != EOF)
                ungetch(c);
            return '-'; /* minus sign                   */
        }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
    
    
