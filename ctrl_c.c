
#include "header.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *_ctrl_c - function to capture interruption signal
 *@sig: signal variable
 *Return: void
 */
void _ctrl_c(int sig)
{
	(void)sig;
	write(STDERR_FILENO, "\n", 2);
	exit(0);
}
