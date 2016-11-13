### C programming journaling###

<updated date: mm/dd/yy>

<journal type: errors/algorithms/thoughts>

<content: code/words...>

<references: link/books/media...>

### **content**

- [Compound literals](#compound-literals)
- [Designated structure](#designated-structure)
- [Undeclared array](#undeclared-array)
- [Using boolean value in C](#using-boolean-value-in-c)

----

9/11/16

### Undeclared array###

>  In C, at least back in the old days, variable declarations have to <u>come at the top of the block</u>. C++ is different in that regard.


> edit — apparently C99 is different from C90 in this respect (C99 being essentially the same as C++ on this issue).

[sof](http://stackoverflow.com/questions/4774961/why-do-i-get-error-undeclared-identifier-unless-i-declare-my-variable-at-the-b)



### Using boolean value in C###

```c
// option 1: giving a type a new name
typedef int bool; // using bool instead of int
#define true 1
#define false 0

// option 2: include library (C99)
#include <stdbool.h> // M$ VS 2012 C89
```

```c
typedef struct my_struct_type my_short_type_t;
// using my_short_type_t to represent the struct type and to declare variables
```

- typedef is used to give a new name to represent the old type throughout the program. 
- typedef can be used to ease the burden of declaring structure.


[typedef](http://www.cprogramming.com/tutorial/typedef.html)

[boolean values](http://stackoverflow.com/questions/1921539/using-boolean-values-in-c)



### Designated structure###

```c
struct date today = { .year = 2016, .month = 12, .day = 23 }; 
// "." syntax error
struct date today = { 12, 23, 2016 }
// conformity to C89
struct date today = { 12, 23 }
// zero-initialize member "year"
```

> Designated initializers are a C99 (or newer) feature, and Visual Studio doesn't support C99 (or newer). 

- initialize part of the members in a structure will result in zero-initializing (like array)
- { 0 } to implement all-zero-initializing

[sof](http://stackoverflow.com/questions/23986521/c2059-in-vs2012-how-to-initialize-struct-instance)



### Compound literals###

```c
today = (struct date) {12, 1, 2014};
```

> The construct `(Type){initialisers}` is <u>not a cast operation</u>, but it is the <u>syntactic construct</u> of a *compound literal*. This is a C99 construct, which GCC also supports in its C++ compiler as an extension. As far as I can determine, compound literals are not supported by MSVC in either its C or C++ mode.

- no comments.

[sof](http://stackoverflow.com/questions/3869963/compound-literals-in-msvc)

