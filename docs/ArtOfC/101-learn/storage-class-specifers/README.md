# Storage Class

The storage class specifiers are:

- [What are storage classes?](#what-is-storage-classes)
- [What is scope Scope?](#what-is-scope)

- auto
- regiter
- statis
- extern
- typedef


C enables you to control a program's file points. C's memory management exemplifies that control by letting you determine which functions known which variables and for how long a variable persists in a program. *Using memory storage is one more element of program design*.


### What is storage classes?

C provides several different models, or *storage classes*, for storing data in memory. 

C literature uses the term *object* for data values occupies in physical memory. An object can hold one or more values. An object migh not yet actually have a stored value, but it will of the right size to hold an appropriate value.

```c
int entity = 3;
```

This declaration creates an *identifier* called **entitiy**, the identifier **entity** is how the software designates the object that's stored in hardware memory. This declaration also provides a value to be stored in the object.


Let's consider another expression:

```c
int * pt = &entity;
```

In this first case, **pt** is an identifier. It designates an object that holds an address. Next, the expression ***pt** it not an identifier because it's not a name. However, it does designate an object, in this case the same object that **entity** designates.


<p>
You can describe an object in terms of its <em>storage duration</em>, which is how long it stays in memory. You can describe in identifier use to access the object by its <em>scope</em> and its <em>linkage</em>, which indicate together which parts of program can use it.
</p>

The different storage classes offer different combinations of scope, linkage, and storage duration, such as:

- Identifiers that can be shared over several files of source code.
- Identifiers that can be used by any function in one particular file.
- Identifiers that can be used only within a particular function.
- Identifiers that can be use only within a subsection of a function.
- Objects that exist for the duration of a program.
- Objects that exist only while the function containing them is executing.

