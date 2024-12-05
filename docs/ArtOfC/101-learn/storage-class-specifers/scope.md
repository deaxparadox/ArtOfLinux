### Scope 
### What is Scope?

*Scope* describes the region or regions of a program that can access an identifier.

A C variable has one of the following scopes:

- block scope
- function scope
- function prototype scope
- file scope

A *block* is a region of code contained within an opening brace and the matching closing brace. 

##### Function Scope

The entire body of a function is a block. Any compound statement within a function also is a block. A varible defined inside a block has a *block scope*, and it is visible form the point it is defined until the end of the block containing the definition.

Formal function parameters, even though they occur before the opening brace of a function, have block scope and belong to the block contaning the function body. Therefore, the varibles **apple** and **quantity** in the following code both have block scope extending to the closing brace.

```c

double blocky(double apple)
{
    double quantity = 0.0;
    ...
    return quantity;
}
```


Variables declared in an inner block have scope restricted just to that block:

```c
double blocky(double apple)
{
    double quantity = 0.0;
    int i;

    for (i=0; i<10; i++)
    {
        double q = apple * i;       // start of scope for q
        ...
        quantity *= q;              // end of scope of q
    }
    ...
    return quantity;
}
```

In this example, the scope of **q** is limited to the inner block and only code within the block can access **q**.

*Function scope*  applies just to labels used with **goto** statements. This means that even if a lable first appears inside an inner block in a function, its scope extends to the whole function. It would be confusing 


##### Function Prototype Scope

*Function prototype scope* applies to variable names used in function prototypes, as in the following:

```c
int mighty(int mouse, double large);
```

Function prototype scope runs from the point the variable is defined to the end of the prototype declaration


##### File Scope (Global variable)

A variable with its definition placed outside of any function has *file scope*. A variable with file scope is visible from the point it is defined to the end of the file containing the definition. 

Take a look at this example:

```c
#include <stdio.h>

int units = 0;              // a variable with file scope
void critic(void);

int main(void) 
{
    ...
}

void critic(void)
{
    ...
}
```

Here, the variable **units** has file scope, and it can be used in both **main()** and **critic()**. Because they canbe used in more than one function, file scope variables are also called **global variables**.