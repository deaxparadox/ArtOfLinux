# The Linux Bible — Complete Table of Contents

Every topic. Every concept. Every command. Nothing skipped, nothing compressed.
The [Roadmap](../roadmap/README.md) tells you the order. This tells you everything.

Each entry below is a topic file. The sub-bullets show exactly what is covered inside that file.

---

## phase-1-getting-comfortable/

### [1.1 — What Is Linux?](phase-1-getting-comfortable/1.1-what-is-linux.md)
- Unix history — Bell Labs, Thompson, Ritchie, the birth of Unix (1969)
- The GNU Project — Richard Stallman, the GPL, free software vs open source
- Linux the kernel — Linus Torvalds, the 1991 announcement, kernel vs OS
- Linux distributions — what a distro is, who packages what and why
- Debian family — Debian, Ubuntu, Mint, Kali, Raspberry Pi OS
- Red Hat family — RHEL, Fedora, CentOS, Rocky Linux, AlmaLinux
- Arch family — Arch Linux, Manjaro, EndeavourOS
- SUSE family — openSUSE Leap, Tumbleweed, SLES
- Independent distros — Gentoo, Slackware, NixOS, Alpine, Void
- Linux in the world — servers, Android, embedded, supercomputers, cloud
- Kernel versioning — `uname -r`, stable vs LTS vs mainline
- The Unix philosophy — do one thing well, text streams, composability
- POSIX — what it is, why it matters, what it guarantees across systems

### [1.2 — The Terminal](phase-1-getting-comfortable/1.2-the-terminal.md)
- What is a terminal emulator — xterm, gnome-terminal, kitty, alacritty
- What is a TTY — virtual consoles (`Ctrl+Alt+F1`–`F6`), `tty` command
- What is a shell — the program that reads your input
- Bash — Bourne Again Shell, history, why it's everywhere
- Zsh — features over bash, oh-my-zsh, prezto
- Other shells — `sh` (POSIX), `dash`, `fish`, `ksh`, `tcsh`
- The prompt — `PS1`, `PS2`, customization, color codes
- Shell startup files — `/etc/profile`, `~/.bash_profile`, `~/.bashrc`, `~/.profile`
- Interactive vs non-interactive shells — what loads, what doesn't, and why it matters
- Login vs non-login shells — the difference, when each fires
- Command history — `history`, `!!`, `!$`, `!n`, `Ctrl+R` reverse search
- Tab completion — what completes, how to extend it
- Keyboard shortcuts — `Ctrl+C`, `Ctrl+D`, `Ctrl+Z`, `Ctrl+L`, `Ctrl+A`, `Ctrl+E`, `Ctrl+W`, `Ctrl+U`, `Ctrl+K`
- Terminal multiplexers — `tmux`, `screen`; sessions, windows, panes
- `tmux` in depth — key bindings, `.tmux.conf`, copy mode, sessions across SSH

### [1.3 — Navigating the Filesystem](phase-1-getting-comfortable/1.3-navigating-the-filesystem.md)
- `ls` — listing files; `-l`, `-a`, `-h`, `-R`, `-t`, `-S`, `--color`; output decoded column by column
- `cd` — changing directories; `-` for previous, `~` for home, `pushd`/`popd`
- `pwd` — print working directory; `-P` for physical path (no symlinks)
- `tree` — directory structure visualization; `-L` depth, `-a` hidden, `-d` dirs only
- Absolute vs relative paths — the most common source of beginner confusion
- `find` basics — `-name`, `-type`, `-maxdepth`; enough to be dangerous
- `locate` / `updatedb` — fast filename search using a prebuilt index

### [1.4 — Reading and Writing Files](phase-1-getting-comfortable/1.4-reading-writing-files.md)
- `cat` — concatenate and print; `-n` line numbers, `-A` show non-printing characters
- `less` — paging through files; search with `/`, `n`/`N`, `g`/`G`, `q` to quit
- `more` — older pager; when and why you still see it
- `head` / `tail` — first and last N lines; `tail -f` for live log following
- `nano` — basic terminal editor; keybindings (`Ctrl+O`, `Ctrl+X`), searching
- `vim` fundamentals — modal editing; normal, insert, visual, command modes
- `vim` survival skills — entering insert mode, saving `:w`, quitting `:q`, `:wq`, `:q!`
- `vim` movements — `h/j/k/l`, `w/b/e`, `0/$`, `gg/G`
- `vim` editing — `i/a/o`, `dd`, `yy`, `p`, `u`, `.` repeat
- `vim` configuration — `~/.vimrc`, `set number`, `set expandtab`
- `diff` — comparing files; `-u` unified format
- `cp`, `mv`, `mkdir`, `touch`, `rm` basics — previewed here, deep-dived in Phase 3

### [1.5 — Getting Help](phase-1-getting-comfortable/1.5-getting-help.md)
- `man` — manual pages; navigation, sections (1=user, 2=syscalls, 5=files, 8=admin)
- `man` sections explained — why `man 5 passwd` and `man 1 passwd` are different pages
- `--help` — the quick reference; faster than man for known commands
- `info` — GNU info pages; more structured than man, more verbose
- `apropos` — searching man page descriptions when you don't know the command name
- `whatis` — one-line description of a command
- `type` — what a command actually is: alias, function, builtin, or file
- `which` / `whereis` — finding the executable path
- `tldr` — community-written practical examples; a complement to man, not a replacement

---

## phase-2-filesystem/

### [2.1 — Filesystem Hierarchy Standard (FHS)](phase-2-filesystem/2.1-fhs.md)
- `/` — the root; everything in Linux hangs off one tree
- `/bin`, `/sbin` — essential binaries; now often symlinks to `/usr/bin`, `/usr/sbin`
- `/usr` — the secondary hierarchy; `/usr/bin`, `/usr/lib`, `/usr/share`, `/usr/local`
- `/etc` — system-wide configuration files; no binaries, no data
- `/var` — variable data: logs, spool, mail, lock files, databases
- `/var/log` — system and service logs
- `/run` (was `/var/run`) — runtime data: PID files, sockets; tmpfs, cleared on reboot
- `/tmp` — temporary files; cleared on reboot (on most systems — not guaranteed)
- `/home` — user home directories
- `/root` — root user's home; deliberately not inside `/home`
- `/dev` — device files: block, character, pseudo-devices
- `/proc` — virtual filesystem exposing kernel data structures; generated at runtime
- `/sys` — virtual filesystem for device and driver information (sysfs)
- `/boot` — kernel images, initramfs, GRUB config
- `/lib`, `/lib64` — shared libraries; now often symlinks to `/usr/lib`
- `/mnt` — temporary mount point by convention
- `/media` — auto-mounted removable devices
- `/opt` — optional third-party software
- `/srv` — service data; convention, rarely enforced
- `/lost+found` — recovered files after fsck; one per filesystem

### [2.2 — Everything Is a File](phase-2-filesystem/2.2-everything-is-a-file.md)
- The Unix abstraction — why everything is exposed as a file descriptor
- `/dev/null` — discards all writes; reads return EOF
- `/dev/zero` — reads return infinite null bytes; used to zero-fill or create blank images
- `/dev/urandom` — reads return cryptographic-quality random bytes
- `/dev/tty` — the controlling terminal of the current process
- Block device files — `/dev/sda`, `/dev/nvme0n1`; major/minor numbers
- Character device files — `/dev/null`, `/dev/tty`; byte-by-byte access
- Unix domain sockets — inter-process communication via the filesystem (`/var/run/docker.sock`)
- Named pipes (FIFOs) — `mkfifo`; blocking reads/writes, use cases
- Why this abstraction matters — pipes, redirection, and devices use the same API

### [2.3 — File Types](phase-2-filesystem/2.3-file-types.md)
- The first character in `ls -l` output — `d`, `-`, `l`, `b`, `c`, `s`, `p`
- Regular files — data stored on disk; text, binary, executable
- Directories — not "folders"; a file containing name-to-inode mappings
- Symbolic links — `ln -s`; a pointer to a path, not an inode
- How the kernel resolves symlinks — step by step
- Dangling symlinks — when the target path no longer exists
- Hard links — `ln`; multiple directory entries pointing to the same inode
- What you cannot hard-link — directories and cross-filesystem links
- Block device files — disks, partitions, LVM volumes
- Character device files — serial ports, terminals, pseudo-devices
- Sockets — created by processes; removed when the process exits (usually)
- Named pipes — persist in the filesystem; survive process exit

### [2.4 — Inodes](phase-2-filesystem/2.4-inodes.md)
- What an inode is — the metadata record for a file
- What an inode stores — permissions, owner, group, size, timestamps (atime/mtime/ctime), block pointers
- What an inode does NOT store — the filename (stored in the directory entry)
- Inode numbers — `ls -i`, `stat`, `find -inum`
- How hard links work — multiple directory entries, one inode, one reference count
- When a file is truly deleted — reference count reaches zero and no process has it open
- Running out of inodes — `df -i`; looks identical to disk-full until you check
- The Virtual Filesystem (VFS) — how Linux abstracts ext4, xfs, tmpfs behind one API
- `stat` — reading every metadata field: inode, permissions, link count, timestamps, block count
- `file` — detecting file type from magic bytes, not extension

