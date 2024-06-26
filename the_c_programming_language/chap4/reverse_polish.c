/* Calculator that use reverse Polish notation(postfix notation) instead of infix 
 * In reverse Polish notation, each operator follows its operands;
 * */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */

#define MAXVAL 100      /* maximum depth of val stack   */
#define BUFSIZE 100

int sp = 0;             /* next free stack position      */
double val[MAXVAL];     /* value stack                  */
char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
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
            case '\n':
                printf("\t%.8g\n", pop()); /* g: automatically selects either normal floating-point notation or scientific notation, g stand for general specifier */
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* Because + and * are commutative operators, the order in which the popped operands are combined is irrelevant, but for - and / the left and right operand must be distinguished.
 * */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* A variable is external if it is defined outside of any function.
 * Thus the stack and stack index that must be shared by push and pop are
 * defined outside these functions. But main itself does not refer to
 * the stack or stack position --the representation can be hidden.
 */


/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))   /* value held in s[i] is what is used in the evaluation */
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);     /* "push back" character into the input buffer. */
    return NUMBER;      /* flag indicating than getop processed a numeric value */
}


int getch(void) {       /* get a (possibly pushed-back) character */ 
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {   /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
            
