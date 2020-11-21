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
 * Return: Always return 0.
 */

int main(void)
{
	int i = 0, r_bytes = 0;
	size_t nbytes = 0;
	char *buffer = NULL, **array = NULL, *token = NULL;
	pid_t child;
	
	struct stat st;

	signal(SIGINT, _ctrl_c);
	while (i != -1)
	{
		printf("minishell$ ");
		r_bytes = getline(&buffer, &nbytes, stdin);
		if (r_bytes == -1)/*TODO:liberar buffer incluso si hay error*/
		{
			perror("Error of getline"); /*FIXME: The error output.*/
			break;
		}
		if (r_bytes != 1)
		{
			buffer[r_bytes - 1] = '\0';
			array = _split_string(buffer, " ");
			if (buffer[0] == '/')
				token = *array;
			else
				token = _string_directory(array);
			if (strcmp(array[0], xclose[0]) == 0) /* By sotelo line ♥ */
				free(array[0]), free(array), free(token), free(buffer),	exit(0);
			if (stat(token, &st) == 0)
			{
				child = fork();
				if (child == -1)
					free(buffer), free(token), free(buffer),
					perror("Error"), exit(1);
				if (child == 0)
				{
					if (execve(token, array, NULL) == -1)
						free(buffer), free(array), free(token),
						perror("Error Execve"), exit(1);
				}
				else
					wait(NULL);
			}
		}
	}
	free(buffer);
	return (0);
}
