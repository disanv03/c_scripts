## The C programming Language, Kernighan & Ritchie (1978)

- Basics:
   - variables and constants
   -  arithmetic
   -  control flow
   -  functions
   -  rudiments of input and output.

- Writing bigger programs:
    - pointers
    - structures
    - rich set of operators
    - several control-flow statements
    - and the standard library.

##### Introduction

> "A sequence of characters in double quotes, like `hello, world\n`, is called a character string or string constant"

> "An escape sequence like `\n` provides a general and extensible mechanism for representing hard-to-type or invisible characters."

> "If an arithmetic operator has integer operands, an integer operation is performed. If an arithmetic operator has one floating-point operand and one integer operand, however, the interger will be converted to floating point before the operation is done."

> "In any context where it is permissible to use the value of some type, you can use a more complicated expression of that type."

> "A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called a character constant, although it is just another way to write a small integer"

##### Functions

> "With properly designed functions, it is possible to ignore how a job is done; knowing what is done is sufficient"


##### Arguments - Call by Value

> "Call by value is an asset... It usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine."

##### External Variables and Scope

> "[...] discusses the static storage class, in which local variables do retain their values between calls."

> "As an alternative to automatic variables, it is possible to define variables that are external to all functions, that is, variables that can be accessed by name by any function."

> "Before a function can use an external variables, the name of the variable must be made known to the function; the declaration is the same as before except for the added keyword extern."

> "In certain circumstances, the extern declaration can be omitted. If the defintion of the external variable occurs in the source file before its use in a particular function, then there is no need for an extern declaration in the function. The extern declarations in main, getline, and copy are thus redundant. In fact, commom practice is to place definitions of all external variables at the beginning of the source file, and then omit all extern declarations."

> "You should note that we are using the words definition and declaration carefully when we refer to external variables in this section. `Definition` refers to the place where the variables is created or assigned storage; `declaration` refers to the place where the nature of the variable is stated but not storage is allocated"

#### Types, Operators and Expressions

> "The type of an object determines the set of values it can have and what operations can be performed on it."

> "Declarations list the variables to be used, and state what type they haveand perhaps what their initial values are. Operators specify what is to be done to them. Expressions combine variables and constants to produce new values."

> "We tend to use short names for local variables, especially loop indices, and longer names for external variables."

> "Be careful to distinguish between a character constant and a string that contains a single character: 'x' is not the same as "x". The former is an integer, used to produce the numeric value of the letter x in the machine's character set. The latter is an array of characters that contains one character (the letter x) and a '\0'."

> "There is one other kind of constant, the enumeration constant. An enumeration is a list of constant values, as in:

```c
enum boolean { NO, YES };
```

The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified."


If not all values are specified, unspecified values continue the progression form the last specified value:

```c
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
              JUL, AUG, SEP, OCT, NOV, DEC };
```

> "The quatifier const can be applied to the declaration of any variable to specify that its value will not be changed. For an array, the const qualifier says that the elements will not be altered."

> "The const declaration can also be used with array arguments, to indicate that the function does not change that array: `int strlen(const char[]);`"

> "The expression `x % y` produces the remainder when x is devided by y, and thus is zero when y divides x exactly. For example, a year is a leap year if it is divisible by 4 but not by 100, except that years divisible by 400 are leap years."

```c
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a leap year\n", year);
```

> "The precedence of && is higher than that of ||, and both are lower than relational and equality operators"

> "By definition, the numeric value of a relational or logical expression is 1 if the relation is true, and 0 if the relation is false."

> The unary negation operator ! converts a non-zero operand into 0, and a zero operand in 1. A common use of ! is in constructions like:
```c
if (!valid)
/* rather than */
if (valid == 0)
```

##### Type conversion

> In general, if an operator like + or * that takes two operands has operands of different types, the "lower" type is promoted to the "highter" type before the operation proceeds.

> Conversions take place across assignments; the value of the right side is converted to the type of the left, which is the type of the result.

> Since an argument of a function call is an expression, type conversion also takes place when arguments are passed to functions. In the absence of a function prototype, char and short become int and float becomes double.

> Finally, explicit type conversions can be forced ('coerced') in any expression, with a unary operator called a cast. [...] The precise meaning of a cast is as if the expression were assigned to a variable of the specified type, which is then used in place of the whole construction.

