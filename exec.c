#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

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
	return(0);
}