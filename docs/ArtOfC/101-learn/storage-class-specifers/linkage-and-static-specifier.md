# Linkage

A C variable has one of the following linkages: 

- External linkage
- Internal linkage
- No linkage

Variables with block scope, function scope, or function prototype scope have no linkage. That means they are private to the block, function, or prototype in which they are defined.

A variable with **file scope** can have either *internal* or *external* linkage. A variable with external linkage can  be used anywhere in a multifile program. A variable with internal linkage can be used anywhere in a single translation unit.

----------

#### Translation Unit

While compiling  a program compilier replaces *#include* directive with the content of the header file. Thus the compiler sees a single file containing information from your source code and all the header files. This single file is called a *translation unit*.

----------


#### Internal and External Linkage

To define a internal linkage you have to use `static` specifiers:

```c
int dodgers = 5;                // file scope, external linkage
static int dodgers = 5;         // file scope, interal linkage

int main() {
    ...
}
```

The variables **giants** can be used by other files that are part of same program. The **dodgers** variables is private to this particular file, but can be used any any function in the file.