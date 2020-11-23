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

### Librarys 📚

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <sys/wait.h>

#include <sys/stat.h>

#include <signal.h>

#include <signal.h>

#include "header.h"


### Tools 🛠️

*getline Get line from user

*execve System call - Executing a program

*fork Creating processes

*wait Suspends execution of the calling process


### Compiled this way🔧

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Example

Run the executable in your terminal after compiling

```
$ ./hsh
simpleshell$:ls
README.md   ctrl_c.c  header.h.gch	simple_shell
a.out	        exec.c    minishell.c	splits_string.c
built-in.c  header.h  shell_test_suite	string_directory.c
```

### Authors

Julián Mendez | @julianmendezx

Helena Cortés | @helectron
