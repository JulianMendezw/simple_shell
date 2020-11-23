#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 *_exec - function to executate the program
 *@token: pointer to command from user´s input
 *@array: array to execute with execve
 *Return: 0 for success
 */
int _exec(char *token, char *array[])
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
	return (0);
}