### [2.5 — Mounting](phase-2-filesystem/2.5-mounting.md)
- What mounting means — attaching a filesystem to a directory in the tree
- `mount` and `umount` — syntax, options, common use cases
- `mount -o` options — `ro`, `rw`, `noexec`, `nosuid`, `nodev`, `relatime`
- `/etc/fstab` — fields: device, mountpoint, fstype, options, dump, pass
- UUIDs in fstab — `blkid` to find UUIDs; why UUIDs instead of `/dev/sda1`
- `systemd` mount units — `.mount` files as an alternative to fstab
- `tmpfs` — RAM-backed filesystem; `/tmp`, `/run`, `/dev/shm`; size limits
- Bind mounts — mounting a directory at another path; how containers use them
- `loop` devices — mounting image files with `losetup`; `mount -o loop`
- `findmnt` — viewing the mount tree in a readable format
- `lsblk` — visualizing block device tree with sizes, types, and mountpoints
- `blkid` — identifying filesystems by UUID, LABEL, TYPE
- Automounting — `autofs`, systemd automount units

---

## phase-3-permissions/

### [3.1 — Creating, Copying, Moving, Deleting](phase-3-permissions/3.1-file-operations.md)
- `mkdir` — creating directories; `-p` for parent chain, `-m` for initial permissions
- `touch` — creating empty files; updating timestamps; `-t` set specific time
- `cp` — copying; `-r` recursive, `-a` archive (preserves permissions/timestamps/symlinks), `-u` update only, `-p` preserve, `--sparse`
- `mv` — moving and renaming; atomic within same filesystem via `rename()` syscall; not atomic across filesystems
- `rm` — removing; `-r` recursive, `-f` force; why it is not recoverable by default
- `rmdir` — removing empty directories only
- `find` in depth — `-name`, `-type`, `-mtime`, `-size`, `-perm`, `-user`, `-newer`, `-empty`, `-maxdepth`, `-prune`, `-exec`, `-delete`
- `xargs` — building argument lists from stdin; `-n`, `-P` parallel, `-I{}` replace string
- `rename` — bulk renaming files with a pattern

### [3.2 — Permissions](phase-3-permissions/3.2-permissions.md)
- Permission bits — read (4), write (2), execute (1); three sets: user, group, other
- Execute on a file vs execute on a directory — running vs traversing (the critical distinction)
- `chmod` symbolic mode — `u+x`, `g-w`, `o=r`, `a+x`, `ug=rw,o=`
- `chmod` octal mode — 755, 644, 700, 600, 777; what each is used for
- `ls -l` output decoded — `rwxr-xr-x` character by character
- `umask` — default permission mask; how new files inherit their permissions
- Why 777 on a web-writable directory is a security disaster
- Why executable scripts need both execute permission and a valid shebang

### [3.3 — Ownership](phase-3-permissions/3.3-ownership.md)
- Users and groups — a file has exactly one owner UID and one group GID
- `chown` — changing owner; `chown user:group`, `chown user`, `chown :group`
- `chgrp` — changing group only
- `-R` recursive ownership change — and why it's dangerous to run on `/`
- Why root can `chown` to anyone; why regular users can only `chown` to themselves
- `newgrp` — switching your active group for the current session
- The role of the primary group — what group a new file gets by default

### [3.4 — Special Permissions](phase-3-permissions/3.4-special-permissions.md)
- The setuid bit — `chmod u+s`; running as the file's owner (e.g., `/usr/bin/passwd`)
- How setuid is exploited when implemented carelessly — why it requires auditing
- The setgid bit on files — running as the file's group
- The setgid bit on directories — new files inherit the directory's group, not the creator's
- The sticky bit — `chmod +t`; only the file's owner can delete it (used on `/tmp`)
- `chmod` octal for special bits — 4755 (setuid+755), 2755 (setgid+755), 1777 (sticky+777)
- Finding setuid/setgid binaries — `find / -perm -4000 -o -perm -2000`

### [3.5 — Access Control Lists (ACL)](phase-3-permissions/3.5-acls.md)
- Why basic permissions fall short — one owner, one group, but you need two groups
- `getfacl` — reading ACL entries on a file
- `setfacl -m` — adding or modifying ACL entries; `u:username:rwx`, `g:groupname:r`
- `setfacl -x` — removing specific ACL entries
- `setfacl -b` — removing all ACL entries
- Default ACLs on directories — `setfacl -d`; automatically inherited by new files
- How ACLs interact with the basic permission bits — the mask entry
- `getfacl` / `setfacl` and `cp`, `rsync` — preserving ACLs across copies
- Extended attributes (`xattr`) — `getfattr`, `setfattr`; `user.`, `security.`, `trusted.` namespaces
- `chattr` / `lsattr` — filesystem-level flags: `+i` immutable, `+a` append-only

---

## phase-4-text-processing/

### [4.1 — The Unix Philosophy](phase-4-text-processing/4.1-unix-philosophy.md)
- Do one thing well — why small, focused tools beat monolithic programs for composability
- Text as the universal interface — why everything outputs text and what that enables
- Pipes as the composition mechanism — the pipeline mental model
- Doug McIlroy's original formulation — the memo that defined the philosophy
- Where the philosophy breaks down — binary formats, GUIs, performance-sensitive paths
- The Unix philosophy vs the "batteries included" approach — trade-offs in practice

### [4.2 — grep and Regular Expressions](phase-4-text-processing/4.2-grep-regex.md)
- `grep` basics — searching patterns in files and streams
- `grep` flags — `-i`, `-v`, `-r`, `-l`, `-n`, `-c`, `-A/-B/-C`, `-o`, `-w`, `-x`, `-q`
- Basic Regular Expressions (BRE) — `.`, `*`, `^`, `$`, `[]`, `\(\)`, `\{n,m\}`
- Extended Regular Expressions (ERE) — `egrep` / `grep -E`; `+`, `?`, `|`, `()`
- Perl-compatible regex — `grep -P`; `\d`, `\w`, `\s`, lookahead, lookbehind
- Character classes — `[[:alpha:]]`, `[[:digit:]]`, `[[:space:]]`, `[[:upper:]]`
- Anchors and word boundaries — `^`, `$`, `\b`, `\B`
- `fgrep` / `grep -F` — fixed string matching; faster for literal strings
- `ripgrep` (`rg`) — the modern replacement; speed, `.gitignore` awareness, colored output

### [4.3 — sed — Stream Editor](phase-4-text-processing/4.3-sed.md)
- How `sed` works — reads line by line, applies script, outputs to stdout
- Substitution — `s/pattern/replacement/flags`; `g` global, `i` case-insensitive, `Nth` occurrence
- Address ranges — line numbers, `$` last line, `/regex/` addresses, `addr1,addr2`
- Deletion — `d`; deleting matching or non-matching lines
- Insertion and appending — `i\text` before, `a\text` after a match
- Change — `c\text`; replacing an entire matching line
- Print — `p` with `-n` for selective output
- In-place editing — `-i`; why always using `-i.bak` is a good habit
- Multiple expressions — `-e`; chaining multiple operations
- Hold space — `h`, `H`, `g`, `G`, `x`; multi-line processing
- Labels and branching — `:label`, `b`, `t`; looping and conditional processing

### [4.4 — awk — Data Extraction and Reporting](phase-4-text-processing/4.4-awk.md)
- How `awk` works — pattern-action pairs; reads records, splits into fields
- Fields — `$1`, `$2`, ..., `$NF`; `FS` field separator, `-F`
- Records — `$0` whole record; `RS` record separator
- Built-in variables — `NR`, `NF`, `FILENAME`, `OFS`, `ORS`
- Patterns — `/regex/`, `NR==5`, `$3 > 100`, `BEGIN`, `END`
- `printf` — formatted output
- Conditionals — `if/else`, ternary `? :`
- Loops — `for`, `while`, `do-while`
- Arrays — associative arrays; `for (k in arr)`; counting and aggregating
- String functions — `length()`, `substr()`, `index()`, `split()`, `gsub()`, `sub()`, `match()`, `sprintf()`, `tolower()`, `toupper()`
- Arithmetic functions — `int()`, `sqrt()`, `rand()`, `srand()`
- Pipes in awk — `print | "cmd"`, `cmd | getline`
- `gawk` extensions — `PROCINFO`, `@include`, `nextfile`

### [4.5 — The Classic Toolkit](phase-4-text-processing/4.5-classic-toolkit.md)
- `sort` — `-n` numeric, `-r` reverse, `-k` key field, `-t` delimiter, `-u` unique, `-f` case-fold, `-h` human-numeric, `-s` stable
- `uniq` — `-c` count, `-d` only duplicates, `-u` only unique; requires sorted input
- `cut` — `-d` delimiter, `-f` fields, `-c` characters
- `paste` — merging files side by side; `-d` delimiter
- `join` — relational join on sorted files; `-1`, `-2` key fields
- `tr` — translating or deleting characters; `-d` delete, `-s` squeeze, `-c` complement
- `column` — formatting output into aligned columns; `-t` table mode, `-s` separator
- `wc` — `-l` lines, `-w` words, `-c` bytes, `-m` characters
- `fold` — wrapping long lines; `-w` width, `-s` word boundary
- `nl` — numbering lines
- `comm` — comparing two sorted files; three-column output
- `xargs` — `-n` max args, `-P` parallel, `-I{}` replace string, `-0` null-delimited
- `seq` — generating sequences; `seq 1 10`, `seq 1 2 10`, `seq -w` zero-padded

