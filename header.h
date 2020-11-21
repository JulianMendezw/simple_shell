#ifndef __HEADER_H__
#define __HEADER_H__

char **_split_string(char *str, char *delim);
int _find_file(char **array);
void _ctrl_c(int sig);
char *_strcat(char *dest, char *src);
char *_string_directory(char **argv);
extern char **environ;

#endif