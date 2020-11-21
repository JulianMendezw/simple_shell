
#include "header.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void _ctrl_c(int sig)
{
	(void)sig;
	write(STDERR_FILENO, "\n", 2);
	exit(0);
}
