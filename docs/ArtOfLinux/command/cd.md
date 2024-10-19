# cd (change directory)

### Table of content

- [Introduction](#introduction-introduction)
- [Absolute Usage](https://)
- [Relative Usage](https://)
- [Jump to home directory](https://)
- [Jummp to last direcotry]()


### Introduction {introduction}

ch (*change directory*) is used the change you location on the linux filesystem. Using cd command you can jump to any level in the file system. 

To learn more open a new terminal session, and get started.

### Absolute Usage {absolute-usage}

Currently you can in your home directory ([~](/102-root-structure/special-symbols.md#home-directory--tidle)).

```bash
paradox@paradox:~$ pwd
/home/paradox
```

To jump to **/usr/bin** directory, write:

```bash
paradox@paradox:~$ cd /usr/bin
paradox@paradox:/usr/bin$ pwd
/usr/bin
```