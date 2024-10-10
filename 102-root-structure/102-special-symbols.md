# Special Symbols

---------

[<<< Root filesystem](root-filesystem.md)

---------


### Table of content

- [Root directory](#root-directory--root-directory)
- [Home directory](#home-directory--tidle)
- [User identifier](#user-identifier-cli-user-identifier)
- [Period](#period)
- [Ampersand](#ampersand-)

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

- **$**: represents the regular user.

```bash
paradox@paradox:~$ 
```

- **#**: represents the root user.


```bash
paradox@paradox:~# 
```

### Period


#####  **.**
- The single dot (.) represent the current directory
- If used, as the first character in filename, while creating a file. Then, that file will be known as hidden file (same applicable to directory).

#####

-  **..**: The double dot (..) represent the parent directory

### Dollar ($)

##### Terminal shell prompt

If you open a terminal session, as a normal user (with out using sudo or any administrative priviledges), then prompt in the terminal with contains $.

```bash
paradox@paradox:~$ 
```

##### User variable

Dollar is also used while called the shell variable.

```bash
paradox@paradox:~$ echo $PATH
/home/paradox/.nvm/versions/node/v20.17.0/bin:/home/paradox/.pyenv/shims:/home/paradox/.pyenv/bin:/home/paradox/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin

```


### Ampersand (&)

- &: is use for starting a process in the background.