The <math.h> library routine sqrt expects a double argument, and will produce nonsense if inadvertently handled something else. So if "n" is an interger, we can use:

```c
sqrt((double) n)
```
to convert the value of n to double before passing it to sqrt.


#### Increment and Decrement Operators

In a context where no value is wanted, just the incrementing effect, prefix and postfix are the same.

But there are situations where one or the other is specifically called for:
```c
/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* this is exactly equivalent to */
    if (s[i] != c) {
        s[j] = s[i];
        j++;
    }
```
    
##### Bitwise Operators

```c
/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}
```

This bitwise section is all about understanding this return statement.

First getbits, extracts `n` bits starting from position `p` in the integer `x`, these extracted bits are then "right adjusted", meaning that they are shifted to the right end of the integer (the rest of the bits to the left are set to zero).


Example:

`x = 10110100` and you want to extract 3 bits starting from position 4, you
would extract `101`. Then adjusting, would end up with `00000101`


`x >> (p+1-n)`: this shifts the desired part at the right end.

`~0`: this is a common idiom to inverts every bit.

`~0 << n`: This shifts all-1s value `n` positions to the left, which sets the `n` rightmost bits to 0 and the rest to 1.

`~(~0 << n)`: This inverts the bits, producing a mask, where only the `n` rightmost bits are set to 1, and the rest to 0.

`&`: apply the mask produced above, leaving only the `n`righmost its of the shifted `x`

---

### x &= x - 1

The expression `x &= x - 1` is a clever and efficient way to count the number of 1 bits (set bits) in an integer.

Let consider what happens when you subtract 1 from a binary number:

`x - 1`
- If LSB is 1 `001`, subtrating 1 will turn it to 0 `000`
- If LSB is 0, the subtraction borrows from a more significant bit, flippingall trailing 0s to 1s until it reaches a 1, which is flipped to 0.


`x &=`

Performs a bitwise AND on x with the result of `x - 1`. This operation clears the least significant set bit.

```c
x = 12; /* 1100 */
/* x - 1 = 11;  1011 */

x &= x - 1; /* 1100 & 1011 = 1000 (8 in decimal) */

/* x - 1 = 7;  0111 */
x &= x - 1 /* 1000 & 0111 = 0000 */
```

### Control Flow
 
> "... it's a good idea to use braces when there are nested 'ifs'"

> "... the last 'else' part handles the 'none of the above' or default case where none of the other conditions is satisfied."


#### Switch

> "The break statement causes an immediate exit from the switch. Because cases serve just as labels, after the code for one case is done, execution falls through to the next unless you take explicit action to escape. break and return are the most common ways to leave a switch."

#### Loops

> "One final C operator is the comma ",", which most often finds use in the for statement. A pair of expressions separated by a comma is evaluated left to right, and the type and value of the result are the type and value of the right operand."

```c
#include <stdio.h>
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
```

```c
for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
```

#### Break & Continue

It is sometimes convenient to be able to exit from a loop other than by testing at the top or bottom (for/while loop or do/while loop). The break statement provides an early exit from for, while, and do. A break causes the innermost enclosing loop or switch to be exited immediately.


The continue statement is related to break, but less often used; it causes the next iterations of the enclosing for, while, or do loop to begin. In the while and do, this means that the test part is executed immediately; in the for, control passes to the increment step.

#### Goto and labels

> "The are a few situations where goto(s) may find a place. The most common is to abandon processing in some deeply nested structure, such as breaking out of two or more loops at once. The break statement cannot be used directly since it only exits from the innermost loop."

#### Function

> "C has been designed to make functions efficient and easy to use; C programs generally consist of many small functions rather than a few big ones"

> "Coercion: in the context of function type declarations refers to the automatic conversion of a value from one type to another."

> "[...] Because C arrays begin at position zero, indexes will be zero or positive, and so a negative value like -1 is convenient for signaling failure."

> "A program is just a set of definition of variables and functions. Communication between the functions is by arguments and values returned by the functions, and through external variables."

####  External Variables

> "A C program consists of a set of external objects, which are either variables or functions. The adjective 'external' is used in contrast to 'internal', which describes the arguments and variables defined inside functions."

