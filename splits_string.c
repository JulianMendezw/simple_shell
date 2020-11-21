#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "header.h"


char **_split_string(char *str, char *delim)
{

		int i = 0, x = 0;
		char **array = NULL, *token = NULL, *token2;
		char *str_copy = NULL;

		str_copy = strdup(str);

		token = strtok(str_copy, delim);

		while (token)
		{
			token = strtok(NULL, delim);
			i++;
		}
		free(str_copy);

		str_copy = strdup(str);
		token2 = strtok(str_copy, delim);
		array = malloc(sizeof(char *) * (i + 1)); /*TODO: freeme!!*/

		while (token2)
		{
			array[x] = strdup(token2);
			token2 = strtok(NULL, delim);
			x++;
		}
		array[x] = NULL;

		free(str_copy);
		return (array);
}
