# Handling Directories

----------

### Table of contents

- [Creating a directory](#creating-a-directory)
- [Creating mulitple directories](#creating-multiple-directories)
- [Creating hidden directory](#create-a-hidden-directory)
- [Moving directory](#moving-directory)
- [Renaming directory](#renaming-directory)
- [Removing empty directory](#removing-a-empty-directory)
- [Removing directory with content](#removing-directory-with-content)
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


### Creating multiple directories

We can use the same syntax for creating mulitple directories togther. We have to supply the space separated names in place of personal. We are going to create directory *a*, *b*, and *c*.

```bash
paradox@paradox:~$ mkdir a b c
paradox@paradox:~$ ls -l
total 16
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 a
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 b
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 c
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:39 personal
paradox@paradox:~$ 
```

When we used the mkdir command, it didn't given any message of creating a directory. For getting a message on terminal, we have to use `-v` argument, it stand for *verbose*. Lets creating another directory inside personal named *myfiles*, using '-v' argument.

```bash
paradox@paradox:~$ mkdir personal/myfiles -v
mkdir: created directory 'personal/myfiles'
paradox@paradox:~$ 
```

As you want see, we getting message for creation of directories.


**We can also create directories at a path (location) which does not exists**. For example, I want to create a directory *summertrip* in *photos*, where photos is inside *~/personal/myfiles*. Since, photos doesnot exists, is there a way to do it at once. 

We can use the `-p` argument of mkdir command for creating directory at a location which doesnot exists.

```bash
paradox@paradox:~$ mkdir personal/myfiles/photos/summertrip -p -v
mkdir: created directory 'personal/myfiles/photos'
mkdir: created directory 'personal/myfiles/photos/summertrip'
paradox@paradox:~$ 
```

Here, we have also used verbose argument of getting display of work. Since directory photo doesnot exists, so mkdir command first created directory "photo" and then it created directory "summertrip".

### Create a hidden directory

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

If you can move a directory from one location to another location in the Linux filesystem. You can use `mv` command. To use the *mv* command you have to provide the *source* (the directory you want to move), and *destination*. Let's move directory 'a' and 'b' to the ".hidden" directory.

```bash
paradox@paradox:~$ mv a .hidden/ -v
renamed 'a' -> '.hidden/a'
paradox@paradox:~$ mv b .hidden/ -v
renamed 'b' -> '.hidden/b'
paradox@paradox:~$ ls .hidden/
a  b
paradox@paradox:~$ 
```

To move both "a" and "b" directory at once, we can have to provide [multiple sources](101-commands.md#mv-command):

```bash
$ mv a b .hidden -v
```

### Renaming directory

We now know how to use the mv command, while using mv command, we used the verbose argument -v, which give the operation message. In the message you will see, the mv command always "rename" the file from old location to new location. Similar, to rename a file we just have to provide a different name in place of destination. Let's change the directory "c" name to "c_visible"

```bash
paradox@paradox:~$ mv c c_visible
paradox@paradox:~$ ls
c_visible  files  personal
paradox@paradox:~$ 
```

As you can directory c is change to c_visible.

### Removing a (empty) directory

We can removing a empty directory using the **rmdir** command. Let's remove a directory *summertrip* we created earliear. Currently, the following is three structure of our environment.

```bash
paradox@paradox:~$ tree
...
└── personal
    └── myfiles
        └── photos
            └── summertrip
...
paradox@paradox:~$ 
```

Let's remove the directory *summertrip*:

```bash
paradox@paradox:~$ rmdir personal/myfiles/photos/summertrip/ -v
rmdir: removing directory, 'personal/myfiles/photos/summertrip/'
paradox@paradox:~$ 
```

We got the removing message from rmdir command with no error, which mean our command was successfull. We can again our directory structure to very it.

```bash
paradox@paradox:~$ tree
...
└── personal
    └── myfiles
        └── photos

...
paradox@paradox:~$ 
```

### Removing directory with content

To remove the directory which content (sub-directories, files, etc.). We have to use **rm -rf** command, as we have [discussed here](101-commands.md#rm--rf-command). Directory "myfiles" have a sub-directory "photos" in it. If we try to remove "myfiles" with rmdir command.

```bash
paradox@paradox-CX62-7QL:~/Documents/others$ rmdir personal/myfiles/
rmdir: failed to remove 'personal/myfiles/': Directory not empty
paradox@paradox-CX62-7QL:~/Documents/others$ 
```

We are getting error here, since directory is not empty. Now, lets use *rm -rf* command to removing *myfiles*.

```bash
paradox@paradox-CX62-7QL:~/Documents/others$ rm -rf personal/myfiles/
paradox@paradox-CX62-7QL:~/Documents/others$ tree
...
└── personal

...
paradox@paradox-CX62-7QL:~/Documents/others$ 
```

The *rm -rf* removed the directory *myfiles* with it content. Here, we have used two argument with *rm* command, *-r* which remove directories and their content recursively and *-f* argument which force the rm command to run without fail even if files doesnot exists. 