> "We will see later how to define external variables and functions that are visible only within a single source file. Because external variables are globally accessible, they provide an alternative to function arguments and return values for communicationg data between functions. Any function may access an external variable by referring to it by name, if the name has been declared somehow."

> "External variables are also useful because of their greater scope and lifetime. Automatic variables are internal to a function; they come into existence when then function is entered, and disappear when it is left. External variables, on the other hand, are permanent, so they can retain values from one function invocation to the next. Thus if two functions must share some data, yet neither calls the other, it is often most convenient if the shared data is kept in external variables rather than being passed in and out via arguments."

#### Scope Rules

It is important to distinguish between the declaration of an external variable and its definiton. A declaration announces the properties of a variable (primarly its type); a definiton also causes storage to be set aside.


If lines:
```c
    int sp;
    double val[MAXVAL];
```
appear outside of any function, they define the external variables sp and val, cause storage to be set aside, and also serve as the declarations for the rest of that source file. On the other hand, the lines
```c
    extern int sp;
    extern double val[];
```
declare for the rest of the source file that sp is an int and that val is a double array (whose size is determined elsewhere), but they do not create the variables or reserve storage for them.


There must be only one definition of an external variable among all the files that make up the source program; other files may contain extern declarations to acces it.


```c
    /* in file1: */

    extern int sp;
    extern double val[];

    void push(double f) { ... }
    
    double pop(void) { ... }
```

```c
    /* in file2: */
    int sp = 0;
    double val[MAXVAL];
```

source: page 73.

#### Static Variables

> "static storage class should be used only when a program requires the value of a varaible to persist between different function calls, like in recursive calls" Exploring C - YPK


The static declaration, applied to an external variable or function, limits the scope of that object to the rest of the source file being compiled.
External static thus provides a way to hide names like `buf` and `bufp` in the getch-ungetch combination, which must be external so they can be shared, yet which should not be visible to users(place where function is call) of getch and ungetch.

source: page 75.

#### Initialization

In the absence of explicit initialization, external and static variables are guaranteed to be initialized to zero; automatic and register variables have undefined (i.e, garbage) initial values.


For external and static variables, the initializer must be a constant expression;


For automatic and register variables, the initializer is not restricted to being a constant: it may be any expression involving previously defined values, even function calls.

In effect, initialization of automatic variables are just shorthand for assignement statements. Which form to prefer is largely a matter of taste. We have generally used explicit assignments, because initializes in declarations are harder to see and further away from the point of use.


An array may be initialized by following its declaration with a list of initializers enclosed in braces and separated by commas.


Character arrays are a special case of initialization; a string may be used instead of the braces and commans notation:

```c
    char pattern = "ould";
    /* is a shorthand for the longest but equivalent */
    char pattern = { 'o', 'u', 'l', 'd', '\0' };
```


#### Recursion

C functions may be used recursively; that is, a function may call itself either directly or indirectly.

When a function calls itself recursively, each invocation gets a fresh set of all the automatic variables, independent of the previous set.

#### The C Preprocessor

C provides certain language facilities by means of a preprocessor, which is conceptionally a separate first step in compilation.

###### Macro Substitution

```c
    #define name replacement text
```

It calls for a macro substitution of the simplest kind - subsequent occurences of the token name will be replaced by the replacement text.

The scope of a name defined with #define is from its point of definition to the end of the source file being compiled.


It is also possible to define macros with arguments, so the replacement text can be different for different calls of the macro.

```c
    #define max(A, B) ((A) > (B) ? (A) : (B))
    
    x = max(p+q, r+s);
    /* will be replaced by the line */
    x = ((p+q) > (r+s) ? (p+q) : (r+s))
```


Note, macros are essentially textual replacements, ensure proper precedence by adding parentheses to the macro definiton

```c
    #define square(x) x * x

    square(z+1) /* => z + 1 * z + 1, wrong precedence */
```


#### Pointers

The `void *` pointer is the proper type for a generic pointer.


As a pointer, `void *` can point to any data type, but you cannot directly dereference a `void *` without first casting it to another pointer type that points to a specific data type.


