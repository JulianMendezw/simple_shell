#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * double_free - Function to free double pointers
 * @i_want_to_be_free: double pointer to be free
 */

void double_free(char **i_want_to_be_free)
{
	int ptr_index;

	for (ptr_index = 0; i_want_to_be_free[ptr_index] != NULL; ptr_index++)
	{
		free(i_want_to_be_free[ptr_index]);
	}
	free(i_want_to_be_free);
}