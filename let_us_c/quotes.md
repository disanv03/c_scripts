> "Four important aspects of any language are the way it stores data, the way it operates upon this data, how it accomplishes input and output, and how it lets you control the sequence of execution of instructions in a program."


*32 Keywords available in C*


- auto, break, case, char, const, continue, default, do, double, else, enum,extern, float, for, goto, if, int, long, register, return, short, signed, sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while
 

> "main() is a function. A function is nothing but a container for a set of statements."


| Priority | Operators | Descriptions                                |
|----------|-----------|---------------------------------------------|
| 1st      | * / %     | Multiplication, Division, Modular division  |
| 2nd      | + -       | Addition, Subtraction                       |
| 3rd      | =         | Assignment                                  |

"When an expression contains two operators of equal priority the tie between them is settled using the associativity of the operators. All operators in C have either *Left* to *Right* associativity or *Right* to *Left* associativity."


```c
/* Consider the expression: */
a = 3 / 2 * 5
```


"Here there is a tie between operators of same priority. This tie is settled using the associativity of */* and __*__. Both enjoy *Left* and *Right* associativity. Therefore firstly */* operation is done followed by __*__.


> "Note that in C a non-zero value is considered to be true, whereas a O is considered to be false."
