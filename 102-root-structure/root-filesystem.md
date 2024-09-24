
# Root Filesystem


---------

[<<< Root Structure](README.md) | [Special Symbols >>>](special-symbols.md)

---------



### Table of contents

- [Looking in Linux filesystem](#looking-in-linux-filesystem)
- [Root Drive](#root-drive)
- [Root filesystem Hierarchy](#root-filesystem-hierarchy)
- [Home Directory (~)](#home-directory--tidle)
- [User Identifier (~)](#user-identifier-cli-user-identifier)


### Looking in Linux filesystem

<!-- Linux does not use drive letters in pathnames as windows 

_______
##### Note:

In windows, the physical drives installed on the computer determine the pathname of the file. Windows assigns a letter to each physial disk drive, and each drive contains it own directory structure for accessing files stored on it.

For example, in Windows you may be used to seeing the file paths such as:

```
c:\Users\Nitish\Documents\test.doc
```
________ -->


Linux stores files within a single directory structure called a *virtual directory*. The virtual directory contains file paths from all the storage devices installed on the computer, merged into a single directory structure.

The Linux virtual directory structure contains a single base directory, called the **root**. Directories and files beneath the root directory are listed based on the directory path used to get to them.


Linux uses a forward slash (**/**) to denote the directories in the file paths. Table a look at the following path:


```
/home/Nitish/Documents/test.doc
```

This indicates the file test.doc is in the directory *Documents*, under the directory *Nitish* which is contained in the directory *home*.




### Root drive

The first hardrive installed in a Linux system is called the *root drive*. The root drive contains the virtual directory core. Everything else builds fron there.

On the root drive, Linux can use speical directories as *mount points*. Mount points are directories in the virtual directory where you can assign additional storage devices. Linux causes files and directories to appear within these mount point directories, even though they are physically stored on a different drive.




### Root filesystem Hierarchy 

The Linux filesystem originall evolved from the Unix file structure. In a Linux filesystem, common directory names are used for common functions.

#### Common Linux Directory Names

| **Directory** | **Usage** | 
|-----|-----|
| / | root of the virtual directory, where normally, no files are placed |
| /bin | binary directory, where many GNU user-level utitties are stored | 
| /boot | boot directory, where boot files are stored |
| /dev | device directory, where Linux creates device nodes |
| /etc | system configuration files directory |
| /home | home directory, where Linux creates user directories |
| /lib | library directory, where system and application librar files are stored |
| /media | media directory, a common place for mount oints used for removable media |
| /mnt | mount directory, another common place for mount points used for removable media |
| /opt | optional directory, often used to stored third party software packages and data files |
| /proc | process directory, where current hardware and process information is stored |
| /root | root home directory |
| /sbin | system binary directory, where many GNU admin-level utilities are stored |
| /run | run directory, where runtime data is held during system operation | 
| /srv | service directory, where local services stored their files |
| /sys | system directory, where system hardware information files are stored |
| /temp | temporary directory, where temporary work files can be created and destroyed |
| /usr | user binary directory, where the bulk of GNU user-level utilities and data files are stored |
| /var | variable directory, for files that change frequently, such as log files |

These directory names are based upon the Filesystem Hierarchy Standard (FHS).


When you login to your system and reach a shell CLI prompt, you session starts in your home directory. Your home directory is a unique directory assigned to you user account.



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