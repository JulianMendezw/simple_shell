#ifndef __HEADER_H__
#define __HEADER_H__

extern char **environ;
char **_split_string(char *str, char *delim);
void _ctrl_c(int sig);
char *_strcat(char *dest, char *src);
char *_string_directory(char **argv);
char *_getenv(char *name);
int _print_env(char **array);
int _exec(char *token, char *array[]);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void double_free(char **i_want_to_be_free);
char *_token(char *buffer, char **array);

#endif
