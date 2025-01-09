#include "shell.h"

/**
 * exec_cmd - Executes a command.
 * @argv: The array of arguments for the command.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int exec_cmd(char **argv)
{
	pid_t child_pid;
	int status;
	char *cmd = argv[0];
	char *work_buffer = malloc(1024);

	if (!work_buffer)
		return (_error());

	if (!strcpy(work_buffer, cmd) ||
			path_finder(cmd, work_buffer) == EXIT_FAILURE)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
		free(work_buffer);
		return (127);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		free(work_buffer);
		return (_error());
	}

	if (child_pid == 0)
	{
		if (execve(work_buffer, argv, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
			free(work_buffer);
			exit(127);
		}
	}

	wait(&status);
	free(work_buffer);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (EXIT_FAILURE);
}
