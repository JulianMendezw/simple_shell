#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>

/**
 * main - super minishel ♥.
 *
 * @ac: arguments count.
 * @argv: arguments.
 *
 * Return: Always return 0.
 */

int main(int ac, char *argv[])
{
	int r_bytes = 0;
	size_t nbytes = 0;
	char *buffer = NULL, **array = NULL, *token = NULL;
	char *xclose[] = {"exit", NULL};
	struct stat st;
	(void)ac, (void)argv;

	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\033[94mminishell$: \033[0m", 16);

	signal(SIGINT, _ctrl_c);
	while ((r_bytes = getline(&buffer, &nbytes, stdin)) != -1)
	{
		if (r_bytes != 1) /*enter line*/
		{
			buffer[r_bytes - 1] = '\0';
			array = _split_string(buffer, " ");

			if (buffer[0] == '/' || buffer[0] == ' ')
			{
				token = strtok(buffer, " "); /*By Jong line ♥*/
				if (token[0] != '/')
				token = _string_directory(&token);
			}
			else
				token = _string_directory(array);

			if (_strcmp(array[0], xclose[0]) == 0) /* By sotelo line ♥ */
				free(array[0]), free(array), free(token), free(buffer),	exit(0);

			if (_print_env(array) != 1)
			{
				if (stat(token, &st) == 0)
					_exec(token, array);
			}
		}
		if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\033[94mminishell$: \033[0m", 16);
	}
	if (isatty(STDIN_FILENO) != 0)
	write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	return (0);
}
