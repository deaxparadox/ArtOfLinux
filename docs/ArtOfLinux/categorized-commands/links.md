# Link files

### Table of content

- [Introduction](#introduction)
- [Symbolic link](#symbolic-link)
- [Hard link](#hard-link)

### Introduction

Linking files is a great option available in the linux filesystem. If you need to maintain two (or more) copies of the same file on the system, instead of having separate physical copies, you can use one physical copy and mulitple virtual copies, called *links*. 

----------

In the windows system, we must have used *shortcuts*, which are used in the Desktop to reference files from different locations.

----------


Similarly, a link is a placeholder in a directory that points to the real location of the file. Two types of file links are available in the Linux:

1. [Symbolic link](symbolic-link)
2. A hard link


### Symbolic link

A *symbolic link* is simply a physical file that points to another file somewhere in the virtual directory structure.

To create a symbolic link to a file, the original file must pre-exist: We can then use the *ln* command with the *-s* option to create the symbolic link. We will be creating a symbolic of */home/paradox/Downloads* in our current directory:

```bash
paradox@paradox:~$ ln -s /home/paradox/Downloads/ paradox_downloads
paradox@paradox:~$ ls -l
total 12
drwxrwxr-x 2 paradox paradox 4096 Oct  5 00:41 c_visible
drwxrwxr-x 2 paradox paradox 4096 Oct  7 06:51 files
lrwxrwxrwx 1 paradox paradox   24 Oct 22 07:01 paradox_downloads -> /home/paradox/Downloads/
drwxrwxr-x 2 paradox paradox 4096 Oct 19 07:03 personal
paradox@paradox:~$ 
```

We have success full created a link *paradox_downloads* which points to */home/paradox/Downloads* directory. In above command we have used the full path of user Paradox's Downloads directory to created a link. We could have also used shorthand symbol for home directory expansion in *ln* command, as `ln -s ~/Downloads paradox_download`. If you run this command output would be same. 

While listing files using *ls -l* command, you have seen this line, `lrwxrwxrwx 1 paradox paradox   24 Oct 22 07:01 paradox_downloads -> /home/paradox/Downloads/`, this line shows the new link we have just created. The first thing you can notice is the file type, the file type of link is **l**, after which the permission is displayed, and after the link name there is arrow `->` is pointing to the original directory locations. 

The source file and symbol are physically different file files on the system. We can check the inode number of the both files.

```bash
paradox@paradox:~$ ls -lid paradox_downloads ~/Downloads
1572871 drwxrwxrwx 15 paradox paradox    12288 Oct 21 00:39 /home/paradox/Downloads
1615521 lrwxrwxrwx  1 paradox paradox       24 Oct 22 07:55 paradox_downloads -> /home/paradox/Downloads/
paradox@paradox:~$ 
```

One thing to remember, while creating the symbolic, you have to provide the full path of the *&lt;source file&gt;*.


### Hard link

A *hard link* creates a separated virtual file that contains information about the original file and where to locate it. However, they are physically the same file. When you reference the hard link file, it's just as if you're referncing the original file.

To create  a hard link, againg the original file must pre-exist, except that this time on parameter is needed on the *ln* command. We have text file *allpdf.txt* and we are going to create a *hard link* *allpdf2*.

```bash
paradox@paradox:~$ ls -l
total 1836
-rw-rw-r-- 2 paradox paradox 931112 Oct 22 07:59 allpdf
-rw-rw-r-- 2 paradox paradox 931112 Oct 22 07:59 allpdf2
paradox@paradox:~$ 
```

We have learn about hard link earlier, that it is similar to original files. If we check the *inode number*  of both files, it would be same:

```bash
paradox@paradox:~$ ls -il allpdf allpdf2
1616799 -rw-rw-r-- 2 paradox paradox 931112 Oct 22 07:59 allpdf
1616799 -rw-rw-r-- 2 paradox paradox 931112 Oct 22 07:59 allpdf2
paradox@paradox:~$ 
```

As you can see *inode* number of both files are same.