# History

A convenient feature of the bash shell is the bash history. Bash is configured to keep the last 1,000 commands you have used (and if the shell is never closed, the exact number can grow even much beyond that). When a shell session is closed, the history of that session is updated to the history file. The name of this file is **.bash_history**, and its is created in the home directory of the user who started a specific shell session. Notice that the history file is closed only when the shell session is closed; untill that moment, all commands in the history are kept in memory.

The history feature makes it easy to repeat complex commands. There are several ways of working with history:

- Type **history** to show a list of all commands in the bash history.
- Use **Ctrl+R** to open the prompt from which you can do backward searches in commands that you have previously used. Just type a part of the command you are looking for, and it will be displayed automatically. Use **Ctrl+R** to search futher backward based on the same search criteria.
- Type **!number** to execute a command with a specific number from history.
- Type **!sometext** to execute the last command that start with sometext. Notice that this a potentially dangerous command because the command that was found in executed immediately.


### Working with History

1. Make sure that you have opened a shell as user user.
2. Type **history** to get an overview of commands that you have previously used.
3. Type some commands, such as the following:
    ls
    pwd
    cat /etc/hosts
    ls -l
4. Open a second terminal on your server by right-clicking the graphical desktop and selecting the **Open in Terminal** menu option.
5. Type **history** from this second terminal window. Notice that you do not see the commands that just typed in the other terminal. That is because the history file has not been updated yet.
6. From the first terminal session, type **Ctrl+R**. From the prompt that opens now, type **ls**. You'll see the last **ls** command you used. Press **Ctrl+R** again. You'll now see that you are looking backward and that the previous **ssh** command is highlighted. Press **Enter** to execute it.
7. Type **history | grep cat**. The **grep** command searches the history output for any commands that contained the text *cat*. Remember the command number of one of the **cat** commands you have previously used.
8. Type **!nn**, where *nn* is replaced by the number you remembered in Step 7. You'll see that the last **cat** command is repeated.
9. Close this terminal by typing **exit**.
10. From the remaining terminal window, type **history -c**. This wipes all history that is currently is memory. Close this terminal session as well.
11. Open a new terminal session and type **history**. It may be a bit unexpected, but you'll see a list of commands anyway. That is because **history -c** clears the in-memory history, but it does not eremove the .base_history files in your home directory.
12. As an alternative to deleting the history files, you can also use **history -w** after using **history -c**.