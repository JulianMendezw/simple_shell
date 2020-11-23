### SHELL PROJECT - SIMPLE SHELL

Unix shell is a command-line interpreter designed to read commands typed by a user and execute appropriate programs in response to those commands. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

### For testing

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
```

### Tools 🛠️

*getline 

*execve System call - Executing a program

*fork Creating processes

*wait Suspends execution of the calling process

### Librarys 📚

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <sys/wait.h>

#include "header.h"

### Style for coding

Use the Betty style, it will be checked using betty-style.pl and betty-doc.pl.

###Authors ✒️

Tools 🛠️

*getline Get line from user

*execve System call - Executing a program

*fork Creating processes

*wait Suspends execution of the calling process

Librarys 📚

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <sys/wait.h>

#include <sys/stat.h>

#include <signal.h>

#include "header.h"

### Compiled this way🔧

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Example

Run the executable in your terminal after compiling

```
$ ./hsh
minishell$:ls
README.md   ctrl_c.c  header.h.gch	simple_shell
a.out	        exec.c    minishell.c	splits_string.c
built-in.c  header.h  shell_test_suite	string_directory.c
```

### Authors

Julián Mendez | @julianmendezx

Helena Cortés | @helectron
