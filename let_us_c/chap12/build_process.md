### Preprocessing

During this step, the C source code is expanded based on the preprocessor directives like #define, #include, #ifdef, ect. The expanded source code is stored in an intermediate file with .i extension. Thus, if our source code is PR1.C then the expanded source code is stored in PR1.I. The expanded source code is also in C language. Note that the '.I' extension may vary from one compiler to another.

### Compilation

The expanded source code is then passed to the compiler, which identifies the syntax errors in the expanded source code. These errors are displayed along with warnings, if any.


If the expanded source code is error-free, then the compiler translates the expanded source code, into an equivalent assembly language program.
Thus assembly code is typically stored in .ASM file.

### Assembling

The job of the assembler is to translate .ASM program into Relocatable Object code. Thus, if the assembly language instructions are present in PR1.ASM then the relocatable object code gets stored in PR1.OBJ.


Here the word 'Relocatable' means that the program is complete except for one thing -no specific memory addresses have yet been assigned to the code and data sections in the relocatable code. All the addresses are relative offsets.

The .OBJ file that gets created is a specially formatted binary file. 


### Linking

Linking is the final stage in creating an executable program.
