#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * _string_directory - Split a string in tokens for each directory in the path.
 *
 * @argv: array to concatenate with directory and /.
 *
 * Return: On succes string concatenated 0r NULL if fails.
*/

char *_string_directory(char **argv)
{
	struct stat st;
	int i = 0, j = 0, k = 0;
	char **token_path = NULL, *p = NULL, *path = NULL;

	for (i = 0; environ[i]; i++)
		if (!strncmp(environ[i], "PATH", 4))
			path = (environ[i] + 5); /*string de directorios*/

	token_path = _split_string(path, ":"); /*tokens del path*/

	i = 0;
	while (token_path[i]) /*recorre cada uno de los tokens*/
	{
		for (j = 0; token_path[i][j]; j++)
		;
		for (k = 0; argv[0][k]; k++)
		;
		p = malloc(sizeof(char) * (j + k + 2));
			if (!p)
			perror("Error"), free(token_path), exit(0); /*TODO: verificar error output*/

		for (j = 0; token_path[i][j]; j++)
			p[j] = token_path[i][j];
		p[j] = '/';
		for (k = 0; argv[0][k]; k++)
			p[j + k + 1] = argv[0][k];
		p[j + k + 1] = '\0';

		if (stat(p, &st) == 0)
		{
			free(token_path);
			return (p);
		}
		i++;
	}
	return (NULL);
}
