#include "shell.h"

/**
 * print_env - Prints the environment variables.
 */
void print_env(void)
{
	for (int i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
