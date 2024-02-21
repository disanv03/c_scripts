> "Four important aspects of any language are the way it stores data, the way it operates upon this data, how it accomplishes input and output, and how it lets you control the sequence of execution of instructions in a program."


*32 Keywords available in C*:

- auto, break, case, char, const, continue, default, do, double, else, enum,extern, float, for, goto, if, int, long, register, return, short, signed, sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while
 
---

> "main() is a function. A function is nothing but a container for a set of statements."

---

| Priority | Operators | Descriptions                                |
|----------|-----------|---------------------------------------------|
| 1st      | * / %     | Multiplication, Division, Modular division  |
| 2nd      | + -       | Addition, Subtraction                       |
| 3rd      | =         | Assignment                                  |

"When an expression contains two operators of equal priority the tie between them is settled using the associativity of the operators. All operators in C have either *Left* to *Right* associativity or *Right* to *Left* associativity."

---


```c
/* Consider the expression: */
a = 3 / 2 * 5
```

"Here there is a tie between operators of same priority. This tie is settled using the associativity of */* and __*__. Both enjoy *Left* and *Right* associativity. Therefore firstly */* operation is done followed by __*__.

---

> "Note that in C a non-zero value is considered to be true, whereas a O is considered to be false."

> "Remember that in C, 'truth' is always non-zero"


```c
/* first question */
int a = 10;
!(a < 10) /* value 1 */

/* second question */
/* Why parenthesis */
i >= 5 ? j = 10 : j = 15;
/* find what is confusing for the compiler */
```


> "Almost always, if something is worth doing, it's worth doing more than once"


> "Upon reaching the closing brace of for, control is sent back to the for statement, where the value of **count** gets incremented by 1."


> "We often come across situations where we want to jump out of a loop instantly, without waiting to get back to the condition. The keyword *break* allows us to do this. When *break* is encountered inside any loop, control automatically passes to the first statement after the loop."


> "In some programming situations, we want to take the control to the beginning of the loop, bypassing the statements inside the loop, which have not yet been executed. The keyword *continue* allows us to do this. When continue is encountered inside any loop, control automatically passes to the beginning of the loop"

> "The usage of the *goto* keyword should be avoided as it usually disturbs the normal flow of execution."

> "On executing the return statement, it immediately transfers then control back to the calling function"

> "A function can return only one value at a time. There is a way to get around this limitation, pointers..."

```c
int main() {
    int a, b, c;
    sum = calsum(a, b,c);

    return 0;
}

int calsum(int x, int y, int z) {
    int d;
    d = x + y + z;
    return d;
}
```

In the above code, the varaibles a, b, and c are called *Actual Arguments*,
the variable x, y, and z are called *Formal arguments*


This means that when values are passed to a called function, the values present in actual arguments are not physically moved to the formal arguments; just a photocopy of values in actual argument is made into formal arguments.

> "The value of each of the actual arguments in the calling function is copied into the corresponding formal arguments of the called function."

> "In C order of passing arguments to a function is from right to left"

> "If you observe carefully, whenever we called a function and passed something to it we have always passed the 'values' of variables to the called function. Such function calls are called 'calls by value'."

> "We have also learnt that variables are stored somewhere in memory. So instead of passing the value of a variable, can we not pass the location number of the variable to a function? If we were able to do so, it would become a 'call by reference'"

> "A stack is a last in first out (LIFO) data structure. This means that the last item to get stored on the stack (often called push operation) is the first one to get out of it (often called pop operation).

### Recursive step ###
- Decompose, extract(condition) and reduce.
- Touch the base
- Operation part: previous extractation(condition) and the targeted operation. Were computation take place.


> "... the primary data types themselves can be of several types. For example, a char can be an **unsigned char** or a **signed char**. Or an **int** can be a **short int** or a **long int**."
> "To fully define a variable, one needs to mention not only its type but also its storage class."

16-bit compiler Turbo C the range is -32768 to 32776 (two/bytes used to store)
32-bit compiler like Visual Studio or gcc range id -2147483648 to +2147483648 (four/bytes)

> "Remember that out of the two/four bytes used to store an integer, the highest bit (16th/32nd bit) is used to store the sign of the integer. This bit is 1 if the number is negative and 0 if the number is positive."

> "Sometimes, we come across situations where the constant is small enough to be an **int**, but still we want to give it as much storage as a **long**. In such cases, we add the suffix 'L' or 'I' at the end of the number, as in 23L."

> "A **signed char** is same as an ordinary **char** and has a range from -128 to +127; whereas, an **unsigned char** has a range from 0 to 255."

> "A **float** occupies four bytes in memory and can range from -3.4e38 to +3.4e38. If this is insufficient, then C offers a **double** data type that occupies 8 bytes in memory and has a range from -1.7e308 to +1.7e308."
