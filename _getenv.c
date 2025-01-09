#include "shell.h"

/**
 * _getenv - Retrieve the value of an environment variable
 * @name: The name of the variable to find
 * Return: Pointer to the value of the variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t name_len;

	if (!name || !environ)
		return (NULL);

	name_len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (&environ[i][name_len + 1]);
		i++;
	}
	return (NULL);
}
