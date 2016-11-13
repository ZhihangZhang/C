### C programming journaling###

---

##### structure of journaling#####

<updated date: mm/dd/yy>

<journal type: errors/algorithms/thoughts>

<content: code/words...>

<references: link/books/media...>

-----



9/11/16

**Undeclared array**

No code

>  In C, at least back in the old days, variable declarations have to come at the top of the block. C++ is different in that regard.


> edit — apparently C99 is different from C90 in this respect (C99 being essentially the same as C++ on this issue).

[sof](http://stackoverflow.com/questions/4774961/why-do-i-get-error-undeclared-identifier-unless-i-declare-my-variable-at-the-b)

---

9/11/16

**Using boolean value in C**

```c
// option 1: giving a type a new name
typedef int bool; // using bool instead of int
#define true 1
#define false 0

// option 2: include library (C99)
#include <stdbool.h> // M$ VS 2012 C89
```

- typedef is used to give a new name to represent the old type throughout the program. 
- typedef can be used to ease the burden of declaring structure.

```c
typedef struct my_struct_type my_short_type_t;
// using my_short_type_t to represent the struct type and to declare variables
```

[typedef](http://www.cprogramming.com/tutorial/typedef.html)

[boolean values](http://stackoverflow.com/questions/1921539/using-boolean-values-in-c)

----

