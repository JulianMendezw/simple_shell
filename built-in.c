#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _print_env(char **array)
{
	int i = 0, j = 0;
	char *key_word[] = {"env", NULL};

	if (_strcmp(array[0], key_word[0]) == 0)
	{
		while (environ[i])
		{
			for (j = 0; environ[i][j]; j++)
			;
			write(1, environ[i], j);
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}
return (-1);
}
