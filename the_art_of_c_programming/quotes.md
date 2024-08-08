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

```c
    /* Writing String functions that mimic BASIC's LEN, LEFT$, RIGHT$, and MID$ */

    /* len: return string length */
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


## More about Pointers

Let's revise the len function using pointer.

```c
    int len(char *s) {
        char *begin;
        begin = s;
        while (*s++)
            ;
        return (s - begin - 1);  
    }
```

This is clearly a very close relative of the original len function. We're just missing a few square brackets, and we have to store the initial pointer value rather than setting a counter to zero.


```c
    /* let's write strcpy */
    /* strcpy: copy move string about from source to target */
    char *strcpy(char *dest, const char *src) {
        char *dest_start = dest;
        while (*src)
            *dest++ = *src++;
        *dest = '\0';
        return dest_start;
    }
        
    /* strcat: concatenate two strings together */
    char *strcat(char *string, const char *extra) {
        char *dest_strat = string;
        string += strlen(string);
        while (*extra)
            *string++ = *extra++;
        *string = '\0';
        return dest_start;
    }
```

**Projects:**

```c
    /* Write a function dayO which takes a pointer *date pointing to a string
    * giving a date, in the format "March 18 1937", and returns a pointer *day
    * to a string that gives the corresponding day of the week
    */
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    const char *days_of_week[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
        "Saturday"
    };
    
    int month_to_number(const char *month) {
        for (int i = 0; i < 12; i++) {
            if (strcmp(months[i], month) == 0) {
                return i + 1;
            }
        }
        return -1; /* month not found */
    }

    const char *dayO(const char *date) {
        char month_str[20];
        int day, year;
        sscanf(date, "%s %d %d", month_str, &day, &year);
        
        int month = month_to_number(month_str);
        if (month == -1) return NULL;

        /* adjust month and year for January and February */
        if (month == 1 || month == 2) {
            month += 12;
            year --;
        }

        /* Zeller's Congruence Algorithm
         * Used to determine the day of the week for any given date
         * 
         * K = the year within the century (1937 % 100 = 37)
         * J = century (2001 / 100 = 20)
         */        
         
        int K = year % 100;
        int J = year / 100;
        
        /* Zeller's Congruence formula */
        int f = day + (13*(month+1))/5 + K + K/4 + J/4 + 5*J;
        int day_of_week = f%7;

        day_of_week = (day_of_week + 6) % 7;
    
        return days_of_week[day_of_week];
    }

    int main() {
        const char *date = "March 18 1937";
        const char *day = dayO(date);
        if (day != NULL) {
            printf("The day of the week for %s is %s.\n", date, day);
        else {
            printf("Invalid date format.\n");
        }
        return 0;
    }
```

```c
    /* Write a perpetual calendar which, given the month and year, prints
     * out which days of that month fall on which dates, in the usual
     * calendar format:
     *
     * August                                       1986
     * SUN  MON     TUE     WED     THU     FRI     SAT
     *                                      1       2
     * 3    4       5       6       7       8       9
     * 10   11      12      13      14      15      16
     * [...]
     * 24   25      26      27      28      29      30
     * 31                              
     *
     */

     #include <stdio.h>
     #include <stdlib.h>
     #include <string.h>
    
     const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
     };
    
     const char *days_of_week[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
        "Saturday"
     };

     int month_to_number(const char *month) {
        for (int i = 0; i < 12; i++) {
            if (strcmp(months[i], month) == 0)
                return i + 1;
        }
        return -1; /* month not found */
     }
     
     const char *dayO(const char *date) {
        char month_str[20];
        int day, year;
        sscanf(date, "%s %d %d", month_str, &day, &year);
        
        int month = month_to_number(month_str);
        if (month == -1) return NULL;

        /* adjust month and year for January and February */
        if (month == 1 || month == 2) {
            month += 12;
            year--;
        }
        
        /* Zeller's Congruence Algorithm */
        int K = year % 100;
        int J = year / 100;
        
        /* Zeller's Congruence formula */
        int f = day + (13*(month+1))/5 + K + K/4 + J/4 + 5*J;
        int day_of_week = f % 7;

        day_of_week = (day_of_week + 6) % 7;
        return days_of_week[day_of_week];
     }

     int days_in_month(int month, int year) {
        if (month == 2) {
            /* check for leap year */
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) {
                return 29;
            else {
                return 28;
             }
            }
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }
    
    void print_calendar(int month, int year) {
        char first_date[20];
        /* snprintf: write to the array of char (string) with max n size of characters */
        snprintf(first_date, sizeof(first_date), "%s 1 %d", months[month-1], year);
        const char *first_day = dayO(first_date);
        int start_day = -1;
        for (int i = 0; i < 7; i++) {
            if (strcmp(days_of_week[i], first_day) == 0) {
                start_day = i;
                break;
            }
        }
        if (start_day == -1) {
            printf("invalid date.\n");
            return;
        }
        printf("%s %d\n", months[month-1], year);
        printf("SUN MON TUE WED THU FRI SAT\n");

        int days = day_in_month(month, year);
        int day = 1;
        
        for (int i = 0; i < start_day; i++)
            printf("    ");
        
        for (int i = start_day; i < 7; i++)
            printf("%-5d", day++)
        printf("\n");

        while (day <= days) {
            for (int i = 0; i < 7 && day <= days; i++)
                printf("%-5d", day++) /* -: left-aligned, 5 char wide, d: deciaml */

            printf("\n");
        }
    }

    int main() {
        int month, year;
        printf("Enter month (1-12): ");
        scanf("%d", &month);
        printf("enter year: ");
        scanf("%d", &year);

        if (month < 1 || month > 12) {
            printf("invalid month. enter a value between 1 and 12);
            return 1;
        }

        print_calendar(month, year);
        return 0;
    }
```

## Floats and Other types

> "She can't do Subtraction", said the White Queen. "Can you do Division? devide a loaf by a knife - what's the answer to that?"


The unsigned form allows you to tell the compiler that you want to think about the number as always being positive, and you get a doubled maximum value as an advantage.

### **Declaring Structures**

```c
    /* definition of a cat_entry */
    struct cat_entry {
        int item_no;
        char description[30];
        float price;
        int stock_level;
    };

    /* catalog is an array of 200 elements, each of which has the
     * the cat_entry structure
     */
    struct cat_entry catalog[200];

    /* cat_entry has become just another type
     * Here a pointer to objects of that type
     */
    struct cat_entry *p;
    /* you can now use p to point anywhere in the catalog */
```



    


    
