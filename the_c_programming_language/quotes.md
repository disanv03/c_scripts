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

> "A sequence of characters in double quotes, like "hello, world\n", is called a character string or string constant"

> "An escape sequence like \n provides a general and extensible mechanism for representing hard-to-type or invisible characters."

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




