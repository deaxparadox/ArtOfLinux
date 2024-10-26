# Referencing directory

### Table of content

- [Introduction](#introduction)
- [Absolute directory reference](#absolute-directory-references)
- [Relative directory reference](#relative-directory-reference)

### Introduction 


In the linux (or unix) environment, for traversing the filesystem, for running a program, etc. It is required understand how one can reference a file in the linux filesystem. Files can reference either by using *absolute directory reference* and by using *relative directory reference*. It is important to understand the difference between both the method

### Absolute directory references   

You can reference a directory name within a virtual directory system using an *absolute directory reference*. The absolute directory reference defines exactly where the directory is in the virtual directory structure, starting at the root.

Absolute directory reference always begins with a forward slash (**/**), indicating the virtual direcotry system's root.

To reference  user binaries (executable files), contained within the  **bin** directory stored within the **usr** directory, you would use an absolute directory reference as follows:

```
/usr/bin
```

To move to a specific location in the filesystem using the absolute directory reference, you just specify the full pathname.

```sh
paradox@paradox:~$ cd /usr/bin
paradox@paradox:/usr/bin$
```

Notice in the preceeding example that the prompt originally had a tidle (~) it it. After the change to a new directory occured, the tidle was replace with **/usr/bin**. This is where a CLI prompt can help you keep track of where you are in the virtual directory structure.


### Relative directory reference

*Relative directory references* allow you to specify a destination directory refernce relative to your current location. A relative directory reference doesn't start with a forward slash (/).

A relative directory reference starts with either:

- a directory name (if you're traversing to a directory under your current directory) 
- or a special character. 

##### Using directory name

For example if you are in your *home directory* and want to move to the you *Documents* subdirectory, you can use the *cd* command with a relative directory reference;

```bash
paradox@paradox:~$: pwd
/home/paradox
paradox@paradox:~$: cd Documents
/home/paradox/Documents
paradox@paradox:~/Documents$
```

In the preceeding example, a relative directory was used and the present working directory was changed from */home/paradox* to */home/paradox/Documents*. It can confirmed on the shell prompt, before dollar was preceeded by only *tilde* (~) and after moving to  *Documents*, dollar is preceeded by *~/Documents*, it shows you current location.

##### Using special symbols

You can also use a special character to indicate a relative directory location.

The two special characters used for relative directory references are:

- The single dot (.) to represent the current directory.

- The double dot (..) to represent the parent directory.

The dobule dot character is extremely handy when trying to traverse a directory hierarchy. For example if you are in the *Documents* directory under you home directory and need to go to your *Downloads* directory, also under your home directory, you can do this:

```bash
paradox@paradox:~/Documents$ pwd
/home/paradox/Documents
paradox@paradox:~/Documents$ cd ../Downloads
paradox@paradox:~/Documents$ pwd 
/home/paradox/Download
paradox@paradox:~/Documents$ 
```

The *double dot* character takes you back up one level to your home directory: then the */Downloads* portion of the command takes you back down into the *Downloads* directory. You can use as many double dot character as necessary to move around. For example, if you are in your home directory (*/home/paradox*) and want to go to the */etc* directory, then:

```bash
paradox@paradox:~$ cd ../../etc
paradox@paradox:/etc$ pwd
/etc
paradox@paradox:/etc$
```