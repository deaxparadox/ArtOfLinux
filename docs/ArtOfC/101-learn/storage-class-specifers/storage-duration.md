# Storage Duration

Scope and linkage describe the visibility of identifiers. Storage duration decribes the persistence of the object accessed by these identifiers.

A C object has one of the following four storage durations:

- [Static Storage Duration](#static-storage-duration)
- [Thread Storage Duration](#thread-storage-duration)
- [Automatic Storage Duration](https://)
- [Allocated Storage Duration](https://)


#### Static Storage Duration

If an object has static storage duration, it exits throughout program execution. Variables with file scope have static storage duration. 

Note that for file scope variables, the key **static** indicates the linkage type, not the storage duration. A file scope variable declared usign **static** has internal linkage, but all file scope variables using internal likage or external linkage, have static storage duration.

#### Thread Storage Duration

Thread storage duration comes into play in concurrent programming, which program execution can be divided into mulitple threads. A object with thread storage duration exists from when it's declared until the thread terminates. Such an object is create when the declaration that would otherwise create a file scope object is modified with the keyword **_Thread_local**. When a variable is declaread with this specifier, each thread gets it own private copy of that variable.

#### Automatic Storage Duration

Variables with block scope normally have automatic storage duration. These variables have memory allocated for them when then program enters the block in which they are defined, and the memory is freed when the block is exited.

The idea is that memory used for automatic variables is a workspace or scratch pad that can be reused. For example, after a function call terminates the memory it used for its variables can be used to hold variables for the next function that is called.

Variable-length arrays provide a slight exception in that they exist from the point of declaration to the end of the block rather than from the beginning of the block to the end.

For example, in the following code, the variables *number* and *index* came into being each time  the **bore()** function is called and pass away each time the function completes:

```c
void bore(int number)
{
    int index;

    for (index=0; index<number; index++)
        puts("They don't make them the way they used to.\n");
    return 0;
}
```

##### Block Scope with static storage duration

It is possible, however, for a variable to have block scope but statis storage duration. To create such a variable, declare it inside a block and add the keyword **static** to the declaration:


```c
void more(int number)
{
    int index;
    static int ct = 0;
    ...
    return 0;
}
```

- Here the variable **ct** is stored in static memory; it exists form the time  the program in loaded until the program terminates. 
- But its scope is confined to the **more()** function block. Only while this function executes can the program use **ct** to access the object it designates.


### Five Storage Classes

| Storage Class | Duration | Scope | Linkage | How Declared |
-----------|--------------|--------|---------|--------------|
automatic | Automatic | Block | None | In a block |
register | Automatic | Block | None | In a block with the keyword **register** |
static with external linkage | Static | File | External | Outside of all functions |
static with internal linkage | Static | File | Internal | Outside of all functions with keyword **static** |
static with no linkage | Static | Block | None | In a block with the keyword **static** |