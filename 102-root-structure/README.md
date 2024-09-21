# Root Filesystem

### Table of contents

- [Introduction](#introduction)
- [Root Drive](#root-drive)
- [Root filesystem Hierarchy](#root-filesystem-hierarchy)


### Introduction

Linux uses a forward slash (/) to denote the directories in the file paths. Table a look at the following path:

```
/home/Rich/Documents/test.doc
```

This indicates the file test.doc is in the directory *Documents*, under the directory *rich* which is contained in the directory *home*.


### Root drive

The first hardrive installed in a Linux system is called the *root drive*. The root drive contains the virtual directory core. Everything else builds fron there.

On the root drive, Linux can use speical directories as *mount points*. Mount points are directories in the virtual directory where you can assign additional storage devices. Linux causes files and directories to appear within these mount point directories, even though they are physically stored on a different drive.

### Root filesystem Hierarchy 

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