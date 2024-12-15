# Executing commands

The purpose of the Linux shell is that it provides an environment in which commands can be executed. The shell takes care of interpreting the command that a user has entered correctly. To do this, the shell makes a difference between three kinds of commands:

- Aliases
- Internal commands
- External commands

##### Aliases

An alias is a command that a user can define as needed. Some aliases are provided by default; type **alias** on the command line to get an overview. 

To define an alias, use **alias newcommand='oldcommand'**, as in the default alias **ll='ls -l --color=auto'**. Alias are executed before anything else.

##### Internal command

An internal command is a command that is a part of the shell itself. It is available when the shell is loaded and can be executed from memory without any lookup from disk.


##### External command

An external command is a command hat exists as an executable file on disk of the computer. Because it has to be read from disk, it is bit slower.



### Command search

When a user executes a command,  the shell first looks to determine whether it is an internal command; if it is not, it looks for an executable file with a name that matches the command on disk. To find whether a command is a bash internal, or an executable file on disk, you can use the **[type](/docs/ArtOfLinux/command-list/type.md)** command.

To look up external commands, the **$PATH** variable is used. This variable defines a list of directories that is searched for a matching filename when a user enters a command. To find out which exact command the hsell wil be using you can use the **which** command. For install **which ls** to find out where the shell will get the **ls** command from.

```bash
paradox@paradox:~$ which ls
/usr/bin/ls
paradox@paradox:~$
```

###### Running command in current directory. 

You should notice that for security reasons that the current directory is not in the **$PATH** variable and that Linux does not look in the current directory to see whether a specific command is available from that directory. That is why you need to start a command that is in the current directory by including **./** in front of it. The dot stands for the current directory, and by running it as **./**, you'll tell bash to look for the command in the current directory.

The **$PATH** variable can be set for specific users, but in general, most users will be using the same PATH variable.

##### Usage

1. Type **time ls**. This executes the **ls** command where the bash internal **time** shows information about the time it took to complete this command.
2. Now type **which time**. This shows the filename /bin/time that was found in the $PATH variable.


### Index

- [type command](https://)
- [which command](https://)
- [$PATH env](https://)
- [./](https://)
- [time command](https://) 
- [ls command](https://)
- [alias](https://)
- [internal command](https://)
- [external command](https://)