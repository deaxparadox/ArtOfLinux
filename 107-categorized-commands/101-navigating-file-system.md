
# Navigating the Filesystem

#####  Navigate and explore the filesystem using various Linux command.

----------

##### Table of contents


- [What is navigation commands?](#what-is-navigation-commands)
- [Traversing directory](#traversing-directories)
- [Checking you current location](#checking-you-current-location)
- [Listing files and directories](#listing-files-and-directories)


[<<< Command usage](README.md) | [Handling files >>>](102-handling-files.md)


----------

### What is navigation commands?

Navigation commands used to explore the areas in the Linux system. When you into the system and reach the shell command prompt you are usually placed in your home directory. Therefore, you can use navigation commands to explore the filesystem.


### Traversing directories

You use the **change directory** (**cd**) command to move your shell session to another directory in the Linux filesystem.

Syntax:

```bash
paradox@paradox:~$ cd /usr/bin
```

This will change you location to /usr/bin directory.



### Checking you current location

You can check your location in the linux filesystem using **pwd** command called *Present working directory*. The pwd command displays the shell session's current directory location.


```bash
paradox@paradox:/usr/bin$ pwd
/usr/bin
paradox@paradox:/usr/bin$
```



### Listing files and directories

For listing files and directories in the filesystem in the filesystem, you can with either of two commands:

- **li**: List directory contents.
- **dir**: List directory contents.

List see basic usage of all the both the commands.

##### ls

Open a new terminal and run *ls* command, it will show the content in the home directory:

```bash
paradox@paradox:~$ ls
DD         Downloads            Music       Postman  Templates
Desktop    install-docker.sh    myfile.rar  Public   Videos
Documents  javasharedresources  Pictures    snap
```

The *ls* command just give the basic list of the files and directory. For getting the *long listing* (or detailed view) for contents, you can use `-l` argument with it. Lets again run the *ls* command with with `-l` parameter:

```bash
paradox@paradox:~$ ls -l
lrwxrwxrwx  1 paradox paradox     3 Aug 12 20:08 DD -> /dd
drwxrwxrwx  2 root    root     4096 Aug  7 11:34 Desktop
drwxrwxrwx 13 root    root     4096 Sep 18 08:57 Documents
drwxrwxrwx 14 root    root    12288 Sep 30 06:41 Downloads
-rw-rw-r--  1 paradox paradox   586 Aug  7 11:14 install-docker.sh
drwxrwxr-x  2 paradox paradox  4096 Aug  8 23:20 javasharedresources
drwxrwxrwx  2 root    root     4096 Sep 11 01:51 Music
-rw-rw-r--  1 paradox paradox   439 Aug 27 15:35 myfile.rar
drwxrwxrwx  3 root    root     4096 Sep 22 17:16 Pictures
drwxrwxr-x  3 paradox paradox  4096 Aug 23 03:58 Postman
drwxr-xr-x  2 paradox paradox  4096 Aug  7 11:07 Public
drwx------  4 paradox paradox  4096 Aug  7 11:08 snap
drwxr-xr-x  2 paradox paradox  4096 Aug  7 11:07 Templates
drwxrwxrwx  2 root    root     4096 Aug  7 11:31 Videos
paradox@paradox:~$ 
```

The *long listing* format gives details such as *permission* , *user*,  *group*, etc. 

For the detail usage of *ls* command visited [ls usage](/101-command/101-ls.md)

##### dir

The next command which we can use for listing content is *dir*. 

```bash
paradox@paradox:~$ dir
DD	   Downloads		Music	    Postman  Templates
Desktop    install-docker.sh	myfile.rar  Public   Videos
Documents  javasharedresources	Pictures    snap
```

It work similar to *ls* commands, and it support almost all the parameter avialable in *ls* command.