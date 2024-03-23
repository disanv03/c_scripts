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