### [4.6 — Redirects and Pipes](phase-4-text-processing/4.6-redirects-pipes.md)
- Standard streams — stdin (fd 0), stdout (fd 1), stderr (fd 2)
- Output redirection — `>` overwrite, `>>` append
- Input redirection — `<` from file
- Error redirection — `2>` stderr to file, `2>>` append
- Combined — `&>` both stdout and stderr, `2>&1` redirect stderr to where stdout goes
- Order matters — `cmd > file 2>&1` vs `cmd 2>&1 > file` (they are different)
- Pipes — `|`; stdout of left connects to stdin of right; stderr does not go through pipes
- `tee` — split output to file and stdout; `-a` append
- `/dev/null` — discarding output; `2>/dev/null`, `>/dev/null 2>&1`
- Here documents — `<<EOF ... EOF`; multiline input to a command
- Here strings — `<<< "string"`; sending a string to stdin directly
- Process substitution — `<(cmd)` and `>(cmd)`; using command output as a file argument
- Pipefail — `set -o pipefail`; why a pipeline's exit code is not always the last command's

---

## phase-5-shell-scripting/

### [5.1 — Shell Basics](phase-5-shell-scripting/5.1-shell-basics.md)
- What a shell is — the program that reads input, expands it, and executes commands
- `bash` — Bourne Again Shell; the default on most Linux systems
- `sh` vs `bash` vs `dash` — POSIX sh, extended bash, and why Ubuntu's `/bin/sh` is `dash`
- `zsh` — when and why to choose it over bash
- Shell startup files — which file loads in which shell mode (login/non-login/interactive/non-interactive)
- The PATH variable — how the shell finds executables; `which`, `type`, `hash`
- Builtins vs external commands — `cd`, `echo`, `type` are builtins; `ls`, `cat` are not
- Aliases — `alias`, `unalias`; why they don't work in non-interactive scripts
- Shell options — `shopt` for bash-specific options; `set -o` for POSIX options

### [5.2 — Variables, Quoting, and Expansion](phase-5-shell-scripting/5.2-variables-quoting-expansion.md)
- Variable assignment — no spaces around `=`; `VAR=value`
- Reading variables — `$VAR`, `${VAR}`; when braces are required
- Quoting rules — single quotes (literal), double quotes (expand variables/subshells), no quotes (word splitting + globbing)
- Word splitting — unquoted variables split on `IFS`; the source of most shell bugs
- Parameter expansion — `${VAR:-default}`, `${VAR:=assign}`, `${VAR:+alt}`, `${VAR:?error}`
- String operations — `${#VAR}` length, `${VAR#prefix}`, `${VAR##prefix}`, `${VAR%suffix}`, `${VAR%%suffix}`
- Substitution — `${VAR/old/new}`, `${VAR//old/new}`, `${VAR/old/}` (delete)
- Command substitution — `$(cmd)` and backticks; why `$()` is always preferred
- Arithmetic expansion — `$((expr))`, `$(( x + y ))`, `$(( x ** 2 ))`
- `declare` and attributes — `-i` integer, `-r` readonly, `-x` export, `-a` array, `-A` assoc, `-l` lowercase
- `export` — promoting a shell variable to an environment variable
- Special variables — `$0`, `$1`–`$9`, `${10}`, `$@`, `$*`, `$#`, `$?`, `$$`, `$!`, `$_`

### [5.3 — Control Flow](phase-5-shell-scripting/5.3-control-flow.md)
- `if` / `elif` / `else` / `fi` — structure and exit-code-based evaluation
- `test` / `[` — POSIX test; file tests (`-f`, `-d`, `-e`, `-r`, `-w`, `-x`, `-s`, `-L`, `-z`, `-n`), string tests, integer comparisons
- `[[` — bash extended test; regex with `=~`, no word splitting, `&&`/`||` inside
- `(( ))` — arithmetic condition; C-style comparisons
- `case` / `esac` — pattern matching; `;;`, `;;&`, `;&`
- `for` loops — `for var in list`, C-style `for ((i=0; i<10; i++))`
- `while` loops — `while condition; do ... done`
- `until` loops — `until condition; do ... done`
- `break` and `continue` — with optional level argument
- `select` — menu generation from a list; `PS3` prompt
- `&&` and `||` — short-circuit evaluation; chaining by success/failure
- `;` — sequential execution regardless of exit code

### [5.4 — Functions, Arguments, Exit Codes](phase-5-shell-scripting/5.4-functions-arguments.md)
- Defining functions — `name() { ... }` and `function name { ... }`
- `local` variables — scope inside functions; the keyword you must use
- Return values — `return N` sets exit code; use `echo` + capture for data
- Passing arguments — same as scripts: `$1`, `$2`, `$@`, `$#`, `$*`
- Recursive functions — factorial, tree traversal
- `shift` — consuming positional parameters; `shift N`
- `getopts` — parsing short options (`-v`, `-f file`); `OPTARG`, `OPTIND`
- Exit codes — 0 success, non-zero failure; standard codes (1, 2, 126, 127, 128+N)
- `$?` — capturing exit codes immediately; the variable that gets overwritten by every command
- `source` / `.` — running a script in the current shell (shares variables and functions)

### [5.5 — Writing Safe Scripts](phase-5-shell-scripting/5.5-safe-scripts.md)
- The shebang — `#!/bin/bash` vs `#!/usr/bin/env bash`; portability implications
- `set -e` — exit on error; which errors it catches and which it misses
- `set -u` — unset variables are errors; catches typos in variable names
- `set -o pipefail` — pipeline exit code reflects the first failing command
- `set -x` (for debugging, not production) — traces every command before executing
- `set -euo pipefail` — the combination that belongs at the top of every script
- Quoting every variable — `"$var"` not `$var`; the rule with no exceptions
- Temporary files safely — `mktemp`, cleanup with `trap ... EXIT`
- `flock` — preventing concurrent script execution via file locking
- `shellcheck` — treating its warnings as errors, not suggestions

### [5.6 — Debugging Scripts](phase-5-shell-scripting/5.6-debugging.md)
- `bash -n script.sh` — syntax check without execution
- `bash -x script.sh` — full trace from the command line
- `set -x` inline — targeted trace around a specific section
- `PS4` — customizing the trace prefix to show line numbers: `PS4='+(${BASH_SOURCE}:${LINENO}): '`
- `trap 'echo "Error at line $LINENO"' ERR` — catching errors as they happen
- `trap 'cleanup' EXIT` — running cleanup on any exit path
- `shellcheck` — static analysis; treating warnings as blocking errors
- Common bugs — unquoted variables, missing `local`, `$?` not captured immediately, `[ ]` vs `[[ ]]`
- Debugging `set -e` surprises — commands that return non-zero legitimately

---

## phase-6-processes/

### [6.1 — The Process Model](phase-6-processes/6.1-process-model.md)
- What a process is — running code, open files, memory, state
- PID and PPID — process ID and parent process ID
- `fork()` — creating a child; copy-on-write memory
- `exec()` family — replacing the current process image
- `exit()` — process termination; exit code, resource cleanup
- Zombie processes — finished but parent hasn't called `wait()`; `defunct` in `ps`
- Orphan processes — parent exited; adopted by PID 1
- PID 1 — the ancestor of all processes; `systemd` on modern systems
- Process groups — `PGID`; signals sent to a whole group
- Sessions — `SID`; shell and its children share a session
- Threads — `clone()` with shared memory; threads vs processes in Linux
- Daemons — detached from terminal; double-fork technique; PID files

### [6.2 — Viewing Processes](phase-6-processes/6.2-viewing-processes.md)
- `ps aux` — BSD syntax; all processes with user, CPU, memory
- `ps -ef` — SysV syntax; all processes with PPID and full command
- `ps -eo` — custom output columns: `pid,ppid,user,%cpu,%mem,stat,comm`
- Process states — `R` running, `S` sleeping, `D` uninterruptible sleep, `Z` zombie, `T` stopped
- `D` state in depth — kernel I/O wait; cannot be killed; a disk/NFS problem indicator
- `top` — interactive process viewer; `k` to kill, `r` to renice, `f` to choose columns
- `htop` — enhanced `top`; tree view, mouse support, per-CPU bars, per-core usage
- `pgrep` — finding PIDs by name; `-u` user, `-l` list names, `-a` full cmdline
- `pidof` — PID of a named process
- `pstree` — process tree; `-p` show PIDs, `-u` show user changes
- `/proc/PID/` — complete process information without any external tools