Before the adoption of `void *` as a generic pointer, `char *` was frequently used for this purpose. This is because a `char` in C is defined to be 1 byte, and `char *` can access each byte of memory individually.


Using `void *` pointer is like positioning a cursor at a starting point in memory. At this stage, the pointer simply indicates where something is located but doesn't provide information about what exactly is at that location or how it should be interpreted. 


The unary operator `&` gives the address of an object. This operator only applies to objects in memory: variables and array elements.


The unary operator `*` is the indirection or dereferencing operator; when applied to a pointer, it accesses the object the pointer points to.

##### Pointers and Function arguments

Since C passes argument to functions by value, there is no direct way for the called function to alter a variable on the calling function. The way to obtain the desired effect is for the calling program to pass pointers to the values to be changed.

##### Pointers and Arrays

Any operations that can be achieved by array subscripting can also be done with pointers.


The correspondence between indexing and pointer arithmetic is very close. By definiton, the value of a variable or expression of type array is the address of element zero of the array. Since the name of an array is a synonym for the location of the initial element, the assignment `pa=&a[0]` can also be written as `pa = a`;

Rather more surprising, at first sight, is the fact that a reference to a[i] can also be written as *(a+1). In evaluating a[i], C converts it to *(a+i) immediately; the two forms are equivalent.

In C, `[ ]` is metaphorically equivalent to `* +` becoming `* (array_name + subscript)`

In short, an array-and-index expression is equivalent to one written as a pointer and offset.

An array name has a special behavior that distinguishes it from regular variables. Instead, it acts as a constant pointer to the first element of the array. The key distinction is that while 'a' behaves like a pointer, you cannot change its value. That is, 'a' is a constant pointer, 'a' is not a modifiable value.


The array name 'a' gives the address of the first element, but itself is not stored anywhere as a separate entity. It's more of a compile-time constructthat refers to the memory location where the array elements are stored.

When an array name is passed to a function, what is passed is the location of the initial element. Within the called function, this argument is a local variable, and so an array name parameter is a pointer, that is, a variable containing an address.

```c
    /* as formal parameters in a function definition, */
    char s[];
    /* and */
    char *s;
    /* are equivalent; we prefer the latter because it says more
     * explicitly that the variable is a pointer */
```

#### Address Arithmetic

```c
    /* strlen: return length of string s */
    int strlen(char *s) {
        char *p = s;
        
        while (*p != '\0')
            p++;
        return p - s;
    }
```

In the while loop the pointer increment until is own address is equal to `\0`
    
#### Character Pointers & Functions

A string constant is accessed by a pointer to its first element.

```c
char *pmessage;

/* assigns to pmessage a pointer to the character array */
pmessage = "now is the time";
```

There is an important difference between these defintions:

```c
char amessage[] = "now is the time"; /* an array */
char *pmessage = "now is the time";  /* a pointer */
```
Arrays have their own storage, while pointers reference existing storage, typically read-only in the case of string literals.
Arrays and pointers are fundamentally different in C, although they can be accessed similarly in many contexts.
The main differences are the memory allocation and size. The similarities are, accessing elements (both can be used to access elements using the subscript operator `[]`, notation, and (pointer)arithmetic.

In C, an assignement operations returns the value that was assigned.

```c
/* strcpy: copy t to s; pointer version 2 */
void strcpy(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}
```

Interesting idiom, frequently used in C:

```c
/* the comparison against '\0' is redundant, since the question
* is merely whether the expresion is zero */

/* strcpy: copy t to s: pointer version 3 */
void strcpy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}
/* '\0' has an integer value of 0 */
```

Standard idiom for pushing and popping a stack:

```c
    *p++ = val;     /* push val onto stack */
    val = *--p;    /* pop top of stack into val */   
```

NOTE:

It's great practice to `return 0` indicating equality.

```c
int strncmp(char *s, char *t, int n) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
```

In this case, if either condition is met, (`*s == '\0' || --n <= 0`), the function return 0, indicating that the strings are equal.
Else we return the difference (`*s - *t`) indicating whether the character from 's' is greater than or less than.

##### Pointer Arrays; Pointers to pointers

```c
    char *lineptr[MAXLINES]
```
This line says that lineptr is an array of MAXLINES elements, each element of which is a pointer to a char.

