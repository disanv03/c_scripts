## The Art of C programming

#### Compilers and Interpreters

>__Interpreter__:
> "when the program is executed, to take each line in turn, translate it into machine code and then run the machine code. When the translation of a line takes place, the resulting machine code overwrites that from the previous line, so that if a line of source code appear in a loop which is executed 200 times, it also must be translated 200 times"


>__Compilers__:
> "The obvious alternative is to translate the entire source code into a single machine code program, and then run the machine code. This will clearly execute faster, and there are no translations during execution. A translator that adopts this approach is called a compiler."


#### The Skeleton of a C program

> "All C programs consist of a series of functions"

> "The effective length of a function name is often six letters"

> "In C, the newline character has no significance at all"


#### Loop and Control Constructs

```c
    /* conditional expression */
    if (x == 0) printf("x is zero");
    /* is exactly equivalent to */
    if (!x) printf("x is zero");

    /* logical connectives */
    if (a > 10 && a < 20)
        printf("a is within range");
    /* this could be negated: */
    if (!(a > 10 && a < 20))
        printf("a is not within range");
```


#### Arithmetic and Logic

> "... and then the different branches of arithmetic -- Ambition, Distraction, Uglification, and Derision". Alice's Adventures in Wonderland


__ASCII coding system in binary__


| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

- Bit 7: Not used in standard ASCII
- Bit 6: 0=Digit, 1=Letter  
- Bit 5: 0=Upper case, 1=digit/lower case
- Bit 4: 0= a-o, 1=digit/p-z  
- Bit 3:  
- Bit 2:  
- Bit 1:  
- Bit 0: 


#### AND (&)

> "The AND operation compares two bit patterns and produces a third result pattern. If corresponding pairs of bits are both 1 the result bit for that position is set to 1. Under all other circumstances it is set to 0"

```c
    /* toupper, convert lower case to their upper case equivalents */
    toupper(char c) {
        char mask;
        mask = 223;
        return (c & mask);
    }
```

Binary value of 223: `11011111` bit 5 is forced to zero, and the other bits are left unchanged.


> "a bit that is set, i.e., 1, is considered "true"; a cleared bit, or 0, is "false". Thus, in the result of `z = x & y`, each bit is set if and only if the corresponding bit is set in both `x` and `y`."


#### OR

> "If either of the corresponding pairs of bits is a `1` the result bit for that column is `1`. Only if both bits are zero is the result zero"

```
    p   01101010
    q   00100011
    p|q 01101011
```

```c
    /* tolower: lower case letters from either upper of lower case arguments/*
    tolower(char c){
        char mask;
        mask = 32;  /* 00100000 */
        return (c | mask);
    }

    /* you can see that bit 5 is forced to 1 */
```

#### XOR

This is short for eXclusive OR. It's like OR except that it excludes the condition that both bits are '1'.

```
    p   01101010
    q   00100011
    p^q 01001001

    1^1 = 0
```

Now we can write the function swapcase

```c
    /* swapcase: converts lower to upper case and vice versa */
    swapcase(char c) {
        char mask;
        mask = 32;
        return (c ^ mask);
    }
```


#### NOT

> "There's one remaining logical operator, NOT. This inverts every bit in a field."

```
    p   01110001
    ~p  10001110
```

#### Shifts

> "If you shift a bit pattern left and fill in to the right with zeros it has the effect of multiplying by 2"

```
    p   00010011 = 19
    <<  00100110 = 38

    /* this can be done directly with */
    y = x << 1;
    /* will shift x left 1 bit and put the result in y */

    /* similary: */
    p = r << 4;
    /* would shift r 4 bits left, resulting in a multiplication by 16 */
```

Here a "mulitply by ten" technique:

```c
    times10(int n) {
        int m, p;
        m = n << 1;
        p = m << 2;
        return (m + p);
    }
```

Right shifts are also possible: `a = b >> 2;`, would shift b 2 bits right and put the result in a.

> "Normally, a right shift is equivalent to a divide by 2, as you'd expect, but there are exceptions to this rule which we'll come across later."


#### Strings, Arrays, and pointers

##### Strings and Pointers

 
| Number | Character |
|--------|-----------|
| 38012  | t         |
| 38013  | h         |
| 38014  | i         |
| 38015  | s         |
| 38016  |           |
| 38017  | m         |
| 38018  | e         |
| 38019  | s         |
| 38020  | s         |
| 38021  | a         |
| 38022  | g         |
| 38023  | e         |
| 38024  | 0         | 

0 = [ASCII null delimiter]

When C compiles a statement like `s = "this message";` it sets up a set of consecutive bytes somewhere in memory [...]. You'll notice that there's a delimiter provided by the system, which is a zero byte. That's not ASCII zero (whose value is 48) but ASCII null (i.e., all bits set to '0').


The variable `s` is set to `38012`. In other words, it is not the string but rather a pointer to the string. For the moment it is enough to note that it is pointer to strings, rather than the strings themselves, that are passed around in a C program.


Even in the `"printf("some output");` the argument that is really passed to printf is the pointer to the string "some output".


#### Arrays

```c
    char s[30];
    
    /* transfer the string "some stuff" to the array s */
    strcpy(s, "some stuff");
```

> An array name is a pointer to the beginning of the array. However, there is one difference: an array name is a constant and you can't do arithmetic with it whereas a pointer can be manipulated in any way you like.

#### String Functions


Let's illustrate pointer manipulation by writing string functions.
So first we want a function that is passed a pointer to the string, and will return the number of bytes the string contains:

```
    /* string length */
    int len(char s[]) {
        int k;
        k = 0;
        while (s[k++])
            ;
        return (k-1);
    }

    /* left: copy the lefmost 'n' char from string to sub array */
    void left(const char string[], char sub[], int n) {
        int i;
        for (i = 0; i < n && string[i] != '\0'; i++) {
            sub[i] = string[i];
        }
        sub[i] = '\0';
    }

    /* right: copy rightmost n char */
    void right(const *string, char *sub, int n) {
        int length = strlen(string);
        int start = length - n; /* starting index for copying */
        
        if (start < 0)
            start = 0;  /* ensure we don't start before beginning of the string */
        int i, j;
        for (i = start, j = 0; i < length; i++, j++) {
            sub[j] = string[i];
        }
        sub[j] = '\0';
    }

    /* substring: takes a string and two numeric arguments: one for
     * starting position and one for the number of char to transfer */
    void substring(const char *string, char *sub, int start, int length) {
        int string_length = strlen(string);
        
        /* ensure starting index is within bounds */
        if (start < 0 || start >= string_length) {
            sub[0] = '\0';
            return;
        }
        
        /* ensure length doesn't exceed */
        if (start + length > string_length) {
            length = string_length - start;
        }

        int i;
        for (i = 0; i < length && string[start + i] != '\0'; i++) 
            sub[i] = string[start + i];
        sub[i] = "\0';
    }

}
```


#### More about Pointers

    
        
        
