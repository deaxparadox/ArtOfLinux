# Special Symbols

---------

[<<< Root filesystem](root-filesystem.md)

---------


### Table of content

- [Root directory](#root-directory--root-directory)
- [Home directory](#home-directory--tidle)
- [User identifier](#user-identifier-cli-user-identifier)
- [Single period]()
- [Double period]()

### Root Directory (/) {root-directory}

*Forward slash* (/) represent the root directory. Root directory is the first mount point in the linux filesystem when the system start, and all the other system directories and files are stored in the root directory

To change to the root directory:

```bash
paradox@paradox:~$ cd /
paradox@paradox:/$ pwd
/
```

### Home Directory (~) {tidle}

When you open a new terminal shell session, you get a prompt where you enter your commands, that prompt contains a tidle (**~**) which represent your home directory:

```sh
paradox@paradox:~$ 
```


### User Identifier {cli-user-identifier}

In the Linux system *user identifier* are used to differentiate between normal and root user. 

Normal users are regular users, who can use the system, but can't make any change to the system. While root user(s), can make change system wide changes.


When you open a teminal session, you see a prompt with **$** or **#**.


#### Dollar ($)

If you open a terminal session, as a normal user (with out using sudo or any administrative priviledges), then prompt in the terminal with contains $.

