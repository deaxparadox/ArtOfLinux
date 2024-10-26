# Inodes and the Linux filesystem.

### Introduction

Inodes are data structures that describe a filesystem object, such as a file or directory. and store all the metadata pretaining to the file and directory (such as time stamps, block maps, and extended attributes). Each inode has its own address in the system. When you manipulate hard and soft links, you also deal with the inodes of the original files and directories.

### What is an inode?

By definition, an inode is an index node. It serves as an unique  identifier for a specific piece of metadata on a given filesystem. Each piece of metadata describes what we think of as a file. That's right, inodes operate on each filesystem, independent of the others.

Each filesystem, mounted to your computer has its own inodes. An inode number may be used more than once but never by the same filesystem. The filesystem id combines with the inode number to create a unique identification label.

### How many inodes are there?

There are man inodes on every system, and there are couple of numbers to be aware of. First up, and less important, the theoritical maximum number of inodes is equal to 2^32 (approximately 4.3 billion inodes). Second, and far more important, is the number of inodes on your system. Generally, the ratio of inodes is 1:16KB of system capacity. Obviously, every system is different, so you need to do that math for yourself.

### Advanced usage

To check the number of inodes on your system, you can use the `-i` otpion with the `df` command, as seen here:

```bash
paradox@paradox:~$ df -i /dev/sdc
Filesystem      Inodes IUsed   IFree IUse% Mounted on
udev           1510410   598 1509812    1% /dev
```

You can see from the command syntax and the output above that we ran `df -i` on filesystem `/dev/sda1`. There are a total of 1,510,410 inodes on this filesystem, with only 598 of them being used (about 0.039%).


### File-level inode

We can also look at the inode number of specific file. To do this, we use the `ls -i` command on the desired file. For example:

```bash
paradox@paradox:~$ ls -i README.md 
1608209 README.md
paradox@paradox:~$ 
```

The inode number of this file is **1608209**.


Another command, which we can use to file the inode number of the files is `stat` command:

```bash
paradox@paradox:~$ stat README.md 
  File: README.md
  Size: 678             Blocks: 8          IO Block: 4096   regular file
Device: 822h/2082d      Inode: 1608209     Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/ paradox)   Gid: ( 1000/ paradox)
Access: 2024-10-27 02:18:10.102114671 +0530
Modify: 2024-10-27 02:18:10.061114331 +0530
Change: 2024-10-27 02:18:10.061114331 +0530
 Birth: 2024-09-18 09:14:45.681441671 +0530
paradox@paradox:~$ 
```

`stat` command also gives the same inode as `ls -i` command, **1608209**.

### Directory-level inode

Just like with files, we can also see the inode of a directory. To do this, we use the `ls -i` command again with a few additional options. For example:

```bash
paradox@paradox:~$ ls -ild Documents/
1572870 drwxrwxrwx 14 root root 4096 Oct  4 06:04 Documents/
paradox@paradox:~$ 
```

You can see the we used `-i` (inodes) as well as `-l` (long format) and `-d` (directory). These flags present us with a plethora of information about the **Documents** directory including inode number, permissions, ownership, etc.

We can also use `stat` command as we used, to find the inode of a file.


### Commands used

- [ls](/docs/ArtOfLinux/command/101-ls.md)
- [df](/docs/ArtOfLinux/command/fdisk.md)
- [stat](/docs/ArtOfLinux/command/stat.md)

### Reference

- [https://www.redhat.com/en/blog/inodes-linux-filesystem](https://www.redhat.com/en/blog/inodes-linux-filesystem)
- [Linux command line and shell scripting: bible part 1](https://)
- [https://www.redhat.com/en/blog/hard-links-linux](https://www.redhat.com/en/blog/hard-links-linux)