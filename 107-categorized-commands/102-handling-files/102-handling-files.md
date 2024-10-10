# File handling

##### File handling in the Linux filesystem.

----------


[<<< File handling commands](101-commands.md) | [Handling directories >>>](103-handling-directories.md)


### Table of contents

- [Introduction](#introduction)
- [Creating files](#traversing-directories)
- [Display files content](#checking-you-current-location)
- [Moving files](#listing-files-and-directories)
- [Copying files](https://)
- [Removing files](https://)

----------


### Introduction 

Here, we are going to look at how we can handle files in the Linux system. Using commands we previous learned in [previous page](101-commands.md), we are going manipulating files. If you have not read the previous page, please have a look at it, we have discuss the basic (important) command their.

### Creating a files

Let's create a file using `touch` command.

```bash
$ touch file1
$ ls
file1
$ 
```

Next, we are going to create multiple files at once. Let's create "file2", "file3".

```bash
$ touch file2 file3
$ ls -l
total 0
-rw-rw-r-- 1 paradox paradox 0 Oct  7 06:49 file1
-rw-rw-r-- 1 paradox paradox 0 Oct  7 06:51 file2
-rw-rw-r-- 1 paradox paradox 0 Oct  7 06:51 file3
$ 
```

### Display file content

##### cat

To display the content of file in the terminal, we use "cat" command. Let's display the content of `.bashrc` file in the terminal.

```
$ cat ~/.bashrc
....
....
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

```

The content of *.bashrc*  is large so, we have ommited the content and displayed the last few lines of the file. It's not the preferred way to display content of the large file with thousands of line, becuase, it will populate the terminal by writing all the content on terminal.

The preferred is to use *editor* or *less* command:


##### less

"less" command create a page, for file content and render it terminal. By using this command, once you quit the "less" command, you can continue form the previous command.

```
$ less bashrc
```

Content is rendered in a page, you can also search the page. To exit the page press *q*, and you will be able to continue below the last command you run.