# File globing    

#### File globbing is the processing of pattern matching using wildcards


----------

##### Table of content

- [What is the file globbing in linux?](#what-is-file-globbing-in-linux)
- [File globbing characters](#file-globbing-character)
    - [`?`](#-question-mark--is-used-to-match-a-single-characters)
    - [`*`](#-asterisk--is-used-to-match-any-any-number-of-characters)
    - [`[]`](#--is-used-to-match-any-any-number-of-characters)
    - [`{}`](#-curly-brackets-commas-seperated-terms)
    - [`!`](#-exclamation-mark-not-character)
    - [`\`](#-backslash-escape-character)

----------


### What is file globbing in Linux?

File globbing is the expansion of wild character (such as `*`, `?`, etc), to match patterns and search for the files, in the linux system. File globbing is similar to *regular expression*.

### File globbing character


##### `?` (question mark)  is used to match a single characters.

Here is the content of the directory.

```bash
paradox@paradox:~/Documents/others$ ls
cater.txt  cat.txt  cbt.txt  cct.txt  cdt.txt  cet.txt  chat.txt  theory.txt
```

To match, all the text files starting with *c* and ending *t*, which only contains a single character between *c* and *t* (`c<character>t.txt`), for this kinds of file searching, we can use glob character `?`. Lets searching for the following files.

```bash
paradox@paradox:~/Documents/others$ ls c?t.txt
cat.txt  cbt.txt  cct.txt  cdt.txt  cet.txt
```

Preceeding command display the required files.


##### `*` (asterisk)  is used to match any any number of characters.

Imagine you have populated the you home directory, and you are searching for all the files starting with `D`, instead for searching listing all the files with *ls* command and going through all the file names, you can `*` for sort you search and list all the files.

```bash
paradox@paradox:~$ ls D* -d
DD  Desktop  Documents  Downloads
```

If you run the above command, it will list all the files starting with `D*`.


##### `[]` (square bracket) specifies a range.

We have multiple files starting with the *c* and ending with *d.txt*, having a single character in betweeen. Now, we want to search files, which contains *a*,*b*, or *c*. For this, we can use squared bracket.


```bash
paradox@paradox:~/Documents/others$ ls c[a-c]t.txt
cat.txt  cbt.txt  cct.txt
paradox@paradox:~/Documents/others$ 
```

We are also specify the set of character to match using *square brackets*.

```bash
paradox@paradox:~/Documents/others$ ls c[abc]t.txt
cat.txt  cbt.txt  cct.txt
paradox@paradox:~/Documents/others$ 
```


##### `{}` (curly brackets) commas seperated terms

These character are used to separate terms by commas and each term must be the name of something or a wildcard.

Consider the situation similar to that we used in the square brackets. But, now inplace of range we will specify the characters we want to match.

```bash
paradox@paradox:~/Documents/others$ ls c{a,b,c}t.txt
cat.txt  cbt.txt  cct.txt
paradox@paradox:~/Documents/others$ 
```

Another example, of the *curly brackets*, lets imagine we have huge number of 'pdf', 'txt', and 'docx' files and we need for copy 'pdf' and 'text' to another location. To do this operation, we can use *curly brackets*, and in it we can specify the files we want to copy.

```bash
paradox@paradox:~/Documents/others$ cp {*.pdf,*txt} ~/Downloads
# output
```

This will be copy 'pdf' and 'txt' to *Downloads.


##### `[!]` (exclamation mark) not character

This construct is similar to the `[]` construct, execpt rather than matching any characters inside the brackets, it'll match any character, as long as it is not listed between the `[`  and `]`. This is *logical* NOT.

In the [*square bracket*](#-square-bracket-specifies-a-range) case, we were listing files having character from 'a' to 'c', we will use the similar case, for listing files which doesn't included characters from 'a' to 'c', using the exclamation mark (`!`).

```bash
paradox@paradox:~/Documents/others$ ls c[!a-c]t.txt
cdt.txt  cet.txt
paradox@paradox:~/Documents/others$ 
```

##### `\` (backslash) escape character


It is used as an "escape" character, i.e. too protext a subsequent special character. Thus, "\\" searches for a backslash. 