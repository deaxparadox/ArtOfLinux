# Link files

### Table of content

- [Introduction](#introduction)
- [Symbolic link](#symbolic-link)
- [Hard link](#hard-link)

##### Prerequisite

<!-- This block should be in warning container, with small text -->

- [Inode in linux filesystem](/docs/ArtOfLinux/linux-filesystem/inodes.md)


### Introduction

Linking files is a great option available in the linux filesystem. If you need to maintain two (or more) copies of the same file on the system, instead of having separate physical copies, you can use one physical copy and mulitple virtual copies, called *links*. 

----------

In the windows system, we must have used *shortcuts*, which are used in the Desktop to reference files from different locations.

----------


Similarly, a link is a placeholder in a directory that points to the real location of the file. Two types of file links are available in the Linux:

1. [Symbolic link](#symbolic-link)
2. [Hard link](#hard-link)


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

In other words, when we're creating a hard link, we're creating another file (with a different name) that points to the exact same data as the original file. That means it acts as the original file, and you cannot differentiate between the new hard link and original name of the file. 

It's basically a mirror copy of the original file. They both have the same content, permissions, and inode address. Be aware that any changes made in one file affect the other file in same way, except for deletion, which will not impact the original data. When you delete the original file, and there's at least one hard link alive, you can still access the original data untill all hardlinks have been deleted.

##### Usage

To create  a hard link, again the original file must pre-exist, except that this time no parameter is needed on the *ln* command. We have a file *install-docker.sh* and we are going to create a hard link *install-docker-hl.sh* to our original file.

```bash
paradox@paradox:~$ ln install-docker.sh install-docker-hl.sh 
paradox@paradox:~$ 

```

We have learn about hard link earlier, that it is similar to original files. If we check the *inode number* of both files, it would be same:

```bash
paradox@paradox:~$ ls -il
9438203 -rw-rw-r--  2 paradox paradox      586 Aug  7 11:14 install-docker-hl.sh
9438203 -rw-rw-r--  2 paradox paradox      586 Aug  7 11:14 install-docker.sh
paradox@paradox:~$ 
```

As you can see *inode* number of both files are same and there is no referencing pointer (`->`), which was present in soft link, pointing to original file location.


Now, let's edit out hard link. We're going to add a comment in it. After that we are going to check our original file for changes. Firstly, we are going to check content of the original file **install-docker.sh** :

```bash
paradox@paradox:~$ cat install-docker.sh 
# Add Docker's official GPG key:
sudo apt-get update
    ...
sudo apt-get update
paradox@paradox:~$ 
```

You can also display content of hard link (we didn't display here because both file and link share same cotent, you can try to display yourself).

Adding comment "docker repository added successfully" at the end of hard link 

**install-docker-hl.sh**:

```bash
paradox@paradox:~$ echo "# docker repository added successfully" >> install-docker-hl.sh 
paradox@paradox:~$ cat install-docker-hl.sh 
# Add Docker's official GPG key:
sudo apt-get update
    ...
sudo apt-get update
# docker repository added successfully
paradox@paradox:~$ 

```

Now, let's see the original content:

```bash
paradox@paradox:~$ cat install-docker.sh 
# Add Docker's official GPG key:
sudo apt-get update
    ...
sudo apt-get update
# docker repository added successfully
paradox@paradox:~$ 

```

As we can see the content in both the files is same, because they share the same inode number.



##### Limitations

Hard links have limitations, You cannot create hard links for directories or create a hard link in a different filesystem from the original file.


----------

##### Command used

[ln](https://)  [ls](https://)  [echo](https://)  [cat](https://)  [redirection (>>)](https://)

##### Reference

- [Linux command line and shell scripting: bible 1](https://)
- [https://www.redhat.com/en/blog/hard-links-linux](https://www.redhat.com/en/blog/hard-links-linux)