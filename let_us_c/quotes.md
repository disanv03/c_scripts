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
