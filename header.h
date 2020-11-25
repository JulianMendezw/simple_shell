#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>

extern char **environ;
char **_split_string(char *str, char *delim);
void _ctrl_c(int sig);
char *_strcat(char *dest, char *src);
char *_string_directory(char **argv);
char *_getenv(char *name);
int _print_env(char **array);
int _exec(int count_w, char *token, char *array[]);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void _sfree(char **i_want_to_be_free);
char *_token(char *buffer, char **array);
void _error(int count_w, char *array[]);
char *_itoa(int integer);
char *_strtok(char *str, const char *delim);
char *_hack_path(char *path);

#endif
