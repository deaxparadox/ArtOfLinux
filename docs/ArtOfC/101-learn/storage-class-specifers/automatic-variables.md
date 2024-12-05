# Automatics Variables

A variable belonging to the automatic storage clas has automatic storage duration, block scope and no linkage. *By default, any variable declared in a block or function header belongs to the automatic storage class*.

You can, however, make your intentions perfectly clear by explicitly using the keyword *auto*, as shown here:

```c
int main(void)
{
    auto int plox;
```

You might do this, to document that you are intentionally overridding an external definition or that it is important not to change the variable to another storage class. **But, it's preffered not to use this method.**.

Block scope and no linkage imply that only the block in which the variable is defined can access that variable by name. Another function can use a variable with the same name, but it will be an independent variable stored in a different memory location.


Automatic storage duration means that the variable comes into existence when the program enters the block that contains the variable declaration. When the program exits the block, the automatic variable disappears. Its memory location not can be used for something else, although not necessarily.

#### Nested Blocks

A variale is known only to the block in which it is declared and to any block inside that block:

```c
int loop(int n):
{
    int m;                      // m in scope
    scanf("%d", &m);
    {
        int i;                  // both m and i in scope
        for (i=m; i<n; i++) 
            puts("i is local to sub-block\n");
    }
    return m;                   // m in scope, i gone
}
```

In this code, *i* is visible only within the inner braces. You'd get a compiler error if you tried to use it before or after the inner block. The variable *n* and *m*, being defined in the function head and in the outer block, are in scope for the whole function and exist until the function terminates.


#### What if you declare variable in an inner block that has the same name as one in the outer block?

The name defined inside the block is the variable used inside the block. We say it *hides*  the outer definition. However, when execution exits the inner block, the outer variable comes back into scope.

```c
int outer_hide_impl()
{
    int x = 30;                 // Original x

    printf("x in outer block: %d at %p\n", x, &x);
    
    {
        int x = 7;              // new x, hides first x
        printf("x in inner block: %d at %p\n", x, &x);
    }
    
    printf("x in outer block: %d at %p\n", x, &x);

    while (x++ < 33)            // Original x
    {       
        int x = 100;            // new x, hides first x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);

}
```

Here's the output:

```sh
x in outer block: 30 at 0x7ffc80228770
x in inner block: 7 at 0x7ffc80228774
x in outer block: 30 at 0x7ffc80228770
x in while loop: 101 at 0x7ffc80228774
x in while loop: 101 at 0x7ffc80228774
x in while loop: 101 at 0x7ffc80228774
x in outer block: 34 at 0x7ffc80228770
```

- First, the program creates an *x* variable with the value 30, as the first *printf()* statement shows.
- Then it defines a new *x* variable with the value 77, as  the second *print()* statement shows.
- That it is a new variable hiding the first *x* is shown by the address and also by the third *printf()* statement. It is located after the first inner block, and it displays the original *x* value, showing the original *x* variable never went away  and never got changed.
- The *while* loop test uses the original *x*:

```c
while (x++ < 30)
```

Inside  the loop, however, the program sees a third *x* variable, one defined just inside the *while* loop block. So when the code use *x++* in the body of the loop, it is the new *x*that is increment to 101 and then displaye. When each loop cycle is completed, that new *x* disappears. Then the loop test condition uses and increments the original *x*, the loop block is entered again, and the new *x* is created again. 

In this examples, that *x* is created and destroyed three times. Note that, to terminate, this loop had to increment *x* in the test condition becuase incrementing *x* in the body increments a different *x* than the one used for the test.

This particular compiler didn't reuse the inner block memory location of *x* for the *while* loop version of *x*, but some compilers do.

