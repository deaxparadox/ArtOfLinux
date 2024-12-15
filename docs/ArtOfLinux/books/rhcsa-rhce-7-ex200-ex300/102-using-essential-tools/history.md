# History

A convenient feature of the bash shell is the bash history. Bash is configured to keep the last 1,000 commands you have used (and if the shell is never closed, the exact number can grow even much beyond that). When a shell session is closed, the history of that session is updated to the history file. The name of this file is **.bash_history**, and its is created in the home directory of the user who started a specific shell session. Notice that the history file is closed only when the shell session is closed; untill that moment, all commands in the history are kept in memory.

The history feature makes it easy to repeat complex commands. There are several ways of working with history:

- Type **history** to show a list of all commands in the bash history.
- Use **Ctrl+R** to open the prompt from which you can do backward searches in commands that you have previously used.