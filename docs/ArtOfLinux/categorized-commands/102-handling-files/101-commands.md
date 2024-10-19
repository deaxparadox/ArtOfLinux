# Handling files and directories


----------


[<<< Navigating filesystem](../101-navigating-file-system.md) | [File handling >>>](102-handling-files.md)


### Table of content

- [Introduction](#introduction)
- [Commands](#commands)
    - [mv](#mv-command)
    - [cp](#cp-command)
    - [rm](#rm-command)
    - [cat](#cat-command)
    - [less](#less-command)
    - [mkdir](#mkdir-command)
    - [rmdir](#rmdir-command)
    
----------


### Introduction

To store data in the system, we need to have to way, to can manipulating the files in the system. We are going to look that the basic file handling operations such as *creating files*, *removing files*, *copying files*, etc. Most of the command used for handling files and directories are same. But, we can use different *options* and *parameters*, to use the command against file or directories.

### Commands


##### `mv` command

This command is used to moving the  file in the Linux system. Syntax for "mv" command:

```
$ mv <source 1> <source 2> ... <source n> <destination>
```

where *source 1*, *source 2*, ... *source n*, are files (or directories) you want to move to *destination* .

##### `cp` command

Used to **copy** files in the Linux filesystem. Syntax for "cp" command:

```
$ cp <source 1> <source 2> ... <source n> <destination>
```

where *source 1*, *source 2*, ... *source n*, are files (or directories) you want to copy to *destination* .



##### `rm` command

Used to remove files in the Linux filesystem. Syntax for "rm" command:

```
$ rm <file 1> <file 2> ... <file n>
```

After "rm", we can specify any number of files, we want to remove. And "rm" command will remove all the files at once.


##### `touch` command

Used to create file in the Linux filesystem. Syntax for "touch" command:

```
$ touch <file 1> <file 2> ... <file n>
```

After "touch", we can specify any number of files, we want to create. And "touch" command will create all the files at once.



##### `cat` command

Used to print the content of a file in the Linux terminal. Syntax for "cat" command:


```
$ cat <filename>
```

To display the file content, we need to give "cat" a filename.


##### `less` command

Used to print the content of a file, in a page supporting, scrolling and search in the Linux terminal. Syntax for "less" is similar to "cat".

```
$ less <filename>
```

##### `mkdir` command

Used to create directory in the Linux filesystem. Using "mkdir" we can create a directory (or multiple directories). Syntax for `mkdir` command:

```
$ mkdir <dir 1> <dir 2> <dir 3> ... <dir n>
```

##### `rmdir` command

Used to remove **empty** directory in the Linux filesystem. Syntax for "rmdir" is:


```
$ rmdir <dir 1> <dir 2> <dir 3> ... <dir n>
```

##### `rm -rf` command

The **rm -f** is the sub-command of **rm** command, it is used for removing directory with content.



[<<< Navigating filesystem](../101-navigating-file-system.md) | [File handling >>>](102-handling-files.md)