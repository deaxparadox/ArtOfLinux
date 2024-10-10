# Handling Directories

----------

### Table of contents

- [Creating a directory](#creating-a-directory)
    - [Creating mulitple directories](#creating-multiple-directories)
    - [Creating hidden directory](#create-a-hidden-directory)
- Remove a directory
- Move a directory
- Copy a directory

----------


### Creating a directory

For the creating a directory in the Linux filesystem, we use the `mkdir` (make directory) command. Lets create a directory named *personal*.

```bash
paradox@paradox:~$ mkdir personal
paradox@paradox:~$ ls
personal
paradox@paradox:~$ 
```

We have created a personal directory, using mkdir command.


##### Creating multiple directories

We can use the same syntax for creating mulitple directories togther. We have to supply the space separated names in place of personal. We are going to create directory *a*, *b*, and *c*.

```bash
paradox@paradox-CX62-7QL:~/Documents/others$ mkdir a b c
paradox@paradox-CX62-7QL:~/Documents/others$ ls -l
total 16
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 a
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 b
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 c
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:39 personal
paradox@paradox-CX62-7QL:~/Documents/others$ 
```

When we used the mkdir command, it didn't given any message of creating a directory. For getting a message on terminal, we have to use `-v` argument, it stand for *verbose*. Lets creating another directory inside personal named *myfiles*, using '-v' argument.

```bash
paradox@paradox:~$ mkdir personal/myfiles -v
mkdir: created directory 'personal/myfiles'
paradox@paradox:~$ 
```

As you want see, we getting message for creation of directories.


**We can also create directories who at a path (location) which does not exists**. For example, I want to create a directory *summertrip* in *photos*, where photos is inside *~/personal/myfiles*. Since, photos doesnot exists, is there a way to do it at once. 

We can use the `-p` argument of mkdir command for creating directory at a location which doesnot exists.

```bash
paradox@paradox:~$ mkdir personal/myfiles/photos/summertrip -p -v
mkdir: created directory 'personal/myfiles/photos'
mkdir: created directory 'personal/myfiles/photos/summertrip'
paradox@paradox:~$ 
```

Here, we have also used verbose argument of getting display of work. Since directory photo doesnot exists, so mkdir command first created directory "photo" and then it created directory "summertrip".

##### Create a hidden directory

Let's create a hidden directory:

```bash
paradox@paradox:~$ mkdir .hidden -v
mkdir: created directory '.hidden'
paradox@paradox:~$ 
```

We have created a hidden directory named *.hidden*, and to view the hidden diretory you have  to run *ls* command with *-a* argument.

```bash
paradox@paradox:$ ls -al
total 28
drwxrwxr-x  7 paradox paradox 4096 Oct  7 05:17 .
drwxrwxrwx 14 root    root    4096 Oct  4 06:04 ..
drwxrwxr-x  2 paradox paradox 4096 Oct  5 00:41 a
drwxrwxr-x  2 paradox paradox 4096 Oct  5 00:41 b
drwxrwxr-x  2 paradox paradox 4096 Oct  5 00:41 c
drwxrwxr-x  2 paradox paradox 4096 Oct  7 05:17 .hidden
drwxrwxr-x  3 paradox paradox 4096 Oct  5 00:46 personal
paradox@paradox:~$ 
```


### Moving directory

If you can move a directory from one location to another location in the Linux filesystem. You can use `mv` command. To use the *mv* command you have to provide the *source* (the directory you want to move), and *destination*

```bash
paradox@paradox:~$ mv a .hidden/ -v
renamed 'a' -> '.hidden/a'
paradox@paradox:~$ mv b .hidden/ -v
renamed 'b' -> '.hidden/b'
paradox@paradox:~$ ls .hidden/
a  b
paradox@paradox:~$ 
```

We have moved the directories to new location.

Let's move directory 'a' and 'b' to the ".hidden" directory.

```bash
```
