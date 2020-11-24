#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * _exec - Funtion to execute program.
 *
 * @token: Command from the user imput.
 * @array: arguments for the program to execute.
 * @count_w: holis.
 *
 * Return: Always return 0.
 */

int _exec(int count_w, char *token, char *array[])
{
	struct stat st;
	pid_t child = 0;

	if (stat(token, &st) == 0)
	{
		child = fork();
		if (child == -1)
			free(token),
			perror("Error"), exit(1);

		if (child == 0)
		{
			if (execve(token, array, NULL) == -1)
				/* free(buffer), free(array), free(token),*/
				perror("Error Execve"), exit(1);
		}
		else
			wait(NULL);
	}
	else
		_error(count_w, array);

	return (0);
}


/**
 * _error - Funtion to execute program.
 *
 * @count_w: Command from the user imput.
 * @array: arguments for the program to execute.
 *
 * Return: Always return 0.
 */

void _error(int count_w, char *array[])
{
	int i = 0;
	char *print_c = NULL;

	print_c = _itoa(count_w);

	for (i = 0; print_c[i]; i++)
	;

	write(STDERR_FILENO, "\033[94mminishell$: \033[0m", 17);
	write(STDERR_FILENO, print_c, i); /* by Andy.*/
	write(STDERR_FILENO, ": ", 2);

	for (i = 0; array[0][i]; i++)
	;

	write(STDERR_FILENO, array[0], i);
	write(STDIN_FILENO, ": not found\n", 12);

}

/**
 * _itoa - Funtion to execute program.
 *
 * @count_w: Command from the user imput.
 *
 * Return: Always return 0.
 */


char *_itoa(int count_w)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count_w;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count_w; --digits)
	{
		numstr[digits] = (count_w % 10) + '0';
		count_w /= 10;
	}
	return (numstr);
}
