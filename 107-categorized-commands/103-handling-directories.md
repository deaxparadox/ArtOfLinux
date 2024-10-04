# Handling Directories

----------

### Table of contents

- Create a directory
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

### Create a hidden directory

We know that in the linux file system, 