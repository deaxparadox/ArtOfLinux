# Command: compgen

Display possible completions depending on the options.

Generate possible completion matches for word according to the options, which may be any option accepted by the complete builtin with the exception of -p and -r, and write the matches to the standard output.


- `compgen -a` will list all the aliases you could run.
- `compgen -b` will list all the bulit-ins you could run.
- `compgen -c` will list all the commands you run.
- `compgen -d` means names of all directores.
- `compgen -e` means names of exported shell variables.
- `compgen -f` means names of files.
- `compgen -g` means names of groups.
- `compgen -j` means names of all jobs.
- `compgen -k` means names of shell reserved words.
- `compgen -s` means names of services.
- `compgen -u` means names of user names.
- `compgen -v` means names of shell variables.
- `compgen -A function` will list all the function you could run.
- `compgen -A function -abck` will list all the above in one go. 