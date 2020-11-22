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

		str_copy = _strdup(str);

		token = strtok(str_copy, delim);

		while (token)
		{
			token = strtok(NULL, delim);
			i++;
		}
		free(str_copy);

		str_copy = _strdup(str);
		token2 = strtok(str_copy, delim);
		array = malloc(sizeof(char *) * (i + 1)); /*TODO: freeme!!*/

		while (token2)
		{
			array[x] = _strdup(token2);
			token2 = strtok(NULL, delim);
			x++;
		}
		array[x] = NULL;

		free(str_copy);
		return (array);
}


/**
 * _strdup - a function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter.
 *
 *@str: string source.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

char *_strdup(char *str)
{
	char *copy;
	int index = 0, len = 0;

	if (str == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		copy[index] = str[index];

	copy[len] = '\0';

	return (copy);
}

/**
 * _strcmp - to compare two string
 *@s1: value waited from the main.c
 *@s2: source to be compare
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int c = 0, x = 0;

	for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
	{
		if (s1[c] == s2[c])
			x = 0;
		else
			return (s1[c] - s2[c]);
	}
	return (x);
}