### [6.3 — Signals](phase-6-processes/6.3-signals.md)
- What signals are — asynchronous kernel notifications to processes
- `SIGTERM` (15) — polite termination; the default `kill`; can be caught
- `SIGKILL` (9) — unconditional kill; cannot be caught, blocked, or ignored
- `SIGHUP` (1) — hangup; conventional meaning: reload configuration
- `SIGINT` (2) — interrupt; sent by `Ctrl+C`
- `SIGQUIT` (3) — quit with core dump; sent by `Ctrl+\`
- `SIGSTOP` (19) — pause process; cannot be caught (`Ctrl+Z` sends `SIGTSTP`)
- `SIGCONT` (18) — resume a stopped process
- `SIGUSR1` (10) / `SIGUSR2` (12) — user-defined; used by daemons for custom actions
- `SIGCHLD` (17) — sent to parent when child terminates
- `SIGPIPE` (13) — broken pipe; sent when writing to a closed pipe
- `kill -l` — listing all signal names and numbers
- `kill` — sending signals by PID; `kill -9 PID`, `kill -SIGTERM PID`
- `pkill` — sending signals by process name; `-u` user, `-t` terminal
- `killall` — sending signals by exact name
- `trap` in scripts — catching signals; `trap 'handler' SIGTERM SIGINT EXIT`

### [6.4 — Job Control](phase-6-processes/6.4-job-control.md)
- Foreground vs background — `&` to start in background
- `Ctrl+Z` — suspending the foreground job (sends `SIGTSTP`)
- `jobs` — listing background and suspended jobs; `%1`, `%2` job references
- `fg` — bringing a job to the foreground; `fg %1`
- `bg` — resuming a suspended job in the background; `bg %1`
- `nohup` — running a process immune to hangup; output to `nohup.out`
- `disown` — removing a job from shell's job table; survives shell exit
- `wait` — waiting for a background job; `wait $pid`, `wait` for all
- `GNU parallel` — running jobs with controlled concurrency

### [6.5 — Resource Limits](phase-6-processes/6.5-resource-limits.md)
- `ulimit` — viewing and setting per-process limits: `-n` open files, `-u` processes, `-s` stack size, `-v` virtual memory
- `/etc/security/limits.conf` — persistent ulimit configuration via PAM
- `/proc/PID/limits` — current limits for a specific running process
- Soft vs hard limits — soft is the current limit; hard is the ceiling; only root can raise hard limits
- cgroups overview — the kernel's resource accounting and enforcement mechanism
- cgroups v2 hierarchy — CPU, memory, I/O controllers; `/sys/fs/cgroup/`
- `systemd` resource directives — `MemoryMax=`, `CPUQuota=`, `TasksMax=` as unit file directives

### [6.6 — /proc Filesystem](phase-6-processes/6.6-proc-filesystem.md)
- What `/proc` is — a virtual filesystem; no disk I/O; generated by the kernel on read
- `/proc/PID/cmdline` — null-separated command line
- `/proc/PID/environ` — null-separated environment variables
- `/proc/PID/cwd` — symlink to current working directory
- `/proc/PID/exe` — symlink to the executable
- `/proc/PID/fd/` — open file descriptors; symlinks to files, sockets, pipes
- `/proc/PID/maps` — virtual memory map; address ranges, permissions, mapped files
- `/proc/PID/status` — human-readable process status: state, memory, UIDs, threads
- `/proc/PID/io` — read/write byte counts
- `/proc/meminfo` — system-wide memory accounting
- `/proc/cpuinfo` — CPU details: model, cores, flags
- `/proc/loadavg` — load averages and running/total process count
- `/proc/sys/` — tunable kernel parameters (same as `sysctl`)
- `/proc/net/tcp` — TCP socket table
- `/proc/mounts` — currently mounted filesystems

---

## phase-7-users-auth/

### [7.1 — User and Group Management](phase-7-users-auth/7.1-user-group-management.md)
- `/etc/passwd` — format: username, x, UID, GID, GECOS, home, shell; world-readable by design
- `/etc/shadow` — hashed passwords, aging fields; readable only by root
- `/etc/group` — format: group name, x, GID, member list
- `/etc/gshadow` — group passwords and administrators
- UID ranges — 0 (root), 1–999 (system accounts), 1000+ (regular users)
- `useradd` — creating users; `-m` home, `-s` shell, `-G` groups, `-u` UID, `-e` expiry, `-d` home dir
- `useradd` vs `adduser` — `adduser` is a Debian/Ubuntu wrapper with interactive prompts
- `usermod` — modifying users; `-l` rename, `-aG` add to group (the `-a` is critical), `-L`/`-U` lock/unlock, `-s` shell
- `userdel` — deleting users; `-r` remove home and mail spool
- `groupadd`, `groupmod`, `groupdel` — group lifecycle
- `passwd` — changing passwords; `-l` lock, `-u` unlock, `-e` expire immediately, `-d` delete password
- `chage` — password aging: `-l` list, `-M` max days, `-m` min days, `-W` warn days, `-E` expiry date
- `id` — current user's UID, GID, and supplementary groups
- `who` / `w` — who is logged in; idle time, what they're running
- `last` / `lastb` — successful and failed login history; `/var/log/wtmp`, `/var/log/btmp`

### [7.2 — The Auth Files](phase-7-users-auth/7.2-auth-files.md)
- `/etc/passwd` in depth — every field explained; why the password field is always `x`
- `/etc/shadow` in depth — hash algorithm prefix (`$6$` = SHA-512), salt, hash, aging fields
- Password hashing algorithms — MD5 (`$1$`), SHA-256 (`$5$`), SHA-512 (`$6$`), yescrypt (`$y$`)
- `/etc/group` in depth — primary group vs supplementary groups
- How the kernel resolves UIDs and GIDs — UID 0 is always root, regardless of username
- `getent passwd user` — looking up users via NSS (works with LDAP, NIS, local)
- Locked accounts — `!` prefix in shadow means no password auth; why this differs from expiry
- Service accounts — no shell (`/usr/sbin/nologin`, `/bin/false`), no home, UID < 1000

### [7.3 — Privilege Escalation](phase-7-users-auth/7.3-privilege-escalation.md)
- `su` — switching user; `su -` for full login environment; `su -c "cmd" user`
- `sudo` — running a command as another user (default: root); logs every invocation
- `/etc/sudoers` — never edit directly; always use `visudo`
- `visudo` — syntax-checking sudoers editor; prevents saving a broken file
- Sudoers rule syntax — `user host=(runas) commands`; `ALL`, `NOPASSWD`, `!cmd`
- Sudoers aliases — `User_Alias`, `Host_Alias`, `Cmnd_Alias`, `Runas_Alias`
- `/etc/sudoers.d/` — drop-in files; cleaner than editing the main file
- `sudo -l` — listing what the current user is allowed to run
- `sudo -i` / `sudo -s` — interactive root shell (different environments)
- `sudo -u user cmd` — running as a specific non-root user
- Linux capabilities — `cap_net_bind_service`, `cap_sys_admin`; `getcap`, `setcap`
- `pkexec` — PolicyKit; GUI privilege escalation; the CVE-2021-4034 lesson

### [7.4 — PAM](phase-7-users-auth/7.4-pam.md)
- What PAM is — a pluggable framework between services and auth mechanisms
- `/etc/pam.d/` — per-service PAM stacks; `common-auth`, `sshd`, `sudo`, `login`
- Module types — `auth`, `account`, `password`, `session`
- Control flags — `required`, `requisite`, `sufficient`, `optional`; how they combine
- `pam_unix.so` — standard Unix password authentication
- `pam_deny.so` / `pam_permit.so` — unconditional deny/allow
- `pam_limits.so` — enforcing ulimit settings from `/etc/security/limits.conf`
- `pam_env.so` — setting environment variables at login
- `pam_tally2.so` / `pam_faillock.so` — account lockout after failed attempts
- `pam_google_authenticator` — TOTP 2FA via PAM

### [7.5 — SSH](phase-7-users-auth/7.5-ssh.md)
- What SSH is — encrypted remote shell; replaces telnet, rlogin
- `ssh` basic usage — `ssh user@host`, `-p` port, `-i` identity file, `-v` verbose
- Key types — RSA (legacy), ECDSA, Ed25519 (preferred); why Ed25519 in 2024
- `ssh-keygen` — generating keys; `-t ed25519`, `-C` comment, `-f` output file, passphrases
- `~/.ssh/authorized_keys` — public keys allowed to log in; permissions must be 600
- `~/.ssh/config` — per-host aliases, `IdentityFile`, `Port`, `User`, `ProxyJump`, `ForwardAgent`
- `ssh-agent` — storing decrypted keys in memory; `ssh-add`, `SSH_AUTH_SOCK`
- `ssh-copy-id` — copying public key to remote `authorized_keys`
- Port forwarding — local `-L`, remote `-R`, dynamic SOCKS `-D`
- `ProxyJump` / `-J` — SSH through a bastion host in one command
- `ControlMaster` / `ControlPath` / `ControlPersist` — multiplexing connections
- `/etc/ssh/sshd_config` — `PermitRootLogin`, `PasswordAuthentication`, `AllowUsers`, `MaxAuthTries`, `ClientAliveInterval`
- SSH hardening — key-only auth, no root login, Ed25519 only, `fail2ban`
- `known_hosts` — host key verification; `StrictHostKeyChecking`; TOFU model
- SSH certificates — signing keys with a CA; fleet key management without `authorized_keys` sprawl

---

## phase-8-packages/

### [8.1 — apt and dpkg (Debian/Ubuntu)](phase-8-packages/8.1-apt-dpkg.md)
- `dpkg` — the low-level package manager; `.deb` files; no dependency resolution
- `dpkg -i` / `-r` / `-P` — install, remove, purge (remove + config files)
- `dpkg -l` — listing installed packages
- `dpkg -L pkg` — listing files owned by a package
- `dpkg -S /path/to/file` — which package owns this file
- `dpkg --configure -a` — reconfiguring broken/unconfigured packages
- `apt` — the high-level front-end; resolves dependencies via SAT solver
- `apt update` / `upgrade` / `full-upgrade` / `install` / `remove` / `purge` / `autoremove`
- `apt search` / `apt show` / `apt list --installed`
- `/etc/apt/sources.list` and `/etc/apt/sources.list.d/` — repository configuration
- `apt-mark hold` / `unhold` / `showhold` — pinning packages
- APT pinning — `/etc/apt/preferences`; controlling version selection across repos
- PPA — `add-apt-repository`; third-party repositories; trust model
- Signed repository keys — `signed-by` option; replacing deprecated `apt-key`
- `unattended-upgrades` — automatic security updates; configuration
- `debconf` / `dpkg-reconfigure` — package configuration framework

### [8.2 — dnf and rpm (RHEL/Fedora/CentOS)](phase-8-packages/8.2-dnf-rpm.md)
- `rpm` — low-level package manager; `.rpm` files
- `rpm -i` / `-U` / `-e` / `-F` — install, upgrade, erase, freshen
- `rpm -qa` / `-ql pkg` / `-qf /path` / `-qi pkg` — query installed packages
- `rpm -V pkg` — verifying package integrity against recorded checksums
- `rpm2cpio` — extracting files from `.rpm` without installing
- `dnf` — the high-level front-end; replaces `yum`
- `dnf install` / `remove` / `update` / `upgrade` / `reinstall`
- `dnf search` / `info` / `list` / `provides`
- `dnf history` — transaction history; `undo`, `redo`
- `dnf group` — installing groups of related packages
- `dnf config-manager` — adding/enabling/disabling repositories
- `/etc/yum.repos.d/` — repository configuration files
- EPEL — Extra Packages for Enterprise Linux; what it provides and why you almost always need it
- `mock` — building RPMs in a clean chroot

### [8.3 — pacman (Arch)](phase-8-packages/8.3-pacman.md)
- `pacman -S` / `-R` / `-U` — install, remove, install local file
- `pacman -Syu` — full system upgrade (the only correct way on Arch)
- `pacman -Ss` / `-Si` / `-Ql` / `-Qo` — search and query
- `pacman -Qdt` — orphaned packages; the cleanup step most users skip
- `/etc/pacman.conf` — repositories, `Color`, `ParallelDownloads`, `ILoveCandy`
- AUR — Arch User Repository; `PKGBUILD` format; the trust model
- `makepkg` — building packages from a `PKGBUILD`; `-s` install deps, `-i` install after build
- AUR helpers — `yay`, `paru`; convenience vs security trade-off

### [8.4 — Compiling from Source](phase-8-packages/8.4-compiling-from-source.md)
- Why compile from source — newer version, custom flags, unavailable package
- The classic `./configure && make && make install`
- `./configure` — checking dependencies, generating Makefiles; `--prefix`, `--enable-*`, `--disable-*`, `--with-*`
- `Makefile` anatomy — targets, prerequisites, rules, variables, `.PHONY`
- `make -j$(nproc)` — parallel builds; why you should always use this
- `make install` — installing to prefix; why `/usr/local` is the right choice for manual installs
- `checkinstall` — creating a trackable `.deb` or `.rpm` from a `make install`
- `cmake` — modern build system generator; `cmake -B build`, `cmake --build build`
- `meson` / `ninja` — another modern pair common in GNOME/freedesktop projects
- `pkg-config` — finding compile flags for libraries; `pkg-config --cflags --libs openssl`
- `ldd` — listing shared library dependencies of an executable
- `ldconfig` — updating the dynamic linker cache after installing libraries

### [8.5 — Containers as an Alternative](phase-8-packages/8.5-containers-distribution.md)
- Why containers solved software distribution — "it works on my machine" at the OS level
- OCI image format — layers, `config.json`, `manifest.json`; what a Docker image actually is
- The image layer model — union filesystem; why layer order matters for build size
- Static binaries — no shared library dependencies; the extreme end of self-contained
- `docker run` vs installing — when each approach is correct
- Container registries — Docker Hub, ghcr.io, quay.io; image naming and tagging
- The trade-off — isolation and reproducibility at the cost of size and complexity

---

## phase-9-networking/

### [9.1 — Network Fundamentals](phase-9-networking/9.1-network-fundamentals.md)
- Network interfaces — physical (`eth0`, `enp3s0`), virtual (`lo`, `veth`, `br0`, `tun0`)
- IPv4 addressing — CIDR notation, subnets, broadcast, loopback, private ranges
- IPv6 — address format, link-local (`fe80::/10`), global unicast, `::1`
- Routing — default gateway, routing table, longest-prefix match
- DNS — resolution process: stub resolver → recursive resolver → authoritative
- DHCP — dynamic address assignment; `dhclient`, systemd-networkd, NetworkManager
- ARP — Address Resolution Protocol; `ip neigh`; ARP cache
- NetworkManager — `nmcli`, `nmtui`; connection profiles; distro default on RHEL/Ubuntu desktop
- systemd-networkd — `.network` files; minimal, server-oriented

### [9.2 — Diagnostic Tools](phase-9-networking/9.2-diagnostic-tools.md)
- `ip addr` — viewing and configuring IP addresses; replaces `ifconfig`
- `ip link` — viewing and configuring interfaces; `up`/`down`; replaces `ifconfig`
- `ip route` — viewing and modifying the routing table; replaces `route`
- `ip neigh` — ARP/NDP neighbor table; replaces `arp`
- `ss` — socket statistics; `-t` TCP, `-u` UDP, `-l` listening, `-p` process, `-n` no DNS, `-tulpn` the classic combo
- `netstat` (legacy) — same as `ss` but installed by default on older systems
- `ping` — ICMP echo; `-c` count, `-i` interval, `-s` packet size
- `traceroute` / `tracepath` — path to a host; MTU discovery
- `mtr` — continuous `traceroute`; packet loss per hop; better for intermittent issues
- `dig` — DNS queries; `+short`, `+trace`, record types (A, AAAA, MX, NS, TXT, SOA, PTR)
- `nslookup` (legacy) — interactive DNS lookup
- `host` — simple DNS lookup
- `nmap` — network scanning; port discovery, OS detection, service version
- `tcpdump` — packet capture; `-i` interface, `-n`, `-w` pcap, BPF filters
- `netcat` (`nc`) — TCP/UDP Swiss army knife; port testing, banner grabbing, file transfer

### [9.3 — Network Configuration Files](phase-9-networking/9.3-network-config-files.md)
- `/etc/hosts` — static hostname-to-IP mappings; checked before DNS
- `/etc/resolv.conf` — DNS resolver configuration; often managed by `systemd-resolved` or NetworkManager
- `/etc/nsswitch.conf` — Name Service Switch; the file that decides resolution order
- `systemd-resolved` — caching DNS resolver; `resolvectl status`; `/run/systemd/resolve/stub-resolv.conf`
- NetworkManager connection files — `/etc/NetworkManager/system-connections/`
- systemd-networkd `.network` files — `/etc/systemd/network/`
- `/etc/hostname` — the system's hostname; `hostnamectl set-hostname`

### [9.4 — Firewalls](phase-9-networking/9.4-firewalls.md)
- Netfilter — the kernel's packet filtering framework; tables, chains, hooks
- `iptables` — tables (`filter`, `nat`, `mangle`, `raw`), chains (`INPUT`, `OUTPUT`, `FORWARD`, `PREROUTING`, `POSTROUTING`)
- `iptables` operations — append (`-A`), insert (`-I`), delete (`-D`), list (`-L -n -v`), flush (`-F`), save
- Connection tracking — `ESTABLISHED`, `RELATED`, `NEW`, `INVALID`; stateful firewall
- NAT — `MASQUERADE`, `SNAT`, `DNAT`; enabling IP forwarding with `net.ipv4.ip_forward=1`
- `nftables` — modern replacement; tables, chains, rules; `nft` command; `iptables-nft` compat layer
- `ufw` — Uncomplicated Firewall (Ubuntu); `enable`, `allow`, `deny`, `status verbose`
- `firewalld` — zone-based firewall (RHEL/Fedora); `firewall-cmd`; permanent vs runtime changes
- `fail2ban` — banning IPs after repeated failures; jails, filters, actions

### [9.5 — SSH Advanced](phase-9-networking/9.5-ssh-advanced.md)
- Local port forwarding — `-L localport:remotehost:remoteport`; accessing remote services locally
- Remote port forwarding — `-R remoteport:localhost:localport`; exposing local services through a remote server
- Dynamic SOCKS proxy — `-D port`; routing arbitrary traffic through SSH
- `ProxyJump` / `-J` — SSH through a bastion host; multi-hop SSH
- `ssh -N -f` — background tunnel without an interactive shell
- `ControlMaster` / `ControlPath` / `ControlPersist` — connection multiplexing
- `scp` — secure copy; being superseded by `rsync` and `sftp`
- `sftp` — interactive secure file transfer
- `rsync` over SSH — `rsync -avz -e ssh src/ user@host:dst/`
- SSH certificates — signing keys with a CA; `ssh-keygen -s`

### [9.6 — HTTP from the Command Line](phase-9-networking/9.6-http-cli.md)
- `curl` basics — fetching URLs; `-o`, `-O`, `-L` follow redirects, `-s` silent, `-v` verbose, `-I` headers only
- HTTP methods — `-X POST`, `-X PUT`, `-X DELETE`, `-X PATCH`
- Request headers — `-H "Content-Type: application/json"`, `-H "Authorization: Bearer token"`
- POST data — `-d 'key=val'`, `-d @file.json`, `--data-urlencode`
- Authentication — `-u user:pass`, `--netrc`, bearer tokens
- TLS — `--cacert`, `--cert`, `--key`, `-k` (insecure; know when not to use this)
- Output control — `-o file`, `-D` dump headers, `-i` include headers in output
- Timing — `--write-out "%{time_total}\n%{time_starttransfer}\n"` for latency measurement
- `wget` — downloading files; `-r` recursive, `-N` timestamping
- `curl` vs `wget` — when to use each

### [9.7 — Network Namespaces](phase-9-networking/9.7-network-namespaces.md)
- What a network namespace is — isolated network stack; interfaces, routing table, firewall
- `ip netns add` / `ip netns exec` / `ip netns list` / `ip netns delete`
- `veth` pairs — virtual ethernet cables connecting namespaces
- Connecting a namespace to the outside — veth pair + bridge or NAT
- `ip link add br0 type bridge` — software bridge; multiple namespaces on one broadcast domain
- How containers use network namespaces — each container gets its own netns
- Network namespace use cases — testing network software, container networking, traffic isolation

---

## phase-10-storage/

### [10.1 — Block Devices and Partitioning](phase-10-storage/10.1-block-devices-partitioning.md)
- Block devices — HDDs, SSDs, NVMe; device naming conventions (`/dev/sda`, `/dev/nvme0n1`, `/dev/vda`)
- MBR vs GPT — partition table formats; 4-partition limit, 2TB limit, why GPT is always right now
- `fdisk` — MBR and GPT partitioning; `n` new, `d` delete, `t` type, `p` print, `w` write
- `gdisk` — GPT-specific; better for GPT than `fdisk`
- `parted` — scriptable partitioning; used by installers; `mklabel`, `mkpart`, `resizepart`
- Partition types — Linux filesystem (83/8300), swap (82/8200), LVM (8e/8e00), EFI System (EF00)
- `lsblk` — visualizing block device tree: disks, partitions, LVM, dm-crypt layers
- `blkid` — probing block devices for filesystem type, UUID, LABEL
- Disk health — `smartctl -a /dev/sda`; SMART attributes, short/long self-tests
- `hdparm -t` — simple sequential read benchmark

### [10.2 — Filesystems](phase-10-storage/10.2-filesystems.md)
- ext4 — journaling, extent tree, delayed allocation; the safe default
- xfs — high-performance, great for large files; used by RHEL by default; cannot shrink
- btrfs — copy-on-write, subvolumes, snapshots, RAID modes; `btrfs` command suite
- zfs (OpenZFS) — `zpool`, `zfs`; datasets, snapshots, checksums, compression, dedup
- tmpfs — RAM-backed; configured at mount time; `/tmp`, `/run`, `/dev/shm`
- overlayfs — layered filesystem; lower (read-only) + upper (writable) + merged view
- `mkfs.ext4` / `mkfs.xfs` / `mkfs.btrfs` — creating filesystems; important options
- `fsck` — filesystem check and repair; only run on unmounted filesystems
- `tune2fs` — tuning ext4 parameters; reserved blocks, journal mode
- `resize2fs` — online resizing ext4; always extend the LV first, then the filesystem
- `xfs_growfs` — growing xfs online; xfs cannot shrink

### [10.3 — LVM](phase-10-storage/10.3-lvm.md)
- LVM concepts — Physical Volume (PV), Volume Group (VG), Logical Volume (LV), Physical Extent (PE)
- `pvcreate` — initializing a disk or partition as a PV
- `vgcreate` — creating a VG from one or more PVs
- `lvcreate -L size -n name vg` — creating an LV
- `vgextend` — adding a new PV to an existing VG
- `lvextend -L +size /dev/vg/lv` — extending an LV; then `resize2fs` or `xfs_growfs`
- `lvreduce` — shrinking an LV; only ext4 supports shrink; unmount and `resize2fs` first
- LVM snapshots — `lvcreate -s`; consistent backups of live volumes
- LVM thin provisioning — over-commit storage; thin pool, thin LV
- `pvdisplay` / `vgdisplay` / `lvdisplay` — detailed inspection
- `pvs` / `vgs` / `lvs` — terse status output
- Removing LVM — `lvremove`, `vgremove`, `pvremove`; order matters

### [10.4 — RAID](phase-10-storage/10.4-raid.md)
- What RAID is — Redundant Array of Independent Disks; performance, redundancy, or both
- RAID is not a backup — protects against hardware failure, not deletion or corruption
- RAID 0 — striping; maximum performance, zero redundancy
- RAID 1 — mirroring; full redundancy; one disk can fail
- RAID 5 — distributed parity; one disk can fail; minimum 3 disks; URE risk during rebuild
- RAID 6 — dual parity; two disks can fail; minimum 4 disks
- RAID 10 — mirrored stripes; best performance and redundancy; minimum 4 disks
- `mdadm --create` — creating a software RAID array
- `/proc/mdstat` — monitoring RAID status and rebuild progress
- `mdadm --detail /dev/md0` — detailed array status
- `mdadm --add` / `--remove` / `--fail` — managing array members
- RAID rebuild — what happens after disk replacement; monitoring progress
- Hardware RAID vs software RAID — when each is appropriate

### [10.5 — Disk Usage](phase-10-storage/10.5-disk-usage.md)
- `df -h` — filesystem-level usage; `-T` show type, `-i` show inodes
- `du -sh dir` — directory-level disk usage; `-h` human, `-s` summary, `--max-depth`
- `du -sh /* | sort -h` — finding the largest directories at root level
- `ncdu` — interactive disk usage browser; navigate with arrow keys
- `lsblk` — block device sizes and partition layout
- `blkid` — identifying filesystems
- Disk full but `df` shows space — inodes exhausted; check `df -i`
- Disk full but du shows space — deleted files held open; `lsof | grep deleted`
- Disk full from logs — `/var/log` is usually the culprit; check with `du -sh /var/log/*`

### [10.6 — Backups](phase-10-storage/10.6-backups.md)
- The 3-2-1 rule — 3 copies, 2 different media, 1 offsite
- `rsync` for backups — `-avz --delete --progress`; basic mirror
- `rsync --link-dest` — space-efficient incremental backups using hard links
- `tar` — archiving; `-czf` gzip, `-cjf` bzip2, `-cJf` xz; `-x` extract, `-t` list
- `tar` incremental — `--listed-incremental` for level-based incrementals
- `dd` — disk imaging; `if=`, `of=`, `bs=4M`, `status=progress`; whole-disk backup
- LVM snapshots for backup — consistent state of a live volume without stopping services
- `btrfs send` / `receive` — streaming snapshots for replication
- `restic` / `borgbackup` — modern backup tools with dedup, encryption, and verification
- Testing restores — a backup you haven't restored from is a backup you can't trust

---

## phase-11-init-services/

### [11.1 — The Boot Process](phase-11-init-services/11.1-boot-process.md)
- Power-on — BIOS/UEFI firmware runs POST
- BIOS vs UEFI — legacy boot, Secure Boot, GPT requirement, UEFI boot entries
- GRUB2 — GRand Unified Bootloader; menu display, kernel selection, `grub.cfg`
- GRUB configuration — `/etc/default/grub`, `update-grub` (Debian) / `grub2-mkconfig` (RHEL)
- GRUB command line — editing kernel parameters at boot; `e` to edit entry
- Kernel loading — GRUB loads `vmlinuz` and `initrd.img` into memory
- initramfs / initrd — temporary root filesystem in RAM; mounts real root, then `pivot_root`
- `dracut` / `mkinitramfs` — rebuilding initramfs after kernel or module changes
- Kernel ring buffer — `dmesg`; reading early boot messages; `-H` human-readable, `-T` timestamps
- PID 1 — systemd (or legacy init) takes over; mounts filesystems, starts services
- Kernel parameters — `quiet`, `ro`, `nomodeset`, `systemd.unit=rescue.target`
- Single-user / rescue mode — booting to recover a broken system
- `systemd-analyze` — boot timing; `blame`, `critical-chain`, `plot`

### [11.2 — systemd Architecture](phase-11-init-services/11.2-systemd-architecture.md)
- What systemd is — PID 1, init system, service manager, socket activator, mount manager
- Unit types — service, socket, timer, mount, automount, target, device, path, slice, scope
- Unit file locations — `/lib/systemd/system/` (distro), `/etc/systemd/system/` (admin, wins), `/run/systemd/system/` (runtime)
- `[Unit]` section — `Description`, `After`, `Before`, `Requires`, `Wants`, `Conflicts`, `ConditionPathExists`
- `Wants` vs `Requires` — soft vs hard dependency; `Wants` doesn't fail the unit if the dependency fails
- Targets — analogous to runlevels; `multi-user.target`, `graphical.target`, `rescue.target`, `emergency.target`
- Default target — `systemctl get-default` / `set-default`
- `systemctl isolate target` — immediately switch to a different target

### [11.3 — systemctl](phase-11-init-services/11.3-systemctl.md)
- `systemctl start` / `stop` / `restart` / `reload` / `status`
- `systemctl enable` / `disable` — creates/removes symlinks in `.wants/`; does not start/stop
- `systemctl enable --now` — enable and start in one command
- `systemctl mask` / `unmask` — symlinking to `/dev/null`; prevents any start
- `systemctl daemon-reload` — required after creating or editing unit files
- `systemctl list-units` — all loaded units; `--failed`, `--type=service`, `--state=active`
- `systemctl list-unit-files` — all installed units and enablement state
- `systemctl is-active` / `is-enabled` / `is-failed` — scriptable status checks
- `systemctl --user` — managing user-session units
- Drop-in overrides — `systemctl edit unit`; creates `/etc/systemd/system/unit.d/override.conf`

### [11.4 — journalctl](phase-11-init-services/11.4-journalctl.md)
- `journalctl` — reading the systemd journal; binary format, indexed, fast
- `-f` follow — live log stream
- `-n N` — last N lines
- `-b` / `-b -1` — this boot / previous boot; `--list-boots`
- `-u unit` — filtering by service unit
- `--since` / `--until` — time-based filtering; `"1 hour ago"`, `"2024-01-01 10:00"`
- `-p priority` — filtering by syslog priority (0=emerg, 3=err, 4=warn, 6=info, 7=debug)
- `-xe` — last errors with explanations; the go-to command after a failure
- Output formats — `-o short` (default), `-o json`, `-o json-pretty`, `-o verbose`, `-o cat`
- Persistent journal — `Storage=persistent` in `/etc/systemd/journald.conf`
- Journal size management — `SystemMaxUse`, `MaxFileSec`; `journalctl --vacuum-size=500M`
- Forwarding to syslog — `ForwardToSyslog=yes`; integrating with `rsyslog`

### [11.5 — Writing a systemd Service](phase-11-init-services/11.5-writing-services.md)
- A complete `.service` file — `[Unit]`, `[Service]`, `[Install]` sections
- `[Service]` section — `Type`, `ExecStart`, `ExecStop`, `ExecReload`, `Restart`, `RestartSec`
- `User=` / `Group=` — running as a non-root user
- `WorkingDirectory=` / `Environment=` / `EnvironmentFile=`
- Service types — `Type=simple` (default), `Type=exec`, `Type=forking`, `Type=oneshot`, `Type=notify`
- `Restart=on-failure` with `RestartSec=5` — the standard production pattern
- `WantedBy=multi-user.target` — the `[Install]` section that makes `enable` work
- Sandboxing directives — `PrivateTmp=yes`, `ProtectSystem=strict`, `ProtectHome=yes`, `NoNewPrivileges=yes`
- Drop-in overrides — adding or overriding directives without modifying the original file
- Systemd timer units — `[Timer]` with `OnCalendar=` and `Persistent=true`
- Path units — `[Path]` with `PathExists=`, `PathChanged=`, triggering a service on filesystem events

### [11.6 — Legacy Init Systems](phase-11-init-services/11.6-legacy-init.md)
- SysV init — `/etc/init.d/` scripts, sequential startup, runlevels 0–6
- SysV init script anatomy — `start`, `stop`, `restart`, `status` functions
- `chkconfig` / `update-rc.d` — managing SysV service enablement
- Upstart — event-based init; Ubuntu default before systemd
- Why systemd replaced them — parallel startup, dependency declarations, socket activation, integrated logging
- `service` and `chkconfig` today — wrappers that call `systemctl`; still work on systemd systems
- When you'll still see SysV — legacy enterprise systems, embedded Linux, some containers

---

## phase-12-performance/

### [12.1 — CPU Analysis](phase-12-performance/12.1-cpu-analysis.md)
- CPU topology — sockets, cores, threads (SMT); `lscpu`
- Load average — 1/5/15-minute averages; what they count; interpreting relative to CPU count
- `uptime` — load averages and system uptime at a glance
- `vmstat 1` — one-second snapshots; `r` run queue, `b` blocked, `si`/`so` swap, `us`/`sy`/`id`/`wa`/`st`
- `mpstat -P ALL 1` — per-CPU statistics; identifying hot CPUs
- `sar` — System Activity Reporter; `sar -u`, `sar -r`, `sar -d`; historical data
- Context switching — `vmstat cs` column; what causes it, when it matters
- `%steal` — CPU stolen by hypervisor; what it means in VMs when it's high
- `perf stat cmd` — hardware performance counters; cache misses, branch mispredicts, IPC
- `perf top` — live function-level CPU profiling
- `perf record` / `perf report` — sampling profiler; input for flame graphs
- Flame graphs — Brendan Gregg's visualization; reading call stacks from the base up

### [12.2 — Memory Analysis](phase-12-performance/12.2-memory-analysis.md)
- `free -h` — memory overview; why "available" matters more than "free"
- Buffer cache — page cache; Linux uses free RAM to cache disk reads; this is normal
- `/proc/meminfo` — full accounting; `MemAvailable`, `Buffers`, `Cached`, `Dirty`, `Writeback`, `SwapTotal`
- Swap — `swapon`, `swapoff`, `mkswap`; swap partition vs swap file
- `vm.swappiness` — sysctl parameter; 0–100; what it actually controls (not what most articles say)
- OOM killer — triggered when all memory is exhausted; log in `dmesg` / `journalctl`
- `oom_score` / `oom_score_adj` — adjusting OOM priority per process
- `smem` — per-process proportional set size (PSS); more accurate than `ps` RSS
- `pmap -x PID` — per-process virtual memory map; resident vs virtual
- Huge pages — THP; `AnonHugePages` in `/proc/meminfo`; enabling/disabling per-process

### [12.3 — I/O Analysis](phase-12-performance/12.3-io-analysis.md)
- `iostat -x 1` — per-device I/O statistics; `%util`, `await`, `r/s`, `w/s`, `rkB/s`, `wkB/s`
- `%util` at 100% — device saturated; requests queueing
- `await` — average I/O wait time in ms; high await with low util = slow device
- `iotop -o` — per-process I/O; only showing active processes
- I/O schedulers — `mq-deadline`, `bfq`, `kyber`, `none` (NVMe); `/sys/block/*/queue/scheduler`
- Page cache writeback — `vm.dirty_ratio`, `vm.dirty_background_ratio`; when to tune
- `fio` — flexible I/O tester; benchmarking storage subsystems

### [12.4 — Load Averages](phase-12-performance/12.4-load-averages.md)
- What load average measures — count of processes in R (runnable) + D (uninterruptible sleep)
- Load average is not CPU usage — D-state processes inflate load without using CPU
- Interpreting load relative to CPU count — load of 4.0 on 4 cores = 100%, on 8 cores = 50%
- When high load is not a problem — batch jobs, known bursts
- When high load is I/O — check `vmstat wa` and `iostat`; not a CPU problem
- `uptime` vs `w` — same load averages, different context

### [12.5 — strace and ltrace](phase-12-performance/12.5-strace-ltrace.md)
- What system calls are — the interface between user space and kernel
- `strace cmd` — tracing system calls of a new process
- `strace -p PID` — attaching to a running process
- `-e trace=open,read,write` — filtering to specific syscalls
- `-tt` timestamps, `-T` time per call, `-s 256` string length, `-o file` output
- `strace -c cmd` — counting and timing syscalls; finding the slow one
- Reading `strace` output — decoding `openat()`, `read()`, `write()`, `mmap()`, `clone()`
- `ltrace` — tracing library function calls; `malloc()`, `fopen()`, etc.
- Performance overhead — `strace` slows traced processes 2–10×; use with care on production
- `strace` for debugging — finding config file locations, missing libraries, permission errors

### [12.6 — lsof](phase-12-performance/12.6-lsof.md)
- `lsof` — list open files; files, sockets, pipes, devices, all represented as file descriptors
- `lsof -p PID` — what a specific process has open
- `lsof -u user` — all open files for a user
- `lsof -i :port` — which process is using a specific port
- `lsof -i TCP` / `lsof -i UDP` — all network connections
- `lsof +D /path` — all processes with files open in a directory (why won't this unmount?)
- `lsof | grep deleted` — files deleted but still held open; space not freed until process exits
- Recovering content from a deleted-but-open file — `/proc/PID/fd/N` still points to it

---

## phase-13-security/

### [13.1 — Principle of Least Privilege](phase-13-security/13.1-least-privilege.md)
- Definition — every process, user, and service with the minimum access needed, nothing more
- Applied in practice — dedicated service accounts, minimal sudo rules, network access scoping
- Linux capabilities — splitting root into fine-grained privileges; `getcap`, `setcap`
- `cap_net_bind_service` — allow binding to ports < 1024 without root
- `cap_sys_admin` — the "god" capability that is almost as powerful as full root
- Reviewing capability assignments — `getcap -r /usr/bin/` to audit
- Attack surface — every unnecessary service, open port, and installed package is exposure

### [13.2 — File Permissions Audit](phase-13-security/13.2-permissions-audit.md)
- `find / -perm -4000 2>/dev/null` — all setuid binaries; audit this list on every new system
- `find / -perm -2000 2>/dev/null` — all setgid binaries
- `find / -perm -0002 -type f 2>/dev/null` — world-writable files
- `find / -perm -0002 -type d ! -perm -1000 2>/dev/null` — world-writable dirs without sticky bit
- `find / -nouser -o -nogroup 2>/dev/null` — files with no owner; leftover from deleted users
- `chattr +i /etc/passwd /etc/shadow /etc/sudoers` — immutable critical files
- `lsattr` — listing filesystem attribute flags

### [13.3 — Mandatory Access Control](phase-13-security/13.3-mac-selinux-apparmor.md)
- DAC vs MAC — Discretionary (permissions) vs Mandatory (policy); MAC enforces even on root
- SELinux — user:role:type:level labels; every file and process has a context
- SELinux modes — enforcing, permissive, disabled; `getenforce`, `setenforce 0`
- `sestatus` — current mode, policy, and booleans summary
- Reading SELinux denials — `avc: denied` in `/var/log/audit/audit.log`
- `audit2why` — human-readable denial explanation
- `audit2allow` — generating a policy module from denials; read before applying
- SELinux booleans — `getsebool -a`, `setsebool -P`; toggling policy without recompiling
- `restorecon` / `chcon` — fixing and setting file contexts
- `semanage fcontext` — permanent file context rules
- AppArmor — path-based profiles; simpler than SELinux; Ubuntu/SUSE default
- `aa-status` — loaded profiles and modes
- `aa-complain` / `aa-enforce` — switching profile modes
- `aa-genprof` / `aa-logprof` — building profiles from logs

### [13.4 — Kernel Hardening](phase-13-security/13.4-kernel-hardening.md)
- `sysctl` — reading and writing kernel parameters at runtime
- `/etc/sysctl.conf` and `/etc/sysctl.d/` — persisting settings across reboots
- `sysctl -p` — reloading configuration without reboot
- Network hardening — `net.ipv4.ip_forward=0`, `net.ipv4.conf.all.accept_redirects=0`, `net.ipv4.tcp_syncookies=1`, `net.ipv4.conf.all.rp_filter=1`
- Kernel address exposure — `kernel.kptr_restrict=2`; hiding kernel pointers from unprivileged users
- `dmesg` restriction — `kernel.dmesg_restrict=1`
- ASLR — `kernel.randomize_va_space=2`; must be 2, not 1
- Core dumps — `kernel.core_pattern`; disable or redirect on production
- `kernel.modules_disabled=1` — preventing module loading after boot (hardened systems)

### [13.5 — Audit Logging](phase-13-security/13.5-audit-logging.md)
- `auditd` — Linux Audit Daemon; kernel-level syscall and file monitoring
- `auditctl -w /etc/passwd -p wa -k passwd-change` — watch a file for writes/attribute changes
- `auditctl -a always,exit -F arch=b64 -S execve -k exec-log` — log all program executions
- `/etc/audit/audit.rules` / `/etc/audit/rules.d/` — persistent audit rules
- `ausearch -f /etc/sudoers` — all events touching a specific file
- `ausearch -ua user` — all events by a specific user
- `aureport --summary` — high-level summary of audit events
- `/var/log/auth.log` (Debian) / `/var/log/secure` (RHEL) — SSH logins, sudo, su
- `last` / `lastb` — login history; baseline and anomaly detection
- `who` / `w` — current sessions
- `fail2ban` — automated IP banning; jails, filters, actions; email alerts

### [13.6 — Hardening Checklist](phase-13-security/13.6-hardening-checklist.md)
- SSH hardening — key-only auth, `PermitRootLogin no`, `MaxAuthTries 3`, `ClientAliveInterval`, strong ciphers/MACs
- Firewall — default deny incoming; allow only necessary ports; verify with `ss -tulpn`
- Services — disable every service not in use; `systemctl list-units --type=service --state=active`
- Updates — `unattended-upgrades` (Debian) / `dnf-automatic` (RHEL); security patches only
- User accounts — remove or lock unused accounts; verify with `passwd -S -a`
- sudo — minimum necessary rules; no broad `ALL`; no `NOPASSWD` without justification
- File permissions — setuid/setgid audit; world-writable files; sensitive file permissions
- Kernel parameters — the 8 essential sysctl hardening settings
- Logging — `auditd` running, persistent journal, log rotation configured
- Verification — each item verified with the appropriate tool before signing off

---

## phase-14-advanced/

### [14.1 — Kernel Modules](phase-14-advanced/14.1-kernel-modules.md)
- What kernel modules are — loadable pieces of kernel code; drivers, filesystems, protocols
- `lsmod` — listing loaded modules; name, size, use count, used by
- `modinfo module` — description, author, parameters, aliases, dependencies
- `modprobe module` — loading with automatic dependency resolution
- `rmmod module` — removing; fails if in use
- `insmod module.ko` — direct insert without dependency resolution
- `/etc/modules-load.d/` — modules to load at boot
- `/etc/modprobe.d/` — module options and blacklisting
- Blacklisting — `blacklist nouveau` in `/etc/modprobe.d/`; preventing a module from loading
- Writing a kernel module — `module_init()`, `module_exit()`, `printk()`, `MODULE_LICENSE()`, Makefile
- Module parameters — `module_param()`; passing options at `modprobe` time
- Compiling out-of-tree — `make -C /lib/modules/$(uname -r)/build M=$(pwd) modules`

### [14.2 — cgroups v2](phase-14-advanced/14.2-cgroups-v2.md)
- What cgroups are — resource accounting and enforcement for groups of processes
- cgroups v1 vs v2 — multiple independent hierarchies vs unified tree; why v2 is the future
- The unified hierarchy — `/sys/fs/cgroup/`; browsing the tree
- Controllers — `cpu`, `memory`, `io`, `pids`, `cpuset`; enabled per-cgroup
- CPU controller — `cpu.max` for bandwidth; `cpu.weight` for relative shares
- Memory controller — `memory.max` (hard limit, OOM) vs `memory.high` (soft limit, throttle)
- I/O controller — `io.max`; limiting IOPS and bandwidth per device
- PID controller — `pids.max`; preventing fork bombs
- Creating a cgroup — `mkdir /sys/fs/cgroup/mygroup`; writing PIDs into `cgroup.procs`
- systemd and cgroups — every service in its own cgroup; `systemd-cgls`, `systemd-cgtop`

### [14.3 — Linux Namespaces](phase-14-advanced/14.3-namespaces.md)
- What namespaces are — kernel feature isolating different aspects of the system view
- PID namespace — isolated process tree; first process is PID 1 inside the namespace
- Network namespace — isolated network stack; interfaces, routes, firewall rules
- Mount namespace — isolated filesystem view; each namespace can have different mounts
- UTS namespace — isolated hostname and NIS domain name
- IPC namespace — isolated System V IPC, POSIX message queues
- User namespace — UID/GID remapping; unprivileged containers
- Time namespace — isolated monotonic and boot clocks (Linux 5.6+)
- `unshare` — creating new namespaces; `--pid --fork --mount-proc`, `--net`, `--user`, `--mount`
- `nsenter -t PID --net --pid` — entering existing namespaces of a running process
- `/proc/PID/ns/` — namespace file descriptors; bind-mounting to keep a namespace alive
- How containers combine namespaces — all seven types together = container isolation

### [14.4 — Containers from Scratch](phase-14-advanced/14.4-containers-from-scratch.md)
- What a container actually is — a process + namespaces + cgroups + overlayfs
- `chroot` — changing the apparent root; not real isolation (no namespace separation)
- `pivot_root` — the correct kernel call for container runtimes; harder to escape than `chroot`
- Building a minimal rootfs — Alpine minirootfs; `debootstrap` for Debian-based
- Combining namespaces — `unshare --pid --fork --mount-proc` inside a chroot
- overlayfs in practice — `mount -t overlay overlay -o lowerdir=,upperdir=,workdir= merged/`
- Container from scratch — step by step: namespace + pivot_root + overlayfs + cgroup
- OCI image format — layers, `config.json`, `manifest.json`; what Docker images actually are
- `runc` — OCI container runtime reference implementation; `runc spec`, `runc run`
- `containerd` — higher-level runtime managing images and lifecycle; what Docker delegates to

### [14.5 — eBPF](phase-14-advanced/14.5-ebpf.md)
- What eBPF is — safe, sandboxed programs that run in the kernel at hook points
- eBPF program types — kprobe, uprobe, tracepoint, XDP, TC, socket filter, LSM
- The eBPF verifier — why eBPF programs are safe; what it checks; bounded loops
- eBPF maps — shared data between kernel programs and userspace; hash, array, ring buffer
- `bpftrace` — high-level tracing language; one-liners for kernel and userspace observation
- `bpftrace` one-liners — syscall latency histograms, open() call logging, TCP connection tracking
- BCC tools — `opensnoop`, `execsnoop`, `biolatency`, `tcpconnect`, `funccount`, `trace`
- `libbpf` + CO-RE — Compile Once, Run Everywhere; portable eBPF programs
- XDP — eXpress Data Path; processing packets before the network stack; DDoS mitigation at line rate
- `bpftool` — inspecting loaded eBPF programs and maps
- Cilium — Kubernetes networking and security built on eBPF
- eBPF vs `strace` — eBPF has ~1% overhead vs `strace`'s 2–10×; production-safe

---

→ **Learning path:** [The Linux Roadmap](../roadmap/README.md)
