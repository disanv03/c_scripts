## Precedence from highest to lowest

| Precedence | Operator         | Description                             | Associativity |
|------------|------------------|-----------------------------------------|---------------|
| 1          | `()`             | Parentheses                             | Left to Right |
| 2          | `!` `~`          | Logical NOT, Bitwise NOT                | Right to Left |
| 3          | `*` `/` `%`      | Multiplication, Division, Remainder     | Left to Right |
| 4          | `+` `-`          | Addition, Subtraction                   | Left to Right |
| 5          | `<<` `>>`        | Bitwise left shift, Bitwise right shift | Left to Right |
| 6          | `<` `<=` `>` `>=`| Relational Operators                    | Left to Right |
| 7          | `==` `!=`        | Equality, Inequality                    | Left to Right |
| 8          | `&`              | Bitwise AND                             | Left to Right |
| 9          | `^`              | Bitwise XOR                             | Left to Right |
| 10         | `\|`             | Bitwise OR                              | Left to Right |
| 11         | `&&`             | Logical AND                             | Left to Right |
| 12         | `\|\|`           | Logical OR                              | Left to Right |
| 13         | `=`              | Assignment                              | Right to Left |
