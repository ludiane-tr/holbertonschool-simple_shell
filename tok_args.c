#include "shell.h"

/**
 * tok_args - Tokenizes a string into an array of arguments.
 * @input_buffer: The string to tokenize.
 * Return: A pointer to an array of arguments.
 */
char **tok_args(char *input_buffer)
{
	char *token, **argv;
	int token_count = 0, i = 0;

	while (*input_buffer == ' ' || *input_buffer == '\t')
		input_buffer++;

	char *temp_buffer = strdup(input_buffer);

	if (!temp_buffer)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(temp_buffer, " \t");
	while (token)
	{
		token_count++;
		token = strtok(NULL, " \t");
	}
	free(temp_buffer);

	argv = malloc((token_count + 1) * sizeof(char *));
	if (!argv)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_buffer, " \t");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	return (argv);
}

