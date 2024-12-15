# I/O Redirection

By default when a command is executed it shows it results on the screen of the computer your are working on. The computer monitor is the so-called standard output, which is also referred to as the STDOUT. The shell also has default destinations to send error message to and to accept input.


###### Table 2.1 Standard Input, Output, and Error Overview
| Name | Default Destination | Use in Redirection | File Descriptor Number |
|-----|-----|-----|-----|
| STDIN | Computer keyboard | < (same as 0<) | 0 |
| STDOUT | Computer monitor | > (same as 1>) | 1 |
| STDERR | Computer monitor | 2> | 2 |

- So if you run a command, the command would expect input form the keyboard and it would normallly send its output to the monitor of your computer without making a difference between normal output and errors.
- Some commands, however are started at the background and not from a current terminal sessions, so these commands do not have a monitor or console session to send their output to, and they do not listen to keyboard input to accepts their standard output. That is where redirection comes in handy.

Programs started from the command line have not idea what they are reading from or writting to. They just read from channel (file descriptor) 0 if they want to read from standard input, and they write to file descriptor 1 to display output and to the file descriptor 2 if they have error messages to the output. By default, these are connected to the keyboard and the screen. If you use redirection symbols such as <, >, and |, the shell connects the file descriptors to files and others commands.

###### 2.3 Common Bash Redirectors
| Redirector | Explanation |
|-----|-----|
| > (same as 1>) | Redirects STDOUT. If redirection is to a file,  the current contents of that file are overritten. |
| >> (same as 1>>) | Redirects STDOUT. If output is written to a file, the output is appended to that file. |
| 2> | Redirects STDERR. |
| 2>&1 | Redirects STDERR to the same destination as STDOUT. |
| < (same as 0<) | Redirects STDIN |


In I/O redirection, files can be used to replace the default STDIN, STDOUT, and STDERR. You can also redirect to device files. A device file on Linux is a file that is used to access specific hardware. Your hard disk for instance can be referred to as /dev/sda, the console of your server is known as /dev/console or /dev/tty1, and if you to discard a command outputs, you can redirect to /dev/null. **Notice that ot access most device files you need to be root.**

### Using Pipes

Where an I/O redirector is used to use alternatives for keyboard and computer monitor, a pipe can be used to catch the output of the command use hat as input for a second command. If a user runs the command **ls**, for instance, the output of the command is shown onscreen. If the user uses **ls | less**, the commands **ls** and **less** are started in parallel. The standard output of the **ls** command is connect to the standard input of **less**.  Everything that **ls** writes to the standard output will become available for read from standard input in **less**. The result is that the output of **ls** is shown in pager, where the user can browse up and down through the results easily

As a Linux administrator, using pipes makes Linux a flexible operating system; by combining multiple commands using pipes, you can create kind of super commands that make almost anything possible.

### Usage 

1. ```paradox@paradox:~$ cd```: This ensures that the home directory of this user in the current working directory while working. Type **pwd** to verify this.
2. ```paradox@paradox:~$ ls```: Result will be displayed onscreen.
3. ```paradox@paradox:~$ ls > /dev/null```: This redirects the STDOUT to the null device, with the result that you will not see it.
4. ```paradox@paradox:~$ ls ilwehgi > /dev/null```: This commands shows a "no such file and directory" message on screen. You see the message become it is not STDOUT, but an error message that is written to STDERR.
5. ```paradox@paradox:~$ ls ilwehgi 2> /dev/null```: Now the error will not be displayed on screen anymore.
6. ```paradox@paradox:~$ ls ilwehgi Document 2> /dev/null```: This shows the name of the Documents folder in your home director while hiding the error message.
7. ```paradox@paradox:~$ ls ilwehgi Document 2> /dev/null > output```: this command write the error message to /dev/null while sending STDOUT to a file with the name output that will be created in your current directory.
8. ```paradox@paradox:~$ cat output``` : Shows the contents of this file.
9. ```paradox@paradox:~$ echo hello > output``` : This overwrites the contents of the output file.
10. ```paradox@paradox:~$ ls >> output``` : This appends the results of the **ls** command to the output file.
11. ```paradox@paradox:~$ ls -R /``` : This shows a long list of files and folders scrolling over your computer monitor.
12. ```paradox@paradox:~$ ls -R | less``` : This shows the same result, but in the pager **less**, where you can scroll up and down using the arrow keys on your keyboard.
13. Type **q** to close **less**. This will also end the **ls** program.
14. ```paradox@paradox:~$ ls > /dev/tty1``` : Thsi gives an error message because you are executing the command as ordinary user (unless you were logged in to tty1). Only the user root has permission to write to device files directly.